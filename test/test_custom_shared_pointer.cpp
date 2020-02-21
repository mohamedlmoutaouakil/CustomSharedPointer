#include "gtest/gtest.h"
#include "custom_shared_pointer.hpp"

TEST(TestCustomSharedPointer, DefaultConstructionTest)
{
	auto shared_ptr = CustomSharedPointer<int>();

	ASSERT_EQ(shared_ptr.get(), nullptr);
}