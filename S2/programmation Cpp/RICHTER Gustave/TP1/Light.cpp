/**
 * @ name: Exo2.cpp
 * @ access: public
 * @ Author: Richter Gustave
 * @ Create Time: 09-02-2024
 * @ email: richtergustave@gmail.com
 * @ description: Utilisation de la classe Fraction
 * 
 * @ argument: NULL
 * @ input: NULL
 * @ output: NULL
 * @ return:    EXIT_SUCCESS Exection OK
 *              EXIT_FAILURE Execution KO
 * 
 * @ copyright: Richter Gustave
 * 
 * @ Modified by: 09-02-2024
 * @ Modified time: 
 */
//codage fait sur telephone a revoir

#include <iostream>
using namespace std;
#define N 40
#include "light.hpp"

void sum(int *p, int n, int d[]){
	int i;
	*p=0;
	for( i=0; i<n; i++) *p +=d[i];
}

int main()
{
	// Exercice 1
	int i;
	int data[N];
	for( i=0; i<N; i++) data[i] = i;
	int accum;
	sum(&accum,N,data);
	cout <<"Sum is :"<<accum;

	// Exercice 2
	Light l1;
	cout<<l1.isOn()<<endl;
	l1.toggle();
	cout<<l1.isOn()<<endl;
	l1.toggle();
	cout<<l1.isOn()<<endl;

	cout<<l1<<endl;
	int n=10;

	//guirlande
	cout<<"guirlande"<<endl;
	Light *tl = new Light[n];
	for (int i = 0; i < n; i++)
	{
		tl[i]=Light();
	}
	for (int i = 0; i < n; i++)
	{
		if (i%2==0)
		{
			tl[i].toggle();
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout<<tl[i].isOn()<<endl;
	}
		
	return EXIT_SUCCESS;
}