#include <iostream>
#include <sstream>

using namespace std;

class Complex
{
    friend Complex Sum(Complex, Complex);
    friend Complex Sub(Complex, Complex);
    friend Complex Multiple(Complex, Complex);
    friend Complex Divide(Complex, Complex);

public:
    float real;
    float imag;
    Complex(float = 0, float = 0);
    void print();
};

Complex::Complex(float real, float imag) // Gnerator
{
    this->real = real;
    this->imag = imag;
}

void Complex::print() // Print
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
            cout << real << endl;
        else
            cout << "+" << real << endl;
    }
    else if (found != string::npos)
        cout << real << imag << "i" << endl;
    else
        cout << real << "+" << imag << "i" << endl;
}

Complex Sum(Complex r1, Complex r2) // tabe SUM
{
    Complex all;
    all.real = r1.real + r2.real;
    all.imag = r1.imag + r2.imag;
    return all;
}
Complex Sub(Complex r1, Complex r2) // tabe SUB
{
    Complex all;
    all.real = r1.real - r2.real;
    all.imag = r1.imag - r2.imag;
    return all;
}

Complex Multiple(Complex r1, Complex r2) // tabe MUL
{
    Complex all;
    all.real = (r1.real * r2.real) - (r1.imag * r2.imag);
    all.imag = (r1.real * r2.imag) + (r1.imag * r2.real);
    return all;
}
Complex Divide(Complex r1, Complex r2) // tabe DIV
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
int main()
{
    Complex n1(4, 2);
    Complex n2(2, -1);

    cout << "*******************************************************";
    cout << "\nComplex Number1:";
    n1.print();
    cout << "Complex Number2:";
    n2.print();

    cout << "*******************************************************";
    cout << "\nThe Sum Of Complex Number: ";
    Complex t1 = Sum(n1, n2);
    t1.print();

    cout << "*******************************************************";
    cout << "\nSubtraction Of Complex Number: ";
    Complex t2 = Sub(n2, n2);
    t2.print();

    cout << "*******************************************************";
    cout << "\nMultiplication Of Complex Number: ";
    Complex t3 = Multiple(n1, n2);
    t3.print();

    cout << "*******************************************************";
    cout << "\nDivision Of Complex Number: ";
    Complex t4 = Divide(n1, n1);
    t4.print();
    cout << "*******************************************************";
}