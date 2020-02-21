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