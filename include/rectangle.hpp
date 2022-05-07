#ifndef __RECTANGLE__HPP__
#define __RECTANGLE__HPP__
#include <iostream>

class PersegiPanjang
{
    // Accessible only inside class
private:
    float x_min, x_max, y_max, y_min;

    // Accessible for everyone
public:
    PersegiPanjang();
    PersegiPanjang(float titikTengahX, float titikTengahY, float panjang, float lebar);
    bool operator==(PersegiPanjang const &) const;
    void operator++();
    void operator++(int);
    void operator--();
    void operator--(int);
    void print();
    PersegiPanjang operator+(PersegiPanjang const &);
    PersegiPanjang operator-(PersegiPanjang const &);
    float operator[](int op);
};

#endif