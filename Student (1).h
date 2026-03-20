// include guards, not really fully sure on there exact purpose but I know they're required for it to run.
// think it might be like it declaring the header file?
#ifndef STUDENTH
#define STUDENTH

// namespace / libraries.
#include <string>
using namespace std;

// creates the student class and all of its private and public members
class Student {
private:
	string firstName;
	string lastName;
	int ID;
	double GPA;

public:
	Student(string fname, string lname, int id, double gpa);

	string GetFirstName() const;

	string GetLastName() const;

	int GetID() const;

	double GetGPA() const;

};

#endif