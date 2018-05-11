#include <stdio.h>
#include <string.h>
#include <math.h>

#define maxAlunos 40
#define maxNome 201

/*******estruturas***********/

//estrutura para data
typedef struct {
	int dia;
	int mes;
	int ano;
} data;

//estrutura para Pessoa (vértice do grafo)
typedef struct {
	char nome[maxNome];
	data nasc;
	char genero;
	char pref;
} pessoa;

//estrutura para os relacionamentos de afinidade (aresta do grafo)
typedef struct {
	pessoa *alunoA, *alunoB;
	float peso;
} aresta;

/*********protótipos das funções**********/

int gerarAresta (int[][maxAlunos], aresta[], pessoa[], int);
void printGrafo(aresta[], int);
pessoa* popular(aresta[], int);
void soundex(char[],char[]);
int calcIdade (data, data);
void codNumerologia (data, data, char[]);
float similaridade(char[], char[]);
float sintonia (float, float, float);


int main (){


	/*******variáveis***********/
	pessoa alunos[maxAlunos]; //vetor de vértices
	aresta afinidade[(maxAlunos*(maxAlunos-1))/2]; //o tamanho do vetor é a máxima quantidade de arestas, visto que não existe autoloop (arestas para ela mesmo) e as arestas são não-direcionadas.
	int i, j; //contadores
	int form[maxAlunos][maxAlunos]; //guardar os valores respondidos no formulário
    	data dataForm;
	int nAlunos, nAresta;
	pessoa *maisPop, *parAluno, *parPerfeito;
	char nomeComp[maxNome], *priNomePop, *priNomePar, codNomePop[5], codNomePar[5], codNumPop[4], codNumPar[4];
	float simNome, simNasc, maxSint=0.0, sint;

	/****ETAPA 01 - Geração dos dados *****/

	scanf("%d/%d/%d\n", &dataForm.dia, &dataForm.mes, &dataForm.ano);
	scanf("%d\n", &nAlunos);
	for (i=0; i<nAlunos; i++){
		scanf("%[^\n]s", alunos[i].nome); //lendo até o \n, ou seja, ler todo o nome do aluno incluindo os espaços
		scanf("%d/%d/%d", &alunos[i].nasc.dia, &alunos[i].nasc.mes, &alunos[i].nasc.ano);
		scanf(" %c %c\n", &alunos[i].genero, &alunos[i].pref);
		for (j=0; j<nAlunos; j++){
			if (j!=i)
				scanf("%d", &form[i][j]);
		}
		if (i!=nAlunos-1)
			scanf("\n");
	}

	//Gerando as arestas do grafo de acordo com os dados do formulário
	nAresta=gerarAresta(form, afinidade, alunos, nAlunos);

//	printGrafo(afinidade, nAresta);



	/**** ETAPA 02 - Definicao pessoa mais popular*****/

	maisPop=popular(afinidade, nAresta);


	/***** ETAPA 03 - Calculando a sintonia ******/

	//Etapa03.A para o aluno mais popular
	strcpy(nomeComp, (*maisPop).nome);
	priNomePop = strtok(nomeComp," ");
	soundex(priNomePop,codNomePop);

	//Etapa03.B para o aluno mais popuplar
	codNumerologia((*maisPop).nasc, dataForm, codNumPop);

	//Etapas para cada par conectado ao aluno mais popular e de acordo com a preferencia do mais popular
	for (i=0; i<nAresta;i++){
		//definindo os pares do aluno mais popular
		if (maisPop==afinidade[i].alunoA)
			parAluno=afinidade[i].alunoB;
		else if (maisPop==afinidade[i].alunoB)
			parAluno=afinidade[i].alunoA;
		else continue; //se a aresta nao contem o aluno mais popular, ir para a proxima aresta
		if ((*parAluno).genero==(*maisPop).pref){
			//Etapa03.A
			strcpy(nomeComp, (*parAluno).nome);
			priNomePar = strtok(nomeComp," ");
			soundex(priNomePar,codNomePar);
			//Etapa03.B
			codNumerologia((*parAluno).nasc, dataForm, codNumPar);
			//Etapa03.C
			simNome=similaridade(codNomePop,codNomePar);
			simNasc=similaridade(codNumPop,codNumPar);
			sint=sintonia (simNome, simNasc, afinidade[i].peso);
			if (sint>maxSint){
				maxSint=sint;
				parPerfeito=parAluno;
			}
		}
	}
	printf("%s combina com %s com %.2f de sintonia s2\n", (*maisPop).nome, (*parPerfeito).nome, maxSint);

	return 0;
}

