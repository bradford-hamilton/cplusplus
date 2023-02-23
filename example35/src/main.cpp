#include <iostream>
#include <vector>

/*

Polymorphism: Pure virtual functions and abstract classes

Abstract class
- Cannot instantiate objects
- Used as base classes in inheritance hierarchies
- Often referred to as Abstract Base Classes
- Contains at least one pure virtual function

Concrete class
- Used to instantiate objects
- All their member functions are defined
  - Checking Account, Savings Account
  - Faculty, Staff
  - Enemy, Level Boss

Think of the Account hierarchy... In real world it could make sense that we
actually never would need a plain "Account", but rather always a type of account
like Checking, Savings, Trust, etc. So Account would be a good candidate for an
abstract base class.

So it seems the abstract base class serves as a sort of class interface for that
class type. All derived concrete classes must override (implement) the pure virtual
funcs defined in the base abstract class.

*/

class Shape {
private:
  // Attributes common to all shapes
public:
  // Pure virtual funcs:
  // Virtual funcs that must be overriden in derived classes (the interface) - if they
  // are not overridden in a derived class, the derived class itself will operate as an
  // abstract base class.
  virtual void draw() = 0;
  virtual void rotate() = 0;
  virtual ~Shape() {}
};

// OpenShape does NOT override the base abstract class' pure virtual functions, so OpenShape
// is itself another abstract class.
class OpenShape: public Shape {
public:
  ~OpenShape() {}
};

// ClosedShape does NOT override the base abstract class' pure virtual functions, so ClosedShape
// is itself another abstract class.
class ClosedShape: public Shape {
public:
  ~ClosedShape() {}
};

// Line overrides the abstract base class' pure virtual functions (the interface)
// so Line is a concrete type that can create objects.
class Line: public Shape {
public:
  virtual void draw() override {
    std::cout << "Drawing a line" << std::endl;
  }
  virtual void rotate() override {
    std::cout << "Rotating a line" << std::endl;
  }
  virtual ~Line() {}
};

// Circle overrides the abstract base class' pure virtual functions (the interface)
// so Circle is a concrete type that can create objects.
class Circle: public Shape {
public:
  virtual void draw() override {
    std::cout << "Drawing a circle" << std::endl;
  }
  virtual void rotate() override {
    std::cout << "Rotating a circle" << std::endl;
  }
  virtual ~Circle() {}
};

// Square overrides the abstract base class' pure virtual functions (the interface)
// so Square is a concrete type that can create objects.
class Square: public Shape {
public:
  virtual void draw() override {
    std::cout << "Drawing a square" << std::endl;
  }
  virtual void rotate() override {
    std::cout << "Rotating a square" << std::endl;
  }
  virtual ~Square() {}
};

// Non-member func showing dynamic polymorphism where we MUST have implemented
// the interface for Shape, so we know we can call its draw method.
void screen_refresh(const std::vector<Shape *> shapes) {
  for (auto shape: shapes) {
    shape->draw();
  }
}

int main() {
  // Compiler errors for trying to initialize an abstract class
  // Shape s;                  object of abstract class type "Shape" is not allowed
  // Shape *p = new Shape();   object of abstract class type "Shape" is not allowed

  Shape *ptr = new Circle();
  ptr->draw();    // Drawing a circle
  ptr->rotate();  // Rotating a circle

  std::cout << "-----------------------------------------------------" << std::endl;

  Shape *s1 = new Line();
  Shape *s2 = new Circle();
  Shape *s3 = new Square();
  std::vector<Shape *> shapes {s1, s2, s3};
  
  for (auto shape: shapes) {
    shape->draw();
    shape->rotate();
  }
  // Drawing a line
  // Rotating a line
  // Drawing a circle
  // Rotating a circle
  // Drawing a square
  // Rotating a square
  
  delete s1;
  delete s2;
  delete s3;

  std::cout << "-----------------------------------------------------" << std::endl;

  Shape *s4 = new Line();
  Shape *s5 = new Circle();
  Shape *s6 = new Square();
  std::vector<Shape *> shapes_for_refresh {s4, s5, s6};

  screen_refresh(shapes_for_refresh);
  // Drawing a line
  // Drawing a circle
  // Drawing a square

  delete s4;
  delete s5;
  delete s6;

  return 0;
}
