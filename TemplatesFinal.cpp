#include<iostream>
using namespace std;

template <typename my_type>
void swapValues(my_type& t1, my_type& t2){
    my_type temp = t1;
    t1 = t2;
    t2 = temp;
}

void test(int& a1, int& a2);

int main(){
    double d1 = 5.25;
    double d2 = 10.23;
    string s1 = "Bob";
    string s2 = "McQueen";

    cout << "d1: " << d1 << endl;
    cout << "d2: " << d2 << endl;

    swapValues(d1, d2);

    cout << "d1: " << d1 << endl;
    cout << "d2: " << d2 << endl;

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    swapValues(s1, s2);
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    int a1 = 1;
    int a2 = 2;

    test(a1, a2);
    cout << "a1: " << a1 << "\ta2: " << a2 << endl;
    
    return 0;
}

void test(int& a1, int& a2){
    a1 = 10;
    a2 = 20;
    cout << "a1: " << a1 << "\ta2: " << a2 << endl;
}