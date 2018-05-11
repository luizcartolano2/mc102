/*Nome: Luiz Eduardo Targa Chaves Cartolano
  RA: 183012
  O programa tem como objetivo descobrir quem eh o melhor funcionario
  de uma empresa. Alem disso, realiza tal fato por meio de metodos recursivos*/

#include<stdio.h>
#include<string.h>
#include<math.h>

typedef char string[30];
typedef struct{
  string fun, chefe;
  int pi, sub, nivel, s_chef;
  double pr, sal,qual,lgt;
}funcionario;

void presidente(funcionario func[],int n_func,string pres);
void subordinados(funcionario func[],int n_func);
void hierarquia(funcionario func[],string pres,int n_func);
void s_chefe(funcionario func[],int n_func);
double p_rel(funcionario func[],int posicao, string pres,int n_func);
double salario(funcionario func[],int posicao, int n_func);
double lg(double niv);
void qualidade(funcionario func[], int fator, int n_func);

int main(void){

  string pres, nome;

  //struct que armazena as informacoes do funcionario
  funcionario func[100];

  //variaveis auxiliares
  int n_func, fator, posicao ,melhor=0;
  double g_tot, s_sal = 0, constante,niv;

  //variaveis contadoras
  int i, j;

  //zerando todas as variaveis
  for(i = 0; i < 100; i++){
    strcpy(func[i].chefe," ");
    func[i].sub = 0;
    func[i].nivel = 0;
  }

  //leitura dos dados auxiliares
  scanf("%lf",&g_tot);
  scanf("%d",&fator);
  scanf("%d",&n_func);

  //leitura do nome dos funcionarios e sua produtividade absoluta
  for(i = 0; i < n_func; i++){
    scanf(" %s %d",func[i].fun,&func[i].pi);
  }

  //leitura dos funcionarios e seus respectivos chefes
  for(i = 0; i < n_func - 1; i++){
    scanf(" %s",nome);
      for(j = 0; j < n_func; j++){
        if(strcmp(nome,func[j].fun) == 0){
          scanf(" %s",func[j].chefe);
        }
      }
  }

  //chama a funcao presidente
  presidente(func,n_func,pres);

  //chama a funcao que calcula o numero de subordinados
  subordinados(func,n_func);

  //chama a funcao que calcula a hierarquia
  hierarquia(func,pres,n_func);

  //chama a funcao que calcula a produtividade relativa
  for(i = 0; i < n_func;i++){
    if(strcmp(pres,func[i].fun) == 0){
      posicao = i;
      func[posicao].pr = p_rel(func,posicao,pres,n_func);
    }
  }

  //chama a funcao que calcula o numero de subordinados do chefe
  s_chefe(func,n_func);
  for(i=0;i<n_func;i++){
  }
  //chama a funcao que calcula o salario dos funcionarios
  for(i = 0 ; i < n_func; i++){
    if(func[i].sub == 0){
      func[i].sal = salario(func,i,n_func);
    }
  }

  for(i = 0; i < n_func; i++){
    s_sal = s_sal + func[i].sal;
  }

  constante = g_tot / s_sal;

  for(i = 0; i < n_func; i++){
    func[i].sal = func[i].sal * constante;
  }

  //chama a funcao que calcula o log* dos niveis (a ser usado no indice de qualidade)
  for(i = 0; i < n_func; i++){
    niv = (double)func[i].nivel;
    func[i].lgt = lg(niv);
  }
  //chama a funcao que calcula o indice de Qualidade
  qualidade(func,fator,n_func);

  for(i = 0; i < n_func; i++){
    if(func[melhor].qual<func[i].qual){
      melhor=i;
    }
  }
  printf("%s %.2lf\n",func[melhor].fun,func[melhor].qual);

}

