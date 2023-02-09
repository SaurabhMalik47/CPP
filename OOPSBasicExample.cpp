#include <iostream>
using namespace std;

// Fraction Class
// NOTE: Friend Functions do not have a 'this' pointer, because friends are not members of a class.
// NOTE: Only member functions have a 'this' pointer.
// NOTE: 'this' pointer holds the address of current object.

class Fraction{
    private:
        int numerator;    // 1st Data Member
        int denominator;  // 2nd Data Member
    public:
        Fraction(int numerator, int denominator){    // Parameterised Constructor
            this -> numerator = numerator;           // Here, 'Argument Name' is same as 'Data Member Name'
            this -> denominator = denominator;       // 'this' pointer is used to indicate that we are putting 'denominator' of Argument in 'denominator' of Data Member           
        }

    // Print Function
    void print(){
        cout << numerator << " / " << denominator << endl;      // Here, print() function does not have any arguments, which means writing 'this' keyword with 'numerator' & 'denominator' is OPTIONAL
    }

    // Simplify Function
    void simplify(){
        int gcd = 1;
        int j = min(this->numerator, this->denominator);     // Using 'this' here is also Optional
        for(int i=1; i<=j; i++){
            if(this->numerator % i == 0 && this->denominator % i == 0)
                gcd = i;
        }
        this -> numerator = this -> numerator / gcd;
        this -> denominator = this -> denominator / gcd; 
    }

    // Add Function -> Add 2 Fractions as f1 = f1+f2
    void add(Fraction f2){
        int lcm = this->denominator * f2.denominator;       // Using 'this' with first denominator is Optional, as Implicitly it means denominator of f1.
        int x = lcm / denominator;
        int y = lcm / f2.denominator;

        int num = (x*numerator) + (y*f2.numerator);
        
        numerator = num;
        denominator = lcm;

        // To Make Fraction in Simplest Form, We would divide Numerator & Denominator by their HCF, by calling Simplify Function
        simplify();
    }
};



// Main Function

int main(){
    Fraction f1(10, 2);
    Fraction f2(15, 4);

    cout << "Fraction f1    = ";
    f1.print();
    cout << "Fraction f2    = ";
    f2.print();

    f1.add(f2);     // Adding Fractions f1 & f2

    cout << "Fraction f1+f2 = ";
    f1.print();
    cout << "Fraction f2    = ";
    f2.print();

    return 0;    
}


// Output:

// Fraction f1    = 10 / 2
// Fraction f2    = 15 / 4
// Fraction f1+f2 = 35 / 4
// Fraction f2    = 15 / 4
