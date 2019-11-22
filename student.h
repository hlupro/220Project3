#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;


class Student
{
private:
	string firstname, lastname;
	string fullname;
	int id;
	int credits;
	int years;
	float GPA;
public:
	Student();
	Student(string first, string last, int num, int cred, int yr, float points);
	void read_name(string, string);
	void read_id(int);
	void read_credits(int);
	void read_years(int);
	void read_gpa(float);
	void estimated_year() const;
	void display_info() const;
};

Student::Student()
{
	years = 0;
	firstname = "Not Given";
	lastname = "Not Given";
	fullname = "Not Given";
	id = 0;
	GPA = 0;
	credits = 0;
}

Student::Student(Student student) //Will need to create getter functions for a copy constructor
{
	firstname = student.get;
	lastname = last;
	fullname = firstname + " " + lastname;
	id = num;
	years = yr;
	GPA = points;
	credits = cred;
}


void Student::read_name(string userfName, string userlName)
{
	firstname = userfName;
	lastname = userlName;
	fullname = firstname + " " + lastname;
}

void Student::read_id(int userID)
{
	id = userID;
}

void Student::read_credits(int userCredits)
{
  credits = userCredits;
}

void Student::read_years(int userYears)
{
	years = userYears;
}

void Student::read_gpa(float userGPA)
{
	GPA = userGPA;
}

void Student::estimated_year() const
{
  if (credits <= 30)
    { cout << "Freshman" << endl; }
  if (credits <= 60 && credits >= 31)
    { cout << "Sophomore" << endl; }
  if (credits <= 90 && credits >= 61)
    { cout << "Junior" << endl; }
  else if (credits <= 120 && credits >= 91)
    { cout << "Senior" << endl; }
  else
    { cout << "Undefined" << endl; }
}

void Student::display_info() const
{
	cout << "Student Info:" << endl;
	cout << "Student: " << fullname << endl;
	cout << "ID: " << id << endl;
	cout << "Credits: " << credits << endl;
	estimated_year();
	cout << "Years In School: " << years << endl;
	cout << "GPA: " << GPA << endl;
}

#endif
