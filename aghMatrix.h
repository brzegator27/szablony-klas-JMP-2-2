/**
* \file aghMatrix.h
* \author Jakub Brzegowski
* \date 16.05.2015
* \version 1.0
* \Header file with class aghMatrix
*/
// -------------------------------------------------------------------------

#include "aghException.h"
#include <stdarg.h>	/// Library essential for funtion with unknown number of parameters

#ifndef AGH_MATRIX
#define AGH_MATRIX
// -------------------------------------------------------------------------

/**
* \class aghMatrix
* \author Jakub Brzegowski
* \date 16.05.2015
* \Class which represent matrix
*/

template <class T>
class aghMatrix
{
	T** pointer;	///< pointer to table containing respective fields of matrix
	int m, n;		///< two integers with matrix size

	/// \brief function allocating memory for tables representing matrix
	///
	/// \param m - number of rows
	/// \param n - number of columns
	void allocateMem(int m, int n);

	/// \brief function deallocating memory from tables representing matrix
	void deallocateMem();
public:
	/// \brief default constructor
	aghMatrix();
	/// \brief two-parameter constructor
	///
	/// \param m - number of rows
	/// \param n - number of columns
	aghMatrix(int m, int n);

	/// \brief default destructor
	~aghMatrix();

	/// \brief function setting value of element of matrix
	///
	/// \param m - number of row
	/// \param n - number of column
	/// \param newValue - new value which we are going to set for partic
	void setItem(int m, int n, T newValue);

	/// \brief function setting values of each element of matrix; values are taken from one-row table
	///
	/// \param tab - pointer to one-row table with values which we are going to set for matrix's elements
	void setItems(T* tab);

	/// \brief function setting values of some elements of matrix; values are passed as arguments
	///
	/// \param n_args - number of arguments
	/// 1st m - numbers of rows in passing matrix
	/// 2nd n - numbers of columns in passing matrix
	/// 3rd and successive ... - elements of passing matrix
	void setItems(int m, int n, ...);

	/// \brief function getting value of element of matrix
	///
	/// \param m - number of row
	/// \param n - number of column
	T getItem(int m, int n);


	/// \brief overloaded operator "="
	///
	/// \param matrix - other matrix
    aghMatrix<T> &operator= (aghMatrix<T>& matrix);

    /// \brief overloaded operator "+"
    ///
    /// \param matrix - other matrix to add
    aghMatrix<T> &operator+ (aghMatrix<T>& matrix);

    /// \brief overloaded operator "*"
    ///
    /// \param matrix - other matrix to multiply
    aghMatrix<T> &operator* (aghMatrix<T>& matrix);

    /// \brief overloaded operator "=="
    ///
    /// \param matrix - other matrix to compare
    /// \return
    /// \li 0 - when not equal
    /// \li 1 - when equal
    bool operator== (aghMatrix<T>& matrix);

    /// \brief overloaded operator "!="
    ///
    /// \param matrix - other matrix to compare
    /// \return it returns:
    /// \li 0 - when equal
    /// \li 1 - when not equal
    bool operator!= (aghMatrix<T>& matrix);

    /// \brief overloaded operator "()"
    ///
    /// \param m - number of row;
    /// \param n - number of column;
    /// \return it returns value under chosen index
    T & operator()(int m, int n);

};

// -------------------------------------------------------------------------
#endif
