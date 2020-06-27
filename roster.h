#ifndef ROSTER_H
#define ROSTER_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include "student.h"
#include "degree.h"

using namespace std;

// class Student;

class Roster {

public:
	Roster();
	Roster(int rosterSize);
	~Roster();
	//Student* GetStudent(int i);
	void Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void ParseAdd(string data);
	void Remove(string studentID);
	void PrintAll();
	void PrintAverageDaysInCourse(string studentID);
	void PrintInvalidEmails();
	void PrintByDegreeProgram(DegreeProgram degreeProgram);
	int lastIndex;
	int rosterSize;
	Student** classRosterArray;
};

#endif // !ROSTER_H