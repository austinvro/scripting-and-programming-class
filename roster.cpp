#include <iostream>
#include "roster.h"

using std::cout;
using std::endl;
using std::string;

// add mutator
void Roster::add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
    // array for number of days
    int daysInCourse[3] = {daysInCourse1, daysInCourse2, daysInCourse3};

    // increment and add index
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, email, age, daysInCourse, degreeProgram);
}

// Removing a student from the classRosterArray by studentID
void Roster::remove(string studentID)
{
    bool found = false; // Variable to track if the student is found

    // Loop through the array to find the student with the given ID
    for (int i = 0; i <= lastIndex; i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            delete classRosterArray[i];                        // Free memory of the student being removed
            classRosterArray[i] = classRosterArray[lastIndex]; // Move the last student into the removed spot
            lastIndex--;                                       // Decrease lastIndex as the array is now smaller
            found = true;
            cout << "Student with ID " << studentID << " was removed." << endl;
            break; // Exit loop after finding and removing the student
        }
    }

    // If the student wasn't found, print a message
    if (!found)
    {
        cout << "Student with ID " << studentID << " not found." << endl;
    }
}

// Printing all students in the classRosterArray
void Roster::printAll()
{
    // Loop through all the students and print their info
    for (int i = 0; i <= lastIndex; i++)
    {
        classRosterArray[i]->print(); // Calls the print function for each student
    }
}

// Printing the average number of days in course for a specific student
void Roster::printAverageDaysInCourse(string studentID)
{
    // Find the student by their ID
    for (int i = 0; i <= lastIndex; i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            // Get the array of days for that student
            const int *days = classRosterArray[i]->getDaysInCourse(); // Use const int* here

            // Calculate the average and print it
            cout << "Average days in course for student " << studentID << ": "
                 << (days[0] + days[1] + days[2]) / 3 << endl;
            return; // Exit the function after printing
        }
    }

    // If the student wasn't found, print a message
    cout << "Student with ID " << studentID << " not found." << endl;
}

// Printing invalid emails (emails that are missing '@', '.', or have spaces)
void Roster::printInvalidEmails()
{
    // Loop through all the students
    for (int i = 0; i <= lastIndex; i++)
    {
        string email = classRosterArray[i]->getEmail();

        // Check if the email is invalid
        if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos)
        {
            cout << "Invalid email: " << email << endl; // Print the invalid email
        }
    }
}

// Printing students by degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    // Loop through all the students and check if their degree program matches
    for (int i = 0; i <= lastIndex; i++)
    {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram)
        {
            classRosterArray[i]->print(); // Print the student if their degree program matches
        }
    }
}

// Destructor to free memory when the roster is no longer needed
Roster::~Roster()
{
    // Loop through the array and delete each student to free memory
    for (int i = 0; i <= lastIndex; i++)
    {
        delete classRosterArray[i];
    }
}
