#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
bool validateEmail(string email){
    return email.contains('@') && email.contains('.');
}
string sanitizeUserInput(string message){
    return message.replace()
}
int main(){
    string email;
    string message;
    cout << "Please enter an email" << endl;
    cin >> email;
    cout << "Please enter a message" << endl;
    cin >> message;
    return 0;
}