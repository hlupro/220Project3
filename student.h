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
	void checkAcademic() const;
	void display_info() const;

	bool operator < (const Student& right);
};

#endif