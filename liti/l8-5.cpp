#include <iostream>

using namespace std;
class Base1
{
public:
    virtual ~Base1();
};
Base1::~Base1(){
    cout << "Base1 destructor" << endl;
}
class Derived : public Base1
{
public:
    Derived();
    ~Derived();
    private:
        int *p;
};
Derived::Derived(){
    p = new int(0);
}
Derived::~Derived(){
    cout << "Derived destructor" << endl;
    delete p;
}

void fun(Base1 *b)
{
    delete b;
}
int main()
{
    Base1 *b = new Derived();
    fun(b);
    return 0;
}
