#pragma once
#include "VectorEngineHeaders.h"

TEST(TensorCoreTensorCoreEntryOperatorMultiplication, Multiplication_Empty)
{
	CoreEntry object_1;
	CoreEntry object_2;

	EXPECT_NO_THROW(object_1 * object_2, std::exception);

	EXPECT_TRUE((object_1 * object_2).isLeaf());
	EXPECT_TRUE((object_1 * object_2) == CoreEntry(EntryFactory::Number(0)));


	EXPECT_NO_THROW(object_1 *= object_2, std::exception);

	EXPECT_TRUE(object_1.isLeaf());
	EXPECT_TRUE(object_1 == CoreEntry(EntryFactory::Number(0)));
}


TEST(TensorCoreTensorCoreEntryOperatorMultiplication, Multiplication_Number_Number)
{
	CoreEntry object_1(EntryFactory::Number(5));
	CoreEntry object_2(EntryFactory::Number(10));

	EXPECT_NO_THROW(object_1 * object_2, std::exception);

	EXPECT_TRUE((object_1 * object_2).isLeaf());
	EXPECT_TRUE((object_1 * object_2) == CoreEntry(EntryFactory::Number(50)));


	EXPECT_NO_THROW(object_1 *= object_2, std::exception);

	EXPECT_TRUE(object_1.isLeaf());
	EXPECT_TRUE(object_1 == CoreEntry(EntryFactory::Number(50)));
}


TEST(TensorCoreTensorCoreEntryOperatorMultiplication, Multiplication_Number_Complex)
{
	CoreEntry object_1(EntryFactory::Number(5));
	CoreEntry object_2(EntryFactory::Complex(10));

	EXPECT_NO_THROW(object_1 * object_2, std::exception);

	EXPECT_TRUE((object_1 * object_2).isLeaf());
	EXPECT_TRUE((object_1 * object_2) == CoreEntry(EntryFactory::Complex(50)));


	EXPECT_NO_THROW(object_1 *= object_2, std::exception);

	EXPECT_TRUE(object_1.isLeaf());
	EXPECT_TRUE(object_1 == CoreEntry(EntryFactory::Complex(50)));
}


TEST(TensorCoreTensorCoreEntryOperatorMultiplication, Multiplication_Number_Variable)
{
	CoreEntry object_1(EntryFactory::Number(5));
	CoreEntry object_2(EntryFactory::Variable("a"));

	EXPECT_NO_THROW(object_1 * object_2, std::exception);
	EXPECT_FALSE((object_1 * object_2).isLeaf());


	EXPECT_NO_THROW(object_1 *= object_2, std::exception);
	EXPECT_FALSE(object_1.isLeaf());
}


TEST(TensorCoreTensorCoreEntryOperatorMultiplication, Multiplication_Complex_Number)
{
	CoreEntry object_1(EntryFactory::Complex(5));
	CoreEntry object_2(EntryFactory::Number(10));

	EXPECT_NO_THROW(object_1 * object_2, std::exception);

	EXPECT_TRUE((object_1 * object_2).isLeaf());
	EXPECT_TRUE((object_1 * object_2) == CoreEntry(EntryFactory::Complex(50)));


	EXPECT_NO_THROW(object_1 *= object_2, std::exception);

	EXPECT_TRUE(object_1.isLeaf());
	EXPECT_TRUE(object_1 == CoreEntry(EntryFactory::Complex(50)));
}


TEST(TensorCoreTensorCoreEntryOperatorMultiplication, Multiplication_Complex_Complex)
{
	CoreEntry object_1(EntryFactory::Complex(5));
	CoreEntry object_2(EntryFactory::Complex(10));

	EXPECT_NO_THROW(object_1 * object_2, std::exception);

	EXPECT_TRUE((object_1 * object_2).isLeaf());
	EXPECT_TRUE((object_1 * object_2) == CoreEntry(EntryFactory::Number(-50)));


	EXPECT_NO_THROW(object_1 *= object_2, std::exception);

	EXPECT_TRUE(object_1.isLeaf());
	EXPECT_TRUE(object_1 == CoreEntry(EntryFactory::Number(-50)));
}


TEST(TensorCoreTensorCoreEntryOperatorMultiplication, Multiplication_Complex_Variable)
{
	CoreEntry object_1(EntryFactory::Complex(5));
	CoreEntry object_2(EntryFactory::Variable("a"));

	EXPECT_NO_THROW(object_1 * object_2, std::exception);
	EXPECT_FALSE((object_1 * object_2).isLeaf());

	EXPECT_NO_THROW(object_1 *= object_2, std::exception);
	EXPECT_FALSE(object_1.isLeaf());
}


TEST(TensorCoreTensorCoreEntryOperatorMultiplication, Multiplication_Variable_Variable_same)
{
	CoreEntry object_1(EntryFactory::Variable("a"));
	CoreEntry object_2(EntryFactory::Variable("a"));

	EXPECT_NO_THROW(object_1 * object_2, std::exception);
	EXPECT_FALSE((object_1 * object_2).isLeaf());

	EXPECT_NO_THROW(object_1 *= object_2, std::exception);
	EXPECT_FALSE(object_1.isLeaf());
}


TEST(TensorCoreTensorCoreEntryOperatorMultiplication, Multiplication_Variable_Variable_diff)
{
	CoreEntry object_1(EntryFactory::Variable("a"));
	CoreEntry object_2(EntryFactory::Variable("b"));

	EXPECT_NO_THROW(object_1 * object_2, std::exception);
	EXPECT_FALSE((object_1 * object_2).isLeaf());

	EXPECT_NO_THROW(object_1 *= object_2, std::exception);
	EXPECT_FALSE(object_1.isLeaf());
}