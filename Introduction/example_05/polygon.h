
template <class T>
class Polygon{
public:
  Polygon(){}

  virtual T area() 
  { return -1; }

  void SetParams(T width, T height)
  { w = width; h = height; }

protected:
  T w, h;
};

template <class T>
class Rectangle : public Polygon<T>{
public:
  Rectangle(){}
  virtual T area() { return Polygon<T>::w * Polygon<T>::h; }
};

template <class T>
class Triangle : public Polygon<T>{
public:
  Triangle(){}
  virtual T area() { return Polygon<T>::w * Polygon<T>::h / 2.; }
};
