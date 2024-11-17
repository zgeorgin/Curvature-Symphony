#include <Curves.h>
#include <iostream>
int main()
{
    std::vector<Point2D> points = {{0, 0}, {0.5, 0.5}, {1, 0}};
    BezierCurve2D c(points);
    std::vector<double> t = {0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    std::vector<Point2D> curvePoints = c.renderCurve(t);
    for (int i = 0; i < t.size(); i++) std::cout << curvePoints[i] << std::endl;
}