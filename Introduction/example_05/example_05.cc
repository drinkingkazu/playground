
#include <iostream>
#include "polygon.h"

int main() {

  Polygon<float>   obj1;
  Rectangle<float> obj2;
  Triangle<float>  obj3;

  obj1.SetParams(5,5);
  obj2.SetParams(5,5);
  obj3.SetParams(5,5);

  std::cout 
    << std::endl
    << "Area of (w,h) = (5,5) Polygon   : " << obj1.area() << std::endl
    << "Area of (w,h) = (5,5) Rectangle : " << obj2.area() << std::endl
    << "Area of (w,h) = (5,5) Triangle  : " << obj3.area() << std::endl
    << std::endl;

  return 0;
}


