#include "Figure.hpp"

Figure::Figure(int size){
    figure.reserve(size);
}

Figure::~Figure(){
    std::cout << "~Figure\n";
    
    for(Point* p : figure)delete p;
}


