/*
 * n C++, friendship is not inherited. If a base class has a friend 
 * function, then the function doesn’t become a friend of the derived 
 * class(es).
 */
#include <iostream>
using namespace std;
 
class A
{
  protected:
    int x;
  public:
    A() { x = 0;}
  friend void show();
};
 
class B: public A
{
  public:
    B() : y (0) {}
  private:
    int y;
};
 
void show()
{
  B b;
  cout << "The default value of A::x = " << b.x;
 
  // Can't access private member declared in class 'B'
  //cout << "The default value of B::y = " << b.y;
}
 
int main()
{
  show();
  return 0;
}
