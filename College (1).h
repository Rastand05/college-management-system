#ifndef COLLEGEH
#define COLLEGEH

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include "Student.h"
#include "Course.h"

// creates the college class and all of its private and public members
class College{
    
    private:
        string ColName;
        vector<Course> courses;
        vector<Student> colstudents;
        
    public:
    
        College(string clname);
        
        string GetColName() const;
        
        vector<Course>& GetCourses();
        
        vector<Student>& GetStudents();
        
        void AddCourse(const Course& course);
        
        void SaveCourses(const string& filename) const;
        
        void LoadCourses(const string& filename);
        
        void PrintCourses() const;
        
        void AddStudent(const Student& student); 
        
        void SaveStudents(const string& filename) const;
        
        void LoadStudents(const string& filename);
        
        bool Offered(const string& courseName) const;
       
        bool Attends(int studentID) const;
        
        bool Attends(const string& lastName, const string& firstName) const;
};

#endif