template <typename T>
class Point {
  private:
    T x_;
    T y_;
  public:
    Point(const T x, const T y)
      : x_(x), y_(y) {}
    T x() { return x_; }
    T y() { return y_; }
};
