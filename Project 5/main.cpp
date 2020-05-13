/*
 Name: Brandon Trastoy and Timothy Schutte
 Class: CIS - 161
 Date: November 20, 2017
 Program Name: Project 5
 Description:
 
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int SIZE = 20;

typedef  struct info {
    
    int id;
    float test1, test2, test3, average;
    
} studentInfo[SIZE];

void heading();
void getdata(info *, ifstream &);
void highScores(const info *);

template <class T>
void Swap(T &, T &);
void bubble(studentInfo);


int main() {
    
    studentInfo students;
    
    // Reading information from the file
    ifstream fin("pr2data.txt");
    
    
    if (fin) {
        
        getdata(students, fin);
        fin.close();
        
        bubble(students);
        
        highScores(students);
        
    }
    
    else {
        
        cout << "File does not exist or is not open " << endl;
    }
    
    return 0;
}


void getdata(info * st, ifstream & fin) {
    
    for (int i = 0; i < SIZE; i++, st++) {
        
        fin >> st->id;
        fin >> st->test1;
        fin >> st->test2;
        fin >> st->test3;
        
        st->average = (st->test1 + st->test2 + st->test3) / 3.0;
    }
}

void highScores(const info * st) {
    
    ofstream fout("highScores.txt");
    fout << fixed << showpoint << setprecision(2);
    
    for (int i = 0; i < SIZE; i++, st++) {
        
        if (st->average >= 85) {
            
            fout << "Student ID: " << st->id << " Student Avg: " << st->average << endl;
        }
    }
    fout.close();
}

template<class T>

void Swap(T & x, T & y) {
    
    T temp = x;
    x = y;
    y = temp;
    
}

void bubble(studentInfo s) {
    
    for (int j = 1; j < SIZE - 1; j++) {
        
        for (int i = 0; i < SIZE - j; i++) {
            
            if (s[i].average > s[i+1].average) {
                
                Swap(s[i].id, s[i+1].id);
                Swap(s[i].test1, s[i+1].test1);
                Swap(s[i].test2, s[i+1].test2);
                Swap(s[i].test3, s[i+1].test3);
                Swap(s[i].average, s[i+1].average);
            }
        }
    }
}

void heading() {

    cout << endl << endl << "\t\tCIS Department - Fall 2017" << endl <<
    "\t\t CIS 161 Class Statistics" << endl << endl;

    cout << left << setw(14) << "Student ID"  << left << setw(12) << "Quiz 1" <<
    left << setw(12) << "Quiz 2" << left << setw(12) << "Quiz 3" <<
    left << setw(12) << "Average" << endl;

    cout << left << setw(14) << "----------"  << left << setw(12) << "------" <<
    left << setw(12) << "------" << left << setw(12) << "------" <<
    left << setw(12) << "-------" << endl;
}

