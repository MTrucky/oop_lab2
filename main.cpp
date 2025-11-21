/**
 * @file main.cpp
 * @brief Демонстрационная программа для класса Polynomial с интерактивным меню
 */

 #include "Polynomial.h"
 #include <iostream>
 #include <limits>
 
 using namespace std;
 
 // функции меню
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
             cout << "Ошибка ввода. Введите число.\n";
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
     cout << "1. Создать/изменить poly1\n";
     cout << "2. Создать/изменить poly2\n";
     cout << "3. Демонстрация унарных операторов\n";
     cout << "4. Демонстрация арифметического присваивания\n";
     cout << "5. Демонстрация бинарных операторов\n";
     cout << "6. Демонстрация операторов сравнения\n";
     cout << "7. Поиск корней и статическое поле\n";
     cout << "0. Выход\n";
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
                 cout << "Ошибка ввода!!\n";
                 waitForEnter();
                 continue;
             }
             
             switch (operatorChoice) {
                 case 1: {
                     cout << "\nПрефиксный инкремент (++" << polyName << "):\n";
                     cout << "++" << polyName << " = ";
                     (++selectedPoly).print();
                     waitForEnter();
                     break;
                 }
                 case 2: {
                     cout << "\nПостфиксный инкремент (" << polyName << "++):\n";
                     cout << polyName << "++ = ";
                     (selectedPoly++).print();
                     waitForEnter();
                     break;
                 }
                 case 3: {
                     cout << "\nПрефиксный декремент (--" << polyName << "):\n";
                     cout << "--" << polyName << " = ";
                     (--selectedPoly).print();
                     waitForEnter();
                     break;
                 }
                 case 4: {
                     cout << "\nПостфиксный декремент (" << polyName << "--):\n";
                     cout << polyName << "-- = ";
                     (selectedPoly--).print();
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
    cout << "АРИФМЕТИЧЕСКОЕ ПРИСВАИВАНИЕ (ИЗМЕНЯЕТ ОБЪЕКТЫ)\n\n";
    
    cout << "Исходные полиномы:\n";
    cout << "poly1: ";
    poly1.print();
    cout << "poly2: ";
    poly2.print();
    cout << endl;
    
    // сохр значения для демонстрации изменений
    Polynomial original1 = poly1;
    Polynomial original2 = poly2;
    
    cout << "1. poly1 += poly2:\n";
    cout << "   До: poly1 = ";
    poly1.print();
    poly1 += poly2;
    cout << "   После: poly1 = ";
    poly1.print();
    cout << endl;
    
    // Восстанавл для следующей демонстрации
    poly1 = original1;
    
    cout << "2. poly1 -= poly2:\n";
    cout << "   До: poly1 = ";
    poly1.print();
    poly1 -= poly2;
    cout << "   После: poly1 = ";
    poly1.print();
    cout << endl;
    
    poly1 = original1;
    double scalar;
    cout << "3. poly1 *= scalar:\n";
    cout << "   Введите скаляр: ";
    cin >> scalar;
    cout << "   До: poly1 = ";
    poly1.print();
    poly1 *= scalar;
    cout << "   После: poly1 = ";
    poly1.print();
    cout << endl;
    
    poly1 = original1;
    cout << "4. poly1 /= scalar:\n";
    cout << "   Введите скаляр: ";
    cin >> scalar;
    if (scalar != 0) {
        cout << "   До: poly1 = ";
        poly1.print();
        poly1 /= scalar;
        cout << "   После: poly1 = ";
        poly1.print();
    }
    
    // Восстанавливаем исходные значения
    poly1 = original1;
    poly2 = original2;
    
    waitForEnter();
}
 
void demonstrateBinaryOperators(Polynomial& poly1, Polynomial& poly2) {
    system("clear");
    cout << "БИНАРНЫЕ ОПЕРАТОРЫ (СОЗДАЮТ НОВЫЕ ОБЪЕКТЫ)\n\n";
    
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
    
    double scalar_mult;
    cout << "3. Умножение на скаляр (poly1 * scalar):\n";
    cout << "   Введите скаляр для умножения: ";
    cin >> scalar_mult;
    if (cin.fail()) {
        cout << "   Ошибка ввода скаляра!\n";
        clearInputBuffer();
    } else {
        Polynomial result3 = poly1 * scalar_mult;
        cout << "   Результат: ";
        result3.print();
    }
    cout << endl;
    
    double scalar_div;
    cout << "4. Деление на скаляр (poly1 / scalar):\n";
    cout << "   Введите скаляр для деления: ";
    cin >> scalar_div;
    if (cin.fail()) {
        cout << "   Ошибка ввода скаляра!\n";
        clearInputBuffer();
    } else if (scalar_div == 0) {
        cout << "   Ошибка: деление на ноль!\n";
    } else {
        Polynomial result4 = poly1 / scalar_div;
        cout << "   Результат: ";
        result4.print();
    }
    
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
     
     cout << "Сравнение полиномов по значениям в точке x:\n";
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
         cout << "ПОИСК КОРНЕЙ СТАТИЧЕСКОЕ ПОЛЕ\n\n";
         
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