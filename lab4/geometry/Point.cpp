//
// Created by kamila on 31.03.18.
//

#include "Point.h"

//Definicja znajduje się w pliku Point.cpp
#include <cmath>
#include <iostream>
#include "Point.h"

using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;
using ::std::cout;

/* Aby wskazać, ze definicja funkcji dotyczy metody danej klasy
  stosujemy tzw. operator zasięgu - "::"
*/

//Specjalna inicjalizacja zmiennych. Zmienne są inicjowane
//nim zostanie wywołane ciało konstruktora
geometry::Point::Point():x_(0),y_(0){
    cout << "Konstruktor bezparametrowy" << endl;
}

geometry::Point::Point(double x, double y){
    cout << "Konstruktor parametrowy" << endl;
    x_ = x;
    y_ = y;
}

geometry::Point::~Point(){
    cout << "Destruktor! Nic nie robie, bo nie musze zwalniać pamięci!";
    cout << endl;
}

double geometry::Point::Distance(const Point &other) const{
    return sqrt(pow(GetX()-other.GetX(),2)+pow(GetY()-other.GetY(),2));
}

void geometry::Point::ToString(ostream *out) const{
    (*out) << "(" << GetX() << ";" << GetY() << ")";
}

double geometry::Point::GetX() const{
    return x_;
}
double geometry::Point::GetY() const{
    return y_;
}

void geometry::Point::SetX(double x){
    x_ = x;
}
void geometry::Point::SetY(double y){
    y_=y;
}