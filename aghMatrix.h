/**
* \file aghMatrix.h
* \author Jakub Brzegowski
* \date 16.05.2015
* \version 1.0
* \Header file with class aghMatrix
*/
// -------------------------------------------------------------------------

#include "aghException.h"

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

	/// \brief function setting value of elements of matrix
	///
	/// \param m - number of row
	/// \param n - number of column
	/// \param newValue - new value which we are going to set for partic
	void setItems(T* newValue);

	/// \brief function setting value of element of matrix
	///
	/// \param m - number of row
	/// \param n - number of column
	/// \param newValue - new value which we are going to set for partic
	void setItems(int m, int n, T newValue);

	/// \brief function getting value of element of matrix
	///
	/// \param m - number of row
	/// \param n - number of column
	T getItem(int m, int n);
};

// -------------------------------------------------------------------------
#endif
