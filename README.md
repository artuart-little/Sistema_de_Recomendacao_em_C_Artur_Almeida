# 🛒 Sistema de Recomendação (C/C++)

Este repositório contém a implementação de um **Sistema de Recomendação** para o varejo, desenvolvido como projeto acadêmico para a disciplina de Programação Estruturada. 

O sistema processa um histórico massivo de compras de clientes e utiliza o **Método da Vizinhança (Filtragem Colaborativa)** e a **Distância de Jaccard** para calcular a similaridade de consumo entre os usuários.

## 🚀 Funcionalidades

O projeto é dividido em dois módulos principais de processamento:

- **Módulo de Busca (Atividade 1):** - Leitura otimizada de um arquivo CSV contendo milhares de registros de compras.
  - Conversão de IDs de texto (strings) para índices numéricos internos.
  - Sistema de busca interativa em terminal com complexidade de tempo $O(\log N)$

- **Módulo de Similaridade (Atividade 2):**
  - Transformação do histórico de compras em uma matriz de incidência (Clientes x Produtos).
  - Multiplicação algébrica da matriz por sua transposta ($A \times A^T$) para descobrir a interseção exata de produtos em comum entre todos os clientes.
  - Cálculo da Matriz de Similaridade utilizando a métrica da Distância de Jaccard.

## 🛠️ Tecnologias e Arquitetura

O código adota uma abordagem híbrida de alta performance, unindo a velocidade da linguagem C com as estruturas de dados avançadas do C++:

- **C (I/O e Performance):** Utilização de `fopen`, `fscanf` com expressões regulares de formatação (`%[^,]`) e arrays primitivos para uma leitura de arquivo extremamente rápida e direta em disco.
- **C++ STL (Estruturas Dinâmicas):** Uso extensivo de `std::map` (Árvores Binárias de Busca) para mapeamento de clientes/produtos sem perda de performance, e `std::vector` para gestão dinâmica de memória sem necessidade de ponteiros manuais complexos.

## 📁 Estrutura do Projeto

```
📦 sistema-recomendacao
 ┣ 📜 dados_venda_cluster_0.csv   # Base de dados (Histórico de compras)
 ┣ 📜 dadosCSV.h                  # Estruturas primitivas (C) para leitura do buffer
 ┣ 📜 moduloListaCompras.h / .cpp # Módulo de parsing, mapeamento e criação da lista
 ┣ 📜 moduloSimilaridade.h / .cpp # Módulo matemático (Álgebra Linear e Jaccard)
 ┣ 📜 moduloBusca.h / .cpp        # Interface iterativa de pesquisa de clientes
 ┗ 📜 main.cpp                    # Orquestrador principal do sistema
```

*Desenvolvido por Artur Almeida*
