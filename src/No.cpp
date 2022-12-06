#include <iostream>
#include <vector>

#include "../include/No.h"
#include "../include/Tabuleiro.h"

using namespace std;

No::No(int linha, int coluna, bool heuristica, Tabuleiro* t){
    this->tabuleiro = new Tabuleiro(linha, heuristica);
    if(t != nullptr){
        this->tabuleiro->setLinha(t->getLinha()+1);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                this->tabuleiro->matriz[i][j] = t->matriz[i][j];
    }

    this->tabuleiro->adicionaRainha(coluna);

    if(heuristica){
        this->h = this->tabuleiro->h;
    }
}

No::~No(){
    for (int i = 0; i < filhos.size(); i++)
        delete filhos[i];
}

bool No::visitaNo(int coluna){

    //verifica se e solucao
    if(this->tabuleiro->verificaResolvido()){
        cout << "Solucao encontrada: " << endl << endl;
        this->tabuleiro->imprimeTabuleiro();
        return true;
    }

    //gera filhos
    if(coluna == -1){ //nao e backtracking, gera todos os filhos
        vector<int> colunasFilhos = this->tabuleiro->verificaDisponiveis();

        cout << "Posicoes possiveis na linha " << this->tabuleiro->getLinha()+1 << ": ";
        for (int i = 0; i < colunasFilhos.size(); i++)
        {
            cout << colunasFilhos[i] << " ";
            filhos.push_back(new No(this->tabuleiro->getLinha(), colunasFilhos[i], this->h, this->tabuleiro));
        }
        cout << endl;
    }
    return false;
}

void No::imprimeFilhos(){
    for (int i = 0; i < filhos.size(); i++)
    {
        cout << "Filho " << i << endl;
        filhos[i]->tabuleiro->imprimeTabuleiro();
    }
    
}