#include<iostream>
using namespace std;

class Derived;

class Base {
private:
    virtual void fun() { cout << "Base Fun"; }
friend int main();
};

class Derived: public Base {
public:
    void fun() { cout << "Derived Fun"; }
};

int main()
{
   Base *ptr = new Derived;
   ptr->fun();
   return 0;
}
/*
There are few things to note in the above program.
1) ptr is a pointer of Base type and points to a Derived class object. When ptr->fun() is called, fun() of Derived is executed.

2) int main() is a friend of Base.  If we remove this friendship, the program won’t compile (See this).  We get compiler error. 

Note that this behavior is totally different in Java. In Java, private methods are final by default and cannot be overridden 
*/
