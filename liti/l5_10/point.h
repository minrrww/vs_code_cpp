class Point
{
public:
    Point(int x, int y);
    Point(Point &p);
    ~Point() { count--; }
    int getX() { return x; }
    int getY() { return y; }
    static void showCount();

private:
    int x, y;
    static int count;
};
