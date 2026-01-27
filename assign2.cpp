#include <iostream>
using namespace std;
class Student{
    public:
        string name;
        int age;
        float gpa;
        string gradeLevel;
        Student(){
            name = "No Name Yet";
            age = 0;
            gpa = 0;
            gradeLevel = "No grade level yet";
        }
        Student(string a, int b, float c, string d){
            name = a;
            age = b;
            gpa = c;
            gradeLevel = d;
        }
        void printStudent() const{
            cout << "Name: " << name << "Age: " << age << "GPA: " << gpa << "gradeLevel: " << gradeLevel;
        }
};
int main(){
    Student students[5] = {{"Jack" , 24, 3.2 , "Senior"},
                            {"Jerry" , 18, 3.9, "Junior"} , 
                            {"Bill", 20 , 2.5, "Freshman"} , 
                            {"Jenny" , 21, 3.5, "Sophomore"}, 
                            {"Denny" , 19, 2.0, "Freshman"}};
    for (int i = 0; i < 5; i++){
        students[i].printStudent();
    }
    cout << "\n";
    return 0;
}