// namespace / libraries and headers.
#include <iostream>
#include "Student.h"
using namespace std;


// sets the private data to a public variable so it can be used in the functions / public members.
Student::Student(string fname, string lname, int id, double gpa) {
	firstName = fname;
	lastName = lname;
	ID = id;
	GPA = gpa;
}


// function to get the first name of a student
string Student::GetFirstName() const {
	return firstName;
}


// function to get the last name of a student
string Student::GetLastName() const {
	return lastName;
}


// function to get the ID# of a student
int Student::GetID() const {
	return ID;
}


// function to get the GPA of a student
double Student::GetGPA() const {
	return GPA;
}