/*
 Authors: Brandon Trastoy and Tim Schutte
 Class: CIS - 161
 Date: September 26, 2017
 Program: loops and functions
 Description:
 
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>

using namespace std;

//Function prototype for loop, it is a function that calls all other functions.
void loop();

//Function prototype for menu, does not return a value. Used to print the user menu
void menu(float, float, float, float, float, float);

//Function prototype for getdata, returns 2 characters and 4 integers by reference. This
//  function gets information from the user, and makes sure they cannot enter values that are
//  not accepted. It also increments the time if the user enters 60 minutes, by adding one to
//  the hours and setting minutes to 0.
void getdata(char &, char &, int &, int &, int &, int &);

//Function prototype for setdata, returns 4 integers by reference. This functions sets the
//  total hours and minutes, and then assigns a cutoff time r to be used in calculations
void setdata(char, char, int, int, int, int, int &, int &, int &, int &);

//Function prototype for calculations, returns 1 float by reference. This functions computes
//  the total cost for the parking bill. It also uses multiple if statements to determine which
//  cost it will be calculating.
void calculation(char, char, int, int, float &, float, float, float, float, float, float);

//Function prototype for print, this function returns no values. This function constructs a
//  final bill for the user to view and it also uses if statements to set the time of day.
void print(char, char, int, int, int, int, int, int, int, float);


int main() {
    
    //Function Call for loop, allowing the initial running of the program
    loop();
    
    return 0;
}

//Function definition for loop
void loop(){
    //Character variable for vehicle type, truck size, and for answeing whether the user would
    //  like to loop again or not.
    char vehicleType=' ', truckSize=' ', loopVar=' ';
    
    //Int variable for in hours and minutes; out hours and minutes (THESE VALUES ARE PURPOSELY
    //  INITIALIZED AS INCORRECT VALUES); total hours and minutes, then r and hours. "r" is a
    //  value that represents the cutoff for each values and hours represents the rounded total hours.
    int inHour=5, inMin=61, outHour=5, outMin=61, totalHour = 0, totalMin = 0, r = 0, hours = 0;
    
    //Float variable for total cost.
    float totalCost = 0.0;
    
    //Const float values for each vehicle types primary and secondary fare.
    const float CAR_FARE = 0.0, CAR_FARE_2ND = 1.50, BUS_FARE = 1.00,
    BUS_FARE_2ND = 2.50, TRUCK_FARE = 2.00,TRUCK_FARE_2ND = 3.50;
    
    //Function call for menu, it uses the const float values as parameters and outputs them to
    //  the user.
    menu(CAR_FARE, CAR_FARE_2ND, BUS_FARE, BUS_FARE_2ND, TRUCK_FARE,
         TRUCK_FARE_2ND);
    
    //Function call for getdata, it takes the parameters: vehicleType, truckSize, inHour,
    //  inMin, outHour, outMin. Then it returns these values by reference.
    getdata(vehicleType, truckSize, inHour, inMin, outHour, outMin);
    
    //Function call for setdata, it takes the parameters: totalHour, totalMin, r, hours.
    //  It passes these values by reference and the rest are pass by value.
    setdata(vehicleType, truckSize, inHour, inMin, outHour, outMin,
            totalHour, totalMin, r, hours);
    
    //Function call for calculations, returns total cost by reference.
    calculation(vehicleType, truckSize, r, hours, totalCost, CAR_FARE, CAR_FARE_2ND,
                BUS_FARE, BUS_FARE_2ND, TRUCK_FARE, TRUCK_FARE_2ND);
    
    //Function call for print. It prints ...
    print(vehicleType, truckSize, inHour, inMin, outHour, outMin, totalHour, totalMin, hours, totalCost);
    
    //Checks if user would like to repeat the program
    while(loopVar != 'N' && loopVar != 'Y'){
        
        cout<< "Do you have another vehicle? (Y/N) "; cin>> loopVar;
        
        //Takes the char value for loopVar then capitalizes it
        loopVar = toupper(loopVar);
        
        //If y/Y Function calls for loop. It runs the function again from the beginning
        if(loopVar == 'Y')
            loop();
        
        //Otherwise, if the user input anything besides a Y or N, it will ask them to
        //  input a proper answer, if an N is input, then it will end the program
        //	without starting another loop.
        else if(loopVar != 'N'){
            cout << "Please Enter Y/N\n";
        }
    }
    
}


//Function definition for menu
void menu(float CAR_FARE, float CAR_FARE_2ND, float BUS_FARE,
          float BUS_FARE_2ND, float TRUCK_FARE, float TRUCK_FARE_2ND) {
    
    cout << "\t\tPassaic County Parking Authority" << endl << endl;
    
    cout << "NOTICE: The parking lot opens at 6:00 AM and closes at 12:00 PM. Any vehicles left in the lot after closing will be towed!" << endl << endl;
    
    //Set the decimal place value to 2
    cout << setprecision(2) << fixed;
    
    cout << "\tFares and Pricing Options " << endl << endl;
    
    cout << "Car:   \t$" << CAR_FARE   << " First 3 Hours; |\t$" << CAR_FARE_2ND   << " After 3 Hours |" << endl;
    cout << "Bus:   \t$" << BUS_FARE   << " First 2 Hours; |\t$" << BUS_FARE_2ND   << " After 2 Hours |" << endl;
    cout << "Truck: \t$" << TRUCK_FARE << " First Hour;    |\t$" << TRUCK_FARE_2ND << " After 1 Hour  |" << endl;
    
    cout << endl << endl;
    
}


//Function definition for getdata
void getdata(char & vehicleType, char & truckSize, int & inHour, int & inMin, int & outHour, int & outMin) {
    
    cout << "Please Enter The First Letter When Entering Your Vehicle Type!" << endl;
    cout << "Also, Please Enter Hours Using A 24 Hour Clock." << endl << endl;
    
    
    //While the vehicle type is not set to a proper variable, asks the user to enter a vehicle type.
    while(vehicleType != 'C' && vehicleType != 'V' && vehicleType != 'S' && vehicleType != 'B' && vehicleType != 'T'){
        
        cout << "Enter A Vehicle Type: "; cin >> vehicleType;
        
        //Takes the char value for vehicleType then capitalizes it
        vehicleType = toupper(vehicleType);
        
        //If an improper vehicle type is entered, prompts the user to enter a proper truck size
        if(vehicleType != 'C' && vehicleType != 'V' && vehicleType != 'S' && vehicleType != 'B' && vehicleType != 'T')
            cout<< "Please Enter a Proper Vehicle Type\n";
        
        //While the vehicle type is a truck, and the truck size is not a proper truck size,
        //	the user is asked to enter a truck size, running at least once.
        while(vehicleType == 'T' && (truckSize!= 'S' && truckSize != 'L') ){
            
            cout << "Enter the size of the truck (S small, L large): "; cin >> truckSize;
            
            //Takes the char value for truckSize then capitalizes it
            truckSize = toupper(truckSize);
            
            //If an improper truck size is entered, prompts the user to enter a proper truck size
            if(truckSize!= 'S' && truckSize != 'L')
                cout<< "Please Enter a Proper Truck Size\n";
        }
    }
    
    
    //These loops makes it so that the user cannot enter an invalid input. In loop the values
    //  are initialized so this atleast runs once.
    //---------------------------------------------------------------------------------------
    while(inHour < 6 || inHour > 23)
    {
        cout << "Enter the time in Hours: "; cin >> inHour;
        if(inHour==24)
            cout << "It is not possible to enter the parking garage at closing\n";
        else if(inHour < 6 || inHour > 23)
            cout << "Please enter a time within the 6:00 AM and  12:00 PM (24:00) Time Frame\n";
    }
    
    while(inMin < 0 || inMin > 60)
    {
        cout << "Enter the time in Minutes: "; cin >> inMin;
        if(inMin < 0 || inMin > 60)
            cout << "Please enter a proper time for minutes\n";
    }
    
    while(outHour < 6 || outHour > 23 || outHour < inHour)
    {
        cout << "Enter the time out Hours: "; cin >> outHour;
        if(outHour < 6 || outHour > 23)
            cout << "Please enter a time within the 6:00 AM and  12:00 PM (24:00) Time Frame\n";
        if(outHour < inHour)
            cout << "Please enter a time greater than or equal to your start time\n";
    }
    
    while(outMin < 0 || outMin > 60)
    {
        cout << "Enter the time out Minutes: "; cin >> outMin;
        if(outMin < 0 || outMin > 60)
            cout << "Please enter a proper time for minutes\n";
        if (inHour == outHour && outMin<inMin)
        {
            cout << "Please enter a time greater than your start time\n";
            outMin=-1;
        }
    }
    //---------------------------------------------------------------------------------------
    
    
    //These if statements increment the value of hours by 1 and reset the minutes if minutes
    //  are set to 60.
    //---------------------------------------------------------------------------------------
    if(inMin==60) {
        inHour++;
        inMin = 0;
    }
    if(outMin==60) {
        outHour++;
        outMin = 0;
    }
    //---------------------------------------------------------------------------------------
    
}


//Function definition for setdata
void setdata(char vehicleType, char truckSize, int inHour, int inMin, int outHour,
             int outMin, int & totalHour, int & totalMin, int & r, int & hours) {
    
    //These if/else statements make it so that calculation the total hours and minutes do not
    //  return a negative value.
    //---------------------------------------------------------------------------------------
    if (outMin < inMin) {
        totalMin = (outMin + 60) - inMin;
        totalHour = (outHour - 1) - inHour;
    }
    else {
        totalHour = outHour - inHour;
        totalMin = outMin - inMin;
    }
    //---------------------------------------------------------------------------------------
    
    
    //These if/else statements find the rounded hours that a vehicle has been in the parking
    //  lot.
    //---------------------------------------------------------------------------------------
    if (totalMin > 0) {
        hours = totalHour + 1;
    }
    
    else {
        hours = totalHour;
    }
    //---------------------------------------------------------------------------------------
    
    
    //These if/else statements find the cut off time, either by setting r to that value or
    //  zero for the calculations.
    //---------------------------------------------------------------------------------------
    if (vehicleType == 'C' || vehicleType == 'S' || vehicleType == 'V')
        if (totalHour > 3)
            r = 3;
    
        else if (vehicleType == 'B' || truckSize == 'S')
            if (totalHour > 2)
                r = 2;
            else
                r = 1;
    //---------------------------------------------------------------------------------------
}

//Functions definition for calculations
void calculation(char vehicleType, char truckSize, int r, int hours, float & totalCost, float CAR_FARE,
                 float CAR_FARE_2ND, float BUS_FARE, float BUS_FARE_2ND, float TRUCK_FARE, float TRUCK_FARE_2ND) {
    
    //These if statements find the total cost. There are two statements for each vehicle type, and
    //  small trucks are set to the bus fare.
    //---------------------------------------------------------------------------------------
    if ((vehicleType == 'C' || vehicleType == 'S' || vehicleType == 'V') && r > 0) {
        totalCost = ((hours - r) * CAR_FARE_2ND) + (r * CAR_FARE);
    }
    
    else if ((vehicleType == 'C' || vehicleType == 'S' || vehicleType == 'V') && r == 0) {
        totalCost = hours * CAR_FARE;
    }
    
    else if ((vehicleType == 'B' || truckSize == 'S') && r > 0) {
        totalCost = ((hours - r) * BUS_FARE_2ND) + (r * BUS_FARE);
    }
    
    else if ((vehicleType == 'B' || truckSize == 'S') && r == 0) {
        totalCost = hours * BUS_FARE;
    }
    
    else if ((vehicleType == 'T') && r > 0) {
        totalCost = ((hours - r) * TRUCK_FARE_2ND) + (r * TRUCK_FARE);
    }
    else if ((vehicleType == 'T') && r == 0) {
        totalCost = hours * TRUCK_FARE;
    }
    //---------------------------------------------------------------------------------------
}

//Function definition for print
void print(char vehicleType, char truckSize, int inHour, int inMin, int outHour, int outMin,
           int totalHour, int totalMin, int hours, float totalCost) {
    
    //Local string value, used for the AM and PM portion.
    string timeOfDayIn, timeOfDayOut, properMinIn, properMinOut;
    
    //Sets the value to AM or PM for the in time
    if (inHour > 11 && inHour < 23) timeOfDayIn = "PM";
    else if (inHour <= 11 || inHour == 23) timeOfDayIn = "AM";
    
    //Sets the value to AM or PM for the out time
    if (outHour > 11 && outHour < 23) timeOfDayOut = "PM";
    else if (outHour <= 11 || outHour == 23) timeOfDayOut = "AM";
    
    //Allows the proper printing of minutes should they be less than 10
    //---------------------------------------------------------------------------------------
    if (inMin < 10) properMinIn = "0";
    
    if (outMin < 10) properMinOut = "0";
    //---------------------------------------------------------------------------------------
    
    cout << endl << endl;
    
    cout << "\t\tPassaic County Parking Authority" << endl << endl;
    
    cout << "\t\t\tParking Lot Charges" << endl << endl;
    
    //Prints the vehicle type, if it is a truck it will display the truck size on another line
    cout << "Vehicle Type:  \t\t\t\t";
    
    if(vehicleType == 'C') cout << "Car\n";
    else if(vehicleType == 'S') cout << "SUV\n";
    else if(vehicleType == 'V') cout << "Van\n";
    else if(vehicleType == 'B') cout << "Bus\n";
    else if(vehicleType == 'T'){
        cout << "Truck\nTruck Size:\t\t\t\t";
        if(truckSize == 'S') cout << "Small\n";
        else cout << "Large\n";
    }
    
    if (inHour > 12) {
        cout << "Time-In:               \t\t" << inHour - 12 << ":" << properMinIn << inMin << " " << timeOfDayIn << endl;
    }
    else if (inHour <= 12) {
        cout << "Time-In:               \t\t" << inHour << ":" << properMinIn << inMin << " " << timeOfDayIn << endl; }
    
    if (outHour > 12) {
        cout << "Time-out:              \t\t" << outHour - 12 << ":" << properMinOut << outMin << " " << timeOfDayOut << endl;;
    }
    else if (inHour <= 12) {
        cout << "Time-out:              \t\t" << outHour << ":" << properMinOut << outMin << " " << timeOfDayOut << endl; }
    
    
    cout << "                       \t\t--------" << endl;
    cout << "Parking-Time:          \t\t" << totalHour << " Hrs and " << totalMin << " Min" << endl << endl;
    
    cout << "Rounded Parking Time:  \t\t" << hours << " Hours" << endl;
    cout << "                       \t\t--------" << endl;
    cout << "Total Due:             \t\t$" << totalCost << endl << endl;
    
    cout << "\tThank you for using Passaic County Parking Authority" << endl;
    
    cout << endl;
}


/* Test 1--------------------------------------------------------------------------------
 
 Fares and Pricing Options
 
 Car:   	$0.00 First 3 Hours; |	$1.50 After 3 Hours |
 Bus:   	$1.00 First 2 Hours; |	$2.50 After 2 Hours |
 Truck: 	$2.00 First Hour;    |	$3.50 After 1 Hour  |
 
 
 Please Enter The First Letter When Entering Your Vehicle Type!
 Also, Please Enter Hours Using A 24 Hour Clock.
 
 Enter A Vehicle Type: c
 Enter the time in Hours: 12
 Enter the time in Minutes: 40
 Enter the time out Hours: 14
 Enter the time out Minutes: 22
 
 
 Passaic County Parking Authority
 
 Parking Lot Charges
 
 Vehicle Type:  				Car
 Time-In:               		12:40 PM
 Time-out:              		2:22 PM
 --------
 Parking-Time:          		1 Hrs and 42 Min
 
 Rounded Parking Time:  		2 Hours
 --------
 Total Due:             		$0.00
 
 Thank you for using Passaic County Parking Authority
 
 Do you have another vehicle? (Y/N) n
 Program ended with exit code: 0
 
 ---------------------------------------------------------------------------------------*/

