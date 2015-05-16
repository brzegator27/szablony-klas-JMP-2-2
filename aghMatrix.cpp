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
void aghMatrix<T>::allocateMem(int m, int n)
{
	this->pointer = new T*[m];	/// Creation of table for pointers to tables with rows' values

	for (int i = 0; i < m; i++)
		this->pointer[i] = new T[n];	/// Allocation of memory for tables representing each row

	this->m = m;	/// Setting filed in aghMatrix object in order to know how many rows we have created
	this->n = m;	/// Setting filed in aghMatrix object in order to know how many columns we have created

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			this->pointer[i][j] = 0;	/// By Default values are set to 0
}

template <class T>
void aghMatrix<T>::deallocateMem()
{
	for (int i = 1; i < this->m; i++)
		delete[] this->pointer[i];	/// We deallocate memory of tables in which are values from rows

	delete[] this->pointer;		/// Deletion of table with pointers to tables with rows' values

	this->m = 0;	/// Setting number of rows in object's matrix to 0 because now we don't have any
	this->n = 0;	/// Setting number of columns in object's matrix to 0 because now we don't have any
}

template <class T>
aghMatrix<T>::aghMatrix()
{
	this->pointer = nullptr;	/// Setting pointer to nullptr because there is no matrix 
	this->m = 0;	/// Setting number of rows in object's matrix to 0 because now we don't have any
	this->n = 0;	/// Setting number of columns in object's matrix to 0 because now we don't have any
}

template <class T>
aghMatrix<T>::aghMatrix(int m, int n)
{
	allocateMem(m, n);	/// Allocatioin of memory for matrix
}

template <class T>
aghMatrix<T>::~aghMatrix()
{
	deallocateMem();	/// Aeallocation of memory from matrix
}

template <class T>
void aghMatrix<T>::setItem(int m, int n, T newValue)
{
	if (m > this->m || n > this->n || m < 0 || n < 0)
		throw aghException(0, "Index out of range", __FILE__, __LINE__);	/// If somebody would like to set value, which is out of range of matrix, then we throw exception

	this->pointer[m][n] = newValue;	/// Setting value of particular element of matrix
}

template <class T>
T aghMatrix<T>::getItem(int m, int n)
{
	if (m > this->m || n > this->n || m < 0 || n < 0)
		throw aghException(0, "Index out of range", __FILE__, __LINE__);	/// If somebody would like to get value, which is out of range of matrix, then we throw exception

	return this->pointer[m][n];	/// Returning value of particular element of matrix
}