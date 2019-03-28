#pragma once
#include "VectorEngineDatastructureHeader.h"


TEST(VectorEngineTypeMatrixSpan, spanFullDependent)
{
	Matrix *matrix = new Matrix(3, 4);
	matrix->setEntry(0, 0, 1);
	matrix->setEntry(0, 1, 2);
	matrix->setEntry(0, 2, 3);
	matrix->setEntry(0, 3, 4);
	matrix->setEntry(1, 0, 1);
	matrix->setEntry(1, 1, 2);
	matrix->setEntry(1, 2, 3);
	matrix->setEntry(1, 3, 4);
	matrix->setEntry(2, 0, 1);
	matrix->setEntry(2, 1, 2);
	matrix->setEntry(2, 2, 3);
	matrix->setEntry(2, 3, 4);

	TypeMatrix TM;
	EXPECT_NO_THROW(TM.span(*matrix));
	EXPECT_EQ(1, TM.span(*matrix));
}

TEST(VectorEngineTypeMatrixSpan, spanFullDependentDistributed)
{
	Matrix *matrix = new Matrix(3, 4);
	matrix->setEntry(0, 0, 1);
	matrix->setEntry(0, 1, 2);
	matrix->setEntry(0, 2, 3);
	matrix->setEntry(0, 3, 4);
	matrix->setEntry(1, 0, 2);
	matrix->setEntry(1, 1, 4);
	matrix->setEntry(1, 2, 6);
	matrix->setEntry(1, 3, 8);
	matrix->setEntry(2, 0, 4);
	matrix->setEntry(2, 1, 8);
	matrix->setEntry(2, 2, 12);
	matrix->setEntry(2, 3, 16);

	TypeMatrix TM;
	EXPECT_NO_THROW(TM.span(*matrix));
	EXPECT_EQ(1, TM.span(*matrix));
}

TEST(VectorEngineTypeMatrixSpan, spanZeroes)
{
	Matrix *matrix = new Matrix(3, 4);
	matrix->setEntry(0, 0, 0);
	matrix->setEntry(0, 1, 0);
	matrix->setEntry(0, 2, 0);
	matrix->setEntry(0, 3, 0);
	matrix->setEntry(1, 0, 0);
	matrix->setEntry(1, 1, 0);
	matrix->setEntry(1, 2, 0);
	matrix->setEntry(1, 3, 0);
	matrix->setEntry(2, 0, 0);
	matrix->setEntry(2, 1, 0);
	matrix->setEntry(2, 2, 0);
	matrix->setEntry(2, 3, 0);

	TypeMatrix TM;
	EXPECT_NO_THROW(TM.span(*matrix));
	EXPECT_EQ(0, TM.span(*matrix));
}

TEST(VectorEngineTypeMatrixSpan, spanOf2)
{
	Matrix *matrix = new Matrix(3, 4);
	matrix->setEntry(0, 0, 1);
	matrix->setEntry(0, 1, 2);
	matrix->setEntry(0, 2, 3);
	matrix->setEntry(0, 3, 4);
	matrix->setEntry(1, 0, 3);
	matrix->setEntry(1, 1, 1);
	matrix->setEntry(1, 2, 4);
	matrix->setEntry(1, 3, 1);
	matrix->setEntry(2, 0, 3);
	matrix->setEntry(2, 1, 1);
	matrix->setEntry(2, 2, 4);
	matrix->setEntry(2, 3, 1);

	TypeMatrix TM;
	EXPECT_NO_THROW(TM.span(*matrix));
	EXPECT_EQ(2, TM.span(*matrix));
}

TEST(VectorEngineTypeMatrixSpan, spanOf2_2)
{
	Matrix *matrix = new Matrix(3, 4);
	matrix->setEntry(0, 0, 1);
	matrix->setEntry(0, 1, 2);
	matrix->setEntry(0, 2, 3);
	matrix->setEntry(0, 3, 4);
	matrix->setEntry(1, 0, 1);
	matrix->setEntry(1, 1, 2);
	matrix->setEntry(1, 2, 3);
	matrix->setEntry(1, 3, 4);
	matrix->setEntry(2, 0, 3);
	matrix->setEntry(2, 1, 1);
	matrix->setEntry(2, 2, 4);
	matrix->setEntry(2, 3, 1);

	TypeMatrix TM;
	EXPECT_NO_THROW(TM.span(*matrix));
	EXPECT_EQ(2, TM.span(*matrix));
}

