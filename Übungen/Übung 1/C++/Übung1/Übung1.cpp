#include<iostream>
#include<memory>
struct Point 
{  
	float x,y;  
	Point(float _x, float _y)
	{    x=_x; y=_y;  }  
	~Point() 
	{    std::cout << "destroy " << x << "," << y << "\n";  }
};
struct A 
{  Point *p;};
struct B {  std::shared_ptr<Point> p;};
struct C {  std::unique_ptr<Point> p;};
int main() 
{  
	A a1,a2;
	B b1,b2;
	C c1,c2;
	a1.p = new Point(11,11);               //                11    
	a2.p = new Point(12,12);               //             12  |  
	b1.p = std::make_shared<Point>(21,21); //          21  |  |  
	b2.p = std::make_shared<Point>(22,22); //       22  |  |  |  
	c1.p = std::make_unique<Point>(31,31); //    31  |  |  |  |  
	c2.p = std::make_unique<Point>(32,32); // 32  |  |  |  |  |                                         
										   //  |  |  |  |  |  |  
	a1.p = a2.p;                           // [ ][ ][ ][ ][ ][ ]  
	b1.p = b2.p;                           // [ ][ ][ ][ ][ ][ ] 
	// c1.p = c2.p;  // kompiliert nicht!
}