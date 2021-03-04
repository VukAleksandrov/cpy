#pragma once


typedef unsigned int uint32_t;
using namespace std;

namespace cpy
{

	template<typename MATRIX_TYPE>
	class matrix
	{
	private:


		int* MAIN_MATRIX = new MATRIX_TYPE[rowSize * columnSize];

	public:

		uint32_t rowSize,
			columnSize;

		matrix(uint32_t n, uint32_t m)
			:rowSize(n), columnSize(m)	
		{
			for (int i = 0; i < size(); ++i)
				MAIN_MATRIX[i] = 0;
		}

		virtual ~matrix()
		{
			delete[] MAIN_MATRIX;
		}


	//  initialize index with brackets [][]
		const int* operator [](int*& rowIndex) const
		{
			return &MAIN_MATRIX[*rowIndex * columnSize];
		}

		const int* operator [](int& columnIndex) const
		{
			return &MAIN_MATRIX[columnIndex * columnSize];
		}


		matrix& operator= (matrix& revalueTo)
	//  can't revalue matrix with an array or heap,
	//  only with same type
		{
			this->MAIN_MATRIX = revalueTo.MAIN_MATRIX;

			return *this;
		}


		const bool operator == (matrix& compareTo)
	//  works only on same-size matrices
		{
			bool areEqual = true;

			for (int i = 0; i < rowSize * columnSize; ++i)
			{
				if (&MAIN_MATRIX[i] != compareTo.MAIN_MATRIX[i])
				{
					areEqual = false;
					break;
				}
			}

			return areEqual;
		}

		const bool operator!= (matrix& compareTo)
		{
			return this->operator== (compareTo);
		}

		int size()
		{
			return rowSize * columnSize;
		}

		void resize(uint32_t newRowSize,uint32_t newColumnSize)
	//  Values surounding matrix are valuated to zero
		{
			int ResizedMatrixValue[newRowSize][newColumnSize] = { 0 };

			for (int i = 0; i < rowSize; i++) {

				for (int j = 0; j < columnSize; j++)
				{
					ResizedMatrixValue[i][j] = MAIN_MATRIX[i * columnSize + j];
				}
			}

			rowSize = newRowSize;
			columnSize = newColumnSize;
		}
	

		int* row(uint32_t row_)
	 // you can take the row if the l-value you are 
	 //	giving this row/column is an heap-allocated array 
		{
			int* rowCopy= new int[&columnSize];
			for (int i = row_; i < columnSize * row_; ++i)
			{
				rowCopy[i-row_] = &MAIN_MATRIX[i];
				
			}
			return  rowCopy;

			delete[] rowCopy;
		}

  
		int* column(uint32_t column_)
		{
			int* columnCopy = new int[&rowSize];
			for (int i = column_; i < rowSize * column_; ++i)
			{
				columnCopy[i - column_] = &MAIN_MATRIX[i];

			}
			return  columnCopy;

			delete[] columnCopy;
		}
	};

}

