
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>

#include "roster.h"
#include "student.h"
#include "degree.h"

using namespace std;


int main() {

	int rosterSize = 5;

	const string studentData[5] = {
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Andrew,Bright,abrig64@wgu.edu,25,12,70,91,SOFTWARE" };

		cout << "Scripting and Programming - Applications - C867" << endl;
		cout << "Programming language: C++" << endl;
		cout << "Student ID: #001316519" << endl;
		cout << "Andrew Bright" << endl << endl << endl << endl;

		Roster *classRoster = new Roster(rosterSize);

		cout << "Building Student Data Table...";

		for (int i = 0; i < rosterSize; ++i) {
			classRoster->ParseAdd(studentData[i]);
		}

		cout << "done." << endl;

		cout << "Printing Student Data Table" << endl << endl;

	    classRoster->PrintAll();

		cout << "Scanning for invalid emails...";

	    classRoster->PrintInvalidEmails();

		cout << endl << endl;


	//loop through classRosterArray and for each element:

		cout << "Printing average days in course..." << endl << endl;
		for (int i = 0; i < rosterSize; ++i) {

			Student student;
			classRoster->PrintAverageDaysInCourse(student.GetStudentID());

		}
		cout << endl << endl;


		cout << "Printing out students with a specific degree program..." << endl << endl;

	    classRoster->PrintByDegreeProgram(SOFTWARE);

		cout << "Removing student with ID: A3..." << endl << endl;

	    classRoster->Remove("A3");

		cout << endl << endl;

		cout << "Printing Student Data Table" << endl << endl;

	    classRoster->PrintAll();

		cout << "Removing student with ID: A3..." << endl << endl;

	    classRoster->Remove("A3");
		//expected: the above line should print a message saying such a student with this ID was not found.

		cout << "Clearing Roster from memory..." << endl << endl;
	  
		classRoster->~Roster();
		
  return 0;
}