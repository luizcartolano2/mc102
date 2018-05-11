/*Aluno : Luiz Eduardo Targa Chaves Cartolano
  RA: 183012
  O programa em questao visa criar uma agenda de contatos pessoais e profissionais que seja automatizada
  e permita a insercao, exclusao, alteracao e listagem dos nomes para o usuario que a esteja utilizando*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char string[60];
string nome_contato;

//funcao inserir
int inserir(string * nome_pessoal,string * nome_profisional,long long int * cpf_pessoal,long long int * cpf_profissional,string * endereco_pessoal,string * endereco_profissional,long long int * telefone_residencial,long long int * telefone_comercial,long long int * telefone_celular,long long int * telefone_celular2)
{
    int i, posicao,opcao2;
    int resultado;
    long long int cpf,telefone,celular;
    string nome,endereco;

    /*primeiro iremos ler os dados a serem inseridos, depois iremos percorrer todo o vetor e decobrir se ha ou nao espacos vazios, caso haja
    substituiremos os mesmos pelos dados da entrada. Caso nao haja, retornaremos o valor que informa
    que a agenda esta lotada*/

    printf("Informe o tipo de contato:\n");
    scanf("%d",&opcao2);
    printf("Informe o nome do contato:\n");
    scanf(" %[^\n]s",nome);
    printf("Informe o cpf do contato:\n");
    scanf("%lli",&cpf);
    printf("Informe o endereco do contato:\n");
    scanf(" %[^\n]s",endereco);
    printf("Informe telefone do contato:\n");
    scanf("%lli",&telefone);
    printf("Informe o celular do contato:\n");
    scanf("%lli",&celular);

    if(opcao2 == 1)
    {

        for(i = 0; i < 10; i++)
        {

            if(cpf_pessoal[i] == 0)
            {

                posicao = i;
                strcpy(nome_pessoal[posicao],nome);
                cpf_pessoal[posicao]=cpf;
                strcpy(endereco_pessoal[posicao],endereco);
                telefone_residencial[posicao]=telefone;
                telefone_celular[posicao]=celular;
                resultado = 1;
                break;

            }

            else
            {

                resultado = 0;

            }

        }

    }

    if(opcao2 == 2)
    {

        for(i = 0; i < 10; i++)
        {

            if(cpf_profissional[i] == 0)
            {

                posicao = i;
                strcpy(nome_profisional[posicao],nome);
                cpf_profissional[posicao]=cpf;
                strcpy(endereco_profissional[posicao],endereco);
                telefone_comercial[posicao]=telefone;
                telefone_celular2[posicao]=celular;
                resultado = 1;
                break;

            }

            else
            {

                resultado = 0;

            }

        }

    }

    return resultado;

}

