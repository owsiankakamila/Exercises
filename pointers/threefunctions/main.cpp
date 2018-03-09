#include <iostream>

int variable(int);
int pointer(int*);
int reference(int&);

int main() {
    int n = 20;
    int * pn=&n;
    int & rn=n;
    std::cout<< variable(n)<< "  " << n<<std::endl;
    std::cout<< pointer(pn)<< "  " << n<<std::endl;
    std::cout<< reference(rn)<< "  " << n<<std::endl;


    return 0;
}

int variable(int n){
    n=n+5;
    return n;
}

int pointer(int*pn){
    *pn=*pn+5;
    return*pn;
}

int reference(int&rn){
    rn=rn+5;
    return rn;
}