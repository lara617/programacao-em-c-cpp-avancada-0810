#ifndef FRUTALANG_H
#define FRUTALANG_H

#include <string>
#include <vector>
#include <map>
#include <iostream>

namespace FrutaLang {
    class Frutalang {
    public:
        Frutalang();
        void executar(const std::string& codigo);
        void adicionar(const std::string& nome, double preco, int quantidade);
        void listar();
        void remover(const std::string& nome);
        void adicionarCarrinho(const std::string& nome, int quantidade);
        void listarCarrinho();
        void removerCarrinho(const std::string& nome, int quantidade);
        double calcularTotalCarrinho();
        void finalizarCompra();
        void calcularTroco(double valorPago);
    
    private:
        struct Produto {
            std::string nome;
            double preco;
            int quantidade;
        };
        
        struct ItemCarrinho {
            std::string nome;
            int quantidade;
            double preco;
        };
        
        std::vector<Produto> produtos;
        std::map<std::string, double> mapaProdutos;
        std::vector<ItemCarrinho> carrinho;
        double valorPago;
    };
}

#endif // FRUTALANG_H
