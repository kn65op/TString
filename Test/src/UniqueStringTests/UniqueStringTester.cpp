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

TEST_F(UniqueStringWithStringTester, NewUniqueStringShouldNotChange)
{
  std::string t{"tesT"};
  UniqueString<std::string> un2{t};
  
  ASSERT_EQ(t, un2);
}

TEST_F(UniqueStringWithStringTester, UniqueStringShouldBeEqualToUnderlyingTypeInBoothCases)
{
  std::string s{"Test1"};
  UniqueString<std::string> us{s};
  
  ASSERT_TRUE(s == us);
  ASSERT_TRUE(us == s);               
}

TEST_F(UniqueStringWithStringTester, UniqueStringShouldNotBeEqualToUnderlyingTypeInBoothCases)
{
  std::string s{"Test1"};
  std::string other{"Test2"};
  UniqueString<std::string> us{s};
  
  ASSERT_NE(s, un);
  ASSERT_TRUE(un != s);
}

TEST_F(UniqueStringWithStringTester, TwoNewUniqueStringsShouldNotBeEqual)
{
  UniqueString<std::string> un2;
  
  ASSERT_NE(un, un2);
}