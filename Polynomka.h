/**
 * @file Polynomka.h
 * @brief Заголовочный файл класса Polynomka для работы с многочленами 2-й степени
 */

 #ifndef POLYNOMKA_H
 #define POLYNOMKA_H
 
 #include <cstddef>
 
 /**
  * @class Polynomka
  * @brief Класс для работы с многочленами второй степени вида ax² + bx + c
  */
 class Polynomka {
 private:
     double a_; ///< Коэффициент при x²
     double b_; ///< Коэффициент при x  
     double c_; ///< Свободный член
     
     static std::size_t rootsCalculationCounter_; ///< Статический счетчик вызовов поиска корней
 
 public:
     // Конструкторы (3 штуки)
     
     /**
      * @brief Конструктор по умолчанию. Создает нулевой многочлен 0x² + 0x + 0
      */
     Polynomka();
     
     /**
      * @brief Параметризованный конструктор
      * @param a Коэффициент при x²
      * @param b Коэффициент при x
      * @param c Свободный член
      */
     Polynomka(double a, double b, double c);
     
     /**
      * @brief Конструктор копирования
      * @param other Объект для копирования
      */
     Polynomka(const Polynomka& other);
     
     /**
      * @brief Деструктор с выводом сообщения
      */
     ~Polynomka();
 
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
     Polynomka& operator++();       // Префиксный инкремент
     Polynomka operator++(int);     // Постфиксный инкремент  
     Polynomka& operator--();       // Префиксный декремент
     Polynomka operator--(int);     // Постфиксный декремент
 
     // Операторы арифметического присваивания
     Polynomka& operator+=(const Polynomka& other);
     Polynomka& operator-=(const Polynomka& other);
     Polynomka& operator*=(double scalar);
     Polynomka& operator/=(double scalar);
 
     // Бинарные арифметические операторы (реализованы через присваивание)
     friend Polynomka operator+(Polynomka lhs, const Polynomka& rhs);
     friend Polynomka operator-(Polynomka lhs, const Polynomka& rhs);
     friend Polynomka operator*(Polynomka lhs, double scalar);
     friend Polynomka operator/(Polynomka lhs, double scalar);
 
     // Бинарные операторы сравнения (сравнивают значения в точке x)
     bool isLessThan(const Polynomka& other, double x) const;
     bool isGreaterThan(const Polynomka& other, double x) const;
     bool isLessOrEqual(const Polynomka& other, double x) const;
     bool isGreaterOrEqual(const Polynomka& other, double x) const;
     bool isEqual(const Polynomka& other, double x) const;
     bool isNotEqual(const Polynomka& other, double x) const;
     
     /**
      * @brief Вывод многочлена в читаемом формате
      */
     void print() const;
 };
 
 #endif 