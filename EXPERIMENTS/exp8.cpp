#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
    private:
        string name;
        int id;
        double gpa;
    public:
        Student(string name, int id, double gpa) {
            this->name = name;
            this->id = id;
            this->gpa = gpa;
        }
        string getName() {
            return name;
        }
        int getId() {
            return id;
        }
        double getGpa() {
            return gpa;
        }
};

class StudentDatabase {
    private:
        vector<Student> students;
    public:
        void addStudent(Student student) {
            students.push_back(student);
        }
        void searchStudentById(int id) {
            for (int i = 0; i < students.size(); i++) {
                if (students[i].getId() == id) {
                    cout << "Student Found!" << endl;
                    cout << "Name: " << students[i].getName() << endl;
                    cout << "ID: " << students[i].getId() << endl;
                    cout << "GPA: " << students[i].getGpa() << endl;
                    return;
                }
            }
            cout << "Student not found." << endl;
        }
};

int main() {
    StudentDatabase db;

    Student s1("John Doe", 1001, 3.5);
    Student s2("Jane Doe", 1002, 3.8);
    Student s3("Bob Smith", 1003, 3.2);

    db.addStudent(s1);
    db.addStudent(s2);
    db.addStudent(s3);

    db.searchStudentById(1002);
    db.searchStudentById(1004);

    return 0;
}
