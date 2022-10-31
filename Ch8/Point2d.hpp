#ifndef POINT2DHEADERDEF
#define POINT2DHEADERDEF

class Point2d{
    public:
        double x,y;
        Point2d(double x1, double y1);
        bool operator<(const Point2d& other)const;
};
#endif