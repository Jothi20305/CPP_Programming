

#include <iostream>
#include <cmath>  // for M_PI
using namespace std;

// Base class
class Shape {
protected:
    string name;
public:
    Shape(string n) : name(n) {}
    virtual void calculateArea() = 0;  // pure virtual
    virtual ~Shape() {
        cout << "Destroying Shape: " << name << endl;
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    float length, breadth;
public:
    Rectangle(float l, float b) : Shape("Rectangle"), length(l), breadth(b) {}
    void calculateArea() override {
        float area = length * breadth;
        cout << name << " Area: " << area << endl;
    }
    ~Rectangle() {
        cout << "Destroying Rectangle" << endl;
    }
};

// Derived class: Circle
class Circle : public Shape {
private:
    float radius;
public:
    Circle(float r) : Shape("Circle"), radius(r) {}
    void calculateArea() override {
        float area = M_PI * radius * radius;
        cout << name << " Area: " << area << endl;
    }
    ~Circle() {
        cout << "Destroying Circle" << endl;
    }
};

// Derived class: Triangle
class Triangle : public Shape {
private:
    float base, height;
public:
    Triangle(float b, float h) : Shape("Triangle"), base(b), height(h) {}
    void calculateArea() override {
        float area = 0.5 * base * height;
        cout << name << " Area: " << area << endl;
    }
    ~Triangle() {
        cout << "Destroying Triangle" << endl;
    }
};

int main() {
    const int size = 3;
    Shape* shapes[size];

    shapes[0] = new Rectangle(4.5, 3.2);
    shapes[1] = new Circle(2.0);
    shapes[2] = new Triangle(5.0, 2.5);

    cout << "\n--- Area Calculations ---\n";
    for (int i = 0; i < size; i++) {
        shapes[i]->calculateArea();
    }

    for (int i = 0; i < size; i++) {
        delete shapes[i];
    }

    return 0;
}
