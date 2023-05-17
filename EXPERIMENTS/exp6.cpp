#include <iostream>
#include <vector>
using namespace std;

// Course class definition
class Course {
private:
    string course_id;
    string course_name;
    int credit_hours;
public:
    // Constructor
    Course(string id, string name, int hours) {
        course_id = id;
        course_name = name;
        credit_hours = hours;
    }
    
    // Getter functions
    string getCourseId() const {
        return course_id;
    }
    
    string getCourseName() const {
        return course_name;
    }
    
    int getCreditHours() const {
        return credit_hours;
    }
    
    // Setter functions
    void setCourseId(string id) {
        course_id = id;
    }
    
    void setCourseName(string name) {
        course_name = name;
    }
    
    void setCreditHours(int hours) {
        credit_hours = hours;
    }
    
    // Delete function
    void deleteCourse() {
        course_id = " ";
        course_name = " ";
        credit_hours = 0;
    }
};

// Main function
int main() {
    // Create a vector of courses
    vector<Course> courses;
    
    // Add some courses to the vector
    courses.push_back(Course("COM-401","oops",5));
    courses.push_back(Course("COM-402","rdbms",6));
    courses.push_back(Course("COM-403","coa",3));
    
    // Delete the details of a course
    for (int i = 0; i < courses.size(); i++) {
        if (courses[i].getCourseId() == "COM-402") {
            courses[i].deleteCourse();
            cout<<"Values after deletion of the given course"<< endl;
            cout << "Course ID: " << courses[i].getCourseId() << endl;
            cout << "Course Name: " << courses[i].getCourseName() << endl;
            cout << "Credit Hours: " << courses[i].getCreditHours() << endl;
            break; 
        }
    }
    
    // Get the details of a course by course_id
    string course_id = "COM-401";
    for (int i = 0; i < courses.size(); i++) {
        if (courses[i].getCourseId() == course_id) {
            cout<<"Getting Details of a given Course"<< endl;
            cout << "Course ID: " << courses[i].getCourseId() << endl;
            cout << "Course Name: " << courses[i].getCourseName() << endl;
            cout << "Credit Hours: " << courses[i].getCreditHours() << endl;
            break;
        }
    }
    
    return 0;
}