TEST(VectorEngineTypeMatrixSpan, spanOf3)
{
	Matrix *matrix = new Matrix(3, 4);
	matrix->setEntry(0, 0, 1);
	matrix->setEntry(0, 1, 2);
	matrix->setEntry(0, 2, 3);
	matrix->setEntry(0, 3, 4);
	matrix->setEntry(1, 0, 3);
	matrix->setEntry(1, 1, 1);
	matrix->setEntry(1, 2, 3);
	matrix->setEntry(1, 3, 1);
	matrix->setEntry(2, 0, 5);
	matrix->setEntry(2, 1, 1);
	matrix->setEntry(2, 2, 2);
	matrix->setEntry(2, 3, 6);

	TypeMatrix TM;
	EXPECT_NO_THROW(TM.span(*matrix));
	EXPECT_EQ(3, TM.span(*matrix));
}

TEST(VectorEngineTypeMatrixSpan, spanOf3x3Matrix)
{
	Matrix *matrix = new Matrix(3, 3);
	matrix->setEntry(0, 0, 1);
	matrix->setEntry(0, 1, 2);
	matrix->setEntry(0, 2, 3);
	matrix->setEntry(1, 0, 3);
	matrix->setEntry(1, 1, 1);
	matrix->setEntry(1, 2, 3);
	matrix->setEntry(2, 0, 5);
	matrix->setEntry(2, 1, 1);
	matrix->setEntry(2, 2, 2);

	TypeMatrix TM;
	EXPECT_NO_THROW(TM.span(*matrix));
	EXPECT_EQ(3, TM.span(*matrix));
}

TEST(VectorEngineTypeMatrixSpan, spanOf3x5Matrix)
{
	Matrix *matrix = new Matrix(3, 5);
	matrix->setEntry(0, 0, 1);
	matrix->setEntry(0, 1, 0);
	matrix->setEntry(0, 2, 0);
	matrix->setEntry(0, 3, 0);
	matrix->setEntry(0, 4, 0);
	matrix->setEntry(1, 0, 0);
	matrix->setEntry(1, 1, 1);
	matrix->setEntry(1, 2, 0);
	matrix->setEntry(1, 3, 0);
	matrix->setEntry(1, 4, 0);
	matrix->setEntry(2, 0, 0);
	matrix->setEntry(2, 1, 0);
	matrix->setEntry(2, 2, 0);
	matrix->setEntry(2, 3, 1);
	matrix->setEntry(2, 4, 0);

	TypeMatrix TM;
	EXPECT_NO_THROW(TM.span(*matrix));
	EXPECT_EQ(3, TM.span(*matrix));
}

TEST(VectorEngineTypeMatrixSpan, spanZeroSpecial)
{
	Matrix *matrix = new Matrix(4, 5);
	matrix->setEntry(0, 0, 0);
	matrix->setEntry(0, 1, 0);
	matrix->setEntry(0, 2, 0);
	matrix->setEntry(0, 3, 0);
	matrix->setEntry(0, 4, 0);
	matrix->setEntry(1, 0, 0);
	matrix->setEntry(1, 1, 1);
	matrix->setEntry(1, 2, 0);
	matrix->setEntry(1, 3, 0);
	matrix->setEntry(1, 4, 0);
	matrix->setEntry(2, 0, 0);
	matrix->setEntry(2, 1, 0);
	matrix->setEntry(2, 2, 0);
	matrix->setEntry(2, 3, 1);
	matrix->setEntry(2, 4, 0);
	matrix->setEntry(3, 0, 0);
	matrix->setEntry(3, 1, 0);
	matrix->setEntry(3, 2, 0);
	matrix->setEntry(3, 3, 0);
	matrix->setEntry(3, 4, 1);

	TypeMatrix TM;
	EXPECT_NO_THROW(TM.span(*matrix));
	EXPECT_EQ(3, TM.span(*matrix));
}

TEST(VectorEngineTypeMatrixSpan, spanSpecialCase)
{
	Matrix *matrix = new Matrix(3, 4);
	*matrix = { 0, 0, 0, 1,
				0, 0, 0, 0,
				0, 0, 0, 0 };

	TypeMatrix TM;
	EXPECT_NO_THROW(TM.span(*matrix));
	EXPECT_EQ(1, TM.span(*matrix));
}



