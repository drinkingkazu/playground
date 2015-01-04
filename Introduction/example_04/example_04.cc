
#include <iostream>
#include "polygon.h"

int main() {

  Polygon   obj1(2,2);
  Rectangle obj2(2,2);
  Triangle  obj3(2,2);

  std::cout 
    << std::endl
    << "Area of (w,h) = (2,2) Polygon   : " << obj1.area() << std::endl
    << "Area of (w,h) = (2,2) Rectangle : " << obj2.area() << std::endl
    << "Area of (w,h) = (2,2) Triangle  : " << obj3.area() << std::endl
    << std::endl;

  return 0;
}


