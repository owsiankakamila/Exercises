//
// Created by kamila on 31.03.18.
//

#include "Square.h"
#include <math.h>

geometry::Square::Square() {

}

geometry::Square::Square(Point p1, Point p2, Point p3, Point p4) {
    p1_ = p1;
    p2_ = p2;
    p3_ = p3;
    p4_ = p4;
}

bool geometry::Square::IsSquare() const{
    if (p1_.Distance(p4_) == p2_.Distance(p3_)){
        return true;
    }
    else{
        return false;
    }
}


double geometry::Square::Circumference()const{
    if (this->IsSquare()){
        double side =p1_.Distance(p2_);

        return 4*side;
    }
    else{
        return 0;
    }
}
double geometry::Square::Area()const{
    if (this->IsSquare()){
        double side =p1_.Distance(p2_);

        return side*side;

    }
    else{
        return 0;
    }
}