//funcao excluir
int excluir(string * nome_pessoal,string * nome_profisional,long long int * cpf_pessoal,long long int * cpf_profissional,string * endereco_pessoal,string * endereco_profissional,long long int * telefone_residencial,long long int * telefone_comercial,long long int * telefone_celular,long long int * telefone_celular2)
{

    /*Primeiro percorreremos todas as strings armazenadas buscando o nome informado pelo usuario para a eclusao
    caso o encontremos, os dados armazenados nas posicoes seguintes a deste nome serao transportadas para a posicao
    anterior. Caso nao o encontremos, sera informado ao usuario que o o nome em questao nao existe*/

    int i, posicao,opcao2;
    int resultado2, comparacao;
    int teste = 0;

    printf("Informe o tipo do contato:\n");
    scanf("%d",&opcao2);
    printf("Informe o nome do contatp:\n");
    scanf(" %[^\n]s",nome_contato);

    if(opcao2 == 1)
    {

        for(i = 0; i < 10; i++)
        {

            comparacao = strcmp(nome_contato,nome_pessoal[i]);

            if(comparacao == 0)
            {

                posicao = i;
                teste++;
                break;

            }

        }

        if(teste == 1)
        {

            for(i = posicao ; i < 10; i++)
            {

                if (i<9)
                {

                    strcpy(nome_pessoal[i],nome_pessoal[i + 1]);
                    cpf_pessoal[i] = cpf_pessoal[i + 1];
                    strcpy(endereco_pessoal[i],endereco_pessoal[i + 1]);
                    telefone_residencial[i] = telefone_residencial[i + 1];
                    telefone_celular[i] = telefone_celular[i + 1];

                }

                else
                {

                    strcpy(nome_pessoal[i],"");
                    cpf_pessoal[i] = 0;
                    strcpy(endereco_pessoal[i],"");
                    telefone_residencial[i] = 0;
                    telefone_celular[i] = 0;

                }

            }

            resultado2 = 1;

        }

        if(teste == 0)
        {

            resultado2 = 0;

        }

    }

    if(opcao2 == 2)
    {

        for(i = 0; i < 10; i++)
        {

            comparacao = strcmp(nome_contato,nome_profisional[i]);

            if(comparacao == 0)
            {

                posicao = i;
                teste++;
                break;

            }

        }

        if(teste == 1)
        {

            for(i = posicao ; i < 10; i++)
            {

                if (i<9)
                {

                    strcpy(nome_profisional[i],nome_profisional[i + 1]);
                    cpf_profissional[i] = cpf_profissional[i + 1];
                    strcpy(endereco_profissional[i],endereco_profissional[i + 1]);
                    telefone_comercial[i] = telefone_comercial[i + 1];
                    telefone_celular2[i] = telefone_celular2[i + 1];

                }

                else
                {

                    strcpy(nome_profisional[i],"");
                    cpf_profissional[i] = 0;
                    strcpy(endereco_profissional[i],"");
                    telefone_comercial[i] = 0;
                    telefone_celular2[i] = 0;

                }

            }

            resultado2 = 1;

        }

        if(teste == 0)
        {

            resultado2 = 0;

        }

    }

    return resultado2;

}

//funcao alterar
int alterar(string * nome_pessoal,string * nome_profisional,long long int * cpf_pessoal,long long int * cpf_profissional,string * endereco_pessoal,string * endereco_profissional,long long int * telefone_residencial,long long int * telefone_comercial,long long int * telefone_celular,long long int * telefone_celular2)
{

    /*Primeiro faremos um loop passando por todos as strings armazenadas e comparando se alguma delas
    eh a string informada pelo usuario, caso a encontremos alteramos as informacoes armazenadas, caso
    nao encontremos informamos que o contato nao existe*/
    //alterar o lugar de leitura do nome
    int i, posicao,opcao2;
    int resultado3, comparacao=1;
    int teste2 = 0;

    printf("Informe o tipo do contato:\n");
    scanf("%d",&opcao2);
    printf("Informe o nome do contato:\n");
    scanf(" %[^\n]s",nome_contato);

    if(opcao2 == 1)
    {

        for(i = 0; i < 10; i++)
        {

            comparacao = strcmp(nome_contato,nome_pessoal[i]);

            if(comparacao == 0)
            {

                teste2++;
                posicao = i;
                break;

            }

        }

        if(teste2 == 1)
        {
            printf("Informe o cpf do contato:\n");
            scanf("%lli",&cpf_pessoal[posicao]);
            printf("Informe o endero do contato:\n");
            scanf(" %[^\n]s",endereco_pessoal[posicao]);
            printf("Informe o telefone do contato:\n");
            scanf("%lli",&telefone_residencial[posicao]);
            printf("Informe o celular do contato:\n");
            scanf("%lli",&telefone_celular[posicao]);
            resultado3 = 1;

        }

        if(teste2 == 0)
        {

            resultado3 = 0;

        }

    }


    if(opcao2 == 2)
    {

        for(i = 0; i < 10; i++)
        {

            comparacao = strcmp(nome_contato,nome_profisional[i]);

            if(comparacao == 0)
            {

                teste2++;
                posicao = i;
                break;

            }

        }

        if(teste2 == 1)
        {

            printf("Informe o cpf do contato:\n");
            scanf("%lli",&cpf_profissional[posicao]);
            printf("Informe o endero do contato:\n");
            scanf(" %[^\n]s",endereco_profissional[posicao]);
            printf("Informe o telefone do contato:\n");
            scanf("%lli",&telefone_comercial[posicao]);
            printf("Informe o celular do contato:\n");
            scanf("%lli",&telefone_celular2[posicao]);
            resultado3 = 1;

        }

        if(teste2 == 0)
        {

            resultado3 = 0;

        }

    }

    return resultado3;

}

