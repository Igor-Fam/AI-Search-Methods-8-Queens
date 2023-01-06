#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <vector>
#include <queue>

#define N 4

using namespace std;

class Tabuleiro
{
private:
    char matriz [N][N];
    int linha;
    int colunaRainha;
    int quantA, quantF, quantQ;

public:
    friend class No;
    Tabuleiro(int linha, bool r = false);
    // ~Tabuleiro();
    int getLinha(){ return linha; };
    void setLinha(int linha){ this->linha = linha; };
    void adicionaRainha(int coluna);
    bool verificaResolvido(){ return linha+1 == N; };
    bool verificaImpasse();
    void imprimeTabuleiro();
    queue<int> verificaDisponiveis();
    vector<int> verificaDisponiveis1();
    void atualizaHeuristica();
    void verificaColunaRainha();
    int getQuantF() { return quantF; };
    int getQuantA() { return quantA; };
    int getQuantQ() { return quantQ; };
};

#endif