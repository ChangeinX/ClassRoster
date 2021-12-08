#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "roster.h"
#include "degree.h"
#include "student.h"

using namespace std;

Roster::Roster(const string studentData[], int sizeofStudentData, int maxSize) {
	/*E1 Create an array of pointers*/
	this->studentCount = sizeofStudentData;
	this->classRosterArray = new Student *[maxSize];
	this->maxSize = maxSize;

	/*E2a parse each set of data identified in the "studentData Table" */
	int studentRecord = 0;
	while (studentRecord < sizeofStudentData) {
		vector <string> identity; 
		stringstream streamInput(studentData[studentRecord]);
		string nextIdentity;

		while (getline(streamInput, nextIdentity, ',')) {
			identity.push_back(nextIdentity); 
		}

		int daysToComplete[3] = { std::stoi(identity[5]), std::stoi(identity[6]), std::stoi(identity[7]) };
		int age = std::stoi(identity[4]);

		DegreeProgram degreeProgram = InputError; 
		if (identity[8].compare("SOFTWARE") == 0) {
			degreeProgram = SOFTWARE; 
		}
		else if (identity[8].compare("NETWORK") == 0) {
			degreeProgram = NETWORK; 
		}
		else if (identity[8].compare("SECURITY") == 0) {
			degreeProgram = SECURITY; 
		}
		else {
			degreeProgram = InputError; 
		}

		classRosterArray[studentRecord] = new Student(identity[0], identity[1], identity[2], identity[3], age, daysToComplete, degreeProgram);
		++studentRecord;
	}
}

/*F5 Destructor to release memory*/
Roster::~Roster() {
	delete[] classRosterArray;
}

/*Utilizes from roster.h and placed in roster.cpp as per E3 definition of functions*/

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age,
	int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int daysToComplete[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[studentCount] = new Student(studentID, firstName, lastName, emailAddress, age, daysToComplete, degreeProgram);
	++studentCount;

}

void Roster::remove(string studentID) {
	bool studentIDFound = false;
	for (int i = 0; (i < studentCount) && !studentIDFound; ++i) {
		if (classRosterArray[i]->GetstudentID() == studentID) {
			classRosterArray[i] = classRosterArray[studentCount - 1];
			--studentCount;
			studentIDFound = true;
		}
	}
	if (studentIDFound) {
		cout << "Student Record " << studentID << " removed" << endl;
	}
	else {
		cout << "No such record found" << endl;
	}
}

void Roster::printAll() {
	for (int i = 0; i < studentCount; ++i) {
		classRosterArray[i]->print();
	}
}

void Roster::printAverageDaysInCourse(string studentID) {

	for(int i = 0; i < studentCount; ++i) {
		if (classRosterArray[i]->GetstudentID() == studentID) {
			cout << "Student ID " << classRosterArray[i]->GetstudentID() << ": ";
			int *numDays = classRosterArray[i]->GetdaysToComplete();
			cout << "Has an average number of days in courses: " << (numDays[0] + numDays[1] + numDays[2]) / 3 << endl;
			return;
		}
	}
}

void Roster::printInvalidEmails() {
	for (int i = 0; i < studentCount; ++i) {
		string emailAddress = classRosterArray[i]->GetemailAddress();
		int atSymbolSearch = emailAddress.find('@');
		int periodSearch = emailAddress.find('.', atSymbolSearch);

		if (atSymbolSearch == string::npos) {
			cout << "Emails is missing @ symbol: " << emailAddress << endl;
		}
		else if (periodSearch == string::npos){
			cout << "Email is missing a period: " << emailAddress << endl;
		}
		else if (emailAddress.find(' ') != string::npos) {
			cout << "Email contains an unneccessary space: " << emailAddress << endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i < studentCount; ++i) {
		if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
}