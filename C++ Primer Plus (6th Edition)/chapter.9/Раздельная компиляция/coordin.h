// Листинг9.1. coordin.h 
// coordin.h — шаблоны структур и прототипы функций 
// шаблоны структур 
#ifndef COORDIN_H_
#define COORDIN_H_

struct polar
{
    double distance; // расстояние от исходной точки 
    double angle;    // направление от исходной точки 
};

struct rect
{
    double x;   // расстояние по горизонтали от исходной точки 
    double y;   // расстояние по вертикали от исходной точки 
};

// прототипы
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);
#endif