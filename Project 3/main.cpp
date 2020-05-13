/*
    Name: Brandon Trastoy and Timothy Schutte
	Class: CIS - 161
	Date: October 25, 2017
	Program Name: Project 3
	Description: This program takes information from a file that was given to us
                    and places them into individual arrays. Then, it calculates
                    the average score for each student, the highest quiz grade
                    for each quiz, the lowest quiz grade for each quiz, and the
                    average grade for each quiz. Last, it takes all the 
                    information aquired and outputs it to a file.
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Constant Variable for array size
const int SIZE = 50;

// Arrays ---------------------
typedef  int intArray[SIZE];
typedef float floatArray[SIZE];

//Function prototype for heading, outputs heading to a file
void heading(ostream &);

// Function prototype for getdata, takes in one integer array, three float arrays,
// and a file. Arrays automatically pass by reference, file passed by reference.
int getdata(intArray, floatArray, floatArray, floatArray, ifstream &);

// Function prototype for find student average, takes in arrays and int
void findStAvg(floatArray, floatArray, floatArray, floatArray, int);

// Function protype for find highest quiz, takes in an array and int
int findhigh(floatArray, int);

// Function protype for find lowes quiz, takes in an array and int
int findlow(floatArray, int);

// Function protype for find quiz average, takes in an array and int
float findqzavg(floatArray, int);

// Function prototype for print All, sends results to a file
void printAll(intArray, floatArray, floatArray, floatArray, floatArray, int, int &,
              int &, int &, int &, int &, int &, float &, float &, float &);



int main() {
    
    // Arrays ---------------------
    intArray idNum;
    floatArray quiz1, quiz2, quiz3, avgStGrade;
    
    
    // Variables ------------------
    int numOfElements, high1, high2, high3, low1, low2, low3;
	float avg1, avg2, avg3;
    
    // Reading information from the file
    ifstream fin("pr2data.txt");
    
    
    if (fin) {
        
        // Func call for getdata, returns number of elements, , returns arrays automatically
        numOfElements = getdata(idNum, quiz1, quiz2, quiz3, fin);
        fin.close();
        
        // Func call for find student average, returns arrays automatically
        findStAvg(quiz1, quiz2, quiz3, avgStGrade, numOfElements);
        
        // Func call for printAll, outputs to a file
        printAll(idNum, quiz1, quiz2, quiz3, avgStGrade, numOfElements, high1,
                 high2, high3, low1, low2, low3, avg1, avg2, avg3);
    }
    
    else {
        
        cout << "File does not exist or is not open " << endl;
    }
    
    return 0;
}

// Function declaration for heading, creates a header to be outputted to a file
void heading(ostream & fout) {
    
    fout << endl << endl << "\t\tCIS Department – Fall 2017" << endl <<
    "\t\t CIS 161 Class Statistics" << endl << endl;
    
    fout << left << setw(14) << "Student ID"  << left << setw(12) << "Quiz 1" <<
    left << setw(12) << "Quiz 2" << left << setw(12) << "Quiz 3" <<
    left << setw(12) << "Average" << endl;
    
    fout << left << setw(14) << "----------"  << left << setw(12) << "------" <<
    left << setw(12) << "------" << left << setw(12) << "------" <<
    left << setw(12) << "-------" << endl;
}

// Function declaration for getdata, takes data from a file then places it within 4 arrays
int getdata(intArray Id, floatArray Q1, floatArray Q2, floatArray Q3, ifstream & fin) {
    
    int i = 0;
    
    while (fin >> Id[i]) {
        
        if (Id[i] == 0) {
            
            i = (i-1);
        }
        
        else {
            
            fin >> Q1[i]; fin >> Q2[i]; fin >> Q3[i++];
        }
    }
        
    return i;
}

// Function declaration for findStAvg, calculates the quiz average for each student, then places
// it within an array
void findStAvg(floatArray Q1, floatArray Q2, floatArray Q3, floatArray AvgGrd, int NumEle) {
    
    for (int i = 0; i <= NumEle; i++) {
        
        
        AvgGrd[i] = ((Q1[i] + Q2[i] + Q3[i]) / 3);
    }
}

// Function declaration for findhigh, finds highest quiz grade, then returns it
int findhigh(floatArray Q, int NumEle){
	int high = 0;
	for(int i = 0; i <= (NumEle); i++){
		if(high < Q[i])
			high=Q[i];
	}
	return high;
}

// Function declaration for findlow, finds lowest quiz grade, then returns it
int findlow(floatArray Q, int NumEle){
	int low = 0;
	for(int i = 0; i <= (NumEle); i++){
		if(low < Q[i])
			low=Q[i];
	}
	return low;
}

// Function declaration for findqzavg, calculates the avgerage of all quiz grades, then returns it
float findqzavg(floatArray Q, int NumEle){
    
	float avg = 0;
	for(int i = 0; i <= (NumEle); i++){
		avg += Q[i];
	}
	return (avg/NumEle);
}

// Function declaration for printAll, takes all information received an calculated, then outputs it to a file
void printAll(intArray idNum, floatArray quiz1, floatArray quiz2, floatArray quiz3,
              floatArray avgStGrade, int numOfElements, int & high1, int & high2, int & high3,
              int & low1, int & low2, int & low3, float & avg1, float & avg2, float & avg3) {
    
    high1 = findhigh(quiz1, numOfElements);
    high2 = findhigh(quiz2, numOfElements);
    high3 = findhigh(quiz3, numOfElements);
    low1 = findlow(quiz1, numOfElements);
    low2 = findlow(quiz2, numOfElements);
    low3 = findlow(quiz3, numOfElements);
    avg1 = findqzavg(quiz1, numOfElements);
    avg2 = findqzavg(quiz2, numOfElements);
    avg3 = findqzavg(quiz3, numOfElements);
    
    ofstream fout("StudentInformation.txt");
    
    heading(fout);
    
    fout << showpoint << fixed << setprecision(2);
    
    for (int i = 0; i <= (numOfElements); i++) {
        
        fout << left << setw(14) << idNum[i] << left << setw(12) << quiz1[i] << left << setw(12) <<
        quiz2[i] << left << setw(12) << quiz3[i] << left << setw(12)<< avgStGrade[i] << endl;
    }
    
    fout << endl << left << setw(14) << "High Score" << left << setw(12) << high1 << left << setw(12) <<
    high2 << left << setw(12) << high3 << endl << endl;
    
    fout << left << setw(14) << "Low Score" << left << setw(12) << low1 << left << setw(12) <<
    low2 << left << setw(12) << low3 << endl << endl;
    
    fout << left << setw(14) << "Average Score" << left << setw(12) << avg1 << left << setw(12) <<
    avg2 << left << setw(12) << avg3 << endl << endl;
    
    fout.close();
}
