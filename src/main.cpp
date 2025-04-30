#include "../include/frutalang.h"
#include <iostream>
#include <string>
#include <fstream>

int main() {
    FrutaLang::Frutalang programa;
    std::string comando;
    
    std::cout << "Bem-vindo ao FrutaLang! Digite 'sair' para encerrar.\n\n";
    
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, comando);
        
        if (comando == "sair") {
            break;
        }
        
        programa.executar(comando);
    }
    
    return 0;
}
