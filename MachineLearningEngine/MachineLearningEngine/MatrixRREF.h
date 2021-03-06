#pragma once
#include "Matrix.h"
#include "TypeMatrix.h"

class MatrixRREF
{
public:
	static Matrix& rowReduceUnder(const Matrix&);
	static Matrix& rowReduceOver(const Matrix&);

private:
	static Matrix& reduceRowsUnder(Matrix&);
	static Matrix& reduceRowsOver(Matrix&);
	static void reduceColumnUnder(Matrix&, int, int);
	static void reduceColumnOver(Matrix&, int);

	static void sameSizeColumnUnder(Matrix&, int, std::vector<double>&);
	static void sameSizeColumnOver(Matrix&, int, std::vector<double>&);
	static void substractRow(Matrix&, int, int);
	static Matrix& minimizeAllRows(Matrix&);
	static void minimizeRow(Matrix&, int, double);
	static void correctForZeroRow(Matrix&, int);
	static void correctForZeroRowOver(Matrix&, int);
	static int findPivotRow(const Matrix&);
	static void normalizePivotColumn(Matrix&, int);
	static void normalizeColumn(Matrix&, int, int);
	static int firstPivotInColumn(Matrix&, int);

	static bool checkIfPreColsIsAllZero(const Matrix&, int, int);
	static double columnProduct(const Matrix&, int, int, int);
};