/* Test 2--------------------------------------------------------------------------------
 
 Passaic County Parking Authority
 
 NOTICE: The parking lot opens at 6:00 AM and closes at 12:00 PM. Any vehicles left in the lot after closing will be towed!
 
	Fares and Pricing Options
 
 Car:   	$0.00 First 3 Hours; |	$1.50 After 3 Hours |
 Bus:   	$1.00 First 2 Hours; |	$2.50 After 2 Hours |
 Truck: 	$2.00 First Hour;    |	$3.50 After 1 Hour  |
 
 
 Please Enter The First Letter When Entering Your Vehicle Type!
 Also, Please Enter Hours Using A 24 Hour Clock.
 
 Enter A Vehicle Type: b
 Enter the time in Hours: 8
 Enter the time in Minutes: 20
 Enter the time out Hours: 8
 Enter the time out Minutes: 20
 
 
 Passaic County Parking Authority
 
 Parking Lot Charges
 
 Vehicle Type:  				Bus
 Time-In:               		8:20 AM
 Time-out:              		8:20 AM
 --------
 Parking-Time:          		0 Hrs and 0 Min
 
 Rounded Parking Time:  		0 Hours
 --------
 Total Due:             		$0.00
 
	Thank you for using Passaic County Parking Authority
 
 Do you have another vehicle? (Y/N) n
 Program ended with exit code: 0
 
 ---------------------------------------------------------------------------------------*/

