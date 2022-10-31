#include "Point2d.hpp"

Point2d::Point2d(double x1, double y1){
     x = x1;
     y = y1;
}

bool Point2d::operator<(const Point2d& other) const{
    if ( (other.x - x) > 1e-10){
        return true;
    }
    else if ( (x - other.x) > 1e-10){
        return false;
    }else if ( (other.y- y) > 1e-10){
        // x == other.x
        return true;
    }else{
        // x == other.x and
        // y >= other.y
        return false;
    }
}