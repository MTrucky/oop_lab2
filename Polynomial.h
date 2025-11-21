/**
 * @file Polynomial.h
 * @brief Заголовочный файл класса Polynomial для работы с многочленами 2-й степени
 */

 #ifndef POLYNOMIAL_H
 #define POLYNOMIAL_H
 
 #include <cstddef>
 
 /**
  * @class Polynomial
  * @brief Класс для работы с многочленами второй степени вида ax² + bx + c
  */
 class Polynomial {
 private:
     double a_; ///<  при x²
     double b_; ///<  при x  
     double c_; ///< Свободный
     
     static std::size_t rootsCalculationCounter_; ///< Статический счетчик вызовов поиска корней
 
 public:
     // Конструкторы 3 штуки
     
     /**
      * @brief Конструктор по умолчанию. Создает нулевой многочлен 0x² + 0x + 0
      */
     Polynomial();
     
     /**
      * @brief Параметризованный конструктор
      * @param a Коэффициент при x²
      * @param b Коэффициент при x
      * @param c Свободный член
      */
     Polynomial(double a, double b, double c);
     
     /**
      * @brief Конструктор копирования
      * @param other Объект для копирования
      */
     Polynomial(const Polynomial& other);
     
     /**
      * @brief Деструктор с выводом сообщения
      */
     ~Polynomial();
 
     // Методы доступа
     double getA() const { return a_; }
     double getB() const { return b_; }
     double getC() const { return c_; }
     void setCoefficients(double a, double b, double c);
 
     /**
      * @brief Вычисление значения многочлена в точке x
      * @param x Точка для вычисления
      * @return Значение многочлена в точке x
      */
     double evaluate(double x) const;
     
     /**
      * @brief Поиск и вывод корней многочлена
      */
     void findRoots() const;
     
     /**
      * @brief Получение количества вызовов поиска корней
      * @return Количество вызовов
      */
     static std::size_t getRootsCalculationCount();
 
     // Унарные операторы (4 варианта)
     Polynomial& operator++();       // Префиксный инкремент
     Polynomial operator++(int);     // Постфиксный инкремент  
     Polynomial& operator--();       // Префиксный декремент
     Polynomial operator--(int);     // Постфиксный декремент
 
     // Операторы арифметического присваивания
     Polynomial& operator+=(const Polynomial& other);
     Polynomial& operator-=(const Polynomial& other);
     Polynomial& operator*=(double scalar);
     Polynomial& operator/=(double scalar);
 
     // Бинарные арифметические операторы
     Polynomial operator+(const Polynomial& other) const;
     Polynomial operator-(const Polynomial& other) const;
     Polynomial operator*(double scalar) const;
     Polynomial operator/(double scalar) const;
 
     // Бинарные операторы сравнения
     bool operator<(const Polynomial& other) const;
     bool operator>(const Polynomial& other) const;
     bool operator<=(const Polynomial& other) const;
     bool operator>=(const Polynomial& other) const;
     bool operator==(const Polynomial& other) const;
     bool operator!=(const Polynomial& other) const;
     
     /**
      * @brief Вывод многочлена в читаемом формате
      */
     void print() const;
 };
 
 #endif