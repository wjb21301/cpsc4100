#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <limits>
using namespace std;

int main(){
    srand(time(0));
    int n;
    cout << "Enter a matrix size for multiplication";
    cin >> n;
    vector<vector<int>> m1(n, vector<int>(n,0));
    vector<vector<int>> m2(n, vector<int>(n,0));
    for (size_t i = 0; i < m1.size(); i++){
        for (size_t j = 0; j < m1[0].size(); j++){
            m1[i][j] = rand() % 50;
        }
    }
    for (size_t i= 0; i < m2.size(); i++){
        for (size_t j = 0; j < m2[0].size(); j++){
            m2[i][j] = rand() % 50;
        }
    }
    vector<vector<int>> result(n, vector<int>(n,0));
    for(size_t i = 0; i<m1.size(); i++){
        for(size_t j = 0; j<m2[0].size(); j++){
            for(size_t k = 0; k<m1[0].size(); k++){
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    cout << "--------MATRIX 1------------";
    cout << endl;
    for (size_t i = 0; i < m1.size(); i++) {
        for (size_t j = 0; j < m1[0].size(); j++) {
            cout << m1[i][j] << " ";  
        }
        cout << endl;  
    }
    cout << "--------MATRIX 2----------";
    cout << endl;
    for (size_t i = 0; i < m2.size(); i++) {
        for (size_t j = 0; j < m2[0].size(); j++) {
            cout << m2[i][j] << " ";  
        }
        cout << endl;  
    }
    cout << "-------RESULT-------";
    cout << endl;
    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[0].size(); j++) {
            cout << result[i][j] << " ";  
        }
        cout << endl;  
    }
    string name;
    cout << "------Now, please enter a name to  lexicoigraphically find smallest and largest.";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,name);
    string smallest = name;
    string largest = name;
    string last = name;
    while (true){
        cout << "Enter another name, or * to exit";
        getline(cin,name);
        if (name == "*"){
            break;
        }
        if (name > largest){
            largest = name;
        }
        if (name < smallest){
            smallest = name;
        }
        last = name;
    }
    cout << "Largest: " << (largest) << "\n";
    cout << "Smallest: " << (smallest) << "\n";
    cout << "last: " << (last);


    return 0;
}


    


