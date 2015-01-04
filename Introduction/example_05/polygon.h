
template <class T>
class Polygon{
public:
  Polygon(T width=-1, T height=-1) 
  { w = width; h = height; }

  virtual T area()
  { return -1; }

protected:
  T w,h;
};

template <class T>
class Rectangle : public Polygon<T>{
public:
  Rectangle(T width=-1, T height=-1) : Polygon<T>(width,height) {}
  virtual T area();
  { return Polygon<T>::w * Polygon<T>::h; }
};

template <class T>
class Triangle : public Polygon<T>{
public:
  Triangle(T width=-1, T height=-1) : Polygon<T>(width,height) {}
  virtual T area() 
  { return Polygon<T>::w * Polygon<T>::h / 2.; }
};
