/**
* \file aghMatrix.cpp
* \author Jakub Brzegowski
* \date 16.05.2015
* \version 1.0
* \Header file with class' functions from class aghMatrix
*/
// -------------------------------------------------------------------------


#include "aghMatrix.h"
#include <iostream>

using namespace std;


template class aghMatrix<int>;	/** Written in order to have templates of class' functions in .cpp file
								*	More on: https://isocpp.org/wiki/faq/templates#separate-template-class-defn-from-decl
								*/


template <class T>
aghMatrix<T>::aghMatrix()
{
	this->pointer = nullptr;
}

template <class T>
aghMatrix<T>::aghMatrix(int m, int n)
{
	this->pointer = new T*[m];

	for (int i = 0; i < m; i++)
		this->pointer[i] = new T[n];

	this->m = m;
	this->n = m;
}

template <class T>
aghMatrix<T>::~aghMatrix()
{
	for (int i = 1; i < this->m; i++)
		delete[] this->pointer[i];

	delete[] this->pointer;
}

template <class T>
void aghMatrix<T>::setItem(int m, int n, T newValue)
{
	if (m > this->m || n > this->n || m < 0 || n < 0)
		throw aghException(0, "Index out of range", __FILE__, __LINE__);

	this->pointer[m][n] = newValue;
}

template <class T>
T aghMatrix<T>::getItem(int m, int n)
{
	return this->pointer[m][n];
}