#include "include/rectangle.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std;

void bersih()
{
    system("cls or clear");
}

int main()
{
    int choice;
    float width, height, pX, pY;
    PersegiPanjang simpan, sementara;

    bersih();
    // Object PersegiPanjang 1
    cout << "Titik tengah X    : ";
    cin >> pX;
    cout << "Titik tengah Y    : ";
    cin >> pY;
    cout << "Panjang Persegi 1 : ";
    cin >> width;
    cout << "Lebar Persegi 1   : ";
    cin >> height;
    PersegiPanjang kotak1(pX, pY, width, height);

    bersih();
    // Object PersegiPanjang 2
    cout << "Titik tengah X    : ";
    cin >> pX;
    cout << "Titik tengah Y    : ";
    cin >> pY;
    cout << "Panjang Persegi 2 : ";
    cin >> width;
    cout << "Lebar Persegi 2   : ";
    cin >> height;
    PersegiPanjang kotak2(pX, pY, width, height);

    bersih();
    cout << "Nilai Awal Persegi Panjang 1" << endl;
    kotak1.print();
    cin.ignore();
    cin.ignore();

    cout << "Nilai Awal Persegi Panjang 2" << endl;
    kotak2.print();
    cin.ignore();

    while (1)
    {
        bersih();
        cout << "Masukkan Operator Overload: " << endl;
        cout << "1. \'+\' " << endl;
        cout << "2. \'-\' " << endl;
        cout << "3. \'++\' " << endl;
        cout << "4. \'--\' " << endl;
        cout << "5. \'[]\' " << endl;
        cout << "6. \'==\' " << endl;
        cout << "7. Edit Properti Persegi Panjang." << endl;

        cout << "\nPilihan: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            simpan = kotak1 + kotak2;
            if (kotak1 == kotak2)
            {
                cout << "\n Hasil Operator \'+\' dari 2 Persegi Panjang: \n";
                simpan.print();
                cin.ignore();
                cin.ignore();
            }
            else
            {
                cout << "Persegi Panjang tidak saling overlap" << endl;
            }
        }
        break;

        case 2:
        {
            simpan = kotak1 - kotak2;
            if (kotak1 == kotak2)
            {
                cout << " Hasil Operator \'-\' dari 2 Persegi Panjang: \n";
                simpan.print();
            }
            else
            {
                cout << "Persegi Panjang tidak saling overlap" << endl;
            }
        }
        break;

        case 3:
        {
            bersih();
            sementara = kotak1;
            kotak1++;
            cout << "Hasil Operator \'++\' dari Persegi Panjang 1:" << endl;
            kotak1.print();
            kotak1 = sementara;
            cin.ignore();
            cin.ignore();

            bersih();
            sementara = kotak2;
            kotak2++;
            cout << "Hasil Operator \'++\' dari Persegi Panjang 2 ++" << endl;
            kotak2.print();
            kotak2 = sementara;
            cin.ignore();
            break;
        }
        case 4:
        {
            bersih();
            sementara = kotak1;
            kotak1--;
            cout << "Hasil Operator \'--\' dari Persegi Panjang 1:" << endl;
            kotak1.print();
            kotak1 = sementara;
            cin.ignore();

            bersih();
            sementara = kotak2;
            kotak2--;
            cout << "Hasil Operator \'--\' dari Persegi Panjang 2 ++" << endl;
            kotak2.print();
            kotak2 = sementara;
            cin.ignore();
            break;
        }

        case 5:
        {
            bersih();
            int nilai;
            cout << "Lihat Nilai X dan Y" << endl;
            cout << "1. X Max" << endl;
            cout << "2. X Min" << endl;
            cout << "3. Y Max" << endl;
            cout << "4. Y Min" << endl;
            cout << "\n Pilihanmu: ";
            cin >> nilai;

            switch (nilai)
            {
            case 1:
            {
                cout << "Nilai X Max Persegi Panjang 1: " << kotak1[3] << endl;
                cout << "Nilai X Max Persegi Panjang 2: " << kotak2[3] << endl;
                cin.ignore();
                cin.ignore();
            }
            break;
            case 2:
            {
                cout << "Nilai X Min Persegi Panjang 1: " << kotak1[1] << endl;
                cout << "Nilai X Min Persegi Panjang 2: " << kotak2[1] << endl;
                cin.ignore();
                cin.ignore();
            }
            break;
            case 3:
            {
                cout << "Nilai Y Max Persegi Panjang 1: " << kotak1[2] << endl;
                cout << "Nilai Y Max Persegi Panjang 2: " << kotak2[2] << endl;
                cin.ignore();
                cin.ignore();
            }
            break;
            case 4:
            {
                cout << "Nilai Y Min Persegi Panjang 1: " << kotak1[4] << endl;
                cout << "Nilai Y Min Persegi Panjang 2: " << kotak2[4] << endl;
                cin.ignore();
                cin.ignore();
            }
            break;
            }
        }

        case 6:
        {
            if (kotak1 == kotak2)
            {
                bersih();
                cout << "Persegi Panjang Beririsan" << endl;
                cin.ignore();
                cin.ignore();
                break;
            }
            else
            {
                bersih();
                cout << "Persegi Panjang Tidak Beririsan" << endl;
                cin.ignore();
                cin.ignore();
                return 0;
            }
        }
        case 7:
        {
            return main();
        }

        break;
        }
    }
}