/* ETAPA1 => Função recebe a matriz com os dados do formulario, vetores de arestas e vertices (afinidade e aluno) e a quantidade de alunos. Calcula a média geométrica da afinidade entre pares de alunos. Cria aresta apenas se média >=5.0. Função retorna quantidade de arestas*/
int gerarAresta (int matrizAdj[][maxAlunos], aresta afinidade[], pessoa alunos[], int n){
	float mediaGeom;
	int k=0, i, j;

	//percorrendo apenas o triangulo acima da diagonal principal da matriz e invertendo os valores dos índices para acessar o triangulo abaixo da diagonal principal.
	// isto é, percorre as respostas dos primeiros alunos calculando a média com o par na ordem inversa, por exemplo, faz arestas A->B * B->A.
	for (i=0; i<n-1; i++)
		for (j=i+1; j<n; j++){
			mediaGeom=sqrt(matrizAdj[i][j]*matrizAdj[j][i]); //média geométrica com o valor simétrico da matriz
			if (mediaGeom>=5.0){
				afinidade[k].peso=mediaGeom;
				afinidade[k].alunoA=&alunos[i];
				afinidade[k].alunoB=&alunos[j];
				k++;
			}
		}
	return k;
}

/* Função para imprimir arestas do grafo - Função feita apenas para teste. Descomente-a na MAIN para visualizar o grafo gerado*/
void printGrafo(aresta afinidade[], int nAresta){
	int i;
	pessoa *aux;

	for (i=0; i<nAresta; i++){
		aux=afinidade[i].alunoA;
		printf("%s", (*aux).nome);
		printf("===%.2f===", afinidade[i].peso);
		aux=afinidade[i].alunoB;
		printf("%s\n", (*aux).nome);
	}
}

//ETAPA 02 - Função que recebe o vetor de arestas e a quantidade de arestas. Retorna a pessoa mais popuplar de acordo com a centralidade de grau.
pessoa* popular (aresta afinidade[], int nAresta){
	int cont=0, maxInc=0, i, j;
	pessoa *maisPop, *pessoaI;

	//Conta o grau das pessoas que aparecem no lado esquerdo da aresta (alunoA)
	for (i=0; i<nAresta; i++){
		pessoaI=afinidade[i].alunoA;
		cont=0;
		for (j=0; j<nAresta; j++){
			if (pessoaI==afinidade[j].alunoA || pessoaI==afinidade[j].alunoB)
				cont++;
			if (maxInc<cont){
				maisPop=pessoaI;
				maxInc=cont;
			}
		}
	}

	//Conta o grau das pessoas que aparecem no lado direito da aresta (alunoB)
	for (i=0; i<nAresta; i++){
		pessoaI=afinidade[i].alunoB;
		cont=0;
		for (j=0; j<nAresta; j++){
			if (pessoaI==afinidade[j].alunoA || pessoaI==afinidade[j].alunoB)
				cont++;
			if (maxInc<cont){
				maisPop=pessoaI;
				maxInc=cont;
			}
		}
	}

	return maisPop;
}

