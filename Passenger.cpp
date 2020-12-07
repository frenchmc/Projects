/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdexcept>
#include "Passenger.h"
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>

Passenger::Passenger(string name, char type, int row, void priorityCallback(Passenger*)) : lastName(name), type(type),
                                                                       priorityValue(0), lastName2(""), passengerType('X')
{
    
    if (row <1 || row > 26)
        throw new runtime_error("runtime error");
    this->row = row;
    if (priorityCallback != nullptr)
        priorityCallback (this);
}

//NEW CODEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE

//Passenger::Passenger2() : priorityValue(0), lastName(""), passengerType('X')
//{
//}

Passenger::Passenger(std::string inputLine) : priorityValue(0)
{
	istringstream ss(inputLine);
	string token;
	vector<string> tokenVector;

	while (getline(ss, token, ' '))
	{
		tokenVector.push_back(token);
	}

	lastName2 = tokenVector[0];

}



string Passenger::toString() const
{
	ostringstream oss;
	oss << setw(13) << lastName2
		<< setw(5) << passengerType
		<< setw(5) << to_string(seatingRow)
		<< setw(5) << to_string(priorityValue);
	return oss.str();
}

void Passenger::setPriorityValue(int p)
{
	priorityValue = p;
}

int Passenger::getPriorityValue()
{
	return priorityValue;
}

void Passenger::setLastName(string last)
{
	lastName2 = last;
}

string Passenger::getLastName()
{
	return lastName2;
}


char Passenger::getPassengerType()
{
	return passengerType;
}

int Passenger::getSeatingRow()
{
	return seatingRow;
}

//NEW CODEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE

bool Passenger::operator<(const Passenger& other) {
    
    return this->priority< other.priority;
}

bool Passenger::operator>(const Passenger& other) {
    
    return this->priority >other.priority;
}