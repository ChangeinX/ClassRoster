#ifndef roster_h
#define roster_h
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "roster.h"
#include "student.h"

using namespace std;

class Roster {
public: 
	Roster(const string studentData[], int sizeofStudentData, int maxSize);

	/*Requirement E3*/
	void add(string studentID, string firstName, string lastName, string emailAddress, int age,
		int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	void dataParse(string data);
	/*Requirement F5*/
	
	~Roster();


private:
	int maxSize;
	int studentCount;
	Student* *classRosterArray;
	
};


#endif /*protect header file*/