/* Test 3--------------------------------------------------------------------------------
 
 Passaic County Parking Authority
 
 NOTICE: The parking lot opens at 6:00 AM and closes at 12:00 PM. Any vehicles left in the lot after closing will be towed!
 
	Fares and Pricing Options
 
 Car:   	$0.00 First 3 Hours; |	$1.50 After 3 Hours |
 Bus:   	$1.00 First 2 Hours; |	$2.50 After 2 Hours |
 Truck: 	$2.00 First Hour;    |	$3.50 After 1 Hour  |
 
 
 Please Enter The First Letter When Entering Your Vehicle Type!
 Also, Please Enter Hours Using A 24 Hour Clock.
 
 Enter A Vehicle Type: t
 Enter the size of the truck (S small, L large): s
 Enter the time in Hours: 2
 Please enter a time within the 6:00 AM and  12:00 PM (24:00) Time Frame
 Enter the time in Hours: 6
 Enter the time in Minutes: 0
 Enter the time out Hours: 3
 Please enter a time within the 6:00 AM and  12:00 PM (24:00) Time Frame
 Please enter a time greater than or equal to your start time
 Enter the time out Hours: 59
 Please enter a time within the 6:00 AM and  12:00 PM (24:00) Time Frame
 Enter the time out Hours: 7
 Enter the time out Minutes: 59
 
 
 Passaic County Parking Authority
 
 Parking Lot Charges
 
 Vehicle Type:  				Truck
 Truck Size:				Small
 Time-In:               		6:00 AM
 Time-out:              		7:59 AM
 --------
 Parking-Time:          		1 Hrs and 59 Min
 
 Rounded Parking Time:  		2 Hours
 --------
 Total Due:             		$2.00
 
	Thank you for using Passaic County Parking Authority
 
 Do you have another vehicle? (Y/N) n
 Program ended with exit code: 0
 
 ---------------------------------------------------------------------------------------*/

