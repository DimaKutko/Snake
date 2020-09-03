#include "Figure.hpp"

Figure::Figure(int size){
    figure.reserve(size);
}

Figure::~Figure(){
    for(Point* p : figure){
        delete p;
    }
}


