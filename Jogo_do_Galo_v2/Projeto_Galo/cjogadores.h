#ifndef CJOGADORES_H
#define CJOGADORES_H


#include <string>
#include <iostream>
#define DIM 3
using namespace  std;

class CJogador{

private:

    string nome;

public:

    ~CJogador();


    bool quemJogaPrimeiro();
    int posicaoJogador(char matriz[DIM][DIM],int &posicao, int &linha, int &coluna, string &nome);
    void posicaoComputador(char matriz[DIM][DIM], int &linha, int &coluna);
    void escerveNome(string &nome);
    void continua(char tabuleiro[DIM][DIM], string nome, int dificuldade);
    int guardado(char tabuleiro[DIM][DIM],string nome);
};

#endif // CJOGADORES_H
