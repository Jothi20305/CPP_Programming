#include <iostream>
using namespace std;

class Complex {
private:
    float real, imag;

public:
    // Constructor
    Complex(float r = 0, float i = 0) {
        real = r;
        imag = i;
    }

    // Overload >> for input
    friend istream& operator>>(istream& in, Complex& c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }

    // Overload << for output
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;
        if (c.imag >= 0)
            out << " + " << c.imag << "i";
        else
            out << " - " << -c.imag << "i";
        return out;
    }

    // Overload + operator
    Complex operator+(const Complex& c) {
        return Complex(real + c.real, imag + c.imag);
    }

    // Overload - operator
    Complex operator-(const Complex& c) {
        return Complex(real - c.real, imag - c.imag);
    }

    // Overload * operator
    Complex operator*(const Complex& c) {
        float r = real * c.real - imag * c.imag;
        float i = real * c.imag + imag * c.real;
        return Complex(r, i);
    }

    // Overload == operator
    bool operator==(const Complex& c) {
        return (real == c.real && imag == c.imag);
    }
};

int main() {
    Complex c1, c2, result;
    int choice;

    cout << "Enter First Complex Number:\n";
    cin >> c1;

    cout << "\nEnter Second Complex Number:\n";
    cin >> c2;

    do {
        cout << "\n----- Complex Number Calculator -----\n";
        cout << "1. Add\n";
        cout << "2. Subtract\n";
        cout << "3. Multiply\n";
        cout << "4. Compare (==)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            result = c1 + c2;
            cout << "\nResult: " << result << endl;
            break;
        case 2:
            result = c1 - c2;
            cout << "\nResult: " << result << endl;
            break;
        case 3:
            result = c1 * c2;
            cout << "\nResult: " << result << endl;
            break;
        case 4:
            if (c1 == c2)
                cout << "\nThe complex numbers are equal.\n";
            else
                cout << "\nThe complex numbers are not equal.\n";
            break;
        case 5:
            cout << "\nExiting...\n";
            break;
        default:
            cout << "\nInvalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