void presidente(funcionario func[],int n_func,string pres){
  /*Acharemos o presidente para facilitar na hora de calcular a hierarquia.
  Para isso, iremos percorrer a struct chefe procurando a posicao em que
  ela esta vazia, visto que o presidente eh o unico que nao possui chefe*/

  int i;

  for(i = 0; i < n_func; i++){
    if(strcmp(func[i].chefe," ") == 0){
      strcpy(pres,func[i].fun);
      func[i].nivel = 1;
    }
  }

  return;

}

void subordinados(funcionario func[],int n_func){
  /*Para calcular o numero de subordinados veremos o numero de vezes
  que alguem aparece como chefe. O numero sera importante ao longo do
  programa*/

  int i,j;

  for(i = 0; i < n_func; i++){
    for(j = 0; j < n_func; j++){
      if(strcmp(func[i].fun,func[j].chefe) == 0){
        func[i].sub++;
      }
    }
  }
  return;
}

void hierarquia(funcionario func[],string pres,int n_func){
  /*Para calcular a hierarquia iremos sempre considerar alguem
  como presidente, a partir dai, achar seus surbodinados aumentando
  seus respectivos niveis*/

  int i, j;
  string n_pres;

  for(i = 0; i < n_func; i++){
    if(strcmp(pres,func[i].fun) == 0){
      for(j = 0; j < n_func ; j++){
        if(strcmp(pres,func[j].chefe) == 0){
          func[j].nivel = func[i].nivel + 1;
          strcpy(n_pres,func[j].fun);
          hierarquia(func,n_pres,n_func);
        }
      }
    }
  }
  return;
}

void s_chefe(funcionario func[],int n_func){

  /*afim de facilitar a realizacao da funcao salario iremos encontrar o numero
  de subordinados de um chefe separadamente*/

  int i, j;

  for(i = 0; i < n_func; i++){
    for(j = 0; j < n_func; j++){
      if(strcmp(func[i].chefe,func[j].fun) == 0){
        func[i].s_chef = func[j].sub;
      }
    }
  }
  return;
}

double p_rel(funcionario func[],int posicao, string pres,int n_func){
  /*Acharemos a producao relativa de cada funcionario com base
  nos seus subordinados*/

  int i;
  double soma = 0, prod;
  string n_pres;

  if(func[posicao].sub == 0){
    func[posicao].pr=func[posicao].pi;
    return func[posicao].pr;
  }

  else{
    for(i = 0; i < n_func; i++){
      if(strcmp(pres,func[i].chefe) == 0){
        strcpy(n_pres,func[i].fun);
        prod = p_rel(func,i,n_pres,n_func);
        soma = soma + prod;
      }
    }
    func[posicao].pr=0.5 * (func[posicao].pi + (1.0/func[posicao].sub)*soma);
    return func[posicao].pr;
  }
}

double salario(funcionario func[],int posicao, int n_func){
  /*Calculo do salario dos funcionarios com base no salario do chefe*/

  int j;
  double sl=0.0;

  if(strcmp(func[posicao].chefe," ") == 0){
    func[posicao].sal=10.0;
    return 10.0;
  }
  else{
    for(j = 0; j < n_func; j++){
      if(strcmp(func[posicao].chefe,func[j].fun) == 0){
        sl = salario(func,j,n_func);
      }
    }
    func[posicao].sal=(((double)func[posicao].s_chef/((double)func[posicao].s_chef + 1.0)) * sl);
    return func[posicao].sal;
  }
}

double lg(double niv){
  /*Funcao que calcula o log do Nivel*/

  double Nivel;

  if(niv <= 1){
    return 0;
  }
  else{
    Nivel = ((log (niv))/(log (2)));
    Nivel = 1.0 + lg(Nivel);
    return Nivel;
  }
}

void qualidade(funcionario func[],int fator, int n_func){
  /*Funcao que calcula o indice de qualidade*/

  int i;

  for(i = 0; i < n_func; i++){
    func[i].qual = fator * (func[i].lgt + 1) * ((func[i].pr)/(log(func[i].sal)/log (2)));
  }
  return;
}
