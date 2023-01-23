#ifndef ORDENACAO_H
#define ORDENACAO_H

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Structs
typedef struct ponto Ponto;
typedef struct rota Rota;

Ponto* alocaPonto(int);
void desalocaPontos(Ponto **);
double calcularDistancia(Ponto *, int, int);
double calcularDeslocamento(Ponto *, int);
void ordena(Ponto **, int);
void imprime(Ponto *, int);

#endif