
#include <iostream>
#include "polygon.h"

int main() {

  Polygon<float>   obj1(5,5);
  Rectangle<float> obj2(5,5);
  Triangle<float>  obj3(5,5);

  std::cout 
    << std::endl
    << "Area of (w,h) = (5,5) Polygon   : " << obj1.area() << std::endl
    << "Area of (w,h) = (5,5) Rectangle : " << obj2.area() << std::endl
    << "Area of (w,h) = (5,5) Triangle  : " << obj3.area() << std::endl
    << std::endl;

  return 0;
}


