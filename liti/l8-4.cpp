#include <iostream>
using namespace std;
class B0
{
public:
    virtual void display() const;
};
void B0:: display() const{
    cout << "B0::display()" << endl;
}
class Base2 : public B0
{
public:
    void display() const;
};
void Base2::display() const
{
    cout << "Base2::display()" << endl;
}
class Derived : public Base2
{
public:
    void display() const;
};
void Derived::display() const
{
    cout << "Derived::display()";
    cout << endl;
}
void fun(B0 *ptr)
{
    ptr->display();
}
int main()
{
    B0 B0;
    Base2 base2;
    Derived derived;
    fun(&B0);
    fun(&base2);
    fun(&derived);
    return 0;
}
