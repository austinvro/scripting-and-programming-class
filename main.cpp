#include <iostream>
#include <string> // This includes the string type
#include "roster.h"

using std::cout;
using std::endl;
using std::string;

int main()
{
    // Print course title, language used, WGU student ID, and name
    cout << "Course Title: Scripting and Programming Applications C867" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "WGU Student ID: 010594856" << endl;
    cout << "Name: Austin Patton" << endl
         << endl;

    // Student data provided as a list
    const string studentData[] = {
        "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99@yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Austin,Patton,apat465@wgu.edu,24,20,25,30,SOFTWARE"};

    // Create an instance of the Roster class
    Roster classRoster;

    // Loop to add each student to the class roster
    for (int i = 0; i < 5; i++)
    {
        // Parse each string
        string data = studentData[i];
        size_t rhs = data.find(","); // Position of the first comma

        // Get individual
        string studentID = data.substr(0, rhs); // Extract studentID
        data = data.substr(rhs + 1);            // Move past the comma

        rhs = data.find(",");
        string firstName = data.substr(0, rhs);
        data = data.substr(rhs + 1);

        rhs = data.find(",");
        string lastName = data.substr(0, rhs);
        data = data.substr(rhs + 1);

        rhs = data.find(",");
        string email = data.substr(0, rhs);
        data = data.substr(rhs + 1);

        rhs = data.find(",");
        int age = stoi(data.substr(0, rhs));
        data = data.substr(rhs + 1);

        rhs = data.find(",");
        int daysInCourse1 = stoi(data.substr(0, rhs));
        data = data.substr(rhs + 1);

        rhs = data.find(",");
        int daysInCourse2 = stoi(data.substr(0, rhs));
        data = data.substr(rhs + 1);

        rhs = data.find(",");
        int daysInCourse3 = stoi(data.substr(0, rhs));
        data = data.substr(rhs + 1);

        DegreeProgram degreeProgram;
        if (data == "SECURITY")
            degreeProgram = SECURITY;
        else if (data == "NETWORK")
            degreeProgram = NETWORK;
        else
            degreeProgram = SOFTWARE;

        // Add a student to the roster
        classRoster.add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    }

    // function calls
    cout << "Displaying all students:" << endl;
    classRoster.printAll();
    cout << endl;

    cout << "Displaying invalid emails:" << endl;
    classRoster.printInvalidEmails();
    cout << endl;

    // Loop through roster and display average days in course for each student
    for (int i = 0; i < 5; i++)
    {
        string studentID = "A" + std::to_string(i + 1);
        classRoster.printAverageDaysInCourse(studentID);
    }
    cout << endl;

    // Display students by degree program
    cout << "Displaying students in the SOFTWARE program:" << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;

    // Remove student A3
    classRoster.remove("A3");
    cout << "Displaying all students after removing A3:" << endl;
    classRoster.printAll();
    cout << endl;

    // Try removing A3 again
    classRoster.remove("A3");

    return 0;
}
