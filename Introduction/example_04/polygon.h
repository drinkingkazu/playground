
class Polygon{
public:
  Polygon(int w=-1, int h=-1) 
  { width = w; height = h; }

  virtual int area() 
  { return -1; }

protected:
  int width, height;
};

class Rectangle : public Polygon{
public:
  Rectangle(int w=-1, int h=-1) : Polygon(w,h) {}
  virtual int area() { return width * height; }
};

class Triangle : public Polygon{
public:
  Triangle(int w=-1, int h=-1) : Polygon(w,h) {}
  virtual int area() { return width * height / 2.; }
};
