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
  EXPECT_FALSE(un.empty());
}

TEST_F(UniqueStringWithStringTester, NewUniqueStringShouldNotChange)
{
  std::string t{"tesT"};
  UniqueString<std::string> un2{t};
  
  EXPECT_EQ(t, un2.getContent());
}

TEST_F(UniqueStringWithStringTester, UniqueStringShouldBeEqualToUnderlyingTypeInBoothCases)
{
  std::string s{"Test1"};
  UniqueString<std::string> us{s};
  
  EXPECT_TRUE(s == us);
  EXPECT_TRUE(us == s);
}

TEST_F(UniqueStringWithStringTester, UniqueStringShouldNotBeEqualToUnderlyingTypeInBoothCases)
{
  std::string s{"Test1"};
  std::string other{"Test2"};
  UniqueString<std::string> us{s};
  
  EXPECT_NE(s, un);
  EXPECT_TRUE(un != s);
}

TEST_F(UniqueStringWithStringTester, TwoNewUniqueStringsShouldNotBeEqual)
{
  UniqueString<std::string> un2;
  
  EXPECT_NE(un, un2);
}

TEST_F(UniqueStringWithStringTester, AfterDeletionUniqueStringCanBeUseAgain)
{
  std::string s{"test"};
  {
    UniqueString<std::string> us{s};
    ASSERT_EQ(s, us);
  }
  UniqueString<std::string> us{s};
  EXPECT_EQ(s, us);
}
 