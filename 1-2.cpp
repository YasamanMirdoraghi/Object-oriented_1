#include <iostream>

using namespace std;

class Complex
{
public:
    float real;
    float imag;
    Complex(float = 0, float = 0);
    void print();
    static Complex Sum(Complex, Complex);
    static Complex Sub(Complex, Complex);
    static Complex Multiple(Complex, Complex);
    static Complex Divide(Complex, Complex);
};

Complex Complex::Sum(Complex r1, Complex r2)// tabe SUM
{ 
    Complex all;
    all.real = r1.real + r2.real;
    all.imag = r1.imag + r2.imag;
    return all;
}
Complex Complex::Sub(Complex r1, Complex r2) // tabe SUB
{
    Complex all;
    all.real = r1.real - r2.real;
    all.imag = r1.imag - r2.imag;
    return all;
}
Complex Complex::Multiple(Complex r1, Complex r2) // tabe MULT
{
    Complex all;
    all.real = (r1.real * r2.real) - (r1.imag * r2.imag);
    all.imag = (r1.real * r2.imag) + (r1.imag * r2.real);
    return all;
}
Complex Complex::Divide(Complex r1, Complex r2) // tabe DIV
{
    Complex all;
    if ((r2.real * r2.real) == 0 && (r2.imag * r2.imag) == 0)
    {
        cout << " Error Division by zero!" << endl;
        exit(-1);
    }
    else
    {
        float m = (r2.real * r2.real) + (r2.imag * r2.imag);
        all.real = ((r1.real * r2.real) + (r1.imag * r2.imag)) / m;
        all.imag = ((r1.imag * r2.real) - (r1.real * r2.imag)) / m;
        return all;
    }
}
Complex::Complex(float real, float imag) // Generator
{
    this->imag = imag;
    this->real = real;
}
void Complex::print() //Print
{
    string f = to_string(imag);
    size_t found = f.find('-');

    if (real == 0 && imag == 0)
        cout << 0;
    else if (real == 0 && imag != 0)
    {
        if (found != string::npos)
            cout << imag << "i" << endl;
        else
            cout << "+" << imag << "i" << endl;
    }
    else if (imag == 0 && real != 0)
    {
        if (found != string::npos)
            cout << real<< endl;
        else
            cout << "+" << real << endl;
    }
    else if (found != string::npos)
        cout << real << imag << "i" << endl;
    else
        cout << real << "+" << imag << "i" << endl;
}

int main()
{
    Complex n1(2, -2);
    Complex n2(2, -1);
    cout<<"*******************************************************";
    cout << "\nComplex Number1:";
    n1.print();
    cout << "Complex Number2:";
    n2.print();

    cout<<"*******************************************************";
    cout << "\nThe Sum Of Complex Number:";
    Complex t1 = Complex::Sum(n1,n2);
    t1.print();

    cout<<"*******************************************************";
    cout << "\nSubtraction Of Complex Number:";
    Complex t2 = Complex::Sub(n1, n2);
    t2.print();

    cout<<"*******************************************************";
    cout << "\nMultiplication Of Complex Number:";
    Complex t3 = Complex::Multiple(n1, n2);
    t3.print();

    cout<<"*******************************************************";
    cout << "\nDivision Of Complex Number:";
    Complex t4 = Complex::Divide(n1, n2);
    t4.print();
    cout<<"*******************************************************";
    cout << "\n";
}