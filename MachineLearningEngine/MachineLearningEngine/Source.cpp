#include <iostream>
#include "Matrix.h"
#include "string"
#include "SimpleMatrixOperations.h"
#include "BasicMatrixOperations.h"

int main(int argc, char ** argv) {
	std::cout << "hello" << std::endl;

	Matrix *matrix = new Matrix(3, 4);
	matrix->setEntry(0, 0, 1);
	matrix->setEntry(0, 1, 2);
	matrix->setEntry(0, 2, 3);
	matrix->setEntry(0, 3, 4);
	matrix->setEntry(1, 0, 3);
	matrix->setEntry(1, 1, 1);
	matrix->setEntry(1, 2, 5);
	matrix->setEntry(1, 3, 6);
	matrix->setEntry(2, 0, 5);
	matrix->setEntry(2, 1, 1);
	matrix->setEntry(2, 2, 6);
	matrix->setEntry(2, 3, 2);

	MatrixRREF RREF;
	Matrix *resultMatrix = new Matrix();
	*resultMatrix = RREF.rowReduceUnder(*resultMatrix);


	try
	{
		*resultMatrix = RREF.rowReduceOver(*resultMatrix);
		resultMatrix->print();
	}
	catch (const std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}
	

	delete matrix;
	delete resultMatrix;

	exit(0);
}