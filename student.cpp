#pragma once
#include "student.h"
class Roster
{
public:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];

public:
	void parse(string row);
	void add(string sID, /*studentID*/
		string sFirstName,
		string sLastName,
		string sEmailAddress,
		int sage,
		int sdaysincourse1,
		int sdaysincourse2,
		int sdaysincourse3,
		DegreeProgram dp);
	void printAll();
	void printByDegreeProgram(DegreeProgram dp);
	void printInvalidEmailAddress();
	void printAverageDaysInCourse(string);
	void removeStudentByID(string studentID);
	~Roster();
};