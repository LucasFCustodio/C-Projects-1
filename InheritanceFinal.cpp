//Include <iostream> which allows you to put input and output
#include<iostream>

//include <iomanip> which allows you to print the decimal places
#include <iomanip>
//namespace std is the namespace cin and cout are located in. Including them here means that their scope is the entire program
using namespace std;

//class definition
class Vehicle {
    public:
    Vehicle(int h, double p);
    Vehicle();
    void setPower(int h);
    void setPrice(double p);
    int  getPower();
    double getPrice();
    friend bool operator ==(Vehicle v1, Vehicle v2);

    private:
    int horsepower;
    double price;
};

class Ford : public Vehicle{
    public:
    Ford(string m, int y);
    void setModel(string m);
    void setYear(int y);
    string getModel();
    int getYear();
    friend bool operator ==(Ford v1, Ford v2);

    private:
    string model;
    int year;
};


int main(){
    Vehicle Car(250, 20000.00);
    cout << "Power: " << Car.getPower() << endl;
    cout << "Price: " << Car.getPrice() << endl;

    Ford Mustang("Mustang", 2018);
    cout << "Model: " << Mustang.getModel() << endl;
    cout << "Year: " << Mustang.getYear() << endl;
    cout << "Horsepower: " << Mustang.getPower() << endl;
    cout << "Price: " << Mustang.getPrice() << endl;
    Mustang.setPower(250);
    cout << "New Power: " << Mustang.getPower() << endl;
    Mustang.setPrice(20000.00);
    cout << "New Price" << Mustang.getPrice() << endl;

    Ford Bronco("Bronco", 2023);
    Bronco.setPower(450);
    Bronco.setPrice(55000);
    cout << "Bronco hp: " << Bronco.getPower() << endl;

    Ford MachE("Mustang Mach E", 2024);
    MachE.setPower(550);
    MachE.setPrice(45000);
    cout << "\n\nMustang Mach E is equal to Mustang GT: " << (Mustang==MachE) << endl;
    cout << "\nMachE is equal to Bronco: " << (MachE==Bronco) << endl;
    cout << "\nCar is equal to Mustang GT: " << (Car==Mustang) << endl;

    Ford MustangX("Mustang X", 2030);
    cout << "Mustang X: " << MustangX.getModel() << "\t" << MustangX.getYear() << "\t"
    << MustangX.getPower() << "\t" << MustangX.getPrice() << endl;

    MustangX.setPower(1600);
    MustangX.setPrice(20.25);

    cout << "Mustang X: " << MustangX.getModel() << "\t" << MustangX.getYear() << "\t"
    << MustangX.getPower() << "\t" << MustangX.getPrice() << endl;

    //cout << "\n\nVehicle 1 is equal to Vehicle 2: " << (Mustang==Bronco) << endl;

    return 0;
}


//Function declarations for the Vehicle Class
//Constructors need to repeat the name of the class once
//DOn't forget the scope resolution operator
Vehicle::Vehicle(int h, double p){
    horsepower = h;
    price = p;
}

Vehicle::Vehicle(){
    horsepower = 200;
    price = 19999.99;
}

void Vehicle::setPower(int h){
    horsepower = h;
}

void Vehicle::setPrice(double p){
    price = p;
}

int Vehicle::getPower(){
    return horsepower;
}

double Vehicle::getPrice(){
    return price;
}

bool operator ==(Vehicle v1, Vehicle v2){
    return (v1.horsepower == v2.horsepower && v1.price == v2.price);
}

bool operator ==(Ford v1, Ford v2){
    return (v1.year == v2.year);
}

Ford::Ford(string m, int y){
    model = m;
    year = y;
    Vehicle();
}

void Ford::setModel(string m){
    model = m;
}

void Ford::setYear(int y){
    year = y;
}

string Ford::getModel(){
    return model;
}

int Ford::getYear(){
    return year;
}