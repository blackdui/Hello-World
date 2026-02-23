class Person {
private:
  int age_;

public:
  Person operator+(const Person &p) {
    Person person;
    person.age_ = p.age_ + this->age_;
    return person;
  }
  Person(int age)
  {
    this->age_ = age; 
  }
  Person() {}
  int age()
  {
    return age_;
  }
  
};
