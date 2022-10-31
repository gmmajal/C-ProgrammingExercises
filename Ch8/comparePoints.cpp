#include "Point2d.hpp"
#include <iostream>
#include <set>

int main(int argc, char* argv[]){
    std::set<Point2d> points;
    Point2d origin(0.0, 0.0);
    
    points.insert(origin);
    
    points.insert( Point2d(-2.1, 1.5));
    points.insert( Point2d(-2.2, -1.1));
    points.insert( Point2d(-2.2, -1.2));
    points.insert( Point2d(0.0, 0.0));

    std::cout << "Number of points in set = " << points.size() << "\n";

    std::set<Point2d>::const_iterator c;
    for (c=points.begin(); c!=points.end(); c++){
        std::cout << c->x << " " << c->y << "\n";
    }
    
    return 0;
}