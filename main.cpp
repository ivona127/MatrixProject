#include <iostream>
#include <string>
#include "matrix.h"

using std::cout;
using std::string;
using std::cin;
using std::endl;

int main(){
    try{ 
        string fileName; 
        cout << "Enter file name:"<< endl;
        cin >> fileName;

        loadFromFile(fileName);
        GaussianElimination();
        pricePerUnitOfMeasured();
        priceDifference();
        AmountDifference();
    
    } catch(char const*ex) {
        cout << "exception string caught: " << ex << endl;
    }

    return 0;
}