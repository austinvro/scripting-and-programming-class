#include <iostream>
#include "student.h"

using std::cout;
using std::endl;
using std::string;

// Constructor
Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[], DegreeProgram degreeProgram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    for (int i = 0; i < 3; i++)
        this->daysInCourse[i] = daysInCourse[i];
    this->degreeProgram = degreeProgram;
}

// Getters
string Student::getStudentID() const { return this->studentID; }
string Student::getFirstName() const { return this->firstName; }
string Student::getLastName() const { return this->lastName; }
string Student::getEmail() const { return this->email; }
int Student::getAge() const { return this->age; }
const int *Student::getDaysInCourse() const { return this->daysInCourse; }
DegreeProgram Student::getDegreeProgram() const { return this->degreeProgram; }

// Setters
void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysInCourse(int daysInCourse[])
{
    for (int i = 0; i < 3; i++)
        this->daysInCourse[i] = daysInCourse[i];
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

// Print function
void Student::print() const
{
    cout << "Student ID: " << this->getStudentID() << "\t";
    cout << "First Name: " << this->getFirstName() << "\t";
    cout << "Last Name: " << this->getLastName() << "\t";
    cout << "Email: " << this->getEmail() << "\t";
    cout << "Age: " << this->getAge() << "\t";
    cout << "Days in Course: {" << this->daysInCourse[0] << ", " << this->daysInCourse[1] << ", " << this->daysInCourse[2] << "}\t";
    cout << "Degree Program: " << degreeProgramStrings[this->getDegreeProgram()] << endl;
}
