// test2.cpp - test2

// Date   : 2020/12/09
#include <iostream>

class Rectangle {
public:
    explicit Rectangle(double length, double width): length_(length),
                                                     width_(width)
        {};

    double Length() const {
        return length_;
    }
    double Width() const {
        return width_;
    }
    void Scale(double sl, double sw) {
        length_ *= sl;
        width_ *= sw;
    }

private:
    double length_;
    double width_;
};

class Square: public Rectangle {
public:
    explicit Square(double n): Rectangle(n, n) {};
    void Scale(double s) {
        Rectangle::Scale(s, s);
    }
};

int main(void)
{
    Rectangle *a = new Square(3.0);

    std::cout << a->Length() << " " << a->Width() << std::endl;
    static_cast<Square *>(a)->Scale(1.2);
    std::cout << a->Length() << " " << a->Width() << std::endl;

    return 0;
}
