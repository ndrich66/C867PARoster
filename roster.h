#include <string>
#include <iostream>
#include "roster.h"
using std::cout;

void Roster::parse(string studentdata) {

	DegreeProgram d = SOFTWARE;

	if (studentdata.back() == 'Y') {
		d = SECURITY; //1
	}

	else if (studentdata.back() == 'K') {
		d = NETWORK; //2
	}

	// else SOFTWARE);


	int rhs = studentdata.find(",");//find ,
	string studentID = studentdata.substr(0, rhs);//the number of characters after 0, rhs is a number
	// s.setID(studentID);
	

	int lhs = rhs + 1; //move past the previous comma
	rhs = studentdata.find(",", lhs);
	string firstName = studentdata.substr(lhs, rhs - lhs);
	// s.setFirstName(firstName);

	lhs = rhs + 1; //keep going
	rhs = studentdata.find(",", lhs);
	string lastName = studentdata.substr(lhs, rhs - lhs);//last name
	//s.setLastName(lastName);

	lhs = rhs + 1;//keep going
	rhs = studentdata.find(",", lhs);
	string emailAddress = studentdata.substr(lhs, rhs - lhs);//email
	//s.setEmailAddress(emailAddress);

	lhs = rhs + 1;//keep going
	rhs = studentdata.find(",", lhs);
	int age = stoi(studentdata.substr(lhs, rhs - lhs));
	//s.setAge(age);

	lhs = rhs + 1;//keep going
	rhs = studentdata.find(",", lhs);
	int daysInCourse1 = stoi(studentdata.substr(lhs, rhs - lhs));//first dic
	//s.setDaysInCourse1(daysInCourse1);

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int daysInCourse2 = stoi(studentdata.substr(lhs, rhs - lhs));//second dic

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int daysInCourse3 = stoi(studentdata.substr(lhs, rhs - lhs));//third dic 

	//DegreeProgram dp = d.getDegreeProgram(); 
	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, d);
}


void Roster::add(string studentID,
	string firstName,
	string lastName,
	string emailAddress,
	int age,
	int daysInCourse1,
	int daysInCourse2,
	int daysInCourse3,
	DegreeProgram dp) {

	int parr[3] = {
		daysInCourse1, daysInCourse2, daysInCourse3
	};

	classRosterArray[++lastIndex] = new Student(studentID,
		firstName,
		lastName,
		emailAddress,
		age,
		parr,
		dp);
} //++ prefix is better here


void Roster::printAll() {
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) {
		cout << classRosterArray[i]->getID(); cout << '\t';
		cout << classRosterArray[i]->getFirstName(); cout << '\t';
		cout << classRosterArray[i]->getLastName(); cout << '\t';
		cout << classRosterArray[i]->getEmailAddress(); cout << '\t';
		cout << classRosterArray[i]->getAge(); cout << '\t';
		cout << classRosterArray[i]->getDaysInCourse()[0]; cout << '\t';
		cout << classRosterArray[i]->getDaysInCourse()[1]; cout << '\t';
		cout << classRosterArray[i]->getDaysInCourse()[2]; cout << '\t';
		cout << degreeProgramStrings[classRosterArray[i]->getDegreeProgram()] << std::endl;
	}
}

//display only students which match given degree program 

void Roster::printByDegreeProgram(DegreeProgram dp) {
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == dp)
			classRosterArray[i]->print();
	}
	cout << std::endl;
}

//new code for email address, successfully prints invalid email addresses
bool isValidEmailAddress(string emailAddress) {
	if (emailAddress.find("@") != string::npos && emailAddress.find(".") != string::npos && emailAddress.find(" ") == string::npos) {
		return true;
	}
	else {
		return false;
	}
}

void Roster::printInvalidEmailAddress() {
	for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); i++) {
		if (classRosterArray[i] != nullptr) {
			if (!isValidEmailAddress(classRosterArray[i]->getEmailAddress())) {
				cout << classRosterArray[i]->getID()
					<< " " << classRosterArray[i]->getEmailAddress()
					<< std::endl;
			}
		}
	}
	cout << std::endl;
};


void Roster::printAverageDaysInCourse(string studentID)
{ //why you printing out so much space buddy
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if(classRosterArray[i]->getID() == studentID) { 
			cout << studentID << ": ";
			cout << (classRosterArray[i]->getDaysInCourse()[0]
				+ classRosterArray[i]->getDaysInCourse()[1]
				+ classRosterArray[i]->getDaysInCourse()[2]) / 3.0 << std::endl;
		}
		//cout << std::endl;
	}//^commented out, testing, test successful. leave commented out 
}//this is printing out hella space

void Roster::removeStudentByID(string studentID) {  
	bool success = false; //assume it's not here
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getID() == studentID) {
			success = true; //found
			if (i < numStudents - 1) {
				Student* temp = classRosterArray[i]; //swap
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--; //last student no longer visible, not deleted.
		}
	}
	if (success)
	{
		cout << studentID << " removed from repository." << std::endl << std::endl;
		this->printAll();//display students, removed one should not display
	}
	else cout << studentID << " not found." << std::endl << std::endl;
}


Roster::~Roster() {
	cout << "Destructor called!" << std::endl << std::endl;
	for (int i = 0; i < numStudents; i++) {
		cout << "Destroying student #" << i + 1 << std::endl << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}