/* Test 4--------------------------------------------------------------------------------
 
 Passaic County Parking Authority
 
 NOTICE: The parking lot opens at 6:00 AM and closes at 12:00 PM. Any vehicles left in the lot after closing will be towed!
 
	Fares and Pricing Options
 
 Car:   	$0.00 First 3 Hours; |	$1.50 After 3 Hours |
 Bus:   	$1.00 First 2 Hours; |	$2.50 After 2 Hours |
 Truck: 	$2.00 First Hour;    |	$3.50 After 1 Hour  |
 
 
 Please Enter The First Letter When Entering Your Vehicle Type!
 Also, Please Enter Hours Using A 24 Hour Clock.
 
 Enter A Vehicle Type: v
 Enter the time in Hours: 12
 Enter the time in Minutes: 40
 Enter the time out Hours: 16
 Enter the time out Minutes: 22
 
 
 Passaic County Parking Authority
 
 Parking Lot Charges
 
 Vehicle Type:  				Van
 Time-In:               		12:40 PM
 Time-out:              		4:22 PM
 --------
 Parking-Time:          		3 Hrs and 42 Min
 
 Rounded Parking Time:  		4 Hours
 --------
 Total Due:             		$0.00
 
	Thank you for using Passaic County Parking Authority
 
 Do you have another vehicle? (Y/N) n
 Program ended with exit code: 0
 
 ---------------------------------------------------------------------------------------*/

