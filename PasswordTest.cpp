/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, multi_run_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aaaddd");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, case_check_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("JJjjj");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, all_same_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aaaaa");
	ASSERT_EQ(5, actual);
}

TEST(PasswordTest, late_run_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("haiiiiiiiii");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, empty_string)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, special_character_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("$$$#@!!@#$$$");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, null_string_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters(NULL);
	ASSERT_EQ(0, actual);
}

// MIXED CASE TESTS

TEST(PasswordTest, mixed_single_letter_password)
{
	Password my_password;
	int actual = my_password.has_mixed_case("Z");
	ASSERT_FALSE(actual);
}

TEST(PasswordTest, mixed_character_password)
{
	Password my_password;
	int actual = my_password.has_mixed_case("XyZ");
	ASSERT_TRUE(actual);
}

TEST(PasswordTest, mixed_character_long_password)
{
	Password my_password;
	int actual = my_password.has_mixed_case("XyZzzzzabcDDDDD");
	ASSERT_TRUE(actual);
}

TEST(PasswordTest, no_mixed_character_password)
{
	Password my_password;
	int actual = my_password.has_mixed_case("password");
	ASSERT_FALSE(actual);
}

TEST(PasswordTest, oops_just_numbers_password)
{
	Password my_password;
	int actual = my_password.has_mixed_case("1235634787964");
	ASSERT_FALSE(actual);
}

// UNIQ CHARACTER TESTS
TEST(PasswordTest, simple_unique_characters)
{
	Password my_password;
	int actual = my_password.unique_characters("abcde");
	ASSERT_EQ(5, actual);

}
TEST(PasswordTest, complex_unique_characters)
{
	Password my_password;
	int actual = my_password.unique_characters("aaAAbCCCbbbaaCD");
	ASSERT_EQ(5, actual);

}
TEST(PasswordTest, special_characters_and_numbers)
{
	Password my_password;
	int actual = my_password.unique_characters("password13$&");
	ASSERT_EQ(11, actual);

}
TEST(PasswordTest, character_run)
{
	Password my_password;
	int actual = my_password.unique_characters("aaaaaaaaaaaaaa");
	ASSERT_EQ(1, actual);

}








