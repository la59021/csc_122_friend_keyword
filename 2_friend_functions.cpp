#include <iostream>
using namespace std;

class Rectangle {
    private:
        int width;
        int height;

    public:
        Rectangle(int w, int h) : width(w), height(h) {}

        int area() {
            return this->width * this->height;
        }

        friend Rectangle scale(Rectangle, int);
        friend Rectangle swap(Rectangle);
};

Rectangle scale(Rectangle rectangle, int factor) {
    int new_width = rectangle.width * factor;
    int new_height = rectangle.height * factor;
    return Rectangle(new_width, new_height);
}

Rectangle swap(Rectangle rectangle) {
    int temp = rectangle.width;
    int new_width = rectangle.height;
    int new_height = temp;
    return Rectangle(new_width, new_height);
}

int main() {
    Rectangle r1(2, 3);
    cout << "Area of Rectangle 1: " << r1.area() << endl;

    Rectangle r2 = scale(r1, 2);
    cout << "Area of Rectangle 2: " << r2.area() << endl;

    Rectangle r3 = swap(r2);
    cout << "Area of Rectangle 3: " << r3.area() << endl;
  return 0;
}
