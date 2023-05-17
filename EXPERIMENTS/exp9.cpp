#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// Define a class to represent a course record
class CourseRecord {
    private:
        char courseID[10];
        char courseName[50];
        char instructorName[50];
    public:
        CourseRecord() {}
        CourseRecord(const char* id, const char* name, const char* instructor) {
            strcpy(courseID, id);
            strcpy(courseName, name);
            strcpy(instructorName, instructor);
        }
        void display() {
            cout << "Course ID: " << courseID << endl;
            cout << "Course Name: " << courseName << endl;
            cout << "Instructor Name: " << instructorName << endl;
        }
        char* getID() { return courseID; }
};

// Define a class to manage course records
class CourseRecordManager {
    private:
        char fileName[50];
    public:
        CourseRecordManager(const char* fName) { strcpy(fileName, fName); }
        void addRecord(CourseRecord& record) {
            ofstream outFile(fileName, ios::app);
            outFile.write((char*)&record, sizeof(record));
            outFile.close();
            cout << "Record added successfully." << endl;
        }
        void searchRecord(const char* courseID) {
            ifstream inFile(fileName);
            CourseRecord record;
            bool found = false;
            while(inFile.read((char*)&record, sizeof(record))) {
                if(strcmp(record.getID(), courseID) == 0) {
                    found = true;
                    record.display();
                }
            }
            if(!found) {
                cout << "Record not found." << endl;
            }
            inFile.close();
        }
};

int main() {
    CourseRecordManager manager("courses.dat");
    CourseRecord record1("CSC101", "Introduction to Computer Science", "John Smith");
    CourseRecord record2("CSC201", "Data Structures and Algorithms", "Jane Doe");
    CourseRecord record3("MAT101", "Calculus I", "Mike Johnson");

    manager.addRecord(record1);
    manager.addRecord(record2);
    manager.addRecord(record3);

    manager.searchRecord("CSC201");
    manager.searchRecord("PHY101");

    return 0;
}