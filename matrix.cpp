// matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
class Matrix
{
public:
	Matrix(int row , int col, std::vector<int>& value)
	{
		if (row > 0 && row % 1 == 0)
		{
			this->row = row;
		}
		else
		{
			if (row <= 0)
			{
				throw("row is not larger than zero");
			}
			if (row % 1 != 0)
			{
				throw("row is not an integer");
			}
		}
		if (col > 0 && col % 1 == 0)
		{
			this->col = col;
		}
		else
		{
			if (col <= 0)
			{
				throw("col is not larger than zero");
			}
			if (col % 1 != 0)
			{
				throw("col is not an integer");
			}
		}
		if (value.size() == row * col)
		{
			this->values.resize(row);
			for (int i = 0; i < row; i++)
			{
				this->values[i].resize(col);
			}
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					this->values[i][j] = value[i*col + j];
				}
			}
		}
		else
		{
			throw("Matrix doesn't agree with row or col");
		}

	}
	Matrix(int row, int col)
	{
		if (row > 0 && row % 1 == 0)
		{
			this->row = row;
		}
		else
		{
			if (row <= 0)
			{
				throw("row is not larger than zero");
			}
			if (row % 1 != 0)
			{
				throw("row is not an integer");
			}
		}
		if (col > 0 && col % 1 == 0)
		{
			this->col = col;
		}
		else
		{
			if (col <= 0)
			{
				throw("col is not larger than zero");
			}
			if (col % 1 != 0)
			{
				throw("col is not an integer");
			}
		}
		values.resize(row);
		for (int i = 0; i < row; i++)
		{
			this->values[i].resize(col);
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				this->values[i][j] = 0;
			}
		}

	}
	Matrix operator+(const Matrix& a)
	{
		Matrix temp(this->row, this->col);
		if (this->row != a.row || this->col != a.col)
		{
			throw("'+' operation invalid");
		}
		else
		{
			
			for (int i = 0; i < this->row; i++)
			{
				for (int j = 0; j < this->col; j++)
				{
					temp.values[i][j] = a.values[i][j]+this->values[i][j];
				}
			}

		}
		return temp;
	}
	Matrix operator=(const Matrix& a)
	{
		if (this->row != a.row || this->col != a.col)
		{
			throw("'=' operation invalid");
		}
		else
		{
			for (int i = 0; i < this->row; i++)
			{
				for (int j = 0; j < this->col; j++)
				{
					this->values[i][j] = a.values[i][j];
				}
			}

		}
		return *this;
	}
	Matrix operator-(const Matrix& a)
	{
		Matrix temp(this->row, this->col);
		if (this->row != a.row || this->col != a.col)
		{
			throw("'+' operation invalid");
		}
		else
		{

			for (int i = 0; i < this->row; i++)
			{
				for (int j = 0; j < this->col; j++)
				{
					temp.values[i][j] = this->values[i][j]-a.values[i][j];
				}
			}

		}
		return temp;
	}
	Matrix operator*(const Matrix& a)
	{
		Matrix temp(this->row, this->col);
		if (this->col != a.row )
		{
			throw("'*' operation invalid");
		}
		else
		{
			
			for (int i = 0; i < this->row; i++)
			{
				temp.values[i].resize(a.col);
			}
			for (int i = 0; i < this->row; i++)
			{
				for (int j = 0; j < a.col; j++)
				{
					int num = 0;
					for (int p = 0; p < this->col; p++)
					{
						num += (this->values[i][p])*(a.values[p][j]);
					}
					temp.values[i][j] = num;
				}
			}
			
		}
		return temp;
	
	}
	void transport()
	{
		Matrix temp(this->col, this->row);
		for (int i = 0; i < this->row; i++)
		{
			for (int j = 0; j < this->col; j++)
			{
				temp.values[j][i] = this->values[i][j] ;
			}
		}
		this->row = temp.row;
		this->col = temp.col;
		this->values.resize(this->row);
		for (int i = 0; i < this->row; i++)
		{
			this->values[i].resize(this->col);
		}
		for (int i = 0; i < this->row; i++)
		{
			for (int j = 0; j < this->col; j++)
			{
				this->values[i][j] = temp.values[i][j];
			}
		}



	}
	void print()
	{
		for (int i = 0; i < this->row; i++)
		{
			for (int j = 0; j < this->col; j++)
			{
				std::cout << this->values[i][j] << " ";

			}
			std::cout << std::endl;
		}
	}
	~Matrix()
	{
		for (int i = 0; i < this->row; i++)
		{
			this->values[i].resize(0);
		}
	}
	

private:
	int row = 0;
	int col = 0;
    std::vector<std::vector<int>> values;
};



int main()
{
	std::vector<int> values;
	int row = 0;
	int col = 0;
	std::cin >> row>>col;
	for (int i = 0; i < row*col; i++)
	{
		int temp = 0;
		std::cin >> temp;
		values.push_back(temp);
	}
	Matrix temp(row,col,values);
	temp.transport();
	temp.print();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


