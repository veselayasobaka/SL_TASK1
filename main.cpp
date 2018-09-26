#include <iostream>
#include "geometry.hpp"
using namespace std;

int main()
{
    int coord_x, coord_y, length, height;
    cout << "Enter data for x-coordinate: ";
    cin >> coord_x;
    cout << "Enter data for y-coordinate: ";
    cin >> coord_y;
    cout << "Enter data for the length of rectangle: ";
    cin >> length;
    cout << "Enter data for the height of rectangle: ";
    cin >> height;
    Point2D A(coord_x, coord_y);
    Rectangle R1(A, length, height);
    A.show();
    R1.show();
    return 0;
}

