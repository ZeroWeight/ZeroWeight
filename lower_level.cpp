#include<math.h>
#include<stdio.h>
struct Position {
    double x;
    double y;
    double z;
};

Position add(Position a,Position b);//a+b
Position minus(Position a,Position b);//a-b
Position multiple(double k,Position a);//ka
Position cross_product(Position a,Position b);//a*b 
double length(Position a);//
Position norm(Position a);//
double distance(Position a,Position b);//
void show(Position a);//

Position add(Position a,Position b)
{
    Position c;
    c.x=a.x+b.x;
    c.y=a.y+b.y;
    c.z=a.z+b.z;
    return c;
}

Position minus(Position a,Position b)
{
    Position c;
    c.x=a.x-b.x;
    c.y=a.y-b.y;
    c.z=a.z-b.z;
    return c;
}

Position multiple(double k,Position a)
{
    Position c;
    c.x=k*a.x;
    c.y=k*a.y;
    c.z=k*a.z;
    return c;
}

Position cross_product(Position a,Position b)
{
    Position c;
    c.x=a.y*b.z-a.z*b.y;
    c.y=-a.x*b.z+a.z*b.x;
    c.z=a.x*b.y-a.y*b.x;
    return c;
}

double length(Position a)
{
    return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
}

Position norm(Position a)
{
    double l=1/length(a);
    return multiple(l,a);
}

double distance(Position a,Position b)
{
    return length(minus(a,b));
}

void show(Position a)
{
    printf("The position is (%f,%f,%f).\n",a.x,a.y,a.z);
}

