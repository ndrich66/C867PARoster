#include <iostream>
#include <iomanip>
#include "student.h"

Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < daysInCourseArraySize; i++)
		this->daysInCourse[i] = 0;
	this->degreeProgram = DegreeProgram::SOFTWARE;
}

/*constructor*/
Student::Student(string studentID,
	string firstName,
	string lastName,
	string emailAddress,
	int age,
	int daysInCourse[],
	DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysInCourseArraySize; i++)
		this->daysInCourse[i] = daysInCourse[i];
	this->degreeProgram = degreeProgram;
}


Student::~Student() {}/*destructor does nothing*/


/*getters*/
string Student::getID() {
	return this->studentID;
}

string Student::getFirstName() {
	return this->firstName;
}

string Student::getLastName() {
	return this->lastName;
}

string Student::getEmailAddress() {
	return this->emailAddress;
}

int Student::getAge() {
	return this->age;
}

int* Student::getDaysInCourse() {
	return this->daysInCourse;
}

DegreeProgram Student::getDegreeProgram() {
	return this->degreeProgram;
}


/*setters*/
void Student::setID(string ID) {
	this->studentID = ID;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setDaysInCourse(int daysInCourse[]) {
	for (int i = 0; i < daysInCourseArraySize; i++)
		this->daysInCourse[i] = daysInCourse[i];
}

void Student::setDegreeProgram(DegreeProgram dp) {
	this->degreeProgram = dp;
}


void Student::printHeader() {
	cout << "Output format: ID|FirstName|LastName|EmailAddress|Age|DaysInCourse|Type\n";
}//this prints for each section 


/*print...*/
void Student::print() {
	cout << this->getID() << '\t'; /*tab seperate print */
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmailAddress() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getDaysInCourse()[0] << ',';
	cout << this->getDaysInCourse()[1] << ',';
	cout << this->getDaysInCourse()[2] << '\t';
	cout << degreeProgramStrings[this->getDegreeProgram()] << '\n';
}
