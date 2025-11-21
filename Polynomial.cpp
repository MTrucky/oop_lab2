/**
 * @file Polynomial.cpp
 * @brief Реализация методов класса Polynomial
 */

 #include "Polynomial.h"
 #include <iostream>
 #include <cmath>
 
 using namespace std;
 
 std::size_t Polynomial::rootsCalculationCounter_ = 0;
 
 Polynomial::Polynomial() : a_(0), b_(0), c_(0) {
 }
 
 Polynomial::Polynomial(double a, double b, double c) : a_(a), b_(b), c_(c) {
    //  print();
 }
 
 Polynomial::Polynomial(const Polynomial& other) : a_(other.a_), b_(other.b_), c_(other.c_) {
    //  print();
 }
 
 Polynomial::~Polynomial() {
    //  print();
 }
 
 void Polynomial::setCoefficients(double a, double b, double c) {
     a_ = a;
     b_ = b;
     c_ = c;
 }
 
 double Polynomial::evaluate(double x) const {
     return a_ * x * x + b_ * x + c_;
 }
 
 void Polynomial::findRoots() const {
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
 
 std::size_t Polynomial::getRootsCalculationCount() {
     return rootsCalculationCounter_;
 }
 
 // (++poly)
 Polynomial& Polynomial::operator++() {
     a_ += 1;
     b_ += 1; 
     c_ += 1;
     return *this;
 }
 
 // (poly++)
 Polynomial Polynomial::operator++(int) {
     Polynomial temp(a_, b_, c_);
     a_ += 1;
     b_ += 1;
     c_ += 1;
     return temp;
 }
 
 //  (--poly)
 Polynomial& Polynomial::operator--() {
     a_ -= 1;
     b_ -= 1;
     c_ -= 1;
     return *this;
 }
 
 //  (poly--)
 Polynomial Polynomial::operator--(int) {
     Polynomial temp(a_, b_, c_);
     a_ -= 1;
     b_ -= 1;
     c_ -= 1;
     return temp;
 }
 
 // +=
 Polynomial& Polynomial::operator+=(const Polynomial& other) {
     a_ += other.a_;
     b_ += other.b_;
     c_ += other.c_;
     return *this;
 }
 
 // -=
 Polynomial& Polynomial::operator-=(const Polynomial& other) {
     a_ -= other.a_;
     b_ -= other.b_;
     c_ -= other.c_;
     return *this;
 }
 
 // *=
 Polynomial& Polynomial::operator*=(double scalar) {
     a_ *= scalar;
     b_ *= scalar;
     c_ *= scalar;
     return *this;
 }
 
 // /=
 Polynomial& Polynomial::operator/=(double scalar) {
     if (scalar != 0) {
         a_ /= scalar;
         b_ /= scalar;
         c_ /= scalar;
     }
     return *this;
 }
 
 // + 
 Polynomial Polynomial::operator+(const Polynomial& other) const {
     Polynomial result(*this);
     result += other;
     return result;
 }
 
 // - 
 Polynomial Polynomial::operator-(const Polynomial& other) const {
     Polynomial result(*this);
     result -= other;
     return result;
 }
 
 // * 
 Polynomial Polynomial::operator*(double scalar) const {
     Polynomial result(*this);
     result *= scalar;
     return result;
 }
 
 // / 
 Polynomial Polynomial::operator/(double scalar) const {
     Polynomial result(*this);
     result /= scalar;
     return result;
 }
 
 
 // <
 bool Polynomial::operator<(const Polynomial& other) const {
     double x;
     cout << "Введите значение x для сравнения: ";
     cin >> x;
     
     double value1 = evaluate(x);
     double value2 = other.evaluate(x);
     
     cout << "Значение poly1 в точке " << x << ": " << value1 << endl;
     cout << "Значение poly2 в точке " << x << ": " << value2 << endl;
     
     return value1 < value2;
 }
 
 // >
 bool Polynomial::operator>(const Polynomial& other) const {
     double x;
     cout << "Введите значение x для сравнения: ";
     cin >> x;
     
     double value1 = evaluate(x);
     double value2 = other.evaluate(x);
     
     cout << "Значение poly1 в точке " << x << ": " << value1 << endl;
     cout << "Значение poly2 в точке " << x << ": " << value2 << endl;
     
     return value1 > value2;
 }
 
 // <=
 bool Polynomial::operator<=(const Polynomial& other) const {
     double x;
     cout << "Введите значение x для сравнения: ";
     cin >> x;
     
     double value1 = evaluate(x);
     double value2 = other.evaluate(x);
     
     cout << "Значение poly1 в точке " << x << ": " << value1 << endl;
     cout << "Значение poly2 в точке " << x << ": " << value2 << endl;
     
     return value1 <= value2;
 }
 
 // >=
 bool Polynomial::operator>=(const Polynomial& other) const {
     double x;
     cout << "Введите значение x для сравнения: ";
     cin >> x;
     
     double value1 = evaluate(x);
     double value2 = other.evaluate(x);
     
     cout << "Значение poly1 в точке " << x << ": " << value1 << endl;
     cout << "Значение poly2 в точке " << x << ": " << value2 << endl;
     
     return value1 >= value2;
 }
 
 // ==
 bool Polynomial::operator==(const Polynomial& other) const {
     double x;
     cout << "Введите значение x для сравнения: ";
     cin >> x;
     
     double value1 = evaluate(x);
     double value2 = other.evaluate(x);
     
     cout << "Значение poly1 в точке " << x << ": " << value1 << endl;
     cout << "Значение poly2 в точке " << x << ": " << value2 << endl;
     
     return value1 == value2;
 }
 
 // !=
 bool Polynomial::operator!=(const Polynomial& other) const {
     double x;
     cout << "Введите значение x для сравнения: ";
     cin >> x;
     
     double value1 = evaluate(x);
     double value2 = other.evaluate(x);
     
     cout << "Значение poly1 в точке " << x << ": " << value1 << endl;
     cout << "Значение poly2 в точке " << x << ": " << value2 << endl;
     
     return value1 != value2;
 }
 
 void Polynomial::print() const {
     cout << a_ << "x²";
     if (b_ >= 0) cout << " + " << b_ << "x";
     else cout << " - " << -b_ << "x";
     if (c_ >= 0) cout << " + " << c_;
     else cout << " - " << -c_;
     cout << endl;
 }