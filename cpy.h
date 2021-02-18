#pragma once

typedef unsigned int uint32_t;
using namespace std;

namespace cpy
{

	template<typename MATRIX_TYPE>
	class matrix
	{
	private:

		uint32_t rowSize,
			columnSize;

		int* MATRIX = new MATRIX_TYPE[rowSize * columnSize];


	public:

		matrix(uint32_t n, uint32_t m)
			:rowSize(n), columnSize(m)
		{
			for (int i = 0; i <size(); ++i)
				MATRIX[i] = 0;
		}

		virtual ~matrix()
		{
			delete[] MATRIX;
		}


		//initialize index with brackets [][]
		const int* operator [](int*& rowIndex) const
		{
			return &MATRIX[*rowIndex * columnSize];
		}

		const int* operator [](int& columnIndex) const
		{
			return &MATRIX[columnIndex * columnSize];
		}


		const bool operator == (matrix& compareTo)
			//works only on same-size matrices
		{
			bool areEqual = true;

			for (int i = 0; i < rowSize * columnSize; ++i)
			{
				if (&MATRIX[i] != compareTo.MATRIX[i])
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

		int* row(uint32_t row_)
		{
			int* rowCopy= new int[&columnSize];
			for (int i = row_; i < columnSize * row_; ++i)
			{
				rowCopy[i-row_] = &MATRIX[i];
				
			}
			return  rowCopy;

			delete[] rowCopy;
		}

		int* column(uint32_t column_)
		{
			int* columnCopy = new int[&rowSize];
			for (int i = column_; i < rowSize * column_; ++i)
			{
				columnCopy[i - column_] = &MATRIX[i];

			}
			return  columnCopy;

			delete[] columnCopy;
		}
	};
}

