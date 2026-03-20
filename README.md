
# College Management System (C++)

## About

This is a simple C++ program I made to manage students and courses for a college. It runs in the console and lets you add students, create courses, and register students into those courses.

The program also saves everything to text files so the data is still there when you run it again.

## What it can do

* Add a course
* Check if a course exists
* Show all courses
* Add a student
* Check if a student exists
* Add a student to a course
* Check if a student is in a course
* Print all students
* Print a course roster

## How it works

The program uses classes:

* `Student` → stores student info (name, ID, GPA)
* `Course` → stores course name and student IDs
* `College` → manages everything

It reads and writes data using:

* `students.txt`
* `courses.txt`

## How to run

Compile everything:

```
g++ main.cpp Student.cpp Course.cpp College.cpp -o program
```

Then run:

```
./program
```

## Example data

students.txt

```
1,Curtis,Lear,3.82
2,Eddie,Vedder,3.42
```

courses.txt

```
English,1,2
Computer Science,3
```

## Notes

I made this to practice using classes, vectors, and file input/output in C++. It’s a basic system but it shows how everything connects together.

