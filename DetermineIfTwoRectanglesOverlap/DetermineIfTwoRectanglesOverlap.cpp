#include <iostream>
using namespace std;

class Point{
public:
    int x;
    int y;
    Point(int x, int y){    
        this->x = x;
        this->y = y;
    }
};

class Rectangle{
public:
    Point* upperRight;
    Point* lowerLeft;
    
    Rectangle(Point* upperRight, Point* lowerLeft){
        this->upperRight = upperRight;
        this->lowerLeft = lowerLeft;
    }
    
    int height(){
        return upperRight->y - lowerLeft->y;
    }
    
    int width(){
        return upperRight->x - lowerLeft->x;
    }
    
    bool isOverlapping(Rectangle& rect){
        return (
            this->upperRight->x >= rect.lowerLeft->x && this->lowerLeft->x <= rect.upperRight->x &&
            this->upperRight->y >= rect.lowerLeft->y && this->lowerLeft->y <= rect.upperRight->y);
    }
};

int main(){
    Point upperRight1(5, 5);
    Point lowerLeft1(0, 0);
    Rectangle rect1(&upperRight1, &lowerLeft1);
    
    Point upperRight2(8, 8);
    Point lowerLeft2(6, 6);
    Rectangle rect2(&upperRight2, &lowerLeft2);

    cout << rect1.isOverlapping(rect2) << endl;
    cout << rect2.isOverlapping(rect1) << endl;
    return 0;
}

