/**
 * @file Polynomka.cpp
 * @brief Реализация методов класса Polynomka
 */

#include "Polynomka.h"
#include <iostream>
#include <cmath>

using namespace std;

std::size_t Polynomka::rootsCalculationCounter_ = 0;

// Конструктор по умолчанию
Polynomka::Polynomka() : a_(0), b_(0), c_(0) {
    cout << "Вызван конструктор по умолчанию. Создан многочлен: 0x² + 0x + 0" << endl;
}

// Параметризованный конструктор
Polynomka::Polynomka(double a, double b, double c) : a_(a), b_(b), c_(c) {
    cout << "Вызван параметризованный конструктор. Создан многочлен: ";
    print();
}

// Конструктор копирования
Polynomka::Polynomka(const Polynomka& other) : a_(other.a_), b_(other.b_), c_(other.c_) {
    cout << "Вызван конструктор копирования. Скопирован многочлен: ";
    print();
}

// Деструктор
Polynomka::~Polynomka() {
    cout << "Вызван деструктор. Уничтожен многочлен: ";
    print();
}


void Polynomka::setCoefficients(double a, double b, double c) {
    a_ = a;
    b_ = b;
    c_ = c;
}

// Вычисление значения в точке x
double Polynomka::evaluate(double x) const {
    return a_ * x * x + b_ * x + c_;
}

// корней многочлена
void Polynomka::findRoots() const {
    rootsCalculationCounter_++; 
    
    cout << "Поиск корней для: ";
    print();
    
    if (a_ == 0) {
        if (b_ == 0) {
            if (c_ == 0) {
                cout << "  Бесконечное количество корней (нулевой многочлен)" << endl;
            } else {
                cout << "  Нет корней" << endl;
            }
        } else {
            double root = -c_ / b_;
            cout << "  Один корень: x = " << root << endl;
        }
    } else {
        double discriminant = b_ * b_ - 4 * a_ * c_;
        
        if (discriminant > 0) {
            double root1 = (-b_ + sqrt(discriminant)) / (2 * a_);
            double root2 = (-b_ - sqrt(discriminant)) / (2 * a_);
            cout << "  Два корня: x1 = " << root1 << ", x2 = " << root2 << endl;
        } else if (discriminant == 0) {
            double root = -b_ / (2 * a_);
            cout << "  Один корень: x = " << root << endl;
        } else {
            cout << "  Действительных корней нет" << endl;
        }
    }
    cout << "  (Всего поисков корней: " << rootsCalculationCounter_ << ")" << endl;
}

std::size_t Polynomka::getRootsCalculationCount() {
    return rootsCalculationCounter_;
}

// (++poly)
Polynomka& Polynomka::operator++() {
    a_ += 1;
    b_ += 1; 
    c_ += 1;
    return *this;
}

// (poly++)
Polynomka Polynomka::operator++(int) {
    Polynomka temp(a_, b_, c_);
    a_ += 1;
    b_ += 1;
    c_ += 1;
    return temp;
}

//  (--poly)
Polynomka& Polynomka::operator--() {
    a_ -= 1;
    b_ -= 1;
    c_ -= 1;
    return *this;
}

//  (poly--)
Polynomka Polynomka::operator--(int) {
    Polynomka temp(a_, b_, c_);
    a_ -= 1;
    b_ -= 1;
    c_ -= 1;
    return temp;
}

// +=
Polynomka& Polynomka::operator+=(const Polynomka& other) {
    a_ += other.a_;
    b_ += other.b_;
    c_ += other.c_;
    return *this;
}

// -=
Polynomka& Polynomka::operator-=(const Polynomka& other) {
    a_ -= other.a_;
    b_ -= other.b_;
    c_ -= other.c_;
    return *this;
}

// *=
Polynomka& Polynomka::operator*=(double scalar) {
    a_ *= scalar;
    b_ *= scalar;
    c_ *= scalar;
    return *this;
}

// /=
Polynomka& Polynomka::operator/=(double scalar) {
    if (scalar != 0) {
        a_ /= scalar;
        b_ /= scalar;
        c_ /= scalar;
    }
    return *this;
}

// +
Polynomka operator+(Polynomka lhs, const Polynomka& rhs) {
    lhs += rhs; // Используем operator+=
    return lhs;
}

// -
Polynomka operator-(Polynomka lhs, const Polynomka& rhs) {
    lhs -= rhs; // Используем operator-=
    return lhs;
}

// * (умножение скаляр)
Polynomka operator*(Polynomka lhs, double scalar) {
    lhs *= scalar; // Используем operator*=
    return lhs;
}

// / (деление н скаляр)
Polynomka operator/(Polynomka lhs, double scalar) {
    lhs /= scalar; // Используем operator/=
    return lhs;
}

// Бинарные операторы сравнения

// <
bool Polynomka::isLessThan(const Polynomka& other, double x) const {
    return this->evaluate(x) < other.evaluate(x);
}

// >
bool Polynomka::isGreaterThan(const Polynomka& other, double x) const {
    return this->evaluate(x) > other.evaluate(x);
}

// <=
bool Polynomka::isLessOrEqual(const Polynomka& other, double x) const {
    return this->evaluate(x) <= other.evaluate(x);
}

// >=
bool Polynomka::isGreaterOrEqual(const Polynomka& other, double x) const {
    return this->evaluate(x) >= other.evaluate(x);
}

// ==
bool Polynomka::isEqual(const Polynomka& other, double x) const {
    return this->evaluate(x) == other.evaluate(x);
}

// !=
bool Polynomka::isNotEqual(const Polynomka& other, double x) const {
    return this->evaluate(x) != other.evaluate(x);
}

void Polynomka::print() const {
    cout << a_ << "x²";
    if (b_ >= 0) cout << " + " << b_ << "x";
    else cout << " - " << -b_ << "x";
    if (c_ >= 0) cout << " + " << c_;
    else cout << " - " << -c_;
    cout << endl;
}