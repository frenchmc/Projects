/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Passenger.h
 * Author: 14438
 *
 * Created on December 6, 2020, 7:14 PM
 */

#ifndef PASSENGER_H
#include <string>

using namespace std;

class Passenger {
    
public:
    Passenger (string lastName, char type, int row, void priorityCallback(Passenger*) = nullptr);
    Passenger(){};
    //Passenger2();
    int key;
    string lastName;
    string lastName2;
    char type;
    int row;
    int priority;
    bool operator< (const Passenger& other);
    bool operator> (const Passenger& other);
    
    //NEW CODEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE

	/**
	 * Passenger constructor to build passenger given line from input file.
	 * param inputLine - Input line for passenger simulation
	 */
	Passenger(string inputLine);

	/**
	 * Passenger constructor
	 * @param last - Last name
	 * @param type - Type of passenger (H,E,G)
	 * @param row - Row number on flight (1-26)
	 */
	Passenger(string last, char type, int row);

	/**
	* Turns passenger object into a string for i/o
	* @return Passenger object as string.
	*/
	string toString() const;

	/**
	 * Sets passenger priority value for boarding.
	 * @param p - Priority value
	 */
	void setPriorityValue(int p);

	/**
	 * Retrieves passenger priority value.
	 * @return integer priority value
	 */
	int getPriorityValue();

	/**
	 * Sets passengers last name.
	 * @param last - Last name of passenger.
	 */
	void setLastName(string last);

	/**
	 * Retrieves passengers last name.
	 * @return string - last name
	 */
	string getLastName();

	/**
	 * Retrieves passenger type.
	 * @return char - Passenger type
	 */
	char getPassengerType();

	/**
	 * Retrieves the seating row of the passenger
	 * @return int - Row number
	 */
	int getSeatingRow();
        
    //NEW CODEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE   
    //NEW CODEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE   
    private:
	// Priority Value used to determine boarding order
	int priorityValue;


	// Type of passenger:
	// H: Child or passenger who needs help boarding (e.g. wheelchair)
	// E: Elite passenger (frequent flier)
	// G: General boarding passenger
	char passengerType;

	// Row of seat in plane. Value must be between 1 and 26
	int seatingRow;
    //NEW CODEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE   

};

#define PASSENGER_H
#endif /* PASSENGER_H */

