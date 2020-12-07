/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Airworthy.h
 * Author: 14438
 *
 * Created on December 6, 2020, 7:18 PM
 */

#ifndef AIRWORTHY_H
#define AIRWORTHY_H

#include "ArrayMaxHeap.h"
#include "Passenger.h"
#include <iostream>
#include <fstream>

class Airworthy {
    
    public:
        Airworthy(string inputFileName, string outputFileName);
        ArrayMaxHeap<Passenger> normalProc;
        ArrayMaxHeap<Passenger> randomProc;
        int normalTime;
        int randomTime;
        void simulate();
        Airworthy2(string inputFileName, string outputFileName);
        
 //NEW CODEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE

    //private:
	// Queue to hold passengers to simulate previous boarding procedure.
	// Passengers will be assigned a priority value between 1 and 7.
	ArrayMaxHeap<Passenger> previousBoardingProcQueue;

	// Queue to hold passengers to simulate new boarding procedure.
	// Passengers will be assigned a priority value between 1 and 4.
	ArrayMaxHeap<Passenger> newBoardingProcQueue;

	// Time in seconds required to board plane using old boarding procedure.
	int previousBoardingProcTime;

	// Time in seconds required to board plane using new boarding procedure.
	int newBoardingProcTime;

	// File to write simulation results too.
	ofstream outputFile;

	// Data header for output file
	string dataHeader;

	/**
	 * Helper function to generate dataHeader string.
	 */
	void generateDataHeader();

	/**
	 * Calculate time for boarding procedure and generate passenger boarding list.
	 * @param Priority Queue for this simulation
	 * @param Int time variable to measure simulation matching priority queue argument
	 */
	void calculateTimeAndGenerateBoardingList(ArrayMaxHeap<Passenger>& pq, int& time);

	/**
	 * Load priority queues and record passengers in the order they appear in input file.
	 * @param input file name
	 * @param output file name
	 */
	 void loadQueuesAndRecordInputList(string inputFileName, string outputFileName);

	 /**
	 * Run simulation.
	 * This method runs the boarding simulation and outputs the results to the
	 * output file defined by the user.
	 */
	void runSimulation();
};

#endif /* AIRWORTHY_H */

