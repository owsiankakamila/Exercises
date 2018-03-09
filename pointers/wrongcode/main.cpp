#include <iostream>
using namespace std;
//WHAT IS WRONG?
//iostream.h
//pointer is created IN function so..?
// address to plain integral &3?



int * potega(int liczba, int potega){
  int* wynik = &liczba;
  for(int i = 1; i < potega; i++)
    *wynik *= liczba;
  return wynik;
}
int main(void){
  cout << *(potega(3,3)) << endl;
}