/* Test 5--------------------------------------------------------------------------------
 
 Passaic County Parking Authority
 
 NOTICE: The parking lot opens at 6:00 AM and closes at 12:00 PM. Any vehicles left in the lot after closing will be towed!
 
	Fares and Pricing Options
 
 Car:   	$0.00 First 3 Hours; |	$1.50 After 3 Hours |
 Bus:   	$1.00 First 2 Hours; |	$2.50 After 2 Hours |
 Truck: 	$2.00 First Hour;    |	$3.50 After 1 Hour  |
 
 
 Please Enter The First Letter When Entering Your Vehicle Type!
 Also, Please Enter Hours Using A 24 Hour Clock.
 
 Enter A Vehicle Type: s
 Enter the time in Hours: 8
 Enter the time in Minutes: 20
 Enter the time out Hours: 14
 Enter the time out Minutes: 20
 
 
 Passaic County Parking Authority
 
 Parking Lot Charges
 
 Vehicle Type:  				SUV
 Time-In:               		8:20 AM
 Time-out:              		2:20 PM
 --------
 Parking-Time:          		6 Hrs and 0 Min
 
 Rounded Parking Time:  		6 Hours
 --------
 Total Due:             		$4.50
 
	Thank you for using Passaic County Parking Authority
 
 Do you have another vehicle? (Y/N) n
 Program ended with exit code: 0
 
 ---------------------------------------------------------------------------------------*/

