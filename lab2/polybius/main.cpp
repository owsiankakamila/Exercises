//
// Created by kamila on 06.03.18.
//
#include "Polybius.h"
#include <fstream>
#include <cstdlib>

int main(int argc, char* argv[]){
    //argv[1] <- plik wej
    //argv[2] <- plik wyj
    //argv[3] <- tryb 0/1

    if ((argv[3]!="1")&&(argv[3]!="0")){
        std::cout << "Nie ma takiego trybu!" << std::endl;
        exit(0);
    }

    std::string line;
    std::ifstream in_file(argv[1]);
    std::ofstream out_file ("file.txt", std::ios_base::in | std::ios_base::app);


    if(!in_file){
        std::cout << "Nie można otworzyć pliku!" << std::endl;
    }

    if(!out_file){
        std::cout << "Nie można otworzyć pliku!" << std::endl;
    }


    while(!in_file.eof()){
        getline(in_file,line);
        if (argv[3]=="0"){
            out_file << PolybiusCrypt(line)<<std::endl;
        }
        else if (argv[3]=="1"){
            out_file << PolybiusDecrypt(line)<<std::endl;

        }

    }


    in_file.close();
    out_file.close();

    return 0;
}