/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Airworthy.h"
#include "ArrayMaxHeap.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

const int ROW_SEATING_PRIORITY[] = {5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3};

void normalPriority(Passenger* p) {
    
    if (p->type == 'H')
        p->priority = 6;
    
    else if (p->type == 'E')
        p->priority = 4;
    else
        p->priority = ROW_SEATING_PRIORITY[p->row -1];
}

void randomPriority (Passenger* p) {
    
    if (p->type == 'H')
        p->priority = 6;
    
    else if (p->type == 'E')
        p->priority = 4;
    else
        p->priority =0;
}

void parseData(const string path, void priorityCallback(Passenger*), ArrayMaxHeap<Passenger>*passengers) {
   
    string line;
    ifstream file(path);
    
    if (!file)
        throw new runtime_error("invalid");
    getline(file, line);
    
    while (file) {
        istringstream stream(line);
        string lastName, type, row;
        getline(stream, lastName, ' ');
        getline(stream, type, ' ');
        getline(stream, row, ' ');
        passengers->add(Passenger(lastName, type[0], stoi(row), priorityCallback));
        getline(file, line);
    }
    file.close();
}

int simulateBoarding(ArrayMaxHeap<Passenger>* passengers) {
    
    Passenger previous;
    int total = 0;
    int count = passengers->getItemCount();
    for (int i = 0; i <count; i++) {
        Passenger p = passengers->peek();
        if (i != 0 && p.row >= previous.row)
            total += 25;
        else
            total++;
        previous = p;
        passengers->remove();
    }
    return total/60;
}

void Airworthy:: simulate() {
    
    normalTime = simulateBoarding(&normalProc);
    randomTime = simulateBoarding(&randomProc);
}

//Airworthy::Airworthy(string path) {
    
    //parseData(path, normalPriority, &normalProc);
    //parseData(path, randomPriority, &randomProc);
//}


//NEW CODEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE

void assignOldPriorityNumber(Passenger& p)
{
	char passengerType = p.getPassengerType();
	int row = p.getSeatingRow();

	if (passengerType == 'H')
	{
		p.setPriorityValue(7);
	}
	else if (row >= 1 && row <= 4)
	{
		p.setPriorityValue(6);
	}
	else if (passengerType == 'E' || row == 10 || row == 11)
	{
		p.setPriorityValue(5);
	}
	else if (row >= 23 && row <= 26)
	{
		p.setPriorityValue(4);
	}
	else if (row >= 17 && row <= 22)
	{
		p.setPriorityValue(3);
	}
	else if (row >= 11 && row <= 16)
	{
		p.setPriorityValue(2);
	}
	else
	{
		p.setPriorityValue(1);
	}
}

/**
 * Assigns new boarding priority number to passenger.
 * In the old boarding procedure there are 4 priority values.
 * The first three values are the same as the old boarding values, but
 * general passengers simply board in the order they're standing in line.
 *
 * 4: Families with young children or people who need help (Passenger Type = 'H')
 * 3: First class and/or business class (Seating Row = 1-4)
 * 2: Elite passengers and passengers in exit rows (Passenger Type = 'E' or Seating Row = 10 or 11)
 * 1: Everyone else
 *
 * @param Passenger
 */
void assignNewPriorityNumber(Passenger& p)
{
	char passengerType = p.getPassengerType();
	int row = p.getSeatingRow();

	if (passengerType == 'H')
	{
		p.setPriorityValue(4);
	}
	else if (row >= 1 && row <= 4)
	{
		p.setPriorityValue(3);
	}
	else if (passengerType == 'E' || row == 10 || row == 11)
	{
		p.setPriorityValue(2);
	}
	else
	{
		p.setPriorityValue(1);
	}
}

void Airworthy::generateDataHeader()
{
    
	ostringstream oss;
	oss << setw(13) << "Last Name"
		<< setw(5) << "Type"
		<< setw(5) << "Row#"
		<< "  Priority Value";
	dataHeader = oss.str();
}

void Airworthy::calculateTimeAndGenerateBoardingList(
		ArrayMaxHeap<Passenger>& pq, int& time)
{
	// Assume first previous passenger is seated in imaginary back seat to
	// avoid special case
	int previousPassengerRow = 27;
	int currentPassengerRow = 0;

	// Remove passengers from priority queue until empty.
	// Record each passenger to simulate boarding the flight.
	// If previous passenger was seated nearer to the front of the plane
	// (with a lesser seat number), increment boarding time by 25 seconds.
	// Otherwise increment boarding time by 1 second.
	while (!pq.isEmpty())
	{
		Passenger currentPassenger = pq.peek();
		outputFile << currentPassenger.toString() << endl;

		currentPassengerRow = currentPassenger.getSeatingRow();

		if (previousPassengerRow <= currentPassengerRow)
		{
			time += 25;
		}
		else
		{
			time++;
		}

		previousPassengerRow = currentPassengerRow;
		pq.remove();
	}
}

void Airworthy::loadQueuesAndRecordInputList(string inputFileName,
		string outputFileName)
{


	try
	{
		ifstream inFile(inputFileName);
	
		outputFile << "---AIRWORTHY BOARDING SIMULATION RESULTS---\n\n"
				   << "The following list contains passengers in the order\n"
				   << "they were listed in the input file: " << inputFileName << "\n\n"
				   << "NOTE: Passengers from the input file have a default\n"
				   << "priority value set to 0 because they are not yet\n"
				   << "part of a boarding procedure.\n\n";
		outputFile << dataHeader << endl << endl;
			
		string line;

		// Iterate through input file line by line.
		// For each line, build and record two Passenger objects.
		// One passenger object will be assigned a priority value according
		// to old procedures, while the other will be assigned a priority
		// value according to the new procedures.
		// Add the passengers to their corresponding priority queues.
		while (inFile.peek() != EOF)
		{
			getline(inFile, line);

			Passenger oldBoardingPriorityPassenger(line);
			outputFile << oldBoardingPriorityPassenger.toString() << endl;
			assignOldPriorityNumber(oldBoardingPriorityPassenger);
			previousBoardingProcQueue.add(oldBoardingPriorityPassenger);

			Passenger newBoardingPriorityPassenger(line);
			assignNewPriorityNumber(newBoardingPriorityPassenger);
			newBoardingProcQueue.add(newBoardingPriorityPassenger);
		}

		inFile.close();
	}
        	catch (ifstream::failure e)
	{
		cerr << "Error opening input file: " << inputFileName
				  << "\n"  << e.what() << std::endl;
	}

}

void Airworthy::runSimulation()
{
	outputFile << "\nThe following list contains the passengers in the order they"
			   << "\nboarded the simulated flight using the old boarding procedures.\n\n"
			   << dataHeader << endl << endl;
	calculateTimeAndGenerateBoardingList(previousBoardingProcQueue, previousBoardingProcTime);


	outputFile << "\nThe following list contains the passengers in the order they"
			   << "\nboarded the simulated flight using the new boarding procedures.\n\n"
			   << dataHeader << endl << endl;
	calculateTimeAndGenerateBoardingList(newBoardingProcQueue, newBoardingProcTime);


}


Airworthy::Airworthy(string inputFileName, string outputFileName) : previousBoardingProcTime(0), newBoardingProcTime(0) {
    
    //parseData(path, normalPriority, &normalProc);
    //parseData(path, randomPriority, &randomProc);
    generateDataHeader();
    loadQueuesAndRecordInputList(inputFileName, outputFileName);
    runSimulation();
    outputFile.close();
}