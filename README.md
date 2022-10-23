# AFDTool

Ferramenta que lê um Autômato Finito Determinístico (AFD) e realiza algumas operações sobre ele.
Projeto desenvolvido para a disciplina de Fundamentos Teóricos da Computação.

## Integrantes

- Lucas Malek Madureira Oliveira
- Lucas Novais da Silva
- Thiago Rodrigues Souza

## Requisitos

- gcc (Ubuntu 11.2.0-19ubuntu1) 11.2.0
- GNU Make 4.3

## Como executar

- Compilar o programa:
```bash
make
```
- Executar com alguma flag e apontar arquivos de entrada/saída:
```bash
./afdtool --flag [arquivo/arquivos de entrada] --output [arquivo de saida]
```
## Flags disponíveis:
**--dot:** transforma um AFD no formato .txt em um arquivo .dot para visualização com o graphviz.

**--reconhecer:** executa uma ou mais palavras contidas em um arquivo .txt de entrada e retorna um arquivo contendo 1 para palavra reconhecida e 0 para palavra não reconhecida.

**--complemento:** a partir de um AFD de entrada, retorna um arquivo .txt contendo o complemento do AFD informado.
