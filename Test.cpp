/**
 * AUTHORS: Idan Kaminetsky
 * 
 * Date: 2022-03
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input") {

    //correct input with different simbols
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													"@-------@\n"
													"@-@@@@@-@\n"
													"@-@---@-@\n"
													"@-@@@@@-@\n"
													"@-------@\n"
													"@@@@@@@@@"));
	/* Add more test here */

    CHECK(nospaces(mat(13, 5, '@', '-')) == nospaces("@@@@@@@@@@@@@\n"
													 "@-----------@\n"
													 "@-@@@@@@@@@-@\n"
													 "@-----------@\n"
													 "@@@@@@@@@@@@@\n"));

    CHECK(nospaces(mat(3, 5, '$', '+')) == nospaces("$$$\n"
													"$+$\n"
													"$+$\n"
													"$+$\n"
													"$$$\n"));
    

    CHECK(nospaces(mat(1 , 1, '$', '+')) == nospaces("$"));

    CHECK(nospaces(mat(1, 5, '@', '#')) == nospaces("@\n"
													"@\n"
                                                    "@\n"
                                                    "@\n"
													"@"));

	CHECK(nospaces(mat(5, 1, '@', '#')) == nospaces("@@@@@"));

    // same simbols
    CHECK(nospaces(mat(1, 1, '+', '+')) == nospaces("+"));

	CHECK(nospaces(mat(3, 3, '*', '*')) == nospaces("***\n"
													"***\n"
													"***"));

	CHECK(nospaces(mat(5, 3, '#', '#')) == nospaces("#####\n"
													"#####\n"
													"#####"));
}

TEST_CASE("Bad input") {

    // even numbers:
    CHECK_THROWS(mat(10, 5, '$', '%'));
    CHECK_THROWS(mat(2, 2, '$', '%'));
    CHECK_THROWS(mat(1, 2, '$', '%'));

    // zeros:
    CHECK_THROWS(mat(0, 0, '$', '%'));
    CHECK_THROWS(mat(0, 1, '$', '%'));
    CHECK_THROWS(mat(1, 0, '$', '%'));

    // negatives:
    CHECK_THROWS(mat(-1, 3, '$', '%'));
    CHECK_THROWS(mat(3, -1, '$', '%'));
    CHECK_THROWS(mat(-1000, 0, '$', '%'));
    CHECK_THROWS(mat(0, -1000, '$', '%'));

    // spaces and similar:
    CHECK_THROWS(mat(0, -1000, '\n', '%'));
    CHECK_THROWS(mat(0, -1000, '\t', '%'));
    CHECK_THROWS(mat(0, -1000, '\r', '%'));
    CHECK_THROWS(mat(0, -1000, ' ', '%'));
}

TEST_CASE("another checks for good input") {
    
    CHECK(nospaces(mat(1 , 1, '$', '+')).length() == 1*1);
    CHECK(nospaces(mat(3 , 7, '$', '+')).length() == 3*7);
    CHECK(nospaces(mat(7 , 3, '$', '+')).length() == 7*3);
}
