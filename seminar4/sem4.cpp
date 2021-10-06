#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int GCD(int x, int y) {
    if (y % x == 0){
        return x;
    }
    if (x % y == 0){
        return y;
    }
    if (x > y){
        return GCD(x%y, y);
    }
    else{
        return GCD(x, y%x);
    }
}


class Fraction{
public:
    explicit Fraction(int x = 0, int y = 1): x_(x), y_(y) {
        int nod = GCD(abs(x_), abs(y_));
        if (y_ < 0){
            x_ = -x_;
            y_ = -y_;
        }
        else if (y_ == 0){
            throw runtime_error("Number cannot be divisible by zero");
        }
        if (nod!= 1){
            x_ = x_ / nod;
            y_ = y_ / nod;
        }
    };
    friend ostream& operator<<(ostream& dest, const Fraction& c) {
        dest << c.x_ << " / " << c.y_ << endl;
        return dest;
    }
    Fraction& operator*=(const Fraction& other){
        x_ = x_ * other.x_;
        y_ = y_ * other.y_;
        int nod = GCD(x_, y_);
        if (nod!= 1){
            x_ = x_ / nod;
            y_ = y_ / nod;
        }
        return *this;
    }
    friend Fraction operator*(Fraction a, const Fraction& b){
        a *= b;
        return a;
    }
    Fraction& operator/=(const Fraction& other){
        x_ = x_ * other.y_;
        y_ = y_ * other.x_;
        int nod = GCD(x_, y_);
        if (nod!= 1){
            x_ = x_ / nod;
            y_ = y_ / nod;
        }
        return *this;
    }
    friend Fraction operator/(Fraction a, const Fraction& b){
        a /= b;
        return a;
    }
    Fraction& operator+=(const Fraction& other){
        x_ = x_ * other.y_ + other.x_ * y_;
        y_ = other.y_ * y_;
        int nod = GCD(x_, y_);
        if (nod!= 1){
            x_ = x_ / nod;
            y_ = y_ / nod;
        }
        return *this;
    }
    friend Fraction operator+(Fraction a, const Fraction& b){
        a += b;
        return a;
    }
    Fraction& operator-=(const Fraction& other){
        x_ = x_ * other.y_ - other.x_ * y_;
        y_ = other.y_ * y_;
        int nod = GCD(x_, y_);
        if (nod!= 1){
            x_ = x_ / nod;
            y_ = y_ / nod;
        }
        return *this;
    }
    friend Fraction operator-(Fraction a, const Fraction& b){
        a -= b;
        return a;
    }
    friend bool operator<(const Fraction& a, const Fraction& b){
        double fraction1 = (a.x_ * 1.0) / (a.y_ * 1.0);
        double fraction2 = (b.x_ * 1.0)/ (b.y_ * 1.0);
        return fraction1 < fraction2;
    }
    friend bool operator>(const Fraction& a, const Fraction& b){
        double fraction1 = (a.x_ * 1.0) / (a.y_ * 1.0);
        double fraction2 = (b.x_ * 1.0)/ (b.y_ * 1.0);
        return fraction1 > fraction2;
    }
    friend bool operator==(const Fraction& a, const Fraction& b){
        double fraction1 = (a.x_ * 1.0) / (a.y_ * 1.0);
        double fraction2 = (b.x_ * 1.0)/ (b.y_ * 1.0);
        return fraction1 == fraction2;
    }

    Fraction operator!() const{
        Fraction u(-x_, y_);
        return u;
    }
private:
    int x_, y_;
};


int main()
{
    Fraction x(100, 10);
    Fraction y(5, 4);
    y = !x;
    cout << "numerator = " << x;
    cout << "denominator = " << y;
    return 0;
}
