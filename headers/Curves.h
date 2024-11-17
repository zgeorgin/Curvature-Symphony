#include <vector>
#include <stdexcept>
#include <cstdint>
#include <cmath>
#include <iostream>
#ifndef CURVES_H
#define CURVES_H

uint32_t fact(uint32_t n);

uint32_t binomial(uint32_t n, uint32_t k);

double BernsteinCoeff(uint32_t k, uint32_t n, double x);

struct Point2D
{
    double x = 0, y = 0;
};

struct Point3D
{
    double x = 0, y = 0, z = 0;
};


Point2D operator+ (Point2D f, Point2D s);
Point3D operator+ (Point3D f, Point3D s);
Point2D operator* (double a, Point2D b);
Point3D operator* (double a, Point3D b);
Point2D operator* (Point2D b, double a);
Point3D operator* (Point3D b, double a);
std::ostream& operator<< (std::ostream& out, const Point3D& a);
std::ostream& operator<< (std::ostream& out, const Point2D& a);

template<typename T>
class ParamCurve
{
public:
    virtual T evaluate(double t) = 0;
    virtual std::vector<T> renderCurve(std::vector<double> t) = 0;
};

template<typename T>
class BezierCurve : ParamCurve<T>
{
public:
    BezierCurve(size_t n) : points(std::vector<T>(n)) {}
    BezierCurve(std::vector<T> points) : points(points) {}

    void setPoint(T point, size_t number) {if (points.size() > number) points[number] = point; else throw std::range_error("number in BezierCurve.setPoint out of range!!!");}
    T evaluate(double t) override 
    {
        T result; 
        for (int i = 0; i < points.size(); i++) result = result + BernsteinCoeff(i, points.size() - 1, t) * points[i]; 
        return result;
    }
    std::vector<T> renderCurve(std::vector<double> t) override 
    {
        std::vector<T> result(t.size());
        for (int i = 0; i < t.size(); i++) result[i] = evaluate(t[i]);
        return result;
    }
private:
    std::vector<T> points;
};

using BezierCurve2D = BezierCurve<Point2D>;
using BezierCurve3D = BezierCurve<Point3D>;
#endif