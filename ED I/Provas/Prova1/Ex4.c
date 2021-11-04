/*
Escreva um programa, em C/C++, que preencha uma matriz 12 x 4 com os valores das vendas de uma loja, em que cada linha representa 
um mês do ano e cada coluna representa uma semana do mês. O programa deverá calcular e mostrar: 
a) o total vendido em cada mês do ano, mostrando o nome do mês por extenso; 
b) o total vendido em cada semana durante todo o ano; 
c) o total vendido pela loja no ano.
*/
#include <stdio.h>

int main(){
	float vendas[12][4];
	float somaMes=0, somaAno=0;//somatória
	int i, j;//count
	
	//população da matriz
	for(i=0;i<12;i++){
		for(j=0;j<4;j++){
			printf("Insira o valor das vendas na semana %i do mes %i \n", j+1, i+1);
			scanf("%f", &vendas[i][j]);
			somaMes = somaMes + vendas[i][j];
		}
		somaAno = somaAno + somaMes;
		switch(i){
			case 0:
				printf ("Total de vendas em Janeiro: %.2f \n", somaMes);
				break;
			case 1:
				printf ("Total de vendas em Fevereiro: %.2f \n", somaMes);
				break;
			case 2:
				printf ("Total de vendas em Março: %.2f \n", somaMes);
				break;
			case 3:
				printf ("Total de vendas em Abril: %.2f \n", somaMes);
				break;
			case 4:
				printf ("Total de vendas em Maio: %.2f \n", somaMes);
				break;
			case 5:
				printf ("Total de vendas em Junho: %.2f \n", somaMes);
				break;
			case 6:
				printf ("Total de vendas em Julho: %.2f \n", somaMes);
				break;
			case 7:
				printf ("Total de vendas em Agosto: %.2f \n", somaMes);
				break;
			case 8:
				printf ("Total de vendas em Setembro: %.2f \n", somaMes);
				break;
			case 9:
				printf ("Total de vendas em Outubro: %.2f \n", somaMes);
				break;
			case 10:
				printf ("Total de vendas em Novembro: %.2f \n", somaMes);
				break;
			case 11:
				printf ("Total de vendas em Dezembro: %.2f \n", somaMes);
				break;
		}
		somaMes = 0;
	}
	printf("O total de vendas no ano foi %.2f", somaAno);
}