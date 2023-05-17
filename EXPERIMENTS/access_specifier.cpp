#include <iostream>
using namespace std;

class Course {
  private:
    int courseId; // Private because it should not be accessible outside the class
    string courseName; // Private because it should not be accessible outside the class
  public:
    void setCourseDetails(int id, string name) {
      courseId = id;
      courseName = name;
    }
    void displayCourseDetails() {
      cout << "Course ID: " << courseId << endl;
      cout << "Course Name: " << courseName << endl;
    }
};

class Student {
  private:
    int studentId; // Private because it should not be accessible outside the class
    string studentName; // Private because it should not be accessible outside the class
    int age; // Private because it should not be accessible outside the class
    string address; // Private because it should not be accessible outside the class
    Course course; // Private because it should not be accessible outside the class
  public:
    void setStudentDetails(int id, string name, int a, string addr) {
      studentId = id;
      studentName = name;
      age = a;
      address = addr;
    }
    void displayStudentDetails() {
      cout << "Student ID: " << studentId << endl;
      cout << "Student Name: " << studentName << endl;
      cout << "Age: " << age << endl;
      cout << "Address: " << address << endl;
      course.displayCourseDetails(); // accessing private member of Course class through public function
    }
};

int main() {
  Student student;
  student.setStudentDetails(1001, "John Doe", 20, "123 Main Street");
  Course course;
  course.setCourseDetails(101, "C++ Programming");
  student.displayStudentDetails();

  return 0;
}
