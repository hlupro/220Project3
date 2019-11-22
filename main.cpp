
#include "studentList.h"
#include <fstream>

void displayMenu();

int main()
{
  ifstream dataFile;
  StudentList<Student> list;
  std::cout << "Reading from file" << std::endl;
  displayMenu();
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
