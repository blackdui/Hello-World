#include <string>
using std::string;
class Vehicle {
  protected:
    string license_;
    int year_;
  public:
    Vehicle(const string &my_license, const int &my_year)
      : license_(my_license), year_(my_year) {}
    const string &license() const { return license_;}
    const int &year() const { return year_;}
};
// public keeps the protected identifier.
class Car : public Vehicle {
  private:
    string style_;
  public:
    Car(const string &my_license, const int my_year, const string my_style)
      : Vehicle(my_license, my_year), style_(my_style) {}
    const string & style() const { return style_; }
};

class Truck : public Vehicle {
  private:
    string bed_length_;
  public:
    Truck(const string &my_license, const int &my_year, const string &my_bed_length)
      : Vehicle(my_license, my_year), bed_length_(my_bed_length) {}
    const string &bed_length() const { return bed_length_; }
};


