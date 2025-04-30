# Documentação da FrutaLang

## Introdução
FrutaLang é uma linguagem de programação simples e divertida, que usa palavras relacionadas a frutas como comandos. Foi desenvolvida para tornar a programação mais acessível e divertida.

## Comandos Disponíveis

### morango
Adiciona um novo produto ao sistema.

**Sintaxe:**
```
morango "nome_do_produto" preco
```

**Exemplo:**
```
morango "Lápis" 1.50
```

### uva
Lista todos os produtos cadastrados.

**Sintaxe:**
```
uva
```

### limao
Calcula o total dos preços de todos os produtos cadastrados.

**Sintaxe:**
```
limao
```

## Exemplo de Uso
```
morango "Lápis" 1.50
morango "Caneta" 2.00
morango "Caderno" 10.00
uva
limao
```

## Compilação e Execução
Para compilar e executar o programa:

1. Certifique-se de ter um compilador C++ instalado
2. Compile o programa:
```
g++ src/main.cpp src/frutalang.cpp -o frutalang -Iinclude
```
3. Execute o programa:
```
./frutalang
```

## Características
- Interface simples e intuitiva
- Comandos inspirados em frutas
- Gerenciamento de produtos
- Cálculo automático de totais
- Lista organizada de produtos

## Estrutura do Projeto
```
frutalang/
├── include/
│   └── frutalang.h
├── src/
│   ├── frutalang.cpp
│   └── main.cpp
└── DOCUMENTACAO.md
```
