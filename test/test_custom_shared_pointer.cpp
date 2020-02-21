#include "gtest/gtest.h"
#include "custom_shared_pointer.hpp"

TEST(TestCustomSharedPointer, DefaultConstructionTest)
{
	auto shared_ptr = CustomSharedPointer<int>();

	ASSERT_EQ(shared_ptr.get(), nullptr);
}

TEST(TestCustomSharedPointer, ConstructorWithSizeArgTest)
{
	auto shared_ptr = CustomSharedPointer<std::string>(4);

	auto arr_ptr = shared_ptr.get();
	arr_ptr[0] = "first";
	arr_ptr[1] = "second";
	arr_ptr[2] = "third";
	arr_ptr[3] = "fourth";

	ASSERT_EQ(shared_ptr.get()[0], "first");
	ASSERT_EQ(shared_ptr.get()[1], "second");
	ASSERT_EQ(shared_ptr.get()[2], "third");
	ASSERT_EQ(shared_ptr.get()[3], "fourth");
}

TEST(TestCustomSharedPointer, ConstructorWithPointerArgTest)
{
	auto shared_ptr = CustomSharedPointer<std::string>(new std::string[4]);

	auto arr_ptr = shared_ptr.get();
	arr_ptr[0] = "first";
	arr_ptr[1] = "second";
	arr_ptr[2] = "third";
	arr_ptr[3] = "fourth";

	ASSERT_EQ(shared_ptr.get()[0], "first");
	ASSERT_EQ(shared_ptr.get()[1], "second");
	ASSERT_EQ(shared_ptr.get()[2], "third");
	ASSERT_EQ(shared_ptr.get()[3], "fourth");
}

TEST(TestCustomSharedPointer, CopyConstructorTest)
{
	auto shared_ptr1 = CustomSharedPointer<int>(3);
	auto shared_ptr2 = CustomSharedPointer<int>(shared_ptr1);

	ASSERT_EQ(shared_ptr1.get_nbr_owners(), 2);
	ASSERT_EQ(shared_ptr2.get_nbr_owners(), 2);
	ASSERT_EQ(shared_ptr1.get(), shared_ptr2.get());
}

TEST(TestCustomSharedPointer, NumberOfOwnersTest)
{
	auto shared_ptr1 = CustomSharedPointer<int>(3);
	auto shared_ptr2 = CustomSharedPointer<int>(shared_ptr1);
	auto shared_ptr3 = CustomSharedPointer<int>(shared_ptr1);
	auto shared_ptr4 = CustomSharedPointer<int>(shared_ptr1);

	ASSERT_EQ(shared_ptr1.get_nbr_owners(), 4);
}

TEST(TestCustomSharedPointer, CopyAssignmentTest) {
	auto shared_ptr1 = CustomSharedPointer<int>(3);
	auto shared_ptr2 = CustomSharedPointer<int>(6);

	shared_ptr1 = shared_ptr2;

	ASSERT_EQ(shared_ptr1.get_nbr_owners(), 2);
	ASSERT_EQ(shared_ptr2.get_nbr_owners(), 2);
	ASSERT_EQ(shared_ptr1.get(), shared_ptr2.get());
}