//funcao buscar
int buscar(string * nome_pessoal,string * nome_profisional,long long int * cpf_pessoal,long long int * cpf_profissional,string * endereco_pessoal,string * endereco_profissional,long long int * telefone_residencial,long long int * telefone_comercial,long long int * telefone_celular,long long int * telefone_celular2)
{

    /*Primeiro faremos um loop passando por todos as strings armazenadas e comparando se alguma delas
    eh a string informada pelo usuario, caso a encontremos avisamos que o contato foi buscado com sucesso,
    caso nao encontremos informamos que o contato nao existe*/

    int i, posicao,opcao2;
    int comparacao, resultado4;
    int teste3 = 0;

    printf("Informe o tipo de contato:\n");
    scanf("%d",&opcao2);
    printf("Informe o nome do contato:\n");
    scanf(" %[^\n]s",nome_contato);

    if(opcao2 == 1)
    {

        for(i = 0; i < 10; i++)
        {

            comparacao = strcmp(nome_contato,nome_pessoal[i]);

            if(comparacao == 0)
            {

                teste3++;
                posicao = i;
                break;

            }

        }

        if(teste3 == 1)
        {

            printf("%s\n",nome_pessoal[posicao]);
            printf("%lli\n",cpf_pessoal[posicao]);
            printf("%s\n",endereco_pessoal[posicao]);
            printf("%lli\n",telefone_residencial[posicao]);
            printf("%lli\n",telefone_celular[posicao]);
            resultado4 = 1;

        }

        if(teste3 == 0)
        {

            resultado4 = 0;

        }

    }


    if(opcao2 == 2)
    {

        for(i = 0; i < 10; i++)
        {

            comparacao = strcmp(nome_contato,nome_profisional[i]);

            if(comparacao == 0)
            {

                teste3++;
                posicao = i;
                break;

            }

        }

        if(teste3 == 1)
        {

            printf("%s\n",nome_profisional[posicao]);
            printf("%lli\n",cpf_profissional[posicao]);
            printf("%s\n",endereco_profissional[posicao]);
            printf("%lli\n",telefone_comercial[posicao]);
            printf("%lli\n",telefone_celular2[posicao]);
            resultado4 = 1;

        }

        if(teste3 == 0)
        {

            resultado4 = 0;

        }

    }

    return resultado4;

}

//funcao listar pessoais
int listar_pessoais(string * nome_pessoal,long long int * cpf_pessoal,string * endereco_pessoal,long long int * telefone_residencial,long long int * telefone_celular)
{

    /*Primeiro fazemos um loop verificando todas as posicoes dos vetores, caso o vetor nao esteja
    vazio incrementamos um a uma variavel teste. Depois de percorrido todas as posicoes, fazemos um
    novo laco para imprimir o que esta nas posicoes nao vazias (por isso ele se inicia no zero e abrange
    ate o numero de posicoes nao vazias, uma vez que estas se encontram no final). Agora, caso a variavel
    teste continue zerada, sabemos que todos os vetores estao vazios, e assim retornamos um valor que indica
    que a agenda esta vazia*/

    int i, teste4 = 0;
    int resultado5;

    for(i = 0; i < 10; i++)
    {

        if(cpf_pessoal[i] != 0)
        {

            teste4++;

        }

    }

    if(teste4 == 0)
    {

        resultado5 = 0;

    }

    else
    {

        for(i = 0; i < teste4; i++)
        {

            printf("%s\n",nome_pessoal[i]);
            printf("%lli\n",cpf_pessoal[i]);
            printf("%s\n",endereco_pessoal[i]);
            printf("%lli\n",telefone_residencial[i]);
            printf("%lli\n",telefone_celular[i]);
            resultado5 = 1;

        }

    }

    return resultado5;

}

