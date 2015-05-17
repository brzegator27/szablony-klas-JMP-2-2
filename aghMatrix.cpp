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

template <class T>
void aghMatrix<T>::setItems(T* tab)
{
	/// We assume passing table has as many elements as (m * n)

	int flag = 0; ///< Point to current element in table; current means this, which we are going to write in near future

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			this->pointer[i][j] = tab[flag];	/// Assignment of passed values to object's matrix
			flag++;		/// Guide us through passed table
		}
}

template <class T>
void aghMatrix<T>::setItems(int m, int n, ...)
{
	/** There are only set these elements which overlap
	*	For example: when we try to set elements from matrix 2 x 2
	*	by elements from matrix 4 x 1
	*	There will be set only elements: 1:1, 2:1
	*	Warning! We count starting from 1
	*/

	T* passedMatrix = new T[m*n];	///< Table for passed matrix's elements
	int m_min = 0;	///< Variable which tells us how many rows we can change -> Look at above description of function
	int n_min = 0;	///< Variable which tells us how many columns we can change -> Look at above description of function
	int numberOPE = m * n;	///< number Of Passed Elements
	int flag = 0;	///< Auxiliary variable

	if (m < this->m) m_min = m;	/// Setting value of m_min
	else m_min = this->m;

	if (n < this->n) n_min = n;	/// Setting value of n_min
	else n_min = this->n;

	va_list ap;	///< Iterator of arguments
	va_start(ap, m);	/// Starts iterating arguments with a
	va_arg(ap, T);	/// Skipping 2nd argument, which is n, and we don't need to take it once more

	for (int i = 0; numberOPE > 0; numberOPE--)	/// Function read as many arguments as there were passed
	{
		passedMatrix[flag * n + (i % n)] = va_arg(ap, T);	/// Passed arguments are entered into table, which we treat as two-dimension table
		if ((i + 1) % n == 0) flag++;	/// We increase flag so we can move to next, fake row
		i++;	/// Incrementing i variable in order to know how many arguments we have already taken
	}

	va_end(ap); /// This frees va_list list

	for (int i = 0; i < m_min; i++)
		for (int j = 0; j < n_min; j++)
		{
		this->pointer[i][j] = passedMatrix[i * n + j];	/// We change values of elemets in object's matrix which overlap
		}

	delete[] passedMatrix;	/// Deallocating memory
}

    template <class T>
    aghMatrix<T>& aghMatrix<T>::operator= (aghMatrix<T>& matrix){
        if(matrix == *this) return *this;

        deallocateMem();	/// Deallocation of memory
        allocateMem(matrix.m, matrix.n);	/// We allocate as much of new memory, as is in passed 'matrix'

        for (int i=0; i<this->m; i++){
            for (int j=0; j<this->n; j++){
                this->pointer[i][j] = matrix.pointer[i][j];	/// Copying values from 'matrix' to our object
            }
        }
        return *this;	/// Returning pointer to 'this' object
    }

    template <class T>
    aghMatrix<T>& aghMatrix<T>::operator+ (const aghMatrix<T>& matrix){
        if((this->m != matrix.m) || (this->n != matrix.n)) throw aghException(0, "Matrix has different size", __FILE__, __LINE__);

        for(int i=0; i<this->m; i++){
            for(int j=0; j<this->n; j++){
                this->pointer[i][j] = this->pointer[i][j] + matrix.pointer[i][j];
            }
        }
        return *this;
    }

    template <class T>
    aghMatrix<T>& aghMatrix<T>::operator* (aghMatrix<T>& matrix){
        if((this->m != matrix.n)) throw aghException(0, "Matrix has wrong size", __FILE__, __LINE__);

        aghMatrix<T> temp(this->m, matrix.n);
        for(int i=0; i<temp.m; i++){
            for(int j=0; j<matrix.n; j++){
                for(int k=0; k<matrix.m; k++){
                    temp.pointer[i][j] = temp.pointer[i][j] + this->pointer[i][k] * matrix.pointer[k][j];
                }
            }
        }
        *this = temp;
        return *this;
    }

    template <class T>
    bool aghMatrix<T>::operator==(aghMatrix<T>& ClassObj){
        if((this->m != ClassObj.m) || (this->n != ClassObj.n)) return 0;
        for(int i=0;i<this->m;i++){
            for(int j=0;j<this->n;j++){
                if(this->pointer[i][j] != ClassObj.pointer[i][j]) return 0;
            }
        }
        return 1;
    }

    template <class T>
    bool aghMatrix<T>::operator!=(aghMatrix<T>& ClassObj){
        if((this->m != ClassObj.m) || (this->n != ClassObj.n)) return 1;
        for(int i=0;i<this->m;i++){
            for(int j=0;j<this->n;j++){
                if(this->pointer[i][j] != ClassObj.pointer[i][j]) return 1;
            }
        }
        return 0;
    }

    template <class T>
    T& aghMatrix<T>::operator()(int m, int n){
        if((m > this->m) || (m < 0) || (n < 0) || (n > this->n)) throw aghException(0, "Index out of range", __FILE__, __LINE__);
        return this->pointer[m][n];
    }

template class aghMatrix<int>;  /** Written in order to have templates of class' functions in .cpp file
								*	More on: https://isocpp.org/wiki/faq/templates#separate-template-class-defn-from-decl
								*/
