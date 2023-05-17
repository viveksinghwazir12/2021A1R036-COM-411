/*#include<iostream>
using namespace std;

class course {
    private :
    string name ;
    int id ;
    int duration; 

    public: 
    //parameterized constructor
    course( string name , int id , int duration)
    {
        this-> name = name;
        this-> id = id;
        this-> duration = duration;
    }
    void displaydetails() {
        cout << "course name : " << name << endl;
        cout << "course id : " << id << endl;
        cout << "course duration : " << duration << endl;
    }

};

int main() 
{
string name ; 
int id , duration;

cout << "enter course name : " ;
getline(cin,name);
cout << "enter course id : ";
cin >> id;
cout << "enter course duration : ";
cin >> duration;
course s( name , id , duration);

cout << "\n following are the course details entered : \n";

s.displaydetails();

return 0;

}
*/
#include <iostream>
#include <vector>
using namespace std;

class Course
{
private:
    string semester;
    string course_ID;
    string course_name;
    int n;

public:

    void addcourse(vector<Course>& courses)       //Member function to insert student details
    {
        cout << "Enter the semester: ";
        cin >> semester;
        cout << "Enter the number of subjects: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "\nEnter course ID: ";
            cin >> course_ID;
            cout << "\nEnter course name: ";
            cin >> course_name;
            courses.push_back(*this);
        }
    }


    void updatecourse(vector<Course>& courses)      //Member function to Modify student details
    {
        cout << "Enter semester to update the details: ";
        cin >> semester;
        for (int i = 0; i < courses.size(); i++)             //modifying the details by entering roll number
        {
            if (courses[i].semester == semester)
            {
                cout << "Enter updated Course name: ";
                cin >> courses[i].course_name;
                cout << "Enter updated Course ID: ";
                cin >> courses[i].course_ID;
            }
        }
    }


    void displaycourse(vector<Course>& courses)    //Member function to display all student details
    {
        cout << "Course ID\t \tCourse Name\t\n";
        for (int i = 0; i < courses.size(); i++)
        {
            cout << courses[i].course_ID << "\t\t" << courses[i].course_name <<"\t\t"<< endl;
        }
    }
};
int main()
{
    vector<Course> courses;   // class student object is created
    Course c;
    int choice;
    while(1)
    {
        cout << "1. To add Course details:" <<endl;
        cout << "2. To Update Course details:" <<endl;
        cout << "3. To Display Course details:" <<endl;
        cout << "4. Exit" << endl;
        cout << "\n Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
        case 1:
            c.addcourse(courses);
            break;
        case 2:
            c.updatecourse(courses);
            break;
        case 3:
            c.displaycourse(courses);
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}