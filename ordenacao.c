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
