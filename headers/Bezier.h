#include <vector>
struct Point2D
{
    double x, y;
};

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

    void setPoint(T point, size_t number);
    Point2D evaluate(double t) override;
    std::vector<T> renderCurve(std::vector<double> t) override;
private:
    std::vector<T> points;
};