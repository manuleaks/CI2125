#include <iostream>
#include <string>

void my_info(int mode, bool b) {
    std::string nombre = "Manuel";
    int carnet = 2310427; 

    std::cout << nombre << " " << carnet << " ";

    if (mode == 1) {
        if (b == true) {
            std::cout << "verdadero";
        } else {
            std::cout << "falso";
        }
    } else { 
        if (b == true) {
            std::cout << "true";
        } else {
            std::cout << "false";
        }
    }

    std::cout << std::endl;
}