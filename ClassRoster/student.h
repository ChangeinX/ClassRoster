#include <iostream>
#ifndef student_h 
#define student_h
#include <string>
/*D1 last item variable for degree program*/
#include "degree.h"

using namespace std;

/*Define array size as preprocessor directive*/
#define ARRAY_SIZE 3
/*Requirement D1 Defining student class in student.h */
class Student {

private: 
	string studentID;
	string firstName;
	string lastName; 
	string emailAddress;
	int age;
	int *daysToComplete; 
	DegreeProgram degreeProgram; 

public: 
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToComplete[], DegreeProgram degreeProgram);
	~Student();

	/*Accessor D2 a. */
	string GetstudentID();
	string GetfirstName();
	string GetlastName();
	string GetemailAddress();
	int Getage();
	int *GetdaysToComplete();
	DegreeProgram GetDegreeProgram();

	/*Mutator D2 b. */
	void SetstudentID(string studentID);
	void SetfirstName(string firstName);
	void SetlastName(string lastName);
	void SetemailAddress(string emailAddress);
	void Setage(int age);
	void SetdaysToComplete(int daysToComplete[]);
	void SetDegreeProgram(DegreeProgram degreeProgram);
	
	/*Print data*/
	void print();
};

#endif /*protect header file*/