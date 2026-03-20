// namespace / libraries and header files.
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "Course.h"
#include "Student.h"
using namespace std;

// sets the private data to a public variable so it can be used in the Get Course Name function.
Course::Course(string cname) {
	courseName = cname;
}


// function to get the course name.
string Course::GetCName() const {
	return courseName;
}


// a function that adds a student's ID too the vector of student ids
void Course::AddStudentID(int id){
    for (int s : studentIDs) {
        if (s == id) return;
    }
    studentIDs.push_back(id);
}

// a getter for the studentID's vector so you can know what students are in the course
const vector<int>& Course::GetStudentIDs() const {
    return studentIDs;
}


// saves the course but this time with the student ID so they're stored in the courses.txt
void Course::SaveCourse(ofstream& out) const{
    out << courseName;
    for (int id: studentIDs)
    out << "," << id;
    out << endl;
}


// loads a course and parses the saved line into the course name and puts the student ID's back into their vector.
void Course::LoadCourse(ifstream& in) {
    string courseline;
    if (getline(in, courseline)){
        stringstream inSS(courseline);
        getline(inSS,courseName,',');
        
        string IDstring;
        while (getline(inSS,IDstring,',')){
            studentIDs.push_back(stoi(IDstring));
        }
    }
}

bool Course::HasStudent(int id) const{
    for (int studentid : studentIDs){
        if (studentid == id){
            return true;
        }
    }
    return false;
}
