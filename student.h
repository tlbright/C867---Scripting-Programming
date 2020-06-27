#ifndef STUDENT_H
#define STUDENT_H
 
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include "degree.h"
#include "roster.h"

using namespace std;

class Student {
public:
	const int daysArraySize = 3;
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysinCourse[], DegreeProgram degreeProgram);
	~Student();
	void SetStudentID(string userStudentID);
	void SetFirstName(string userFirstName);
	void SetLastName(string userLastName);
	void SetEmailAddress(string userEmail);
	void SetAge(int userAge);
	void SetDaysInCourse(int daysInCourse[]);
	void SetDegreeProgram(DegreeProgram degreeProgram);
	void Print();
	string GetStudentID();
	string GetFirstName();
	string GetLastName();
	string GetEmailAddress();
	int GetAge();
	int* GetDaysInCourse();
	string GetDegreeProgram();

private:
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int* daysInCourse;
	string degreeProgram;
};

#endif // !STUDENT_H