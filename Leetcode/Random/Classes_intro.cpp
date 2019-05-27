#include<iostream> 
using namespace std; 
  
class Shape{
    protected:
        int width;
        int height;
    public:
        Shape(int x, int y);
        virtual int getArea() = 0;
};

Shape::Shape(int x=0, int y=0)
{
    width = x;
    height = y;
}

int Shape::getArea()
{
    cout<<"Parent Shape Class"<<endl;
    return 0;
}

class Rectangle:public Shape{
    public:
        Rectangle(int w, int h):Shape(w,h){}
        int getArea()
        {
            cout<<"From Rectangle Class"<<endl;
            return width * height;
        }
};

class Triangle:public Shape{
    public:
        Triangle(int w, int h):Shape(w,h){}
        int getArea()
        {
            cout<<"From Triangle Class"<<endl;
            return (width * height) / 2;
        }
};

int main() 
{
    Shape* s1;
    Rectangle r1(10,10);
    Triangle t1(10, 50);
    s1 = &r1;
    cout<<s1->getArea()<<endl;
    s1 = &t1;
    cout<<s1->getArea()<<endl;
    return 0;
}