//funcao listar profissionais
int listar_profissionais(string * nome_profisional,long long int * cpf_profissional,string * endereco_profissional,long long int * telefone_comercial,long long int * telefone_celular2)
{

    /*Primeiro fazemos um loop verificando todas as posicoes dos vetores, caso o vetor nao estaja
    vazio incrementamos um a uma variavel teste. Depois de percorrido todas as posicoes, fazemos um
    novo laco para imprimir o que esta nas posicoes nao vazias (por isso ele se inicia no zero e abrange
    ate o numero de posicoes nao vazias, uma vez que estas se encontram no final). Agora, caso a variavel
    teste continue zerada, sabemos que todos os vetores estao vazios, e assim retornamos um valor que indica
    que a agenda esta vazia*/

    int i, teste5 = 0;
    int resultado6;

    for(i = 0; i < 10; i++)
    {

        if(cpf_profissional[i] != 0)
        {

            teste5++;

        }

    }

    if(teste5 == 0)
    {

        resultado6 = 0;

    }

    else
    {

        for(i = 0; i < teste5; i++)
        {

            printf("%s\n",nome_profisional[i]);
            printf("%lli\n",cpf_profissional[i]);
            printf("%s\n",endereco_profissional[i]);
            printf("%lli\n",telefone_comercial[i]);
            printf("%lli\n",telefone_celular2[i]);
            resultado6 = 1;

        }

    }

    return resultado6;

}

//funcao listar todos
void lista_todos(string * nome_pessoal,string * nome_profisional,long long int * cpf_pessoal,long long int * cpf_profissional,string * endereco_pessoal,string * endereco_profissional,long long int * telefone_residencial,long long int * telefone_comercial,long long int * telefone_celular,long long int * telefone_celular2)
{

    /*Primeiro fazemos um loop verificando todas as posicoes dos vetores, caso o vetor nao esteja
    vazio incrementamos um a uma variavel teste. Depois de percorrido todas as posicoes, fazemos um
    novo laco para imprimir o que esta nas posicoes nao vazias (por isso ele se inicia no zero e abrange
    ate o numero de posicoes nao vazias, uma vez que estas se encontram no final). Agora, caso a variavel
    teste continue zerada, sabemos que todos os vetores estao vazios. Ao fim de cada listagem ele imprime
    um "Listado com sucesso", por isso todas as impressoes estao na propria funcao, e ela eh declarada como
    "void" .Realizamos a operacao tanto para os contatos pessoais quanto para os profissionais */

    int i, teste5 = 0, teste6 = 0;
    int resultado7=0, resultado8=0;

    for(i = 0; i < 10; i++)
    {

        if(cpf_pessoal[i] != 0)
        {

            teste5++;

        }

    }

    if(teste5 != 0)
    {

        for(i = 0; i < teste5; i++)
        {

            printf("%s\n",nome_pessoal[i]);
            printf("%lli\n",cpf_pessoal[i]);
            printf("%s\n",endereco_pessoal[i]);
            printf("%lli\n",telefone_residencial[i]);
            printf("%lli\n",telefone_celular[i]);
            resultado7=1;

        }

    }

    if(resultado7==0)
    {

        printf("Desculpe, agenda vazia!\n");

    }

    else if(resultado7 == 1)
    {

        printf("Listado com sucesso!\n");

    }

    for(i = 0; i < 10; i++)
    {

        if(cpf_profissional[i] != 0)
        {

            teste6++;

        }

    }

    if(teste6 != 0)
    {

        for(i = 0; i < teste6; i++)
        {

            printf("%s\n",nome_profisional[i]);
            printf("%lli\n",cpf_profissional[i]);
            printf("%s\n",endereco_profissional[i]);
            printf("%lli\n",telefone_comercial[i]);
            printf("%lli\n",telefone_celular2[i]);
            resultado8=1;

        }

    }

    if(resultado8==0)
    {

        printf("Desculpe, agenda vazia!\n");

    }

    else if(resultado8 == 1)
    {

        printf("Listado com sucesso!\n");

    }

}


