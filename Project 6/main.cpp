/*
 Name: Brandon Trastoy and Timothy Schutte
 Class: CIS - 161
 Date: December 13, 2017
 Program: Project 6
 
 Description: This program creates an array of class objects, whose member variables are private and
                    member functions are public. It uses a static variable to add all quarterly
                    sales from all array objects and outputs the total to the user. This program also

 */

#include "divSales.h"
#include <iostream>
#include <iomanip>
using namespace std;

//Function prototype for getSubScript, this function will prompt
// the user to enter an intger value, then return it
int getSubScript(int);

int main() {
    
    //Variables ------
    string regionName;
    int sub1, sub2;
    
    //Arrays ---------
    float fArray[4];
    
    //Array of classes
    divSales salesArray[4];
    
    //Asks the user to enter region information
    for (int i = 0; i < 4; i++) {
        salesArray[i].setRegionInfo(regionName, fArray);
    }
    
    cout << endl;
    
    //Function call for getSubScript
    sub1 = getSubScript(1);
    sub2 = getSubScript(2);
    // -----------------------------
    
    // Prints out the region name, quarterly sales, and region total
    for (int i = 0; i < 4; i++) {
    	cout << endl << salesArray[i].getRegionName() << endl;
    	cout << salesArray[i].getDivisionSales() << endl;
	}
    
    // Prints the totalCorporateSales
    cout << endl << endl << "All Regions Total: " << salesArray[0].getRegionalSales()
         << endl << endl;
    
    // Prints the name and quarterly region value for the values inputed in getSubScript
    cout<< "The " << salesArray[sub1].getRegionName() << " region's Quarter #" <<
	sub2+1 << " sales total is " << salesArray[sub1].getQuarterlySales(sub2)<< endl << endl;
    
    cout << "Extra Credit **************************************************" << endl << endl;
    
    float total[4] = {0.0};
    
    for (int i = 0; i < 4; i++) {
        
        for(int j = 0; j < 4; j++) {
            total[i] += salesArray[j].extraCredit(i);
        }
        
        cout << "All Regions Quarter " << i+1 << ": " << total[i] << endl;
    }
    
    cout << endl << "Extra Credit **************************************************" << endl;
}

//Function definition for getSubScript
int getSubScript(int j){
	for (int i = 4; i > 3 || i < 0;){
		cout << "Please enter subscript " << j << ": "; cin >> i;
		if(i <= 3 || i >= 0)
			return i-1;
	}
	return -1;
}

/* Test Information --------------------------------------------------------
 
 Enter Region: Wes
 Please Enter a Valid Region: West
 Quarter 1: 12000
 Quarter 2: 12300
 Quarter 3: 24000
 Quarter 4: 56000
 Enter Region: East
 Quarter 1: 50000
 Quarter 2: 53000
 Quarter 3: 990
 Quarter 4: 12000
 Enter Region: North
 Quarter 1: 34000
 Quarter 2: 45000
 Quarter 3: 23000
 Quarter 4: 100000
 Enter Region: South
 Quarter 1: 12300
 Quarter 2: 56000
 Quarter 3: 89000
 Quarter 4: 45000
 
 Please enter subscript 1: 1
 Please enter subscript 2: 4
 
 West
 Quarter 1: 12000.00
 Quarter 2: 12300.00
 Quarter 3: 24000.00
 Quarter 4: 56000.00
 Region Total: 104300.00
 
 East
 Quarter 1: 50000.00
 Quarter 2: 53000.00
 Quarter 3: 990.00
 Quarter 4: 12000.00
 Region Total: 115990.00
 
 North
 Quarter 1: 34000.00
 Quarter 2: 45000.00
 Quarter 3: 23000.00
 Quarter 4: 100000.00
 Region Total: 202000.00
 
 South
 Quarter 1: 12300.00
 Quarter 2: 56000.00
 Quarter 3: 89000.00
 Quarter 4: 45000.00
 Region Total: 202300.00
 
 
 All Regions Total: 624590.00
 
 The West region's Quarter #4 sales total is 56000.00
 
 Extra Credit **************************************************
 
 All Regions Quarter 1: 108300.00
 All Regions Quarter 2: 166300.00
 All Regions Quarter 3: 136990.00
 All Regions Quarter 4: 213000.00
 
 Extra Credit **************************************************
 
------------------------------------------------------------------------- */
