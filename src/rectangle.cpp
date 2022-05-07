#include <iostream>
#include <cmath>
#include "include/rectangle.hpp"

PersegiPanjang::PersegiPanjang(){} // Calling PersegiPanjang Class from Header file

// Menentukan Nilai Max dan Nilai Min
PersegiPanjang::PersegiPanjang(float titikTengahX, float titikTengahY, float panjang, float lebar)
{
    this->x_min = titikTengahX - (panjang/2);
    this->x_max = titikTengahX + (panjang/2);
    this->y_min = titikTengahY - (lebar/2);
    this->y_max = titikTengahY + (lebar/2);
    // nilai x dan y disimpan ke dalam array pointer
}

// Determine the PersegiPanjang whether overlap each other or not
bool PersegiPanjang::operator==(const PersegiPanjang &overlap) const
{
    // overlap is reference to show that PersegiPanjang are overlapping
    if (this->x_max > overlap.x_min and this->x_min < overlap.x_max)
    {
        return true;
    }
    else if (this->y_max > overlap.y_min and this->y_min < overlap.y_max)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Operator + menambah luas PersegiPanjang
PersegiPanjang PersegiPanjang::operator+(PersegiPanjang const &overlap)
{
    // To make sure that the PersegiPanjang's position is starting from 0
    PersegiPanjang temp;
    // temp is temporary that means that value isn't permanently saved
    if (this->x_min < overlap.x_min)
    {
        temp.x_min = this->x_min;
    }
    else
    {
        temp.x_min = overlap.x_min;
    }

    if (this->x_max > overlap.x_max)
    {
        temp.x_max = this->x_max;
    }
    else
    {
        temp.x_max = overlap.x_max;
    }

    if (this->y_min < overlap.y_min)
    {
        temp.y_min = this->y_min;
    }
    else
    {
        temp.y_min = overlap.y_min;
    }

    if (this->y_max > overlap.y_max)
    {
        temp.y_max = this->y_max;
    }
    else
    {
        temp.y_max = overlap.y_max;
    }

    if (*this == overlap)
    {
        return temp;
    }
}

// Operator - mengambil irisan dari PersegiPanjang jika saling overlap
PersegiPanjang PersegiPanjang::operator-(PersegiPanjang const &overlap)
{
    // To make sure that the PersegiPanjang's position is starting from 0
    PersegiPanjang temp;
    // temp is temporary that means that value isn't permanently saved
    if (this->x_min > overlap.x_min)
    {
        temp.x_min = this->x_min;
    }
    else
    {
        temp.x_min = overlap.x_min;
    }

    if (this->x_max < overlap.x_max)
    {
        temp.x_max = this->x_max;
    }
    else
    {
        temp.x_max = overlap.x_max;
    }

    if (this->y_min > overlap.y_min)
    {
        temp.y_min = this->y_min;
    }
    else
    {
        temp.y_min = overlap.y_min;
    }

    if (this->y_max < overlap.y_max)
    {
        temp.y_max = this->y_max;
    }
    else
    {
        temp.y_max = overlap.y_max;
    }

    if (*this == overlap)
    {
        return temp;
    }
}

// Operator ++ memperbesar luas PersegiPanjang
void PersegiPanjang::operator++()
{
    float panjang , lebar , titikTengahX , titikTengahY ;
    panjang = abs(this->x_max - this->x_min);
    lebar = abs(this->y_max - this->y_min);
    titikTengahX = panjang / 2 + this->x_min;
    titikTengahY = lebar / 2 + this->y_min;
    // Lalu luasan persegi panjang menjadi 2 kali luasannya
    panjang = panjang * 2;
    lebar = lebar * 2;
    // Cara menentukkan titik-titik sumbu baru persegi tadi
    this->x_max = titikTengahX + panjang / 2;
    this->y_max = titikTengahY + lebar / 2;
    this->x_min = titikTengahX - panjang / 2;
    this->y_min = titikTengahY - lebar / 2;
}

// Operator -- memperkecil luas PersegiPanjang
void PersegiPanjang::operator--()
{
    float panjang , lebar , titikTengahX , titikTengahY ;
    panjang = abs(this->x_max - this->x_min);
    lebar = abs(this->y_max - this->y_min);
    titikTengahX = panjang / 2 + this->x_min;
    titikTengahY = lebar / 2 + this->y_min;
    // Lalu luasan persegi panjang menjadi 2 kali luasannya
    panjang = panjang / 2;
    lebar = lebar / 2;
    // Cara menentukkan titik-titik sumbu baru persegi tadi
    this->x_max = titikTengahX + panjang / 2;
    this->y_max = titikTengahY + lebar / 2;
    this->x_min = titikTengahX - panjang / 2;
    this->y_min = titikTengahY - lebar / 2;
}

void PersegiPanjang::operator++(int) {}
void PersegiPanjang::operator--(int) {}
float PersegiPanjang::operator[](int op)
{
    switch (op)
    {
    case 1:
        return this->x_min;
        break;

    case 2:
        return this->x_max;
        break;

    case 3:
        return this->y_min;
        break;

    case 4:
        return this->y_max;
        break;
    }
    return 0;
}

// Mengeluarkan hasil
void PersegiPanjang::print()
{
    float panjang , lebar , titikTengahX , titikTengahY ;
    // Menghitung Panjang dan Lebar based on titik x dan y
    panjang = this->x_max - this->x_min;
    lebar = this->y_max - this->y_min;

    panjang = abs(panjang);
    lebar = abs(lebar);

    titikTengahX = this->x_min + panjang / 2;
    titikTengahY = this->y_min + lebar / 2;

    std::cout << "Panjang              : " << panjang << std::endl;
    std::cout << "Lebar                : " << lebar << std::endl;
    std::cout << "Titik Tengah X       : " << titikTengahX << std::endl;
    std::cout << "Titik Tengah Y       : " << titikTengahY << std::endl;
    std::cout << "X Min                : " << this->x_min << std::endl;
    std::cout << "X Max                : " << this->x_max << std::endl;
    std::cout << "Y Min                : " << this->y_min << std::endl;
    std::cout << "Y Max                : " << this->y_max << std::endl;
}