/* Test 6--------------------------------------------------------------------------------
 
 Passaic County Parking Authority
 
 NOTICE: The parking lot opens at 6:00 AM and closes at 12:00 PM. Any vehicles left in the lot after closing will be towed!
 
	Fares and Pricing Options
 
 Car:   	$0.00 First 3 Hours; |	$1.50 After 3 Hours |
 Bus:   	$1.00 First 2 Hours; |	$2.50 After 2 Hours |
 Truck: 	$2.00 First Hour;    |	$3.50 After 1 Hour  |
 
 
 Please Enter The First Letter When Entering Your Vehicle Type!
 Also, Please Enter Hours Using A 24 Hour Clock.
 
 Enter A Vehicle Type: t
 Enter the size of the truck (S small, L large): l
 Enter the time in Hours: 2
 Please enter a time within the 6:00 AM and  12:00 PM (24:00) Time Frame
 Enter the time in Hours: 6
 
 Enter the time in Minutes: 0
 Enter the time out Hours: 12
 Enter the time out Minutes: 0
 
 
 Passaic County Parking Authority
 
 Parking Lot Charges
 
 Vehicle Type:  				Truck
 Truck Size:				Large
 Time-In:               		6:00 AM
 Time-out:              		12:00 PM
 --------
 Parking-Time:          		6 Hrs and 0 Min
 
 Rounded Parking Time:  		6 Hours
 --------
 Total Due:             		$12.00
 
	Thank you for using Passaic County Parking Authority
 
 Do you have another vehicle? (Y/N) n
 Program ended with exit code: 0
 
 ---------------------------------------------------------------------------------------*/












