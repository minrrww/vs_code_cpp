#include <iostream>
class Rectangle
{
public:
    Rectangle(double Length, double Width) : length(Length), width(Width)
    {
        area = Length * Width;
    }
    Rectangle(const Rectangle &r) : length(r.length), width(r.width) {}
    ~Rectangle(){}
    double getLength() { return length; }
    double getWidth() { return width; }
    double getArea() { return area; }

protected:
private:
    double length;
    double width;
    double area;
};
using namespace std;

int main()
{
    Rectangle rect(25, 36);
    cout << rect.getArea() << endl;
    return 0;
}
