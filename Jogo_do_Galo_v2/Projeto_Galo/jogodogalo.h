#ifndef JOGODOGALO_H
#define JOGODOGALO_H
#define DIM 3
#define ESPACO ' '
#include <string>
using namespace  std;



void menuPrincipal();
void menuSecundario();
void cordenadas();
void estatisticaPartida();
void menuCaixa (int cont_jogo, int cont_win, int cont_lose, int cont_draw,  int contaJogadas,string nivel);
void mostraPosicao();


class CTabuleiro{

private:
        char matriz[DIM][DIM];
public:

    ~CTabuleiro();
    CTabuleiro(char matriz[DIM][DIM]);
    void resetMatriz(char matriz[DIM][DIM]);
    int verificaResultado(char matriz[DIM][DIM]);
    void NivelElementar(char matriz[DIM][DIM], int linha, int coluna, bool jogador);
    void  mostraResultado(int &n);
    void NivelBasico(char matriz[DIM][DIM], int linha, int coluna, bool jogador);
    void NivelMedio(char matriz[DIM][DIM], int linha, int coluna, bool jogador);
    void NivelDestruidor(char matriz[DIM][DIM], int linha, int coluna, bool jogador,int jogada);
    void mostraMatriz(char matriz[DIM][DIM]);
    int retornaCasas(char matriz[DIM][DIM]);
};


#endif // JOGODOGALO_H
