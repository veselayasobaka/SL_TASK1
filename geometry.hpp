#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include <iostream>
using namespace std;

/**
 * @brief The Point2D class - keeps 2D-coordinates for given point
 */
class Point2D
{
protected:
    /**
     * @brief _coords_x - keeps data for coordinate x
     */
    float _coords_x;
    /**
     * @brief _coords_y - keeps data for coordinate y
     */
    float _coords_y;

public:
    /**
     * @brief Point2D - constructor
     * @param x - x - coordinate
     * @param y - y - coordinate
     */
    Point2D(const float x, const float y):_coords_x(x), _coords_y(y){}
    /**
     * @brief show - displays coordinates in format (a, b)
     */
    virtual void show() const
    {
        cout << "(" << _coords_x << ", " << _coords_y << ')' << endl;
    }
    /**
     * @brief operator + - returns an object of the Point class, summing the
     * coordinates of two given objects of the Point class
     */
    friend Point2D operator+(const Point2D &a, const Point2D &b)
    {
        return Point2D(a._coords_x+b._coords_x, a._coords_y+b._coords_y);
    }
};
/**
 * @brief The Point3D class - inherits a Point2D class
 * supplemented by z-coordinate
 */
class Point3D : public Point2D
{
protected:
    /**
     * @brief _coords_z - keeps data for coordinate z
     */
    float _coords_z;

public:
    /**
     * @brief Point3D
     * @param x - x - coordinate
     * @param y - y - coordinate
     * @param z - z - coordinate
     */
    Point3D(const float x, const float y, const float z) : Point2D(x,y), _coords_z(z) {}
    /**
     * @brief show - displays coordinates in format (a, b, c)
     */\
    void show() const
    {
        cout << "(" << _coords_x << ", " << _coords_y << ", " << _coords_z <<')' << endl;
    }
};

/**
 * @brief The Square class - keeps data for the square,
 * which includes coordinates for the left bottom point and edge length of a square
 */
class Square
{
protected:
    /**
     * @brief _point0 - coordinate for the left bottom point
     */
    Point2D _point0;
    /**
     * @brief _length - edge length of a square
     */
    float _length;
public:
    /**
     * @brief Square - constructor for the square
     */
    Square(const Point2D point0, const float length):_point0(point0), _length(length){}
    /**
     * @brief show - displays coordinates for the vertices of the square
     * in format
     * A:(a1, a2)
     * B:(b1, b2)...
     */
    virtual void show() const
    {
        cout << "A: ";
        Point2D(_point0).show();
        cout << "B: ";
        Point2D(_point0 + Point2D(0, _length)).show();
        cout << "C: ";
        Point2D(_point0 + Point2D(_length, _length)).show();
        cout << "D: ";
        Point2D(_point0 + Point2D(_length, 0)).show();
    }
};

/**
 * @brief The Rectangle class - inherits class Square, with data supplemented by height
 */
class Rectangle : public Square
{
protected:
    /**
     * @brief _height - height of Rectangle
     */
    float _height;
public:
    /**
     * @brief Rectangle - constructor for the rectangle
     */
    Rectangle(const Point2D point0, const float length, const float height): Square(point0, length), _height(height){}
    /**
     * @brief show - displays coordinates for the vertices of the rectangle
     * in format
     * A:(a1, a2)
     * B:(b1, b2)...
     */
    void show() const
    {
        cout << "A: ";
        Point2D(_point0).show();
        cout << "B: ";
        Point2D(_point0 + Point2D(0, _length)).show();
        cout << "C: ";
        Point2D(_point0 + Point2D(_height, _length)).show();
        cout << "D: ";
        Point2D(_point0 + Point2D(_height, 0)).show();
    }
};

#endif // GEOMETRYH_HPP
