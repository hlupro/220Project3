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
	Student(const Student& user);
	void read_name(string, string);
	void read_id(int);
	void read_credits(int);
	void read_years(int);
	void read_gpa(float);

	string get_lastname() const;
	string get_firstname() const;
	string get_fullname() const;
	int get_id() const;
	int get_credits() const;
	int get_years() const;
	float get_gpa() const;

	void estimated_year() const;
	void display_info() const;

	bool operator < (const Student &right);


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

Student::Student(string first, string last, int num, int cred, int yr, float points)
{
	years = yr;
	firstname = first;
	lastname = last;
	fullname = first + " " + last;
	id = num;
	GPA = points;
	credits = cred;
}

Student::Student(const Student &student)
{
	firstname = student.get_firstname();
	lastname = student.get_lastname();
	fullname = firstname + " " + lastname;
	id = student.get_id();
	years = student.get_years();
	GPA = student.get_gpa();
	credits = student.get_credits();
}

string Student::get_firstname() const
{
	return firstname;
}

string Student::get_lastname() const
{
	return lastname;
}
string Student::get_fullname() const
{
	return fullname;
}

int Student::get_id() const
{
	return id;
}
int Student::get_credits() const
{
	return credits;
}
int Student::get_years() const
{
	return years;
}
float Student::get_gpa() const
{
	return GPA;
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
	{
		cout << "Freshman" << endl;
	}
	if (credits <= 60 && credits >= 31)
	{
		cout << "Sophomore" << endl;
	}
	if (credits <= 90 && credits >= 61)
	{
		cout << "Junior" << endl;
	}
	else if (credits <= 120 && credits >= 91)
	{
		cout << "Senior" << endl;
	}
	else
	{
		cout << "Undefined" << endl;
	}
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

bool Student::operator < (const Student &right)
{
	if (firstname.compare(right.firstname) < 0)
	{
		return true;
	}
	else if(firstname.compare(right.firstname) > 0)
	{
		return false;
	}
}

#endif
