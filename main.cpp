
#include "studentList.h"
#include <fstream>

void displayMenu();
void readFile(StudentList<Student> list);

int main()
{
  StudentList<Student> list;
  readFile(list);
  list.displayList();
};

void displayMenu()
{
  using namespace std;
  cout << "==============================" << endl;
  cout << "Student Information Database Menu" << endl;
  cout << "==============================" << endl;
  cout << "V - View Student Information Database" << endl;
  cout << "F - Find Student Information by Student" << endl;
  cout << "S - Sort Student" << endl;
  cout << "A - Add a Student" << endl;
  cout << "D - Delete a Student" << endl;
  cout << "Q - Quit the Program" << endl;
  cout << "==============================" << endl;
}

void readFile(StudentList<Student> list)
{
  int yr;
	string first;
	string last;
	int num = 0;
	float points = 0;
	int cred = 0;
  fstream inputFile;
  std::cout << "Reading from file" << std::endl;
  inputFile.open("database", ios::in);
  while (inputFile >> first >> last >> num >> cred >> yr >> points)
  {
      Student newStudent(first,last, num, cred, yr, points);
      list.insertStudent(newStudent);
  }
  std::cout << "Closing File" << std::endl;
  inputFile.close();
}
