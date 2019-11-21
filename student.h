#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

template <class T>
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

	void read_name(string, string);
	void read_id(int);
	void read_credits(int);
	void read_years(int);
	void read_gpa(float);
	void estimated_year() const;
	void display_info() const;
};

template <class T>
Student<T>::Student()
{
	years = 0;
	firstname = "Not Given";
	lastname = "Not Given";
	id = 0;
	GPA = 0;
}

template <class T>
void Student<T>::read_name(string userfName, string userlName)
{
	firstname = userfName;
	lastname = userlName;
	fullname = firstname + " " + lastname;
}

template <class T>
void Student<T>::read_id(int userID)
{
	id = userID;
}

template <class T>
void Student<T>::read_credits(int userCredits)
{
  credits = userCredits;
}

template <class T>
void Student<T>::read_years(int userYears)
{
	years = userYears;
}

template <class T>
void Student<T>::read_gpa(float userGPA)
{
	GPA = userGPA;
}

template <class T>
void Student<T>::estimated_year() const
{
  if (credits <= 30)
    { cout << "Freshman"; }
  if (credits <= 60 && credits >= 31)
    { cout << "Sophomore"; }
  if (credits <= 90 && credits >= 61)
    { cout << "Junior"; }
  else if (credits <= 120 && credits >= 91)
    { cout << "Senior"; }
  else
    { cout << "Undefined"; }
}

template <class T>
void Student<T>::display_info() const
{
	cout << "Student Info:" << endl;
	cout << "Student: " << fullname << endl;
	cout << "ID: " << id << endl;
	cout << "Credits: " << credits << endl;
	estimated_years();
	cout << "Years In School: " << years << endl;
	cout << "GPA: " << GPA << endl;
}

#endif 
