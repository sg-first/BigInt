#pragma once
#include <iostream>
#include <string>
#include "bigint.hpp"
using namespace std;

class Fraction
{
private:
    BigInt numerator;
    BigInt denominator;

    //转换小数的保留位数，二者要一致
    const static unsigned int dicDight=5;
    const static unsigned int dicSize=100000;

    static bool isDiv(BigInt n1, BigInt n2)
    {
        return n1%n2==0;
    }
    bool isInt() const
    {
        return isDiv(this->numerator,this->denominator);
    }

    static BigInt measure(BigInt x, BigInt y)
    {
        BigInt z = y;
        while(x%y!=0)
        {
            z = x%y;
            x = y;
            y = z;
        }
        return z;
    }

    void simplification()
    {
        BigInt divNum=measure(this->numerator,this->denominator);
        if(divNum>1)
        {
            this->numerator/=divNum;
            this->denominator/=divNum;
        }
    }

public:
    Fraction(const Fraction& r) : numerator(r.numerator), denominator(r.denominator) { this->simplification(); }
    Fraction(const BigInt numerator=1, const BigInt denominator=2) : numerator(numerator), denominator(denominator)
    {
        if(denominator==0)
            throw 0;
        else
            this->simplification();
    }

    operator string() const
    {
        if(this->numerator==0)
            return "0";
        else
        {
            string intType=(numerator*dicSize/denominator).to_string();
            string left=intType.substr(0,intType.size()-dicDight);
            string right=intType.substr(intType.size()-dicDight);
            return left+"."+right;
        }
    }

    friend Fraction operator+(const Fraction &n1, const int n2)
    {
        return Fraction(n1.denominator*n2+n1.numerator, n1.denominator);
    }
    friend Fraction operator+(const int n1, const Fraction &n2)
    {
        return n2+n1;
    }
    friend Fraction operator+(const Fraction &n1, const Fraction &n2)
    {
        BigInt newDen=n1.denominator*n2.denominator;
        if(newDen==0)
            throw 0;
        BigInt newNum=n1.numerator*n2.denominator+n2.numerator*n1.denominator;
        return Fraction(newNum,newDen);
    }

    friend Fraction operator*(const Fraction &n1, const int n2)
    {
        return Fraction(n1.numerator*n2,n1.denominator);
    }
    friend Fraction operator*(const int n1, const Fraction &n2)
    {
        return n2*n1;
    }
    friend Fraction operator*(const Fraction &n1, const Fraction &n2)
    {
        return Fraction(n1.numerator*n2.numerator,n1.denominator*n2.denominator);
    }

    friend Fraction operator/(const Fraction &n1,const int n2)
    {
        return Fraction(n1.numerator,n1.denominator*n2);
    }
    friend Fraction operator/(const int n1, const Fraction &n2)
    {
        return Fraction(n1*n2.denominator,n2.numerator);
    }
    friend Fraction operator/(const Fraction &n1, const Fraction &n2)
    {
        return Fraction(n1.numerator*n2.denominator,n1.denominator*n2.numerator);
    }

    friend Fraction operator-(const Fraction &n1, const int n2)
    {
        return n1+(-n2);
    }
    friend Fraction operator-(const int n1, const Fraction &n2)
    {
        return n2+(-n1);
    }
    Fraction operator-() const
    {
        return Fraction(-numerator,denominator);
    }
    friend Fraction operator-(const Fraction &n1, const Fraction &n2)
    {
        Fraction temp(-n2);
        return n1+temp;
    }

    Fraction& operator--(int)
    {
        this->numerator-=this->denominator;
        return *this;
    }
    Fraction& operator++(int)
    {
        this->numerator+=this->denominator;
        return *this;
    }
    Fraction& operator=(const Fraction& r)
    {
        this->numerator=r.numerator;
        this->denominator=r.denominator;
        return *this;
    }
    Fraction& operator=(const int r)
    {
        this->numerator=r;
        this->denominator=1;
        return *this;
    }

    friend ostream& operator<<(ostream& output, const Fraction& c)
    {
       if(c.isInt())
           output<<(string)c;
       else
           output<<c.numerator<<"/"<<c.denominator;
       return output;
    }
};