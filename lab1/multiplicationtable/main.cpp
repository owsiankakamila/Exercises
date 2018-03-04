#include "MultiplicationTable.h"
#include <iomanip>
void PrintTable(int tab[][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            std::cout << std::setw(3)<< tab[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
int main() {
    int tab [10][10];
    MultiplicationTable(tab);
    PrintTable(tab);

    return 0;
}
