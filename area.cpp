#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate the area of a circle
double area(double r) {
    return M_PI * r * r;
}

// Function to calculate the area of a rectangle
double area(double l, double w) {
    return l * w;
}

// Function to calculate the area of a triangle
double area(double b, double h, bool isT) {
    if (isT) {
        return 0.5 * b * h;
    }
    return 0.0;
}

int main() {
    double r, l, w, b, h;

    // Area of Circle
    cout << "Enter radius of the circle: ";
    cin >> r;
    cout << "Area of Circle: " << area(r) << endl;

    // Area of Rectangle
    cout << "Enter length and width of the rectangle: ";
    cin >> l >> w;
    cout << "Area of Rectangle: " << area(l, w) << endl;

    // Area of Triangle
    cout << "Enter base and height of the triangle: ";
    cin >> b >> h;
    cout << "Area of Triangle: " << area(b, h, true) << endl;

    return 0;
}
