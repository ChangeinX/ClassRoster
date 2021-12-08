#include "degree.h"
#include "student.h"

/*D2.  Create each of the following functions in the Student class:

a.  an accessor (i.e., getter) for each instance variable from part D1

b.  a mutator (i.e., setter) for each instance variable from part D1

c.  All external access and changes to any instance variables of the Student class must be done using accessor and mutator functions.

d.  constructor using all of the input parameters provided in the table

e.  print() to print specific student data*/

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToComplete[],
	DegreeProgram degreeProgram) {
	/*Pointer to current object
	Question: necessity of pointer if access to data members are ineligble then they are referenced to current object?*/
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->age = age;
	this->emailAddress = emailAddress;
	this->daysToComplete = new int[ARRAY_SIZE];

	for (int i = 0; i < ARRAY_SIZE; ++i) {
		this->daysToComplete[i] = daysToComplete[i];
	}
	this->degreeProgram = degreeProgram;
}

/*Destructor*/
Student::~Student() {
	delete[] daysToComplete;
}

/*Accessors*/

string Student::GetstudentID() {
	return studentID;
}

string Student::GetfirstName() {
	return firstName;
}

string Student::GetlastName() {
	return lastName;
}

int Student::Getage() {
	return age;
}

string Student::GetemailAddress() {
	return emailAddress;
}

int *Student::GetdaysToComplete() {
	return daysToComplete;
}

DegreeProgram Student::GetDegreeProgram() {
	return degreeProgram;
}

/*Mutators*/

void Student::SetstudentID(string studentID) {
	this->studentID = studentID;
	return;
}

void Student::SetfirstName(string firstName) {
	this->firstName = firstName;
	return;
}

void Student::SetlastName(string lastName) {
	this->lastName = lastName;
	return;
}

void Student::Setage(int age) {
	this->age = age;
	return;
}

void Student::SetemailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
	return;
}

void Student::SetdaysToComplete(int daysToComplete[]) {
	for (int i = 0; i < ARRAY_SIZE; ++i) {
		this->daysToComplete[i] = daysToComplete[i];
	}
}

void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
	return;
}

void Student::print() {
	cout << studentID << '\t' << "First name: " << firstName << '\t' << "Last Name: " << lastName << '\t';
	cout << "Email Address: " << emailAddress << '\t' << "Age: " << age << '\t' << "Days in course: "; 

	for (int i = 0; i < ARRAY_SIZE; ++i) {
		cout << daysToComplete[i];
	}
	cout << '\t';

	cout << "Degree Program: ";

	switch (degreeProgram) {
	case SOFTWARE:
		cout << "SOFTWARE";
		break;
		
	case NETWORK: 
		cout << "NETWORK";
		break;
	case SECURITY: 
		cout << "SECURITY";
			break;
	case InputError: 
		cout << "Input Error";
		break;


	}
	cout << endl; 
	return; 
}




