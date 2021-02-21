#pragma once

typedef unsigned int uint32_t;

namespace cpy
{

	template<typename MATRIX_TYPE>
	class matrix
	{
	private:

		uint32_t rowSize,
			columnSize;


		int** MATRIX = new int*[rowSize];

	public:

		matrix( uint32_t n, uint32_t m)
			:rowSize(n), columnSize(m)
		{
			for (int i = 0; i < n; i++)
			{
				MATRIX[i] = new int[columnSize];
			}
		}


		virtual ~matrix()
		{
			delete[] MATRIX;
		}

		
		int size()
		{
			return rowSize * columnSize;
		}


		int* row(uint32_t row_)
	 // you can take the row if the l-value you are 
	 //	giving this row/column is an heap-allocated array 
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

