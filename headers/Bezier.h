#include <vector>
struct Point2D
{
    double x, y;
};

class BezierCurve
{
public:
    BezierCurve(size_t n) : points(std::vector<Point2D>(n)) {}
    BezierCurve(std::vector<Point2D> points) : points(points) {}

    void setPoint(Point2D point, size_t number);
    Point2D evaluate(double t);
    std::vector<Point2D> renderCurve(std::vector<double> t);
private:
    std::vector<Point2D> points;

};