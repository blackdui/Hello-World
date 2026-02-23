// dealing with chars
#include <cctype>

using std::toupper;

template <typename T>
class Container {
  private:
    T content_;
  public:
    Container(const T content)
      : content_(content) {}
    T Inc() { return ++content_; }
};

template<>
class Container <char> {
  private:
    char content_;
  public:
    Container(const char content)
      : content_(content) {}
    char Upper() { return toupper(content_); }
};
