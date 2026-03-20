// include guards, not really fully sure on there exact purpose but I know they're required for it to run.
// think it might be like it declaring the header file?
#ifndef COURSEH
#define COURSEH

// namespace / libraries and header files.
#include<vector>
#include<string>
#include "Student.h"
using namespace std;


// creates the course class and all of its private and public members
class Course {
private:
	string courseName;
	vector<int> studentIDs;
public:
	Course(string cname);

	string GetCName() const;

    void AddStudentID(int id);
    
    const vector<int>& GetStudentIDs() const;
    
    void SaveCourse(ofstream& out) const;
    
    void LoadCourse(ifstream& in);

    bool HasStudent(int id) const;













};

#endif
