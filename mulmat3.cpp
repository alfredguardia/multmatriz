#include <iostream>
#include <stdio.h>      
#include <stdlib.h>    
#include <time.h>
#include <ctime> 
using namespace std;

const int MAX=1000;
double A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

void inicializar()
{
	srand (time(NULL));
	for(int i=0; i<MAX; i++)
		for(int j=0; j<MAX; j++)
		{
			A[i][j]=rand() % 100;
			B[i][j]=rand() % 100;
		}
}

void multmat3()
{
	
	unsigned t0, t1;
	int i, j, k;
	t0=clock();
 	for(i=0; i<MAX; i++)
 	{
        	for(j=0; j<MAX; j++)
        	{
 			C[i][j]=0;         
 			for(k=0; k<MAX; k++)
 				C[i][j]=C[i][j]+A[i][k]*B[k][j];
        	}
 	}
	t1=clock();
	double time=(double(t1-t0)/CLOCKS_PER_SEC);
	cout<<"Matriz de "<<MAX<<" x "<<MAX<<" - 3 bucles: "<<time<<endl;
}

int main()
{	
	inicializar();
	multmat3();
}
