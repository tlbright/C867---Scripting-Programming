#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>

#include "student.h"
#include "roster.h"
#include "degree.h"

using namespace std;

Roster::Roster() {
	this->rosterSize = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}


Roster::Roster(int rosterSize) {
	this->rosterSize = rosterSize;
	this->lastIndex = -1;
	this->*classRosterArray = new Student * [rosterSize];
}

Roster::~Roster() {

	for (int i = 0; i <= lastIndex; ++i) {
		delete[] this->classRosterArray[i];
	}

	delete[] *classRosterArray;
}

//Student* Roster::GetStudent(int index) {
//	return classRosterArray[index];
//}

void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {

	if (lastIndex < rosterSize) {
		++lastIndex;
		
			int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

			classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);

	}

	return;
}

void Roster::ParseAdd(string data) {

	int rhs = 0;
	int lhs = 0;

	//ID
	rhs = data.find(",");
	string userStudentID = data.substr(0, rhs);
	

	//first name
	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	string userFirstName = data.substr(lhs, rhs - lhs);

	//last name
	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	string userLastName = data.substr(lhs, rhs - lhs);

	//email
	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	string userEmail = data.substr(lhs, rhs - lhs);

	//age
	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	int userAge = stoi(data.substr(lhs, rhs - lhs));

	//day1
	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	int daysInCourse1 = stoi(data.substr(lhs, rhs - lhs));

	//day2
	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	int daysInCourse2 = stoi(data.substr(lhs, rhs - lhs));

	//day3
	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	int daysInCourse3 = stoi(data.substr(lhs, rhs - lhs));

	//degree
	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	string userDegree = data.substr(lhs, rhs - lhs);

	Add(userStudentID, userFirstName, userLastName, userEmail, userAge, daysInCourse1, daysInCourse2, daysInCourse3, userDegree);

	return;
} 

void Roster::Remove(string studentID) {

	bool student = false;

	for (int i = 0; i <= lastIndex; ++i) {
		
		if (this->classRosterArray[i]->GetStudentID() == studentID) {
			
			student = true;
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			--lastIndex;
		}
	}

	if (student == true) {
		cout << "Removed student: " << studentID << endl;
	}

	else {
		cout << "Student " << studentID << " not found." << endl;
	}

	return;
}


void Roster::PrintAll() {

	for (int i = 0; i <= this->lastIndex; ++i) {
		
		this->classRosterArray[i]->Print();
	}

	return;
}
// A1[tab] First Name : John[tab] Last Name : Smith[tab] Age : 20[tab]daysInCourse : {35, 40, 55} Degree Program :


void Roster::PrintAverageDaysInCourse(string studentID) {

	bool student = false;

	for (int i = 0; i <= lastIndex; ++i) {
		
		if (this->classRosterArray[i]->GetStudentID() == studentID) {
			
			student = true;
			int* dayAverage = classRosterArray[i]->GetDaysInCourse();
			cout << "Student: " << studentID << " Average course days: " << ((dayAverage[0] + dayAverage[1] + dayAverage[2]) / 3) << endl;
			
		}
	}
	if (student == false) {

		cout << "Student not found." << endl;
	}

	return;
}

void Roster::PrintInvalidEmails() {

	bool validAt = false;
	bool validPrd = false;
	bool invalidSpc = false;


	for (int i = 0; i <= lastIndex; ++i) {
		
		string email = (this->classRosterArray[i]->GetEmailAddress());

		//	for (int j = 0; j < strlen(email); ++j) {
				
				if (email.find("@") != string::npos) {
					validAt = true;
				}
				if (email.find(".") != string::npos) {
					validPrd = true;
				}
				if (email.find(" ") != string::npos) {
					invalidSpc = true;
				}
		//	}
		if (invalidSpc == true) {
			cout << "Invalid email: " << email << endl;
		}
		if (validAt == false || validPrd == false) {
			cout << "Invalid email: " << email << endl;
		}

	}

	return;
}

void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram) {

	for (int i = 0; i <= lastIndex; ++i) {
		
		if (this->classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
			
			this->classRosterArray[i]->Print();
		}

	}

	return;
}



//	if (degreeProgram == "SECURITY") {




//	}

//	if (degreeProgram == "NETWORKING") {
//		int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

//		classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
//	}

//	if (degreeProgram == "SOFTWARE") {
//		int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

//		classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
//	}

//Student* Roster::GetStudent(int i) {

	//return classRosterArray[i];

//}