#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class WF
{
	int M, N;
	vector<vector<int>> matrix;
	string string1, string2;
public:
	void Init(string str1, string str2) 
	{
		string1 = str1;
		string2 = str2;
		M = string1.length() + 1;
		N = string2.length() + 1;
		vector<vector<int>> matrix1(N, vector<int>(M, 0));
		matrix = matrix1;
	}
	int Rows() const 
	{
		return N;
	}
	int Columns() const 
	{
		return M;
	}
	int Get(int i, int j) 
	{
		return matrix[i][j];
	}
	void Set(int i, int j, int val) 
	{
		matrix[i][j] = val;
	}
	void PrintMatrix()
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}

	int Distance() const
	{
		return matrix[N - 1][M - 1];
	}

	void WagnerFischerAlgorithm()
	{
		for (int i = 0; i < Columns(); i++)
		{
			matrix[0][i] = i;
		}
		for (int i = 0; i < Rows(); i++)
		{
			matrix[i][0] = i;
		}
		int temp1, temp2, temp3;
		for (int i = 1; i < Rows(); i++) 
		{
			for (int j = 1; j < Columns(); j++) 
			{
				if (string1[j - 1] == string2[i - 1]) temp1 = matrix[i - 1][j - 1];
				else temp1 = matrix[i - 1][j - 1] + 1;
				temp2 = matrix[i][j - 1] + 1;
				temp3 = matrix[i - 1][j] + 1;
				temp1 = min(temp1, temp2);
				Set(i, j, min(temp1, temp3));
			}
		}
	}
};


