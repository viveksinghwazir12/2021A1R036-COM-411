#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int age;
    string address;
public:
    void setDetails(string n, int a, string add) {
        name = n;
        age = a;
        address = add;
    }
    
    void deleteDetails() {
        name = "";
        age = 0;
        address = "";
    }
    
    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
    }
};

int main() {
    Student s1;
    
    s1.setDetails("John", 18, "123 Main St");
    s1.displayDetails();
    
    s1.deleteDetails();
    s1.displayDetails();
    
    return 0;
}
