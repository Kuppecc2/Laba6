#include <iostream>
#include <cmath>
#include "mycomplex.h"

using namespace std;

/**
 * @brief Конструктор с параметрами.
 * @param aRe Действительная часть комплексного числа.
 * @param aIm Мнимая часть комплексного числа.
 */
Complex::Complex(double aRe, double aIm) {
    Re = aRe;
    Im = aIm;
}

/**
 * @brief Конструктор копирования.
 * @param aRval Комплексное число, которое будет скопировано.
 */
Complex::Complex(const Complex& aRval) {
    Re = aRval.Re;
    Im = aRval.Im;
}

/**
 * @brief Деструктор.
 */
Complex::~Complex() {
    Re = 0.0;
    Im = 0.0;
}

/**
 * @brief Установка новых значений для действительной и мнимой частей.
 * @param aRe Новое значение для действительной части.
 * @param aIm Новое значение для мнимой части.
 */
void Complex::Set(double aRe, double aIm) {
    Re = aRe;
    Im = aIm;
}

/**
 * @brief Преобразование комплексного числа в его модуль.
 * @return Модуль комплексного числа.
 */
Complex::operator double() {
    return abs();
}

/**
 * @brief Вычисление модуля комплексного числа.
 * @return Модуль комплексного числа.
 */
double Complex::abs() {
    return sqrt(Re * Re + Im * Im);
}

/**
 * @brief Перегруженный оператор сложения комплексных чисел.
 * @param aRval Комплексное число, с которым производится сложение.
 * @return Результат сложения комплексных чисел.
 */
Complex Complex::operator+(const Complex& aRval) {
    Complex Result;
    Result.Re = Re + aRval.Re;
    Result.Im = Im + aRval.Im;
    return Result;
}

/**
 * @brief Перегруженный оператор вычитания комплексных чисел.
 * @param aRval Комплексное число, которое вычитается.
 * @return Результат вычитания комплексных чисел.
 */
Complex Complex::operator-(const Complex& aRval) {
    Complex Result;
    Result.Re = Re - aRval.Re;
    Result.Im = Im - aRval.Im;
    return Result;
}

/**
 * @brief Перегруженный оператор сложения комплексного числа с вещественным числом.
 * @param aval Вещественное число, с которым производится сложение.
 * @return Результат сложения.
 */
Complex Complex::operator+(const double& aval) {
    Complex result;
    result.Re = Re + aval;
    result.Im = Im;
    return result;
}

Complex Complex::operator-(const double& aRval) {
    Complex Result(*this);
    Result.Re = Re - aRval;
    return Result;
}

Complex Complex::operator*(const Complex& aRval) {
    Complex Result;
    Result.Re = Re * aRval.Re - Im * aRval.Im;
    Result.Im = Re * aRval.Im + Im * aRval.Re;
    return Result;
}

Complex Complex::operator*(const double& aRval) {
    Complex Result;
    Result.Re = Re * aRval;
    Result.Im = Im * aRval;
    return Result;
}

Complex Complex::operator/(const double& aRval) {
    Complex Result;
    Result.Re = Re / aRval;
    Result.Im = Im / aRval;
    return Result;
}

Complex& Complex::operator+=(const Complex& arval) {
    Re += arval.Re;
    Im += arval.Im;
    return *this;
}

Complex& Complex::operator-=(const Complex& aRval) {
    Re -= aRval.Re;
    Im -= aRval.Im;
    return *this;
}

Complex& Complex::operator*=(const Complex& aRval) {
    double tmpRe = Re;
    Re = Re * aRval.Re - Im * aRval.Im;
    Im = Im * aRval.Re + tmpRe * aRval.Im;
    return *this;
}

Complex& Complex::operator+=(const double& aRval) {
    Re += aRval;
    return *this;
}

Complex& Complex::operator-=(const double& aRval) {
    Re -= aRval;
    return *this;
}

Complex& Complex::operator*=(const double& aRval) {
    Re *= aRval;
    Im *= aRval;
    return *this;
}

Complex& Complex::operator/=(const double& aRval) {
    Re /= aRval;
    Im /= aRval;
    return *this;
}

Complex& Complex::operator=(const Complex& aRval) {
    Re = aRval.Re;
    Im = aRval.Im;
    return *this;
}

Complex& Complex::operator=(const double& aRval) {
    Re = aRval;
    Im = 0.0;
    return *this;
}

istream& operator>>(istream& stream, Complex& a) {
    char tmp[256];
    stream >> a.Re >> a.Im >> tmp;
    return stream;
}

ostream& operator<<(ostream& stream, Complex& a) {
    stream << a.Re;
    if (!(a.Im < 0)) {
        stream << '+';
    }
    stream << a.Im << 'i';
    return stream;
}

Complex operator+(const double& aLval, const Complex& aRval) {
    Complex Result;
    Result.Re = aLval + aRval.Re;
    Result.Im = aRval.Im;
    return Result;
}

Complex operator-(const double& aLval, const Complex& aRval) {
    Complex Result;
    Result.Re = aLval - aRval.Re;
    Result.Im = -aRval.Im;
    return Result;
}

Complex operator*(const double& aLval, const Complex& a) {
    Complex r;
    r.Re = aLval * a.Re;
    r.Im = aLval * a.Im;
    return r;
}