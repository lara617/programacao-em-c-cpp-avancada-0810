#include "../include/frutalang.h"
#include <sstream>
#include <iomanip>
#include <algorithm>

namespace FrutaLang {
    Frutalang::Frutalang() {
        // Inicializa o interpretador
    }

    void Frutalang::executar(const std::string& codigo) {
        std::istringstream iss(codigo);
        std::string linha;
        
        while (std::getline(iss, linha)) {
            if (linha.find("morango") != std::string::npos) {
                std::istringstream linhaStream(linha);
                std::string comando, nome;
                double preco;
                int quantidade;
                linhaStream >> comando >> nome >> preco >> quantidade;
                adicionar(nome, preco, quantidade);
            }
            else if (linha.find("uva") != std::string::npos) {
                listar();
            }
            else if (linha.find("limao") != std::string::npos) {
                finalizarCompra();
            }
            else if (linha.find("banana") != std::string::npos) {
                std::istringstream linhaStream(linha);
                std::string comando, nome;
                linhaStream >> comando >> nome;
                remover(nome);
            }
            else if (linha.find("pera") != std::string::npos) {
                std::istringstream linhaStream(linha);
                std::string comando, nome;
                int quantidade;
                linhaStream >> comando >> nome >> quantidade;
                if (quantidade <= 0) {
                    quantidade = 1;
                }
                adicionarCarrinho(nome, quantidade);
            }

            else if (linha.find("laranja") != std::string::npos) {
                std::cout << "Total do Carrinho: R$ " << std::fixed << std::setprecision(2) << calcularTotalCarrinho() << std::endl;
            }
        }
    }

    void Frutalang::adicionar(const std::string& nome, double preco, int quantidade) {
        if (quantidade <= 0) {
            std::cout << "Quantidade deve ser maior que zero!\n";
            return;
        }
        
        Produto produto = {nome, preco, quantidade};
        produtos.push_back(produto);
        mapaProdutos[nome] = preco;
        std::cout << quantidade << " " << nome << "(s) adicionado(s) ao estoque com preço R$ " << std::fixed << std::setprecision(2) << preco << " cada\n";
    }

    void Frutalang::listar() {
        std::cout << "\nLista de Produtos:\n";
        std::cout << "------------------\n";
        for (const auto& produto : produtos) {
            std::cout << produto.nome << " - R$ " << std::fixed << std::setprecision(2) << produto.preco << " - " << produto.quantidade << " em estoque\n";
        }
        std::cout << "------------------\n";
    }



    void Frutalang::adicionarCarrinho(const std::string& nome, int quantidade) {
        auto it = mapaProdutos.find(nome);
        if (it != mapaProdutos.end()) {
            // Verifica se há estoque suficiente
            auto prod_it = std::find_if(produtos.begin(), produtos.end(),
                [nome](const Produto& p) { return p.nome == nome; });
            
            if (prod_it != produtos.end() && prod_it->quantidade >= quantidade) {
                ItemCarrinho item = {nome, quantidade, it->second};
                carrinho.push_back(item);
                prod_it->quantidade -= quantidade;
                std::cout << quantidade << " " << nome << "(s) adicionado(s) ao carrinho!\n";
            } else {
                std::cout << "Não há estoque suficiente para " << nome << "!\n";
            }
        } else {
            std::cout << "Produto " << nome << " não encontrado!\n";
        }
    }



    double Frutalang::calcularTotalCarrinho() {
        double total = 0;
        for (const auto& item : carrinho) {
            total += item.quantidade * item.preco;
        }
        return total;
    }

    void Frutalang::remover(const std::string& nome) {
        auto it = mapaProdutos.find(nome);
        if (it != mapaProdutos.end()) {
            mapaProdutos.erase(it);
            produtos.erase(std::remove_if(produtos.begin(), produtos.end(),
                [nome](const Produto& p) { return p.nome == nome; }),
                produtos.end());
            std::cout << "Produto " << nome << " removido do estoque!\n";
        } else {
            std::cout << "Produto " << nome << " não encontrado no estoque!\n";
        }
    }



    void Frutalang::finalizarCompra() {
        if (carrinho.empty()) {
            std::cout << "Carrinho vazio!\n";
            return;
        }
        
        double total = calcularTotalCarrinho();
        std::cout << "\nTotal da compra: R$ " << std::fixed << std::setprecision(2) << total << "\n";
        std::cout << "Digite o valor pago: ";
        std::cin >> valorPago;
        
        while (valorPago < total) {
            std::cout << "\nDinheiro insuficiente!\n";
            std::cout << "Faltam R$ " << std::fixed << std::setprecision(2) << (total - valorPago) << "\n";
            std::cout << "Total da compra: R$ " << std::fixed << std::setprecision(2) << total << "\n";
            std::cout << "Digite um novo valor: ";
            std::cin >> valorPago;
        }
        
        double troco = valorPago - total;
        std::cout << "\nCompra realizada com sucesso!\n";
        std::cout << "Troco: R$ " << std::fixed << std::setprecision(2) << troco << "\n";
        std::cout << "Volte sempre!\n";
        carrinho.clear();
    }


}
