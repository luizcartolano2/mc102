/* Aluno: Luiz Eduardo Targa Chaves Cartolano
Ra: 183012
Objetivo: O programa em questao tem como objetivo calcular a data em que um determinado evento acontecera a partir da data atual e
da quantidade de dias ate o evento (este sendo convertido pelo mesmo para base decimal) */

#include<stdio.h>

int main(void)
{

	int dia_e, mes_e, ano_e;
	int dia_s, mes_s, ano_s;
	int N, M;
	int X;
	int dia, mes, n,r, anos, meses, meses_2, meses_3, dias, dias_2,dias_3;

	scanf("%d/%d/%d %d %d %d", &dia_e, &mes_e, &ano_e, &N, &M, &X);

	n= N*M;
	/*para conerverter o numero X, originario da base seis, para a base dez, e necessario decompolo em algarismos  e ir multiplicando os algarismos por potencias de seis, para numeros
	de ate oito digitos teremos o primeiro algarismo multiplicado por seis elevado a setima potencia o segundo por seis a sexta potencia, e assim por diante, sendo o valor de X final a soma de todos os
	algarismos*/
	X = (X / 10000000)*6*6*6*6*6*6*6 + ((X%10000000)/1000000)*6*6*6*6*6*6 + (((X%10000000)%1000000)/100000)*6*6*6*6*6 + ((((X%10000000)%1000000)%100000)/10000)*6*6*6*6 + (((((X%10000000)%1000000)%100000)%10000)/1000)*6*6*6 + ((((((X%10000000)%1000000)%100000)%10000)%1000)/100)*6*6 +  (((((((X%10000000)%1000000)%100000)%10000)%1000)%100)/10)*6 + (((((((X%10000000)%1000000)%100000)%10000)%1000)%100)%10);

	/*Para achar o numero de anos que serao adicionados ao valor inicial devemos divirdir o numero de dias
	fornecido pelo usuario(tempo restante) pelo numero de dias totais em um ano, sendo o quociente o valor a ser adicionado*/
	anos = X / n;

	/*o resto da divisao citada ira nos ajudar a encontrar o numero a ser adicionado em meses e dias*/
	r = X  % n;

	/*o quociente da divisao do resto pelo numero de dias em um mes e equivalente ao numero de meses
	que devem ser adicionados ao valor inicial*/
	meses = r / N;

	/*para termos certeza que o numero de meses encontrado nao sera maior que o numero de meses em um ano
	precisamos dividir esse valor(r/N) pelo numero de meses em um ano, sendo que o quociente dessa divisao
	sera adicionado ao numero de anos, e o resto sera,de fato, o numero de meses a ser somado*/
	meses_2= meses / M;
	meses_3 = meses % M;

	/*para o numero de dias usa-se o mesmo raciocinio usado para o numero de meses, com a diferenca que se
	usa o resto da divisao de X/n(sendo n o numero total de dias em um ano) e que se divide esse resto pelo
	numero de dias em um mes*/
	dias = r % N;
	dias_2 = dias / N;
	dias_3 = dias % N;

	/*na parte final do processo tiramos o 1 dos valores iniciais de dia e mes par que possamos somar 1 ao
	final e assim evitar entradas cujo dia e mes sejam zero. Alem disso, apos somar os valores acima encontrados
	as entradas iniciais devemos realizar novas operacoes de divisoes, visando evitar que tenhamos dias e
	meses com maior valor que o permitido.Faremos isso dividindo o valor obtido para dia e mes apos a soma
	por N e M, respectivamente e usando o resto dessas divisoes como saida, enquanto o quociente da divisao
	dos dias se acresceta nos meses, e o dos meses se acrescenta nos anos */
	dia = (dia_e - 1) + dias_3;
	dia_s = dia%N + 1;
	mes= (mes_e - 1) + meses_3 + (dia/N);
	mes_s = mes%M + 1;
	ano_s = ano_e + anos + (mes/M);

	printf("%d/%d/%d \n", dia_s,mes_s,ano_s);

	return 0;
	
}
