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
int partition(int arr[], int small, int large){
    int randomIndex = small + rand() % (large - small + 1);
    swap(arr[randomIndex], arr[large]);
    int pivot = arr[large];
    int i = small - 1;
    for (int j = small; j < large; j++){
        if (arr[j] < pivot){
            i = i+1;
            swap(arr[i], arr[j]);

        }
    }
    swap(arr[i+1], arr[large]);
    return i + 1;   
}
void quicksort(int arr[], int small, int large){
    if (small < large){
        int pivot = partition(arr, small, large);
        quicksort(arr, small, pivot - 1);
        quicksort(arr, pivot + 1, large);

    }
}
int main(){
    srand(time(0));
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
    int arr[] = {8, 3, 7, 6, 2, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    quicksort(arr, 0, n - 1);

    cout << "After sorting: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}