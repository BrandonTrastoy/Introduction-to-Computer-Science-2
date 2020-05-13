/*  
    Name: Brandon Trastoy
    Class: CIS - 161
    Date: October 9, 2017
    Program: Structures
 
    Description: This program incorporates structures to get information from the user 
    				and then caculates an average and grade for said student. It accepts 
    				a name, id number, 3 test scores and then creates a print statement for
					the information given, average and letter grade.
 
 */

#include <string.h>
#include <iostream>
using namespace std;

struct fields {
    string name;
    int idNumber;
    unsigned short test1, test2, test3;
    float average;
    char grade;
};

//Function declaration for input, returns a structure
fields input();
//Function declaration for calculation, takes a structure as a parameter then passes it by reference
void calculation(fields &);
//Function declaration for letterGrade, takes in a float and returns a character
char letterGrade(float);
//Function declaration for print, does not return any values
void print(const fields);

int main() {
    
    fields student = input();
    calculation(student);
    student.grade = letterGrade(student.average);
    print(student);
    
    return 0;
}

//Function declaration for input, creates a instance of the stucture, accepts inputs, 
// then return the structure.
fields input() {
    
    fields student;
    
    cout << "Enter Your Name: "; getline(cin, student.name);
    cout << "Enter Your ID Number: "; cin >> student.idNumber;
    cout << "Enter the grade for test 1: "; cin >> student.test1;
    cout << "Enter the grade for test 2: "; cin >> student.test2;
    cout << "Enter the grade for test 3: "; cin >> student.test3;
    
    return student;
}

//Function definition for calculation, takes 3 test scores and averages them.
void calculation(fields & student) {
    
    student.average = (student.test1 + student.test2 + student.test3)/3.0;
}

//Function definition for letter grade, uses if statements to set letter grade 
// and then return it
char letterGrade(float average) {
    
    char grade;
    
    if (average >= 90) {
        grade = 'A';
    }
    
    else if (average >= 80) {
        grade = 'B';
    }
    
    else if (average >= 70) {
        grade = 'C';
    }

    else if (average >= 60) {
        grade = 'D';
    }
    
    else {
        grade = 'F';
    }

    return grade;
}

//Function definition for print, prints all the values inputed, and caluculated.
// Also, has an additional if statement to tell the user if they passed or not.
void print(const fields student) {
    cout << endl << endl;
    
    cout << "Student Name: " << student.name << endl;
    cout << "ID Number:    " << student.idNumber << endl;
    
    cout << endl;
    
    cout << "Tests:" << endl << endl;
    
    cout << "\t1-\t" << student.test1 << endl;
    cout << "\t2-\t" << student.test2 << endl;
    cout << "\t3-\t" << student.test3 << endl;
    
    cout << endl;
    
    cout << "Average: " << student.average << endl;
    cout << "Grade:   " << student.grade << " ";
    
    if (student.grade == 'F' || student.grade == 'D') {
        cout << "You Failed!" << endl;
    }
    
    else {
        cout << "You Passed!" << endl;
    }
}





