#include "ordenacao.h"
#define MAXTAM 1000
struct ponto
{
    int x;
    int y;
};

struct rota
{
    Ponto *pontos;
    char id[5];
    double distancia;
    double deslocamento;
};

Ponto *alocaPonto(int ordem)
{
    Ponto *vetponto = calloc(ordem, sizeof(Ponto));
    return vetponto;
}
void desalocaPontos(Ponto **vetor)
{
    free(*vetor);
}

Rota *alocaRota(int qtdRotas, int nPontos)
{
    int i = 0;
    Rota *rotas = (Rota *)malloc(qtdRotas * sizeof(Rota));
    for (; i < qtdRotas; i++)
    {
        rotas[i].pontos = alocaPonto(nPontos);
    }
    return rotas;
}

void desalocaRota(Rota *rotas, int qtdRotas)
{
    int i = 0;
    for (; i < qtdRotas; i++)
    {
        free(rotas[i].pontos);
    }

    free(rotas);
}

void lerRotas(Rota *rotas, int qtdRotas, int qtdPontos)
{
    int i = 0;

    for (; i < qtdRotas; i++)
    {
        scanf("%s", rotas[i].id);

        int j = 0;
        for (; j < qtdPontos; j++)
        {
            scanf("%d", &rotas[i].pontos[j].x);
            scanf("%d", &rotas[i].pontos[j].y);
        }
    }
}

void calcularDistancia(Rota *rota, int qtdPontos, int qtdRotas)
{
    int j = 0;
    for (; j < qtdRotas; j++)
    {
        double soma = 0;
        int i = 0;
        for (; i < qtdPontos - 1; i++)
        {
            soma += (float) sqrt(pow(rota[j].pontos[i].x - rota[j].pontos[i + 1].x, 2) + (pow(rota[j].pontos[i].y - rota[j].pontos[i + 1].y, 2)));
            
        }
        soma = round(soma*100)/100;
        rota[j].distancia = soma;
    }
};

void calcularDeslocamento(Rota *rota, int qtdPontos, int qtdRotas)
{
    int i = 0;
    for (; i < qtdRotas; i++)
    {
        rota[i].deslocamento = sqrt(pow(rota[i].pontos[0].x - rota[i].pontos[qtdPontos - 1].x, 2) + pow(rota[i].pontos[0].y - rota[i].pontos[qtdPontos - 1].y, 2));
    }
}

void ordena(Rota *rotas, int qtdRotas)
{

    Rota aux;

    for (int i = 0; i < qtdRotas; i++)
    {
        for (int j = 0; j < qtdRotas; j++)
        {
            if (rotas[i].distancia > rotas[j].distancia)
            {
                aux = rotas[j];
                rotas[j] = rotas[i];
                rotas[i] = aux;
            }
            else if ((rotas[i].distancia == rotas[j].distancia) && (rotas[i].deslocamento < rotas[j].deslocamento))
            {
                aux = rotas[j];
                rotas[j] = rotas[i];
                rotas[i] = aux;
            }
            else if ((rotas[i].distancia == rotas[j].distancia) && (rotas[i].deslocamento == rotas[j].deslocamento) && strcmp(rotas[i].id, rotas[j].id) < 0)
            {
                aux = rotas[j];
                rotas[j] = rotas[i];
                rotas[i] = aux;
            }
        }
    }
}

void imprime(Rota *rotas, int qtdRotas)
{
    int i = 0;
    for (; i < qtdRotas; i++)
    {
        printf("%s %.4lf %.2lf\n", rotas[i].id, rotas[i].distancia, rotas[i].deslocamento);
    }
}

void quickSort(Rota *rotas, int inicio, int final)
{
    int esquerda, direita, pivo;
    Rota aux;
    if (inicio < final)
    {
        pivo = inicio; // posicao do pivo sempre sera o inicio
        esquerda = inicio;
        direita = final;

        while (esquerda < direita)
        {
            while ( (rotas[esquerda].distancia > rotas[pivo].distancia) || (((rotas[esquerda].distancia == rotas[esquerda].distancia)) && (rotas[esquerda].deslocamento < rotas[pivo].deslocamento)) || (((rotas[esquerda].distancia == rotas[pivo].distancia)) && ((rotas[esquerda].deslocamento == rotas[pivo].deslocamento)) && (strcmp(rotas[esquerda].id, rotas[pivo].id) < 0)))
            {
                esquerda++;
            }
            while  ((rotas[direita].distancia < rotas[pivo].distancia) ||   (((rotas[direita].distancia == rotas[pivo].distancia)) && (rotas[direita].deslocamento > rotas[pivo].deslocamento)) || ((((rotas[direita].distancia == rotas[pivo].distancia)) && ((rotas[direita].deslocamento==rotas[pivo].deslocamento)) && (strcmp(rotas[direita].id, rotas[pivo].id) > 0))))// elementos menores que o pivo devem ficar a diretia
            {
                direita--;
            }
            if (esquerda < direita) // troca os elementos esquerda e direita
            {
                aux = rotas[esquerda];
                rotas[esquerda] = rotas[direita];
                rotas[direita] = aux;
            }
        }
        aux = rotas[pivo];
        rotas[pivo] = rotas[direita]; // elemento pivo troca para a posicao final
        rotas[direita] = aux;
        quickSort(rotas, inicio, direita - 1); // chama a funcao quicksort recursivamente passando o mesmo vetor, porém o inicio e o fim correspondem aos subvetores antes do pivo anterior e depois do pivo anterior
        quickSort(rotas, direita + 1, final);
    }

   
}

int verificaIgualdade(double n1, double n2)
{
    return abs(n1-n2) < 0.008? 1: 0;
}

int arredonda(double n)
{
    return (n >= 0) ? (int)(n + 0.5) : (int)(n - 0.5);
}