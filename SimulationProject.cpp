/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <iostream>
#include "ArrayMaxHeap.h"
#include "Passenger.h"
#include "Airworthy.h"

using namespace std;

void description(void) {
    
    cout << "This program reads and uses passenger information from files to" << endl
            << "simulate passengers boarding a plane." <<endl <<endl;
   
}

int main() {
    
    description();
    //Airworthy a("airworthy70.txt");
    //a.simulate();
    //cout << "70 Passengers" << endl;
    //cout << "Amount of time in minutes: " << a.normalTime << endl;
    //cout << "Amount of time in minutes: " << a.randomTime << endl << endl;
    
    //Airworthy b("airworthy85.txt");
    //b.simulate();
    //cout << "85 Passengers" << endl;
    //cout << "Amount of time in minutes: " << b.normalTime << endl;
    //cout << "Amount of time in minutes: " << b.randomTime << endl << endl;
    
    //Airworthy c("airworthy100.txt");
    //c.simulate();
    //cout << "100 Passengers" << endl;
    //cout << "Amount of time in minutes: " << c.normalTime << endl;
    //cout << "Amount of time in minutes: " << c.randomTime << endl;
    
    Airworthy airworthySimulation70("airworthy70.txt", "results70.txt");
    Airworthy airworthySimulation85("airworthy85.txt", "results85.txt");
    Airworthy airworthySimulation100("airworthy100.txt", "results100.txt");
            
    return 0;
}