int main(void)
{
    //escolhe a funcao a ser executada
    int opcao;

    //variaveis auxiliares
    int i, resultado, resultado2, resultado3, resultado4, resultado5, resultado6;

    //variaveis nas quais serao armazenadas as informacoes dos contatos
    string nome_pessoal[10], endereco_pessoal[10], nome_profisional[10], endereco_profissional[10];
    long long int cpf_pessoal[10], cpf_profissional[10];
    long long int telefone_residencial[10], telefone_comercial[10];
    long long int telefone_celular[10],telefone_celular2[10];

    //zerando todos os vetores
    for(i = 0; i < 10; i++)
    {

        strcpy(nome_pessoal[i],"");
        strcpy(nome_profisional[i],"");
        strcpy(endereco_pessoal[i],"");
        strcpy(endereco_profissional[i],"");
        cpf_profissional[i] = 0;
        cpf_pessoal[i] = 0;
        telefone_celular[i] = 0;
        telefone_celular2[i] = 0;
        telefone_comercial[i] = 0;
        telefone_residencial[i] = 0;

    }

    printf("Opcoes: 1 - inserir\n        2 - excluir\n        3 - alterar\n        4 - buscar\n        5 - listar pessoais\n        6 - listar profissionais\n        7 - listar todos\n        0 - sair\n");

    do
    {

        printf("Escolha uma opcao: \n");
        scanf("%d",&opcao);

        if(opcao == 1)
        {

            resultado = inserir(nome_pessoal,nome_profisional,cpf_pessoal,cpf_profissional,endereco_pessoal,endereco_profissional,telefone_residencial,telefone_comercial,telefone_celular,telefone_celular2);

            if(resultado == 0)
            {

                printf("Desculpe, agenda lotada!\n");

            }

            if(resultado == 1)
            {

                printf("Inserido com sucesso!\n");

            }

        }

        else if(opcao == 2)
        {

            resultado2 = excluir(nome_pessoal,nome_profisional,cpf_pessoal,cpf_profissional,endereco_pessoal,endereco_profissional,telefone_residencial,telefone_comercial,telefone_celular,telefone_celular2);

            if(resultado2 == 0)
            {

                printf("Desculpe, contato %s nao existe!\n", nome_contato);

            }

            if(resultado2 == 1)
            {

                printf("Excluido com sucesso!\n");

            }

        }

        else if(opcao == 3)
        {

            resultado3 = alterar(nome_pessoal,nome_profisional,cpf_pessoal,cpf_profissional,endereco_pessoal,endereco_profissional,telefone_residencial,telefone_comercial,telefone_celular,telefone_celular2);

            if(resultado3 == 0)
            {

                printf("Desculpe, contato %s nao existe!\n", nome_contato);

            }

            if(resultado3 == 1)
            {

                printf("Alterado com sucesso!\n");

            }

        }

        else if(opcao == 4)
        {

            resultado4 = buscar(nome_pessoal,nome_profisional,cpf_pessoal,cpf_profissional,endereco_pessoal,endereco_profissional,telefone_residencial,telefone_comercial,telefone_celular,telefone_celular2);

            if(resultado4 == 0)
            {

                printf("Desculpe, contato %s nao existe!\n", nome_contato);

            }

            if(resultado4 == 1)
            {

                printf("Buscado com sucesso!\n");

            }

        }

        else if(opcao == 5)
        {

            resultado5 = listar_pessoais(nome_pessoal,cpf_pessoal,endereco_pessoal,telefone_residencial,telefone_celular);

            if(resultado5 == 0)
            {

                printf("Desculpe, agenda vazia!\n");

            }

            if(resultado5 == 1)
            {

                printf("Listado com sucesso!\n");

            }

        }

        else if(opcao == 6)
        {

            resultado6 = listar_profissionais(nome_profisional,cpf_profissional,endereco_profissional,telefone_comercial,telefone_celular2);

            if(resultado6 == 0)
            {

                printf("Desculpe, agenda vazia!\n");

            }

            if(resultado6 == 1)
            {

                printf("Listado com sucesso!\n");

            }

        }
        else if(opcao == 7)

        {

            lista_todos(nome_pessoal,nome_profisional,cpf_pessoal,cpf_profissional,endereco_pessoal,endereco_profissional,telefone_residencial,telefone_comercial,telefone_celular,telefone_celular2);

        }

        else if(opcao == 0)
        {

            printf("Obrigado!\n");

        }

    }
    while(opcao !=0);

    return 0;

}
