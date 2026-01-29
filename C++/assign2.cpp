#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <utility>
#include <ctime>
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
void quicksort(int arr[], int small, int large){
    if (small < large){
        int pivot = partition(arr, small, large);
        quicksort(arr, small, pivot - 1);
        quicksort(arr, pivot + 1, large);

    }

}
int partition(int arr[], int small, int large){
    srand(time(0));
    int randomIndex = small + rand() % (large - small + 1);
    int pivot = arr[randomIndex];
    


    
}


    

int main(){
    Student students[5] = {{"Jack" , 24, 3.2 , "Senior"},
                            {"Jerry" , 18, 3.9, "Junior"} , 
                            {"Bill", 20 , 2.5, "Freshman"} , 
                            {"Jenny" , 21, 3.5, "Sophomore"}, 
                            {"Denny" , 19, 2.0, "Freshman"}};
    for (int i = 0; i < 5; i++){
        students[i].printStudent();
        cout << "\n";
    }
    cout << "\n";
    string names[5] = {"John" , "James", "Jimmy", "Jake", "Jerry"};
    int ages[5] = {21,24,18,19,20};
    float gpas[5]={3.0,2.2,3.4,4.0,2.1};
    string gradeLevels[5] = {"Junior", "Freshman", "Sophomore" , "Senior", "Junior"};
    for (int i = 0; i < 5; i++){
        cout << " Name: "<< names[i] << " Age: " << ages[i] << " GPA: "<< gpas[i] << " Grade Level: " << gradeLevels[i] << "\n";
    }
    return 0;
}