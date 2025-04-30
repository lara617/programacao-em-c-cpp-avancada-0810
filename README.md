# FrutaLang - Linguagem de Programação de Frutas

Uma linguagem de programação simples e divertida que usa palavras relacionadas a frutas como comandos.

## Estrutura do Projeto
```
frutalang/
├── include/
│   └── frutalang.h
├── src/
│   ├── frutalang.cpp
│   └── main.cpp
├── exemplos/
│   ├── teste.fruta
│   └── exemplo.fruta
└── README.md
```

## Comandos Disponíveis

### morango
Adiciona um novo produto ao estoque com nome, preço e quantidade.

**Sintaxe:**
```
morango "nome_do_produto" preco quantidade
```

**Exemplo:**
```
morango "Lápis" 1.50 100
```

### uva
Lista todos os produtos no estoque com nome, preço e quantidade disponível.

**Sintaxe:**
```
uva
```

### limao
Finaliza a compra, pede o valor pago e calcula o troco.

**Sintaxe:**
```
limao
```

### banana
Remove um produto do estoque.

**Sintaxe:**
```
banana "nome_do_produto"
```

**Exemplo:**
```
banana "Lápis"
```

### pera
Adiciona um produto ao carrinho de compras.

**Sintaxe:**
```
pera "nome_do_produto" quantidade
```

**Exemplo:**
```
pera "Lápis" 2
```


### laranja
Mostra o total atual do carrinho de compras.

**Sintaxe:**
```
laranja
```

### limao
Finaliza a compra:
1. Mostra o total da compra
2. Pede o valor pago
3. Se o valor for insuficiente:
   - Mostra mensagem "Dinheiro insuficiente!"
   - Mostra quanto falta
   - Mostra o total novamente
   - Pede para digitar um novo valor
4. Se o valor for igual ou superior:
   - Mostra mensagem "Compra realizada com sucesso!"
   - Mostra o troco
   - Mostra mensagem "Volte sempre!"
   - Limpa o carrinho

**Sintaxe:**
```
limao
```

### kiwi
Remove um produto do carrinho com a quantidade desejada.

**Sintaxe:**
```
kiwi "nome_do_produto" quantidade
```

**Exemplo:**
```
kiwi "Lápis" 2
```

## Como Usar

1. Compile o programa:
```bash
g++ src/main.cpp src/frutalang.cpp -o frutalang -Iinclude
```

2. Execute o programa com um arquivo de código:
```bash
./frutalang arquivo.fruta
```

## Exemplos

### Exemplo 1: Gerenciamento Completo
```fruta
morango "Lápis" 1.50
morango "Caneta" 2.00
morango "Caderno" 10.00
uva
pera "Lápis" 2
pera "Caneta" 3
maça
laranja
banana "Caneta"
uva
limao
```

### Exemplo 2: Compras
```fruta
morango "Lapiseira" 15.00
morango "Borracha" 2.50
morango "Apontador" 1.00
uva
pera "Lapiseira" 1
pera "Borracha" 2
maça
laranja
```

## Características
- Interface simples e intuitiva
- Comandos inspirados em frutas
- Gerenciamento de produtos
- Cálculo automático de totais
- Lista organizada de produtos

## Requisitos
- Compilador C++ (g++ recomendado)
- Sistema operacional Windows/Linux/MacOS
