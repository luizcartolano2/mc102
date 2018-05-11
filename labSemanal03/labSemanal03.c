/*Aluno: Luiz Eduardo T. C. Cartolano
  RA: 183012
  O programa tem como objetivo realizar o processamento de imagens, isto e,
  a partir de uma matriz compactada de uma imagem, vamos, em um primeiro momento
  descompacta-la, depois formaremos a matriz cinza, e a partir desta, aplicaremos
  um filtro na ultima etapa*/

#include <stdio.h>

unsigned char matriz_R[600][600];
unsigned char matriz_G[600][600];
unsigned char matriz_B[600][600];
unsigned char matriz_cinza[600][600];
int matriz_M[10][10];
int matriz_P[600][600];
int vetor[100000];
int main(int argc, char **argv)
{

    //declaracao das variaveis auxiliares
    int largura, altura, aux, aux2, divisor, ordem, freq, soma, soma_2=0, multiplicacao;
    int i, j, a;

    /*primeiro faremos a leitura do divisor "D" fornecido na entrada e que sera usado na
    terceira parte do lab*/
    scanf("%d",&divisor);

    /*depois faremos a leitura de um inteiro "X" que representa a ordem da matriz
    M que sera usada na terceira parte do lab*/
    scanf(" %d",&ordem);

    /*uma vez que sabemos a ordem da matriz M, realizaremos a leitura da matriz M, que
    tambem será usada na terceira parte do lab*/
    for(i = 0 ; i < ordem; i++)
    {

        for(j = 0; j < ordem; j++)
        {
            scanf(" %d",&matriz_M[i][j]);
        }
    }

//leitura das dimensoes do pixel
    scanf(" %d %d",&largura,&altura);

    /*enquanto a soma de elementos da matriz Red for menor que altura*largura
    executaremos o seguinte loop, lendo um par de valores frequencia e intensidade
    e atribuindo-o para a matriz Red, depois repetiremos o processo para as matrizes
    Green e Blue*/
    aux = 0;
    soma = 0;
    i = 0;
    j = 0;

    while(soma < largura * altura)
    {
        scanf("%d %d",&vetor[aux],&vetor[aux+1]);

        /*o vetor[aux] gurda a intensidade de repeticoes do numero armazenado no vetor[aux+1],
        assim, enquanto aquele for diferente de 0, atribuiremos a matriz Red o valor armazenado
        no vetor[aux+1]. Quando o vetor[aux] for igual repetiremos o processo para um novo par
        intensidade,numero*/
        freq=vetor[aux];
        while(freq > 0)
        {
            matriz_R[i][j] = vetor[aux+1];
            freq--;
            j++;
            if(j == largura)
            {
                j = 0;
                i++;
            }
        }
        soma+=vetor[aux];
        aux = aux + 2;

    }
    soma = 0;
    aux = 0;
    i = 0;
    j = 0;

    while(soma < largura * altura)
    {
        scanf("%d %d",&vetor[aux],&vetor[aux+1]);
        freq=vetor[aux];
        while(freq > 0)
        {
            matriz_G[i][j] = vetor[aux+1];
            freq--;
            j++;
            if(j == largura)
            {
                j = 0;
                i++;
            }
        }
        soma+=vetor[aux];
        aux = aux + 2;
    }
    soma = 0;
    aux = 0;
    i = 0;
    j = 0;

    while(soma < largura * altura)
    {
        scanf(" %d %d",&vetor[aux],&vetor[aux+1]);
        freq=vetor[aux];
        while(freq > 0)
        {
            matriz_B[i][j] = vetor[aux+1];
            freq--;
            j++;
            if(j == largura)
            {
                j = 0;
                i++;
            }
        }
        soma+=vetor[aux];
        aux = aux + 2;
    }

    /*Na segunda parte do lab iremos calcular uma matriz em tons de cinza
    para tal, usaremos a formula fornecida no enunciado. Usaremos um laco
    para "rodar" todos os valores de R, G e B. */
    for(i = 0; i < altura; i++)
    {

        for(j = 0; j < largura; j++)
        {
            matriz_cinza[i][j] = (matriz_R[i][j] + matriz_G[i][j] + matriz_B[i][j])/3;
        }
    }

    /*caso a orde de M seja tres, a matriz P tera a primeira e a ultima linha e coluna
    iguais a matriz cinza. Caso a ordem seja cinco, as duas primeiras e as duas ultimas
    linhas e colunas, e assim sucessivamente. Primeiro copiaremos toda a matriz cinza
    para a matriz P e depois aplicaremos o filtro nas localidades devidas*/
    for(i = 0; i < altura; i++)
    {

        for(j = 0; j < largura; j++)
        {
            matriz_P[i][j] = matriz_cinza[i][j];
        }
    }

    /*agora aplicaremos o filtro, para tal iremos criar 4 lacos, dois deles para alterar os valores
    de i e j que representam o elemento da matriz sobre o qual aplicaremos o filtro. E os outros dois
    para alterar o valor de "a" que nos permitira percorrer ambas as matrizes (cinza e filtro) ao mesmo tempo*/
    a = (ordem - 1)/2;
    for(i = a ; i < altura - a; i++)
    {
        for(j = a ; j < largura  - a; j++)
        {
            for(aux = -a; aux < a + 1; aux++)
            {
                for(aux2 = -a; aux2 < a + 1; aux2++)
                {
                    multiplicacao = matriz_cinza[i + aux][j + aux2] * matriz_M[aux + a][aux2 + a];
                    soma_2 += multiplicacao;
                }
            }
            matriz_P[i][j] = soma_2/divisor;
            if(matriz_P[i][j] < 0)
            {
                matriz_P[i][j] = 0;
            }

            else if(matriz_P[i][j] > 255)
            {
                matriz_P[i][j] = 255;
            }
            soma_2 = 0;
        }
    }

    printf("P2\n");
    printf("%d %d\n",largura,altura);
    printf("255\n");
    for(i = 0; i < altura; i++)
    {
        for(j = 0; j < largura; j++)
        {
            if(j == largura - 1)
            {
                printf("%d",matriz_P[i][j]);
            }
            else
            {
                printf("%d ",matriz_P[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
