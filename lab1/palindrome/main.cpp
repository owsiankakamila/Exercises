//
// Created by kamila on 04.03.18.
//

#include "Palindrome.h"
using namespace std;

bool IsPalindrome(std::string str);

int main() {
    int choice;
    string word;

    while(true){

        cout<<"1. Sprawdź palindrom" << endl;
        cout<<"2. Wyjście"<<endl;

        cin>>choice;

        switch(choice){
            case 1:
            {
                cout << "Podaj słowo: ";
                cin >> word;


                if(IsPalindrome(word)) cout<<"Tak. To palindrom!"<<endl;
                else cout<<"Nie. To nie jest palindrom!"<<endl;
            }
                break;

            case 2:
                exit(0);
            default:
                cout<<"Nie ma takiej opcji!" <<endl;
                break;
        }
    }
    return 0;
}