//ETAPA 03.A - Funcao soundex codifica o nome de uma pessoa de acordo com o seu fonema.
void soundex(char priNome[], char codNome[]){
	int i=1,j=1;
	codNome[0] = priNome[0];

	for(i=1;i<strlen(priNome);i++){
		if (j<4) //despreza o excesso de consoantes na codificação, mantendo a codificação em 3 dígitos + a letra inicial
			switch (priNome[i]){
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
				case 'y':
				case 'w':
				case 'h':
					break;
				case 'g':
				case 'j':
					codNome[j]='1';
					if (codNome[j]!=codNome[j-1] && codNome[j-1]!=priNome[i]){ //ignora a repetição de código igual e a repetição de consoantes
						j++;
					}
					break;
				case 's':
				case 'z':
				case 'x':
					codNome[j]='2';
					if (codNome[j]!=codNome[j-1] && codNome[j-1]!=priNome[i]){
						j++;
					}
					break;
				case 'c':
				case 'k':
				case 'q':
					codNome[j]='3';
					if (codNome[j]!=codNome[j-1] && codNome[j-1]!=priNome[i]){
						j++;
					}
					break;
				case 'b':
				case 'p':
					codNome[j]='4';
					if (codNome[j]!=codNome[j-1] && codNome[j-1]!=priNome[i]){
						j++;
					}
					break;
				case 'm':
				case 'n':
					codNome[j]='5';
					if (codNome[j]!=codNome[j-1] && codNome[j-1]!=priNome[i]){
						j++;
					}
					break;
				case 'd':
				case 't':
					codNome[j]='6';
					if (codNome[j]!=codNome[j-1] && codNome[j-1]!=priNome[i]){
						j++;
					}
					break;
				case 'f':
				case 'v':
					codNome[j]='7';
					if (codNome[j]!=codNome[j-1] && codNome[j-1]!=priNome[i]){
						j++;
					}
					break;
				case 'l':
					codNome[j]='8';
					if (codNome[j]!=codNome[j-1] && codNome[j-1]!=priNome[i]){
						j++;
					}
					break;
				case 'r':
					codNome[j]='9';
					if (codNome[j]!=codNome[j-1] && codNome[j-1]!=priNome[i]){
						j++;
					}
					break;
			} //fim switch

	} //fim for
	if (j<4){ //completa a codificacao para nomes curtos
		for(i=j;i<4;i++)
			codNome[i]='0';
	}
	codNome[4]='\0';
}

//Função recebe a data de aniversário e a data que o formulario foi aplicado e retorna a idade de uma pessoa naquela data
int calcIdade (data niver, data form){
	int idade;

	idade = form.ano-niver.ano;
	if(niver.mes>form.mes){
		idade --;
	}
	else{
		if(niver.mes==form.mes && niver.dia>form.dia){
			idade--;
		}
	}
	return idade;
}

//Função que recebe a data de nascimento, data do formulario e um vetor de tamanho 3. Insere no vetor recebido a codificação da data de nascimento e idade segundo a numerologia.
void codNumerologia (data niver, data form, char codNum[]){
	int num, resto, idade, i;

	num=niver.dia+niver.mes;

	resto=niver.ano; //separando os dígitos do ano
	for (i=1000;i>0; i/=10){
		num+=resto/i;
		resto%=i;
	}

	while (num>9){ //garantindo que o número seja menor que 10
		num=num/10+num%10;
	}

	codNum[0]=num+48;//48 é o valor correspondente ao 0 na tabela ascii, ou seja, transformamos um inteiro em um char.

	idade=calcIdade(niver, form);

	if (idade>9 && idade<100){
		codNum[1]=idade/10+48;
		codNum[2]=idade%10+48;
	}
	//Adicionando 0 caso a idade seja <9
	else if (idade<=9){
		codNum[1]=idade+48;
		codNum[2]='0';
	}
	else { //Retirando o digito final caso idade >=100
		codNum[1]=idade/100+48;
		codNum[2]=(idade%100)/10+48;
	}

	codNum[3]='\0';
}

//ETAPA 03.C

//Função que recebe duas cadeias de caracteres (tamanhos iguais) e retorna a similaridade entre elas. A comparação feita é caracter a caracter
float similaridade(char cod1[], char cod2[]){
	int i, cont=0;

	for (i=0; i<strlen(cod1); i++){
		if (cod1[i]==cod2[i])
			cont++;
	}

	return (float)cont/strlen(cod1);
}

//Função que recebe a similaridade entre o primeiro nome e data de nascimento da pessoa mais popular e seu par e o peso de afinidade entre elas. Retorna a sintonia entre as pessoas de acordo com a formula do enunciado
float sintonia (float simNome, float simNasc, float pesoAfin){
	float aux;

	aux=3*simNome+5*simNasc+2*pesoAfin/10;

	return aux/10;
}
