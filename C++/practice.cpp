#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <utility>
#include <ctime>
#include <stack>
#include <utility>
using namespace std;
int main(){
    double itemPrice, itemQuantity, total;
    cout << "Enter an item price" << endl;
    cin >> itemPrice;
    cout << "Enter your quantity: " << endl;
    cin >> itemQuantity;
    total = itemPrice * itemQuantity;
    cout << "Total price is: " << total << endl;
    return 0;
}