/**
 * @file main.cpp
 * @brief Демонстрационная программа для класса Polynomial с интерактивным меню
 */

 #include "Polynomial.h"
 #include <iostream>
 #include <limits>
 
 using namespace std;
 
 // Прототипы функций меню
 void displayMainMenu();
 void createPolynomialMenu(Polynomial& poly, Polynomial& otherPoly, int polyNumber);
 void demonstrateUnaryOperators(Polynomial& poly1, Polynomial& poly2);
 void demonstrateArithmeticAssignment(Polynomial& poly1, Polynomial& poly2);
 void demonstrateBinaryOperators(Polynomial& poly1, Polynomial& poly2);
 void demonstrateComparisonOperators(Polynomial& poly1, Polynomial& poly2);
 void demonstrateRootsAndStatic(Polynomial& poly1, Polynomial& poly2);
 
 // Вспомогательные функции
 void clearInputBuffer() {
     cin.clear();
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
 }
 
 void waitForEnter() {
     cout << "\nНажмите Enter для продолжения...";
     clearInputBuffer();
     cin.get();
 }
 
 int main() {
     int choice;
     Polynomial poly1, poly2; 
     
     do {
         displayMainMenu();
         cout << "Выберите действие: ";
         cin >> choice;
         
         if (cin.fail()) {
             clearInputBuffer();
             cout << "Ошибка ввода! Пожалуйста, введите число.\n";
             waitForEnter();
             continue;
         }
         
         switch (choice) {
             case 1:
                 createPolynomialMenu(poly1, poly2, 1);
                 break;
             case 2:
                 createPolynomialMenu(poly2, poly1, 2);
                 break;
             case 3:
                 demonstrateUnaryOperators(poly1, poly2);
                 break;
             case 4:
                 demonstrateArithmeticAssignment(poly1, poly2);
                 break;
             case 5:
                 demonstrateBinaryOperators(poly1, poly2);
                 break;
             case 6:
                 demonstrateComparisonOperators(poly1, poly2);
                 break;
             case 7:
                 demonstrateRootsAndStatic(poly1, poly2);
                 break;
             case 0:
                 cout << "Выход из программы...\n";
                 break;
             default:
                 cout << "Неверный выбор! Попробуйте снова.\n";
                 waitForEnter();
                 break;
         }
     } while (choice != 0);
     
     return 0;
 }
 
 void displayMainMenu() {
     system("clear"); 
     cout << "=== КАЛЬКУЛЯТОР МНОГОЧЛЕНОВ 2-Й СТЕПЕНИ ===\n";
     cout << "=== ЛАБОРАТОРНАЯ РАБОТА №2 ===\n\n";
     cout << "1. Создать/изменить poly1\n";
     cout << "2. Создать/изменить poly2\n";
     cout << "3. Демонстрация унарных операторов\n";
     cout << "4. Демонстрация арифметического присваивания\n";
     cout << "5. Демонстрация бинарных операторов\n";
     cout << "6. Демонстрация операторов сравнения\n";
     cout << "7. Поиск корней и статическое поле\n";
     cout << "0. Выход\n";
     cout << "----------------------------------------\n";
 }
 
 void createPolynomialMenu(Polynomial& poly, Polynomial& otherPoly, int polyNumber) {
     int choice;
     double a, b, c;
     
     do {
         system("clear");
         cout << "=== СОЗДАНИЕ/ИЗМЕНЕНИЕ POLY" << polyNumber << " ===\n\n";
         cout << "Текущий полином: ";
         poly.print();
         cout << "\nВыберите способ создания:\n";
         cout << "1. Конструктор по умолчанию (0x² + 0x + 0)\n";
         cout << "2. Конструктор копирования (из другого poly)\n";
         cout << "3. Ввести коэффициенты вручную\n";
         cout << "0. Назад\n";
         cout << "Выберите: ";
         cin >> choice;
         
         if (cin.fail()) {
             clearInputBuffer();
             cout << "Ошибка ввода!\n";
             waitForEnter();
             continue;
         }
         
         switch (choice) {
             case 1:
                 poly = Polynomial();
                 cout << "Создан полином по умолчанию: ";
                 poly.print();
                 waitForEnter();
                 return;
             case 2:
                 poly = Polynomial(otherPoly);
                 cout << "Создан poly" << polyNumber << " как копия другого полинома: ";
                 poly.print();
                 waitForEnter();
                 return;
             case 3:
                 cout << "Введите коэффициент a: ";
                 cin >> a;
                 cout << "Введите коэффициент b: ";
                 cin >> b;
                 cout << "Введите коэффициент c: ";
                 cin >> c;
                 if (cin.fail()) {
                     cout << "Ошибка ввода коэффициентов!\n";
                     clearInputBuffer();
                 } else {
                     poly.setCoefficients(a, b, c);
                     cout << "Полином установлен: ";
                     poly.print();
                 }
                 waitForEnter();
                 return;
             case 0:
                 return;
             default:
                 cout << "Неверный выбор!\n";
                 waitForEnter();
                 break;
         }
     } while (choice != 0);
 }
 
 void demonstrateUnaryOperators(Polynomial& poly1, Polynomial& poly2) {
     int polyChoice;
     int operatorChoice;
     
     do {
         system("clear");
         cout << "=== ДЕМОНСТРАЦИЯ УНАРНЫХ ОПЕРАТОРОВ ===\n\n";
         
         cout << "Текущие полиномы:\n";
         cout << "poly1: ";
         poly1.print();
         cout << "poly2: ";
         poly2.print();
         cout << endl;
         
         cout << "Выберите полином для работы:\n";
         cout << "1. Работать с poly1\n";
         cout << "2. Работать с poly2\n";
         cout << "0. Назад\n";
         cout << "Выберите: ";
         cin >> polyChoice;
         
         if (cin.fail()) {
             clearInputBuffer();
             cout << "Ошибка ввода!\n";
             waitForEnter();
             continue;
         }
         
         if (polyChoice == 0) return;
         
         if (polyChoice != 1 && polyChoice != 2) {
             cout << "Неверный выбор полинома!\n";
             waitForEnter();
             continue;
         }
         
         Polynomial& selectedPoly = (polyChoice == 1) ? poly1 : poly2;
         string polyName = (polyChoice == 1) ? "poly1" : "poly2";
         
         do {
             system("clear");
             cout << "УНАРНЫЕ ОПЕРАТОРЫ ДЛЯ " << polyName << " \n\n";
             
             cout << "Текущий " << polyName << ": ";
             selectedPoly.print();
             cout << endl;
             
             cout << "Выберите оператор:\n";
             cout << "1. Префиксный инкремент (++" << polyName << ")\n";
             cout << "2. Постфиксный инкремент (" << polyName << "++)\n";
             cout << "3. Префиксный декремент (--" << polyName << ")\n";
             cout << "4. Постфиксный декремент (" << polyName << "--)\n";
             cout << "0. Назад к выбору полинома\n";
             cout << "Выберите: ";
             cin >> operatorChoice;
             
             if (cin.fail()) {
                 clearInputBuffer();
                 cout << "Ошибка ввода!\n";
                 waitForEnter();
                 continue;
             }
             
             switch (operatorChoice) {
                 case 1: {
                     cout << "\nПрефиксный инкремент (++" << polyName << "):\n";
                     cout << "До: ";
                     selectedPoly.print();
                     Polynomial temp = selectedPoly;
                     cout << "++" << polyName << " = ";
                     (++temp).print();
                     cout << "После операции исходный " << polyName << " не изменился: ";
                     selectedPoly.print();
                     waitForEnter();
                     break;
                 }
                 case 2: {
                     cout << "\nПостфиксный инкремент (" << polyName << "++):\n";
                     cout << "До: ";
                     selectedPoly.print();
                     Polynomial temp = selectedPoly;
                     cout << polyName << "++ = ";
                     (temp++).print();
                     cout << "После операции исходный " << polyName << " не изменился: ";
                     selectedPoly.print();
                     waitForEnter();
                     break;
                 }
                 case 3: {
                     cout << "\nПрефиксный декремент (--" << polyName << "):\n";
                     cout << "До: ";
                     selectedPoly.print();
                     Polynomial temp = selectedPoly;
                     cout << "--" << polyName << " = ";
                     (--temp).print();
                     cout << "После операции исходный " << polyName << " не изменился: ";
                     selectedPoly.print();
                     waitForEnter();
                     break;
                 }
                 case 4: {
                     cout << "\nПостфиксный декремент (" << polyName << "--):\n";
                     cout << "До: ";
                     selectedPoly.print();
                     Polynomial temp = selectedPoly;
                     cout << polyName << "-- = ";
                     (temp--).print();
                     cout << "После операции исходный " << polyName << " не изменился: ";
                     selectedPoly.print();
                     waitForEnter();
                     break;
                 }
                 case 0:
                     break;
                 default:
                     cout << "Неверный выбор оператора!\n";
                     waitForEnter();
                     break;
             }
         } while (operatorChoice != 0);
         
     } while (polyChoice != 0);
 }
 
 void demonstrateArithmeticAssignment(Polynomial& poly1, Polynomial& poly2) {
     system("clear");
     cout << "АРИФМЕТИЧЕСКОЕ ПРИСВАИВАНИЕ\n\n";
     
     cout << "Исходные полиномы:\n";
     cout << "poly1: ";
     poly1.print();
     cout << "poly2: ";
     poly2.print();
     cout << endl;
     
     Polynomial temp1 = poly1;
     Polynomial temp2 = poly1;
     Polynomial temp3 = poly1;
     Polynomial temp4 = poly1;
     
     // +=
     cout << "1. Оператор += (poly1 += poly2):\n";
     cout << "   До: ";
     temp1.print();
     temp1 += poly2;
     cout << "   После: ";
     temp1.print();
     cout << endl;
     
     // -=
     cout << "2. Оператор -= (poly1 -= poly2):\n";
     cout << "   До: ";
     temp2.print();
     temp2 -= poly2;
     cout << "   После: ";
     temp2.print();
     cout << endl;
     
     // *=
     cout << "3. Оператор *= (poly1 *= 2.5):\n";
     cout << "   До: ";
     temp3.print();
     temp3 *= 2.5;
     cout << "   После: ";
     temp3.print();
     cout << endl;
     
     // /=
     cout << "4. Оператор /= (poly1 /= 2.0):\n";
     cout << "   До: ";
     temp4.print();
     temp4 /= 2.0;
     cout << "   После: ";
     temp4.print();
     cout << endl;
     
     cout << "Исходные полиномы не изменились:\n";
     cout << "poly1: ";
     poly1.print();
     cout << "poly2: ";
     poly2.print();
     
     waitForEnter();
 }
 
 void demonstrateBinaryOperators(Polynomial& poly1, Polynomial& poly2) {
     system("clear");
     cout << "БИНАРНЫЕ ОПЕРАТОРЫ\n\n";
     
     cout << "Исходные полиномы:\n";
     cout << "poly1: ";
     poly1.print();
     cout << "poly2: ";
     poly2.print();
     cout << endl;
     
     cout << "1. Сложение (poly1 + poly2):\n";
     Polynomial result1 = poly1 + poly2;
     cout << "   Результат: ";
     result1.print();
     cout << endl;
     
     cout << "2. Вычитание (poly1 - poly2):\n";
     Polynomial result2 = poly1 - poly2;
     cout << "   Результат: ";
     result2.print();
     cout << endl;
     
     cout << "3. Умножение на скаляр (poly1 * 3.0):\n";
     Polynomial result3 = poly1 * 3.0;
     cout << "   Результат: ";
     result3.print();
     cout << endl;
     
     cout << "4. Деление на скаляр (poly1 / 2.0):\n";
     Polynomial result4 = poly1 / 2.0;
     cout << "   Результат: ";
     result4.print();
     cout << endl;
     
     cout << "Исходные полиномы не изменились:\n";
     cout << "poly1: ";
     poly1.print();
     cout << "poly2: ";
     poly2.print();
     
     waitForEnter();
 }
 
 void demonstrateComparisonOperators(Polynomial& poly1, Polynomial& poly2) {
     system("clear");
     cout << "ОПЕРАТОРЫ СРАВНЕНИЯ\n\n";
     
     cout << "poly1: ";
     poly1.print();
     cout << "poly2: ";
     poly2.print();
     cout << endl;
     
     cout << "Сравнение полиномов по коэффициентам:\n";
     cout << "poly1 < poly2:  " << (poly1 < poly2 ? "true" : "false") << endl;
     cout << "poly1 > poly2:  " << (poly1 > poly2 ? "true" : "false") << endl;
     cout << "poly1 <= poly2: " << (poly1 <= poly2 ? "true" : "false") << endl;
     cout << "poly1 >= poly2: " << (poly1 >= poly2 ? "true" : "false") << endl;
     cout << "poly1 == poly2: " << (poly1 == poly2 ? "true" : "false") << endl;
     cout << "poly1 != poly2: " << (poly1 != poly2 ? "true" : "false") << endl;
     
     waitForEnter();
 }
 
 void demonstrateRootsAndStatic(Polynomial& poly1, Polynomial& poly2) {
     int polyChoice;
     
     do {
         system("clear");
         cout << "ПОИСК КОРНЕЙ И СТАТИЧЕСКОЕ ПОЛЕ\n\n";
         
         cout << "Текущие полиномы:\n";
         cout << "poly1: ";
         poly1.print();
         cout << "poly2: ";
         poly2.print();
         cout << endl;
         
         cout << "Количество поисков корней до: " << Polynomial::getRootsCalculationCount() << endl;
         cout << endl;
         
         cout << "Выберите полином для поиска корней:\n";
         cout << "1. Найти корни poly1\n";
         cout << "2. Найти корни poly2\n";
         cout << "3. Найти корни обоих полиномов\n";
         cout << "0. Назад\n";
         cout << "Выберите: ";
         cin >> polyChoice;
         
         if (cin.fail()) {
             clearInputBuffer();
             cout << "Ошибка ввода!\n";
             waitForEnter();
             continue;
         }
         
         switch (polyChoice) {
             case 1:
                 cout << "\nПоиск корней для poly1:\n";
                 poly1.findRoots();
                 break;
             case 2:
                 cout << "\nПоиск корней для poly2:\n";
                 poly2.findRoots();
                 break;
             case 3:
                 cout << "\nПоиск корней для poly1:\n";
                 poly1.findRoots();
                 cout << "\nПоиск корней для poly2:\n";
                 poly2.findRoots();
                 break;
             case 0:
                 return;
             default:
                 cout << "Неверный выбор!\n";
                 waitForEnter();
                 continue;
         }
         
         cout << "\nКоличество поисков корней после: " << Polynomial::getRootsCalculationCount() << endl;
         waitForEnter();
         
     } while (polyChoice != 0);
 }