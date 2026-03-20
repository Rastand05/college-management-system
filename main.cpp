

//bring in libraries and header files
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Course.h"
#include "Student.h"
#include "College.h"
#include <fstream>
using namespace std;


// main program.
int main()
{





    // menu options
    // prints all of the options that the user can choose 
    cout << "PROGRAM OPTIONS" << endl;
    cout << "===============" << endl;
    cout << "0: ADD A COURSE" << endl;
    cout << "1: CHECK IF COURSE IS OFFERED" << endl;
    cout << "2: PRINT ROSTER FOR A COURSE" << endl;
    cout << "3: PRINT LIST OF ALL COURSES OFFERED" << endl;
    cout << "4: ADD A STUDENT" << endl;
    cout << "5: CHECK IF STUDENT IS ENROLLED IN THE COLLEGE" << endl;
    cout << "6: ADD STUDENT TO A COURSE" << endl;
    cout << "7: CHECK IF STUDENT REGISTERED FOR A COURSE" << endl;
    cout << "8: PRINT LIST OF ALL STUDENTS ATTENDING COLLEGE" << endl;
    cout << "9: REPRINT PROGRAM OPTIONS" << endl;
    cout << "-1: END PROGRAM" << endl;


  
    // creates the SanJac College object
    // and calls the load course and load student function which
    // brings in the info in the txt files and reassigns them to the vectors for use in other parts of the prog.
    College SanJac("SanJac");
    SanJac.LoadCourses("courses.txt");
    SanJac.LoadStudents("students.txt");


    


    


    // menu loop
    while (true){
        
        
        
        
        
        
        // creates choice which is how we will have the user chose what they want to run in the program
        // intializes it at 999 as just a place holder number, and gets the users input. 
        int choice;
        choice = 999;
        cin >> choice;
        
        
        // if the choice is -1 it will end the program
        if (choice == -1){
            cout << "ENDING PROGRAM" << endl;
            break;
        }
        
        
        // if choice is 0 then it allows the user to add a course to the college
        if (choice == 0){
            cout << "You chose [ADD A COURSE]" << endl;
            string courseName;
            
            cout << "Type in Course Name: " << endl;
            cin.ignore();
            getline(cin, courseName);
            
            if(SanJac.Offered(courseName)){
                cout << "Already Exists" << endl;
            }
            else{
                SanJac.AddCourse(Course(courseName));
                SanJac.SaveCourses("courses.txt");
                cout << courseName << " Has been added." << endl;
            }
        }
        
        // choice allows the user to see if a course is offered at San Jac
        if (choice == 1){
            
            cout << "You chose [CHECK IF A COURSE IS OFFERED]" << endl;
            cout << "Input Course Name: " << endl;
            
            string coursename;
            cin.ignore();
            getline(cin,coursename);
            
            if (SanJac.Offered(coursename)){
                cout << coursename << " is offered at San Jac" << endl;
            }
            else{
                cout << coursename << " is not offered at San Jac" << endl;
            }
        }
        
        
        // choice allows us to print out the roster of a course by checking if the course is offered 
        // and if it is it goes through all of the courses to find it and then goes through each student
        // and prints the students info
        if (choice == 2){
            
            cout << "You chose [PRINT ROSTER FOR A COURSE]" << endl;
            string courseName;
            cout << "Enter Course Name" << endl;
            cin.ignore();
            getline(cin,courseName);
            
            if (!SanJac.Offered(courseName)){
                cout << courseName << " isn't offered." << endl;
            }
            else{
                for (Course& x : SanJac.GetCourses()){
                    if(x.GetCName() == courseName){
                        for (int id: x.GetStudentIDs()){
                            for (Student& s : SanJac.GetStudents()){
                                if(s.GetID() == id){
                                    cout << s.GetLastName() << ", " << s.GetFirstName() <<
                                    " ID: " << s.GetID() << " GPA: " << s.GetGPA() << endl;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        
        
        
        
        
        
        
        
        // if the choice is 3 then it'll call the print courses function and print out all
        // of the courses offered at the college
        if (choice == 3){
            cout << "You chose [PRINT LIST OF ALL COURSES OFFERED]" << endl;
            cout << "Courses Offered: " << endl;
            SanJac.PrintCourses();
        }
        
        
        // if choice was 4 then it allows the user to add a student to the col student vector and
        // saves it to the txt file by calling the savestudent function.
        // and if the student already exists then it won't change anything.
        if (choice == 4){
            cout << "You chose [ADD A STUDENT]" << endl;
            int studentID;
            string firstName;
            string lastName;
            double GPA;
            
            cout << "Enter Student ID: " << endl;
            cin >> studentID;
            cin.ignore();
            cout << "Enter First Name: " << endl;
            getline(cin, firstName);
            cout << "Enter Last Name: " << endl;
            getline(cin, lastName);
            cout << "Enter GPA: " << endl;
            cin >> GPA;
            
            if(SanJac.Attends(studentID)){
                cout << "Student Already Exists" << endl;
            }
            else{
                Student newStudent(firstName, lastName, studentID, GPA);
                SanJac.AddStudent(newStudent);
                SanJac.SaveStudents("students.txt");
                cout << firstName << " Has been added." << endl;
            }
        }
        
        
        
        // choice that allows the user to see if a student is enrolled at the school.
        if (choice == 5){
            cout << "You chose [CHECK IF STUDENT IS ENROLLED IN THE COLLEGE]" << endl;
            cout << "Check via ID or Name (0 for ID, 1 for Name): " << endl;
            int idOrName;
            
            
            while (true){
               
                cin >> idOrName; 
                if (idOrName == 0){
                    
                    cout << "Input Student ID: " << endl;
                    
                    int studentid;
                    cin >> studentid;
                    
            
                    if (SanJac.Attends(studentid)){
                        cout << "Student with ID: " << studentid << " Attends San Jac" << endl;
                    }
                    
                    else{
                        cout << "Student with ID: " << studentid << " Doesn't Attend San Jac" << endl;
                    }
                    
                    break;    
                }
                
                else if (idOrName == 1){
                    
                    string fname;
                    string lname;
                    
                    cout << "Input Student's First Name: " << endl;
                    cin >> fname;
                    cout << "Input Student's Last Name: " << endl;
                    cin >> lname;
                    
                    if (SanJac.Attends(lname, fname)){
                        cout << "Student " << lname << ", " << fname << " Attends San Jac" << endl;
                    }
                    
                    else{
                        cout << "Student " << lname << ", " << fname << " Doesn't Attend San Jac" << endl;
                    }
                    
                    break;
                }
                
                else{
                    cout << "INVALID IDORNAME CHOICE" << endl;
                    cout << "Try Again: " << endl;
                }
            }
            
        }
        
        
        // choice allows the user to add a student to a course, and then it gets saved to the txt file
        // if the student id doesn't exist then it ends or if the course doesnt exist
        if (choice == 6){
            cout << "You chose [ADD STUDENT TO A COURSE]" << endl;
            int studentID;
            string courseName;
            
            cout << "Enter Student ID: " << endl;
            cin >> studentID;
            cin.ignore();
            
            cout << "Enter Course Name: " << endl;
            getline(cin, courseName);
            
            if (!SanJac.Offered(courseName)){
                
                cout << courseName << " Doesn't Exist" << endl;
            }
            
            else if(!SanJac.Attends(studentID)){
                
                cout << "Student with ID " << studentID 
                << " Does not attend San Jac" << endl;
            }
            
            else{
                
                for (Course& x : SanJac.GetCourses()){
                    
                    if (x.GetCName() == courseName){
                        
                        x.AddStudentID(studentID);
                        SanJac.SaveCourses("courses.txt");
                        
                        cout << "Student with ID " << studentID 
                        << " Has been added to " << courseName
                        << "." << endl;
                       
                        break;
                    }
                }
            }
        }
        
        
        
        
        // choice allows the user to see if a student is registered in a specific course
        // if the student doesnt exist it ends and if the course doesnt exist.
        if (choice == 7){
            cout << "You chose [CHECK IF STUDENT REGISTERED FOR A COURSE]" << endl;
            int studentID;
            string courseName;
            
            cout << "Enter Student ID: " << endl;
            cin >> studentID;
            cin.ignore();
            
            cout << "Enter Course Name: " << endl;
            getline(cin, courseName);
            
            if (!SanJac.Offered(courseName)){
                
                cout << courseName << " Doesn't Exist" << endl;
            }
            
            else if(!SanJac.Attends(studentID)){
                
                cout << "Student with ID " << studentID 
                << " Does not attend San Jac" << endl;
            }
            
            else{
                
                for (Course& x : SanJac.GetCourses()){
                    
                    if (x.GetCName() == courseName){
                    
                        if (x.HasStudent(studentID)){
                            cout << "Student with ID: " << studentID <<
                            " is registered in " << courseName << "." << endl;
                        }
                        else{
                            cout << "Student with ID:  " << studentID << 
                            " is not registerd in " << courseName << "." << endl;
                        }
                        break;
                    }
                }
            }
        }    
        
        // uses the getstudents function to get all of the students in the colstudents vector
        // and then prints out all of the students information.
        if (choice == 8){
            cout << "You chose [PRINT LIST OF ALL STUDENTS ATTENDING COLLEGE]" << endl;
            cout << "San Jac Students: " << endl;
            for (Student& x : SanJac.GetStudents()){
                cout << x.GetLastName() << ", " << x.GetFirstName() 
                << " ID:" << x.GetID() << " GPA:" << x.GetGPA() << endl;
            }
        }
        
        
        
        
       
        // reprints the menu options avaliable to the user
        if (choice == 9){
            cout << "You chose [REPRINT PROGRAM OPTIONS]" << endl;
            cout << endl;
            cout << "PROGRAM OPTIONS" << endl;
            cout << "===============" << endl;
            cout << "0: ADD A COURSE" << endl;
            cout << "1: CHECK IF COURSE IS OFFERED" << endl;
            cout << "2: PRINT ROSTER FOR A COURSE" << endl;
            cout << "3: PRINT LIST OF ALL COURSES OFFERED" << endl;
            cout << "4: ADD A STUDENT" << endl;
            cout << "5: CHECK IF STUDENT IS ENROLLED IN THE COLLEGE" << endl;
            cout << "6: ADD STUDENT TO A COURSE" << endl;
            cout << "7: CHECK IF STUDENT REGISTERED FOR A COURSE" << endl;
            cout << "8: PRINT LIST OF ALL STUDENTS ATTENDING COLLEGE" << endl;
            cout << "9: REPRINT PROGRAM OPTIONS" << endl;
            cout << "-1: END PROGRAM" << endl;
        
        
         
        
    }
	
}
	
	
	return 0;
}
