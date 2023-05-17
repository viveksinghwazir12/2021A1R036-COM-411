#include <iostream>
using namespace std;

class Student {
    private:
        string name;
        int rollNo;
        int age;
    public:
        // Parameterized Constructor
        Student(string name, int rollNo, int age) {
            this->name = name;
            this->rollNo = rollNo;
            this->age = age;
        }
        void displayDetails() {
            cout << "Name: " << name << endl;
            cout << "Roll Number: " << rollNo << endl;
            cout << "Age: " << age << endl;
        }
};

int main() {
    string name;
    int rollNo, age;
    
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter Roll Number: ";
    cin >> rollNo;
    cout << "Enter Age: ";
    cin >> age;
    
    Student s(name, rollNo, age);
    s.displayDetails();
    
    return 0;
}
