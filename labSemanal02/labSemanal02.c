/*Aluno: Luiz Eduardo T. C. Cartolano
  RA: 183012
  Programa que visa descobrir a quantidade de vezes que um determinado evento ocorrera e assim informar
  quanto ele custara aos cofres publicos dessa cidade*/
#include<stdio.h>
int main(void)
{
    double Xmax , Xmin , Ymax , Ymin  ;
    int contador , k, quantidade_galoes_final = 0;
    double x0, y0;
    double x1,y1;
    double x2,y2;
    double area = 0, area_total = 0, area_ilha = 0;
    double Area_Reservatorio = 0, Volume_Reservatorio = 0,quantidade_galoes = 0;
    double Fornecedores, capacidade_galao, preco_inicial, Custo;
    int aniversarios = 0,mes,contador_1;
    int dia_aniversario,mes_aniversario,ano_fim	;
    int sexta = 0, dia_semana = 3;
    int ano, ano_i;
    double  Menor_custo;
    int total;
    /*Leitura das entradas, calculo da area do poligono usando determinante e encontrar os valores
     de Xmax, Xmin, Ymax, Ymin, para assim calcular a area do reservatorio e seu volume*/
    scanf("%d",&k);
    for(contador = 0; contador < k; contador++)
    {
        scanf(" (%lf , %lf)",&x0,&y0);
        scanf(" (%lf , %lf)",&x1,&y1);
        scanf(" (%lf , %lf)",&x2,&y2);
        if((x0>=x1) && (x0>=x2) && (contador == 0))
        {
            Xmax = x0;
        }
        if((x1>=x0) && (x1>=x2) && (contador == 0))
        {
            Xmax = x1;
        }
        if((x2>=x0) && (x2>=x1) && (contador == 0))
        {
            Xmax = x2;
        }

        if((x0<=x1) && (x0<=x2) && (contador == 0))
        {
            Xmin = x0;
        }
        if(x1<=x0 && x1<=x2 && contador == 0)
        {
            Xmin = x1;
        }
        if(x2<=x0 && x2<=x1 && contador == 0)
        {
            Xmin = x2;
        }
        if(y0>=y1 && y0>=y2 && contador == 0)
        {
            Ymax = y0;
        }
        if(y1>=y0 && y1>=y2 && contador == 0)
        {
            Ymax = y1;
        }
        if(y2>=y0 && y2>=y1 && contador == 0)
        {
            Ymax = y2;
        }
        if(y0<=y1 && y0<=y2 && contador == 0)
        {
            Ymin = y0;
        }
        if(y2<=y0 && y2<=y1 && contador == 0)
        {
            Ymin = y2;
        }
        if(x0>=Xmax)
        {
            Xmax = x0;
        }
        if(x0<=Xmin)
        {
            Xmin = x0;
        }
        if(y0>=Ymax)
        {
            Ymax = y0;
        }
        if(y0<=Ymin)
        {
            Ymin = y0;
        }
        if(x1>=Xmax)
        {
            Xmax = x1;
        }
        if(x1<=Xmin)
        {
            Xmin = x1;
        }
        if(y1>=Ymax)
        {
            Ymax = y1;
        }
        if(y1<=Ymin)
        {
            Ymin = y1;
        }
        if(x2>=Xmax)
        {
            Xmax = x2;
        }
        if(x2<=Xmin)
        {
            Xmin = x2;
        }
        if(y2>=Ymax)
        {
            Ymax = y2;
        }
        if(y2<=Ymin)
        {
            Ymin = y2;
        }
        area = 0.5 * ((x0*y1)+(x1*y2)+(x2*y0)-(x2*y1)-(x1*y0)-(x0*y2));
        if(area<0)
        {
            area = -area;
        }
        area_ilha = area;
        while(x2 != x0 || y2 != y0)
        {
            x1 = x2;
            y1 = y2;
            scanf(" (%lf , %lf)",&x2,&y2);
            if(x2>=Xmax)
            {
                Xmax = x2;
            }
            if(y2>=Ymax)
            {
                Ymax = y2;
            }
            if(x2<=Xmin)
            {
                Xmin = x2;
            }
            if(y2<=Ymin)
            {
                Ymin = y2;
            }
            area = 0.5 * ((x0*y1)+(x1*y2)+(x2*y0)-(x2*y1)-(x1*y0)-(x0*y2));
            if(area<0)
            {
                area = -area;
            }
            area_ilha = area_ilha + area;
        }
        area_total += area_ilha;
    }
    Area_Reservatorio = (((Xmax+0.5)-(Xmin-0.5)) * ((Ymax+0.5)-(Ymin-0.5))) - area_total;
    Volume_Reservatorio = (Area_Reservatorio * 0.5) * 1000;
    /*Leitura das entradas de aniversario e ano final do evento*/
    scanf("%d/%d",&dia_aniversario,&mes_aniversario);
    scanf("%d",&ano_fim);
    /*Calculo do numero de aniversarios da cidade durante o tempo que o evento ficara aberto*/
    if(dia_aniversario == 29 && mes_aniversario == 2)
    {
        for(ano_i = 2016; ano_i<=ano_fim; ano_i++)
        {
            if(((ano_i%4 == 0) && (ano_i%100 != 0)) || ((ano_i%400 == 0)&&(ano_i%100 == 0)))
            {
                aniversarios = aniversarios + 1;
            }
        }
    }
    else
    {
        aniversarios = (ano_fim - 2016) + 1 ;
    }
    /*Calculo do numero de sexta-feira 13 que ocorrerao no periodo do evento,
     comecando pelo dia 13/01/2016 (3)*/
    /*Adotaremos o seguinte padrao:Domingo - 0; Segunda - 1;Terca - 2;
     Quarta - 3; Quinta - 4; Sexta - 5; Sabado - 6*/
    for(ano = 2016; ano<=ano_fim; ano++)
    {
        for(mes = 1; mes<=12; mes++)
        {

            if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12 )
            {
				
                if(dia_semana == 5)
                {
                    sexta++;
                    if((dia_aniversario == 12 || dia_aniversario == 14 || dia_aniversario == 13)&&(mes  == mes_aniversario))
                    {
                        sexta--;
                    }
                }
                
                dia_semana = (31%7) + dia_semana;
                if(dia_semana >= 7)
                {
                    dia_semana = dia_semana - 7;
                }
            }
            if(mes == 2)
            {
                if(((ano%4 == 0) && (ano%100 != 0)) || ((ano%400 == 0)&&(ano%100 == 0)))
                {
                    if(dia_semana == 5)
                    {
                        sexta++;
                        if((dia_aniversario == 12 || dia_aniversario == 14 || dia_aniversario == 13)&&(mes == mes_aniversario))
                        {
                            sexta--;
                        }
                    }
                    dia_semana = (29%7) + dia_semana;
                    if(dia_semana >= 7)
                    {
                        dia_semana = dia_semana - 7;
                    }
                }
                else
                {
                    if(dia_semana == 5)
                    {
                        sexta++;
                        if((dia_aniversario == 12 || dia_aniversario == 14 || dia_aniversario == 13)&&(mes == mes_aniversario))
                        {
                            sexta--;
                        }
                    }
                    dia_semana = (28%7) + dia_semana;
                    if(dia_semana >= 7)
                    {
                        dia_semana = dia_semana - 7;
                    }
                }
            }
            if(mes==4 || mes==6 || mes==9 || mes==11)
            {
                if(dia_semana == 5)
                {
                    sexta++;
                    if((dia_aniversario == 12 || dia_aniversario == 14 || dia_aniversario == 13)&&(mes  == mes_aniversario))
                    {
                        sexta--;
                    }
                }
                dia_semana = (30%7) + dia_semana;
                if(dia_semana >= 7)
                {
                    dia_semana = dia_semana - 7;
                }
            }
            if(dia_semana >= 7)
                    {
                        dia_semana = dia_semana - 7;
                    }
         }
    }
    total = sexta + aniversarios;
    /*Leitura da quantidade de fornecedores de agua, o preco dos galoes e calculo do preco final do evento*/
    scanf("%lf",&Fornecedores);
    for(contador_1 = 0; contador_1 < Fornecedores; contador_1++)
    {
        scanf("%lf $%lf",&capacidade_galao,&preco_inicial);
        quantidade_galoes = Volume_Reservatorio/capacidade_galao;
        quantidade_galoes_final = (int)quantidade_galoes;
        if(quantidade_galoes_final < quantidade_galoes ){
            quantidade_galoes_final++;
        }
        Custo = quantidade_galoes_final * preco_inicial * total;
        if(contador_1 == 0){
            Menor_custo = Custo;
        }
        else if(Custo < Menor_custo){
            Menor_custo = Custo;
        }
    }    printf("A manutencao da maquete custara $%.2lf aos cofres publicos.\n",Menor_custo);
    return 0;
}
