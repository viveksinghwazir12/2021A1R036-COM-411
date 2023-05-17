#include <iostream>
#include <string>
using namespace std;

// Course class
class Course {
protected:
    string courseName;
    string courseCode;
public:
    Course(string name, string code) : courseName(name), courseCode(code) {}
    virtual void display() {
        cout << "Course Name: " << courseName << endl;
        cout << "Course Code: " << courseCode << endl;
    }
};

// UGCourse class derived from Course
class UGCourse : public Course {
private:
    int year;
public:
    UGCourse(string name, string code, int yr) : Course(name, code), year(yr) {}
    void display() override {
        Course::display();
        cout << "Year: " << year << endl;
    }
};

// PGCourse class derived from Course
class PGCourse : public Course {
private:
    string specialization;
public:
    PGCourse(string name, string code, string spec) : Course(name, code), specialization(spec) {}
    void display() override {
        Course::display();
        cout << "Specialization: " << specialization << endl;
    }
};

// DiplomaCourse class derived from Course
class DiplomaCourse : public Course {
private:
    string type;
public:
    DiplomaCourse(string name, string code, string t) : Course(name, code), type(t) {}
    void display() override {
        Course::display();
        cout << "Type: " << type << endl;
    }
};

int main() {
    UGCourse ugc("Introduction to Computer Science", "CS101", 1);
    PGCourse pgc("Advanced Algorithms", "CS501", "Computer Science");
    DiplomaCourse dc("Web Development", "WD101", "Technical");

    // polymorphism
    Course* c1 = &ugc;
    Course* c2 = &pgc;
    Course* c3 = &dc;

    c1->display();
    c2->display();
    c3->display();

    return 0;
}