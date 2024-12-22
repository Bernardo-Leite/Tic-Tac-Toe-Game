#ifndef CLISTAJOGADOR_H
#define CLISTAJOGADOR_H
#include <string>
#include <iostream>

using namespace std;

class CListaJogador;

class CNoListaJogador {
public:
    string name;
    int jogos;
    int win;
    int loses;
    int draw;
    CNoListaJogador *proximo;
    friend class CListaJogador;
};

class CListaJogador
{
    CNoListaJogador *cabeca;
public:
    CListaJogador()
    {
        cabeca = NULL;
    }
    // ~CListaJogador();
    // void introduzJogador_Fich();
    void criaFich(string, int, int, int, int);
    void ordenaClassificacao(string name, int jogos, int win, int loses, int draw);
    void mostraLista();
    //  void criaFich();
    void readFicheiro();
};


#endif // CLISTAJOGADOR_H
