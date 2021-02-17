#pragma once

#include <stdio.h>

namespace cpy
{
	template<typename MATRIX_VALUE>
	class matrix
	{
	private:

		uint32_t matrix_rowNumber,
			matrix_columnNumber;

		int* MATRIX = new MATRIX_VALUE[matrix_rowNumber * matrix_columnNumber];


	public:

		matrix(uint32_t n, uint32_t m)
			:matrix_rowNumber(n), matrix_columnNumber(m)
		{
			for (int i = 0; i < matrix_rowNumber * matrix_columnNumber; ++i)
				MATRIX[i] = 0;
		}

		virtual ~matrix()
		{
			delete[] MATRIX;
		}


		int* operator= (const matrix& valueSource)
		{
			for (int i = 0; i < matrix_rowNumber; ++i) {
				for (int j = 0; j < matrix_columnNumber; ++j)
				{
					MATRIX[i * matrix_columnNumber + j] = valueSource[i][j];

					return MATRIX;
				}
			}
		}

		//intput index with brackets [][]
		const int* operator [](int*& rowIndex) const
		{
			return &MATRIX[*rowIndex * matrix_columnNumber];
		}

		const int* operator [](int& columnIndex) const
		{
			return &MATRIX[columnIndex * matrix_columnNumber];
		}


		const bool operator == (matrix& compareTo)
			//works only on same-size matrices
		{
			bool areEqual = true;

			for (int i = 0; i < matrix_rowNumber * matrix_columnNumber; ++i)
			{
				if (MATRIX[i] != compareTo.MATRIX[i])
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


		int* row(uint32_t row_)
		{
			int* rowCopy = new MATRIX_VALUE[matrix_columnNumber];
			for (int i = row_; i < matrix_columnNumber * row_; ++i)
			{
				rowCopy[i] == MATRIX[i];
			}

			return rowCopy;

			delete[] rowCopy;
		}
	};
}

