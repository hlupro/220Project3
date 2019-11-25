#include "student.h"

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

Student::Student(const Student& student)
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
		cout << "Academic Status: Freshman" << endl;
	}
	else if (credits <= 60 && credits >= 31)
	{
		cout << "Academic Status: Sophomore" << endl;
	}
	else if (credits <= 90 && credits >= 61)
	{
		cout << "Academic Status: Junior" << endl;
	}
	else if (credits <= 120 && credits >= 91 && years > 4)
	{
		cout << "Academic Status: Super Senior" << endl;
	}
	else if (credits <= 120 && credits >= 91)
	{
		cout << "Academic Status: Senior" << endl;
	}
	else
	{
		cout << "Undefined" << endl;
	}
}

void Student::display_info() const
{
	cout << "Student: " << fullname << endl;
	cout << "ID: " << id << endl;
	cout << "Credits: " << credits << endl;
	estimated_year();
	cout << "Years In School: " << years << endl;
	cout << "GPA: " << GPA << endl;
}

bool Student::operator < (const Student& right)
{
	if (firstname.compare(right.firstname) < 0)
	{
		return true;
	}
	else if (firstname.compare(right.firstname) > 0)
	{
		return false;
	}
}

void Student::checkAcademic() const
{
	if (GPA >= 2.0)
	{
		std::cout << fullname << " is in good academic standing." << std::endl;
	}
	else
	{
		std::cout << fullname << " is in poor academic standing." << std::endl;
	}
}