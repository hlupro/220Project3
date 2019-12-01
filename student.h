// Kutter Aaron & Hunter Lupro
// student.h 
// Student class declaration

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;


class Student
{
private:
	string firstname, lastname; //
	string fullname; //
	int id;
	int credits;
	int years;
	float GPA;
public:
	Student(); //default constructor
	Student(string first, string last, int num, int cred, int yr, float points); //constructor 
	Student(const Student& user); //copy constructor
	void read_name(string, string); //read name function
	void read_id(int); //read id function
	void read_credits(int); //read credits function
	void read_years(int); //read years function
	void read_gpa(float); //read gpa function

	string get_lastname() const; //get last name function
	string get_firstname() const; //get first name function
	string get_fullname() const; // get full name function
	int get_id() const; // get id function
	int get_credits() const; // get credits function
	int get_years() const; //get years function
	float get_gpa() const; //get gpa function
	 
	void estimated_year() const; //estimated year function
	void checkAcademic() const; //check academic standing function
	void display_info() const; //display info function
	 
	bool operator < (const Student& right); //overloaded < operator function
};

#endif