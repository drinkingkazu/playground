
class Polygon{
public:
  Polygon(){}

  virtual int area() 
  { return -1; }

  void SetParams(int width, int height)
  { w = width; h = height; }

protected:
      int w, h;
};

class Rectangle : public Polygon{
public:
  Rectangle(){}
  virtual int area() { return w * h; }
};

class Triangle : public Polygon{
public:
  Triangle(){}
  virtual int area() { return w * h / 2.; }
};
