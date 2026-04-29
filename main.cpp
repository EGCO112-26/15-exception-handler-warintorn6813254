#include <iostream>
#include <exception>
#include <cmath>
#include <limits>
#include <new> 

using namespace std;


class InputFailException : public exception {
public:
    virtual const char* what() const throw() {
        return "Incorrect numbers"; 
    }
};

class Div0Exception : public exception {
public:
    virtual const char* what() const throw() {
        return "Divided by zero";
    }
};

void checkDivisor(int y) {
    if (y == 0) throw Div0Exception();
}

int main() {
    int x, y;
    double d;
    bool retry = true;

    while (retry) {
        try {
            cout << "Enter 2 numbers: ";
            
           
            if (!(cin >> x >> y)) {
                throw InputFailException();
            }

         
            if (abs(x) > 1000 || abs(y) > 1000) {
                throw "Value out of range";
            }

            checkDivisor(y);

            
            d = (double)x / y;
            cout << "The result is " << d << endl;
            
          
            for (int i = 0; i < 100; i++) {
                cout << "Allocating memory .... " << i << endl;
                
                double* myarray = new double[999999999999999]; 
            }

            retry = false; 

        } 
        catch (const InputFailException& e) {
            cerr << e.what() << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        } 
        catch (const Div0Exception& e) {
            cerr << e.what() << endl;
        }
        catch (const char* msg) {
            cerr << msg << endl; 
        } 
        catch (const bad_alloc& e) {
           
            cerr << e.what() << endl;
            retry = false; 
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
        }
    }

    return 0;
}