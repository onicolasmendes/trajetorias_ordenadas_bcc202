#include "ordenacao.h"

struct ponto
{
    int x;
    int y;
};

struct rota
{
    Ponto* pontos;
    char id[5];
    double distancia;
    double deslocamento;
};

Ponto *alocaPonto(int ordem){
    Ponto *vetponto = calloc(ordem,sizeof(Ponto));
    return vetponto;
}
void desalocaPontos(Ponto **vetor){
    free(*vetor);
}

