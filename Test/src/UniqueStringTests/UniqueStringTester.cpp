#include "UniqueString/inc/UniqueString.h"
#include <gtest/gtest.h>
#include <string>

using namespace ::testing;

struct UniqueStringWithStringTester : public Test
{
  UniqueString<std::string> un;
};

TEST_F(UniqueStringWithStringTester, NewUniqueStringShouldNotBeEmpty)
{
  ASSERT_FALSE(un.empty());
}
