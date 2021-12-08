#include <iostream>
#include "student.h"
#include "roster.h"
#include <Windows.h>
#include <tchar.h>
using namespace std; 

int main() {

	/*F1 Message box not covered in course, but thought would add a nice flavor*/
	MessageBox(0,_T("C867: Scripting and Programming \nLanguage Used: C++ \nStudent ID: 001045278 \nNathaniel Mitchell"),_T("Class Roster"), MB_OK);
	const string studentData[] =

	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Nathaniel,Mitchell,nmitc45@wgu.edu,26,11,10,7,SOFTWARE"
	};

	/*F2 Create an instance of the Roster class called classRoster*/
	Roster* classRoster = new Roster(studentData, 5, 50); 

	/*F4 Complete the pseudo code*/
	/*printAll()*/
	cout << "Entire roster is printing: " << endl;
	classRoster->printAll();

	/*printInvalidEmails() prints invalid emails*/
	cout << "These emails are invalid: " << endl;
	classRoster->printInvalidEmails();
	cout << endl;

	/*Loop through each classRosterArray and for each element: 
	classRoster.printAverageDaysInCourse(current_object student id)*/

	cout << "Average days in courses: " << endl;
	classRoster->printAverageDaysInCourse("A1");
	classRoster->printAverageDaysInCourse("A2");
	classRoster->printAverageDaysInCourse("A3");
	classRoster->printAverageDaysInCourse("A4");
	classRoster->printAverageDaysInCourse("A5");

	cout << endl;

	cout << "Student Roster for Security: " << endl;
	classRoster->printByDegreeProgram(SECURITY);
	cout << "Student Roster for Network: " << endl;
	classRoster->printByDegreeProgram(NETWORK);
	cout << "Student Roster for Software: " << endl;
	classRoster->printByDegreeProgram(SOFTWARE);

	cout << endl << endl;


	/*classRoster.remove("A3") removal verification test*/
	classRoster->remove("A3");
	classRoster->printAll();
	classRoster->remove("A3");
	cout << endl;


} 