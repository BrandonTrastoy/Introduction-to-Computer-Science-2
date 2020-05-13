/*
    Name: Brandon Trastoy and Timothy Schutte
	Class: CIS - 161
	Date: November 1, 2017
	Program Name: Project 4
	Description:
 
 
 
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

// Arrays ---------------------
typedef vector<int> intVec;
typedef vector<float> floatVec;


void heading(ostream &);


void getdata(intVec &, floatVec &, floatVec &, floatVec &, ifstream &);
void findStAvg(floatVec, floatVec, floatVec, floatVec &);


int findhigh(floatVec);


int findlow(floatVec);


float findqzavg(floatVec);


void printAll(intVec, floatVec, floatVec, floatVec, floatVec, int &,
              int &, int &, int &, int &, int &, float &, float &, float &);


int main() {
    
    // Arrays ---------------------
    intVec idNum;
    floatVec quiz1, quiz2, quiz3, avgStGrade;
    
    
    // Variables ------------------
    int high1, high2, high3, low1, low2, low3;
    float avg1, avg2, avg3;
    
    // Reading information from the file
    ifstream fin("pr2data.txt");
    
    
    if (fin) {
        
        getdata(idNum, quiz1, quiz2, quiz3, fin);
        fin.close();
        
        findStAvg(quiz1, quiz2, quiz3, avgStGrade);
        
        for (int i = 0; i < idNum.size(); i++) {
            
            cout << left << setw(14) << idNum[i] << left << setw(12) << quiz1[i] << left << setw(12) <<
            quiz2[i] << left << setw(12) << quiz3[i] << left << setw(12) << avgStGrade[i] << endl;
        }
        
        
        
        // Func call for printAll, outputs to a file
        printAll(idNum, quiz1, quiz2, quiz3, avgStGrade, high1,
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
void getdata(intVec & Id, floatVec & Q1, floatVec & Q2, floatVec & Q3, ifstream & fin) {
    
    int i = 0;
    float j = 0.0;
    
    fin >> i;
    
    while (i != 0) {
        
        Id.push_back(i);
        
        fin >> j; Q1.push_back(j);
        fin >> j; Q2.push_back(j);
        fin >> j; Q3.push_back(j);
        
        fin >> i;
        
    }
}


// Function declaration for findStAvg, calculates the quiz average for each student, then places
// it within an array
void findStAvg(floatVec Q1, floatVec Q2, floatVec Q3, floatVec & AvgGrd) {
    
    cout << fixed << showpoint << setprecision(2) << endl;
    
    int j = 0.0;
    
    for (int i = 0; i < Q1.size(); i++) {
        
        j = ((Q1[i] + Q2[i] + Q3[i])/3.0);
        AvgGrd.push_back(j);
        
    }
}

// Function declaration for findhigh, finds highest quiz grade, then returns it
int findhigh(floatVec Q){
    int high = Q[0];
    for(int i = 0; i < Q.size(); i++){
        if(high < Q[i])
            high=Q[i];
    }
    return high;
}

// Function declaration for findlow, finds lowest quiz grade, then returns it
int findlow(floatVec Q){
    int low = Q[0];
    for(int i = 0; i < Q.size(); i++){
        if(low > Q[i])
            low=Q[i];
    }
    return low;
}

// Function declaration for findqzavg, calculates the avgerage of all quiz grades, then returns it
float findqzavg(floatVec Q){
    
    float avg = 0;
    for(int i = 0; i < Q.size(); i++){
        avg += Q[i];
    }
    return (avg/Q.size());
}

// Function declaration for printAll, takes all information received an calculated, then outputs it to a file
void printAll(intVec idNum, floatVec quiz1, floatVec quiz2, floatVec quiz3, floatVec avgStGrade,
              int & high1, int & high2, int & high3, int & low1, int & low2, int & low3,
              float & avg1, float & avg2, float & avg3) {

    high1 = findhigh(quiz1);
    high2 = findhigh(quiz2);
    high3 = findhigh(quiz3);
    low1 = findlow(quiz1);
    low2 = findlow(quiz2);
    low3 = findlow(quiz3);
    avg1 = findqzavg(quiz1);
    avg2 = findqzavg(quiz2);
    avg3 = findqzavg(quiz3);

    ofstream fout("StudentInformation.txt");

    heading(fout);

    fout << showpoint << fixed << setprecision(2);

    for (int i = 0; i < idNum.size(); i++) {

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
                     
