// namespace / libraries and header files.
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include "Course.h"
#include "Student.h"
#include "College.h"
using namespace std;




// sets the private data to a public variable so it can be used in the Get College Name function.
College::College(string clname) {
	ColName = clname;
}



// function that returns the name of the college
string College::GetColName() const {
	return ColName;
}



// function that pushes back a course into the college's vector of courses
void College::AddCourse(const Course& course){
    courses.push_back(course);
}


// loops through all the courses and saves the name of the course into a file that can
// be accessed at a later date
void College::SaveCourses(const string& filename) const {
    ofstream out(filename);
    if (!out) return;
     
    for (const Course& c : courses) {
        out << c.GetCName();
    
    
    for (int id: c.GetStudentIDs()){
        out << "," << id;
    }
    out << endl;
}
    out.close();

}




// loads the file of courses and brings them back into the course vector
void College::LoadCourses(const string& filename) {
    ifstream in(filename);
    if (!in) return;

    courses.clear();
    
    string courseline;
    
    while (getline(in, courseline)) {
       if (courseline.empty()) continue;
       
       stringstream inSS(courseline);
       string courseName;
       
       getline(inSS, courseName, ',');
       
       Course c(courseName);
       
       string IDstring;
       
       while (getline(inSS,IDstring,',')){
           if(!IDstring.empty()){
               int id = stoi(IDstring);
               c.AddStudentID(id);
           }
       }
       courses.push_back(c);
    }

    in.close();
}



// a getter but not a const so it allows us to modify the vector
vector<Course>& College::GetCourses(){
    return courses;
}


// a getter but not a const so it allows us to modify the vector
vector<Student>& College::GetStudents(){
    return colstudents;
}



// prints out the names of all of the courses in the vector 
void College::PrintCourses() const{
    
    for (const Course& x : courses) {
			cout << x.GetCName() << endl;
		}
}




// returns a true or false if the course is offered at the college
bool College::Offered(const string& courseName) const {
    for(const Course& c : courses){
       if(c.GetCName() == courseName){
            return true;   
        }
    }
    return false;
}    
 
 
 
 
// adds student to colstudents which is a vector of all students who go to the college    
void College::AddStudent(const Student& student){
    colstudents.push_back(student);
}





// saves the students and all of their info into a txt file so it can be accessed at a later date
void College::SaveStudents(const string& filename) const{
    ofstream outFile(filename);
    if (!outFile){
        cerr << "Error opening file for writing" << endl;
        return;
    }
    
    for (const Student& x : colstudents){
        outFile << x.GetID() << "," << x.GetFirstName() << "," 
        << x.GetLastName() << "," << x.GetGPA() << endl;
        }
    
    outFile.close();
    
}




// loads the txt file of college students and puts them back into the vector for use in other parts of the program
void College::LoadStudents(const string& filename){
    ifstream in(filename);
    if (!in) return;  
    
    colstudents.clear();
    
    string studentline;
    while (getline(in, studentline)){
        if(studentline.empty()) continue;
        
        stringstream inSS(studentline);
        string IDstring;
        string fname;
        string lname;
        string GPAstring;
       
        getline(inSS, IDstring, ',');
        getline(inSS, fname, ',');
        getline(inSS, lname, ',');
        getline(inSS, GPAstring, ',');
        
        int id = stoi(IDstring);
        double gpa = stod(GPAstring);
        
        colstudents.push_back(Student(fname,lname,id,gpa));
        
    }
}




// checks to see if a student attends the school by checking the ID with the ID's present in the vector
bool College::Attends(int studentID) const {
    for (const Student& x : colstudents){
        if(x.GetID() == studentID)
        return true;
    }
    return false;
    }





// checks to see if a student attends the school by checking its name with the names in the vector
bool College::Attends(const string& lastName, const string& firstName)const{
    for(const Student& x : colstudents){
        if(x.GetFirstName() == firstName && x.GetLastName() == lastName)
        return true;
    }
    return false;
    }

