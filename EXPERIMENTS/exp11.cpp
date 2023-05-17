#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Course {
public:
    string code;
    string name;
    string instructor;
    int credits;

    Course(const string& c = "", const string& n = "", const string& i = "", int cr = 0)
        : code(c), name(n), instructor(i), credits(cr) {}

    void display() const {
        cout << "Course Code: " << code << endl;
        cout << "Course Name: " << name << endl;
        cout << "Instructor: " << instructor << endl;
        cout << "Credits: " << credits << endl;
    }
};

vector<Course> readCoursesFromFile(const string& filename) {
    vector<Course> courses;
    ifstream file(filename);
    if (!file) {
        cout << "Error opening file: " << filename << endl;
        return courses;
    }

    string code, name, instructor;
    int credits;
    while (file >> code >> name >> instructor >> credits) {
        courses.emplace_back(code, name, instructor, credits);
    }

    file.close();
    return courses;
}

void writeCoursesToFile(const string& filename, const vector<Course>& courses) {
    ofstream file(filename);
    if (!file) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    for (const Course& course : courses) {
        file << course.code << " " << course.name << " " << course.instructor << " " << course.credits << endl;
    }

    file.close();
}

void displayAllCourses(const vector<Course>& courses) {
    for (const Course& course : courses) {
        course.display();
        cout << "-------------------------------" << endl;
    }
}

void editCourse(vector<Course>& courses, const string& code) {
    for (Course& course : courses) {
        if (course.code == code) {
            cout << "Enter new course name: ";
            getline(cin, course.name);
            cout << "Enter new instructor name: ";
            getline(cin, course.instructor);
            cout << "Enter new credits: ";
            cin >> course.credits;
            cin.ignore();  // Ignore the newline character

            cout << "Course updated successfully!" << endl;
            return;
        }
    }

    cout << "Course not found." << endl;
}

void deleteCourse(vector<Course>& courses, const string& code) {
    for (auto it = courses.begin(); it != courses.end(); ++it) {
        if (it->code == code) {
            courses.erase(it);
            cout << "Course deleted successfully!" << endl;
            return;
        }
    }

    cout << "Course not found." << endl;
}

int main() {
    string filename = "courses.txt";
    vector<Course> courses = readCoursesFromFile(filename);

    int choice;
    string code;

    do {
        cout << "1. Display all courses" << endl;
        cout << "2. Edit a course" << endl;
        cout << "3. Delete a course" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayAllCourses(courses);
                break;
            case 2:
                cout << "Enter the course code: ";
                cin.ignore();  // Ignore the newline character
                getline(cin, code);
                editCourse(courses, code);
                break;
            case 3:
                cout << "Enter the course code: ";
                cin.ignore();  // Ignore the newline character
                getline(cin, code);
                deleteCourse(courses, code);
                break;
            case 4:
                writeCoursesToFile(filename, courses);
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }

        cout << endl;
    } while (choice != 4);

    return 0;
}
