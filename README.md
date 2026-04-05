# Sistema de Recomendação (C++ / Python)

Este repositório contém a implementação híbrida em C++ e Python de um **Sistema de Recomendação**, desenvolvido como projeto acadêmico para a disciplina de Programação Estruturada. 

O sistema une a velocidade de processamento e gestão de memória do **C++** com a facilidade de prototipagem e uso do **Python**, através de *bindings* construídos com **Pybind11**. A lógica central utiliza o **Método da Vizinhança (Filtragem Colaborativa)** e a **Distância de Jaccard** para calcular a similaridade de consumo entre os usuários e recomendar novos produtos.

## Funcionalidades e Atividades

O projeto foi construído de forma modular, completando as seguintes etapas funcionais:

- **Módulo de Busca:**
  - Leitura extremamente rápida do arquivo CSV (usando `fscanf` do C).
  - Mapeamento dinâmico de chaves em texto para IDs numéricos utilizando Árvores Binárias de Busca (`std::map`), reduzindo a complexidade temporal para $O(\log N)$.

- **Módulo de Similaridade:**
  - Transformação do histórico de compras em uma matriz de incidência.
  - Multiplicação algébrica da matriz por sua transposta ($A \times A^T$).
  - **Otimização de Simetria:** Redução drástica do tempo de processamento computando apenas o triângulo superior da matriz ($i \le j$) e espelhando os resultados.

- **Módulo de Recomendação:**
  - Aplicação do algoritmo de K-Vizinhos Mais Próximos (KNN).
  - Cálculo de decaimento multiplicativo com base na distância de Jaccard para gerar um vetor de *ranking* de produtos ($R_p \leftarrow R_p \times s(c,s)$).
  - Ordenação dos melhores produtos (`std::sort`) preservando o vínculo de IDs estruturais.

- **Integração Pybind11:**
  - Exposição de funções globais escritas em C++ diretamente para um ecossistema Python.
  - Conversão implícita e automática de tipagens da *Standard Template Library* (STL), como `std::vector` e `std::tuple`, para listas e tuplas nativas do Python.

## Tecnologias e Arquitetura

- **C++11/14:** Responsável por alocação estrutural, acesso rápido em disco e cálculos lineares massivos.
- **Python 3:** Camada de Interface, permitindo chamadas diretas às sub-rotinas compiladas.
- **Pybind11:** Biblioteca  utilizada para criar a ponte entre C++ e Python

## 📁 Estrutura do Projeto

```text
📦 sistema-recomendacao
 ┣ 📜 dados_venda_inicial/        # Diretório com arquivos CSV (Base de dados)
 ┣ 📜 sistema_recomendacao.h      # Cabeçalho global (Structs e Assinaturas)
 ┣ 📜 moduloListaCompras.cpp      # Parsing e estruturação das compras
 ┣ 📜 moduloSimilaridade.cpp      # Computação matemática e Jaccard
 ┣ 📜 moduloRecomendacao.cpp      # Motor de recomendação (Ranqueamento)
 ┣ 📜 moduloBusca.cpp             # Recuperação de histórico de clientes
 ┣ 📜 integration.cpp             # Definições do Pybind11 (Ponte C++ -> Python)
 ┣ 📜 setup.py                    # Script de compilação da extensão em Python
 ┗ 📜 main.py                     # Script Python orquestrador (Testador)
```

*Desenvolvido por Artur Almeida*
