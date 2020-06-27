#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>

#include "student.h"
#include "degree.h"
#include "roster.h"

using namespace std;



Student::Student() {
	this->studentId = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	this->daysInCourse = 0;
	for (int i = 0; i < daysArraySize; ++i) {
		this->daysInCourse[i] = 0;
	}
	this->degreeProgram = SECURITY;

}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram) {
	this->studentId = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->daysInCourse = new int[daysArraySize];
	for (int i = 0; i < daysArraySize; ++i) {
		this->daysInCourse[i] = daysInCourse[i];
	}
	this->degreeProgram = degreeProgram;
}

void Student::Print() {

	cout << studentId << "\t" << "First Name: " << firstName;
	cout << "\t" << "Last Name: " << lastName;
	cout << "\t" << "Age: " << age;
	cout << "\t" << "daysInCourse: {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "}";
	cout << "\t" << "Degree Program: " << this->GetDegreeProgram();

	return;
}
// A1[tab] First Name : John[tab] Last Name : Smith[tab] Age : 20[tab]daysInCourse : {35, 40, 55} Degree Program :


Student::~Student() {

	if (daysInCourse != nullptr) {
		delete[] daysInCourse;
		daysInCourse = nullptr;
	}

}

void Student::SetStudentID(string userStudentID) {
	studentId = userStudentID;

	return;
}

void Student::SetFirstName(string userFirstName) {
   firstName = userFirstName;

  return;
}

void Student::SetLastName(string userLastName) {
	lastName = userLastName;

	return;
}

void Student::SetEmailAddress(string userEmail) {
	emailAddress = userEmail;

	return;
}

void Student::SetAge(int userAge) {
	age = userAge;
	
	return;
}

void Student::SetDaysInCourse(int daysInCourse[]) {
	for (int i = 0; i < daysArraySize; ++i) {
		this->daysInCourse[i] = daysInCourse[i];
	}
	return;
}

void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;

	return;
}

string Student::GetStudentID() {
	return studentId;
}

string Student::GetFirstName() {
	return firstName;
}

string Student::GetLastName() {
	return lastName;
}

string Student::GetEmailAddress() {
	return emailAddress;
}

int Student::GetAge() {
	return age;
}

int* Student::GetDaysInCourse() {
	return daysInCourse;
}


string Student::GetDegreeProgram() {
	return degreeProgram;
}


/*
void Student::SetDaysInCourse2(int userCourse2) {
	daysInCourse2 = userCourse2;

	return;
}

void Student::SetDaysInCourse3(int userCourse3) {
	daysInCourse3 = userCourse3;

	return;
}

*/