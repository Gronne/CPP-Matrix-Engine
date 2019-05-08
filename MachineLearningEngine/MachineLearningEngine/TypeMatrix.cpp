#include "TypeMatrix.h"



TypeMatrix::TypeMatrix()
{

}


TypeMatrix::~TypeMatrix()
{

}


bool TypeMatrix::dependent(const Matrix &matrix)
{
	//Is independent if and only if rank(A) == min(row, col)
	if (matrix.getNumberOfColumns() != matrix.getNumberOfRows())
		return true;

	BasicMatrixOperations BMO;
	//If and only if, det(A) = 0
	return (BMO.determinant(matrix) == 0) ? true : false;
}


bool TypeMatrix::homogeneous(const Matrix &matrix)
{
	for (size_t row = 0; row < matrix.getNumberOfRows(); row++)
		if (matrix.getEntry(row, matrix.getNumberOfColumns() - 1) != 0)
			return false;
	return true;
}

bool TypeMatrix::trivial(const Matrix &matrix)
{
	Matrix *buffer = new Matrix();
	*buffer = matrix;

	if (matrix.getNumberOfColumns() - 1 == matrix.getNumberOfRows())
		buffer->deleteColumn(buffer->getNumberOfColumns() - 1);

	bool _dependent = dependent(*buffer);
	delete buffer;

	return !_dependent && homogeneous(matrix);
}


bool TypeMatrix::basis(const Matrix &matrix)
{
	MatrixRREF RREF;
	BasicMatrixOperations BMO;
	
	if (!isSquare(matrix) || RREF.checkForFullDependentMatrix(matrix))
		return false;

	Matrix *buffer = new Matrix();
	*buffer = BMO.getEchelonForm(matrix);

	for (size_t row = 0; row < matrix.getNumberOfRows(); ++row)
		if (buffer->getEntry(row, row) != 1)
			return false;

	return true;
}


bool TypeMatrix::basis(Matrix &, MatrixSpace &) const
{

	return false;
}


bool TypeMatrix::orthogonal(Matrix &, Matrix &) const
{

	return false;
}


bool TypeMatrix::orthogonal(const Matrix &matrix)
{
	MatrixRREF RREF;
	GetMatrix GM;

	if (!isSquare(matrix) || RREF.checkForFullDependentMatrix(matrix))
		return false;

	bool returnState = false;

	if (matrix * matrix.transpose() == GM.getIdentityMatrix(matrix.getNumberOfRows()))
		returnState = true;

	return returnState;
}


int TypeMatrix::rank(const Matrix &matrix)
{
	if (isZeroMatrix(matrix))
		return 0;

	MatrixRREF RREF;
	if (RREF.checkForFullDependentMatrix(matrix))
		return 1;

	BasicMatrixOperations BMO;
	Matrix *buffer = new Matrix();
	*buffer = BMO.getEchelonForm(matrix);

	int rank = 0;
	for (size_t row = 0; row < matrix.getNumberOfRows(); row++)
		for (size_t col = 0; col < matrix.getNumberOfColumns(); col++)
			if (buffer->getEntry(row, col) != 0)
			{
				rank++;
				break;
			}

	delete buffer;
	return rank;
}


int TypeMatrix::rank(const MatrixResult &)
{

	return 0;
}

bool TypeMatrix::fullRank(const Matrix &matrix)
{
	int largestNumber = (matrix.getNumberOfRows() < matrix.getNumberOfColumns()) ? matrix.getNumberOfColumns() : matrix.getNumberOfRows();
	return (largestNumber == rank(matrix)) ? true : false;
}

bool TypeMatrix::fullRank(const MatrixResult &)
{
	return false;
}

//Will return the number of dimensions that the matrix spans over
int TypeMatrix::span(const Matrix &matrix)
{
	return rank(matrix);
}

#include <iostream>

bool TypeMatrix::isInSpan(const Matrix &matrixSpan, const Matrix &newVectors, bool rowVector)
{
	Matrix *firstMatrix = new Matrix();
	Matrix *secondMatrix = new Matrix();
	*firstMatrix = matrixSpan;
	*secondMatrix = newVectors;

	if (rowVector)
	{
		firstMatrix->transpose();
		secondMatrix->transpose();
	}

	bool returnBool = checkSpan(*firstMatrix, *secondMatrix);

	delete firstMatrix;
	delete secondMatrix;
	return returnBool;
}

bool TypeMatrix::checkSpan(const Matrix &matrixSpan, const Matrix &matrixInSpan)
{
	Matrix *spanBuffer = new Matrix();
	*spanBuffer = matrixSpan;
	Matrix *inSpanBuffer = new Matrix();
	*inSpanBuffer = matrixInSpan;

	spanBuffer->transpose();
	inSpanBuffer->transpose();

	if (spanBuffer->getNumberOfRows() != inSpanBuffer->getNumberOfRows())
		inSpanBuffer->transpose();

	spanBuffer->appendMatrix(*inSpanBuffer);

	int primarySpan = span(matrixSpan);
	int secondarySpan = span(*spanBuffer);
	bool returnState = (primarySpan == secondarySpan) ? true : false;

	delete spanBuffer;
	delete inSpanBuffer;
	return returnState;
}


bool TypeMatrix::isomorphic(Matrix &, Matrix &) const
{

	return false;
}

bool TypeMatrix::isSquare(const Matrix &matrix) const
{
	return matrix.getNumberOfColumns() == matrix.getNumberOfRows();
}

bool TypeMatrix::isEqual(const Matrix &matrixA, const Matrix &matrixB, double precision) const
{
	if (precision < 0)
		throw std::exception("Precision needs to be 0 or positive");

	if (matrixA.getNumberOfColumns() != matrixB.getNumberOfColumns() || matrixA.getNumberOfRows() != matrixB.getNumberOfRows())
		return false;

	for (size_t row = 0; row < matrixA.getNumberOfRows(); row++)
		for (size_t col = 0; col < matrixA.getNumberOfColumns(); col++)
		{
			if (matrixA.getEntry(row, col) + precision < matrixB.getEntry(row, col))
				return false;
			else if (matrixA.getEntry(row, col) - precision > matrixB.getEntry(row, col))
				return false;
		}	
	return true;
}

bool TypeMatrix::isZeroMatrix(const Matrix &matrix)
{
	bool zeroes = true;

	for (size_t row = 0; row < matrix.getNumberOfRows(); row++)
		for (size_t col = 0; col < matrix.getNumberOfColumns(); col++)
			if (matrix.getEntry(row, col) != 0)
			{
				zeroes = false;
				break;
			}

	return zeroes;
}

