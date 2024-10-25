#include <iostream>
using namespace std;

struct car{
    double price;
    int fuel;
};

int getFuel(car c1);
int addFuel(car c1, car f1);

int main(){
    car Mustang;
    car Dodge;

    Mustang.fuel = 12;
    Mustang.price = 39999.99;
    Dodge.fuel = 10;
    Dodge.price = 34999.99;

    cout << "Mustang Fuel: " << Mustang.fuel << endl;
    cout << "Dodge Fuel: " << Dodge.fuel << endl;

    cout << addFuel(Mustang, Dodge);

    return 0;
}

int getFuel(car c1){
    return c1.fuel;
}

int addFuel(car c1, car c2){
    return (c1.fuel + c2.fuel);
}