#include <Curves.h>

uint32_t fact(uint32_t n)
{
    uint32_t result = 1;
    for (int i = 1; i <= n; i++) result *= i;
    return result;
}

uint32_t binomial(uint32_t n, uint32_t k)
{
    return fact(n)/(fact(k) * fact(n - k)); // may be optimized!
}

double BernsteinCoeff(uint32_t k, uint32_t n, double x)
{
    return binomial(n, k) * pow(x, k) * pow(1 - x, n - k);
}

Point2D operator+ (Point2D f, Point2D s) {return {f.x + s.x, f.y + s.y};}
Point3D operator+ (Point3D f, Point3D s) {return {f.x + s.x, f.y + s.y, f.z + s.z};}
Point2D operator* (double a, Point2D b) {return {b.x * a, b.y * a};}
Point3D operator* (double a, Point3D b) {return {b.x * a, b.y * a, b.z * a};}
Point2D operator* (Point2D b, double a) {return {b.x * a, b.y * a};}
Point3D operator* (Point3D b, double a) {return {b.x * a, b.y * a, b.z * a};}
std::ostream& operator<< (std::ostream& out, const Point3D& a) {return out << "(" << a.x << ' ' << a.y << ' ' << a.z << ")";}
std::ostream& operator<< (std::ostream& out, const Point2D& a) {return out << "(" << a.x << ' ' << a.y << ")";}