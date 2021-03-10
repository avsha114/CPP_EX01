/**
 * Test file written by Avshalom Avraham
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

string noLineBreak(string input) {
	std::erase(input, '\n');
	return input;
}

string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("Invalid input string") {
    CHECK_THROWS(snowman(1));
    CHECK_THROWS(snowman(11));
    CHECK_THROWS(snowman(111));
	CHECK_THROWS(snowman(111111122));
	CHECK_THROWS(snowman(11156));
    CHECK_THROWS(snowman(11111015));
    CHECK_THROWS(snowman(91011116));
    CHECK_THROWS(snowman(11117411));
    CHECK_THROWS(snowman(211118118));
}

TEST_CASE("Random good snowman input") {
    CHECK(nospaces(snowman(11111111)) == nospaces("       \n _===_ \n (.,.) \n<( : )>\n ( : ) "));
    CHECK(nospaces(snowman(22222222)) == nospaces("  ___  \n ..... \n\\(o.o)/\n (] [) \n (\" \") "));
    CHECK(nospaces(snowman(33333333)) == nospaces("   _   \n  /_\\  \n (O_O) \n/(> <)\\\n (___) "));
    CHECK(nospaces(snowman(44444444)) == nospaces("  ___  \n (_*_) \n (- -) \n (   ) \n (   ) "));
    CHECK(nospaces(snowman(12121212)) == nospaces("       \n _===_ \n (..o)/\n<( : ) \n (\" \") "));
    CHECK(nospaces(snowman(34234321)) == nospaces("   _   \n  /_\\  \n (o O) \n (] [)\\\n ( : ) "));
    CHECK(nospaces(snowman(11234234)) == nospaces("       \n _===_ \n (o,O)/\n (> <) \n (   ) "));
    CHECK(nospaces(snowman(23412311)) == nospaces("  ___  \n ..... \n\\(-_.) \n ( : )\\\n ( : ) "));
    CHECK(nospaces(snowman(12343212)) == nospaces("       \n _===_ \n (O.-)/\n/( : ) \n (\" \") "));
    CHECK(nospaces(snowman(33332222)) == nospaces("   _   \n  /_\\  \n\\(O_O)/\n (] [) \n (\" \") "));
    CHECK(nospaces(snowman(11114444)) == nospaces("       \n _===_ \n (.,.) \n (   ) \n (   ) "));
	CHECK(nospaces(snowman(23412311)) == nospaces("  ___  \n ..... \n\\(-_.) \n ( : )\\\n ( : ) "));
    CHECK(nospaces(snowman(12343212)) == nospaces("       \n _===_ \n (O.-)/\n/( : ) \n (\" \") "));
    CHECK(nospaces(snowman(33332222)) == nospaces("   _   \n  /_\\  \n\\(O_O)/\n (] [) \n (\" \") "));
    CHECK(nospaces(snowman(11114444)) == nospaces("       \n _===_ \n (.,.) \n (   ) \n (   ) "));
}

TEST_CASE("Random bad snowman input") {
    CHECK(nospaces(snowman(11111111)) != nospaces("   _   \n  /_\\  \n (O_O) \n/(> <)\\\n (___) "));
    CHECK(nospaces(snowman(22222222)) != nospaces("   _   \n  /_\\  \n\\(O_O)/\n (] [) \n (\" \") "));
    CHECK(nospaces(snowman(33333333)) != nospaces("       \n _===_ \n (O.-)/\n/( : ) \n (\" \") "));
    CHECK(nospaces(snowman(44444444)) != nospaces("  ___  \n ..... \n\\(-_.) \n ( : )\\\n ( : ) "));
    CHECK(nospaces(snowman(12121212)) != nospaces("       \n _===_ \n (.,.) \n (   ) \n (    ) "));
    CHECK(nospaces(snowman(34234321)) != nospaces("   _   \n  /_\\  \n\\(O_O)/\n (] [) \n (\" \") "));
    CHECK(nospaces(snowman(11234234)) != nospaces("       \n _===_ \n (O.-)/\n/( : ) \n (\" \") "));
    CHECK(nospaces(snowman(23412311)) != nospaces("  ___  \n ..... \n\\(-_.) \n (] [) \n (___) "));
    CHECK(nospaces(snowman(12343212)) != nospaces("       \n _===_ \n (o,O)/\n (> <) \n (   ) "));
    CHECK(nospaces(snowman(33332222)) != nospaces("   _   \n  /_\\  \n (o O) \n (] [)\\\n ( : ) "));
    CHECK(nospaces(snowman(11114444)) != nospaces("       \n _===_ \n (..o)/\n<( : ) \n (\" \") "));
	CHECK(nospaces(snowman(23412311)) != nospaces("  ___  \n (_*_) \n (- -) \n (   ) \n (   ) "));
    CHECK(nospaces(snowman(12343212)) != nospaces("       \n _===_ \n (.,.) \n (   ) \n (   ) "));
    CHECK(nospaces(snowman(33332222)) != nospaces("  ___  \n ..... \n\\(o.o)/\n (] [) \n (\" \") "));
    CHECK(nospaces(snowman(11114444)) != nospaces("       \n _===_ \n (.,.) \n<( : )>\n ( : ) "));
}

TEST_CASE("Test correct hat") {
    CHECK(noLineBreak(snowman(11111111)).substr(0,14) == ("        _===_ "));
	CHECK(noLineBreak(snowman(21111111)).substr(0,14) == ("  ___   ..... "));
    CHECK(noLineBreak(snowman(31111111)).substr(0,14) == ("   _     /_\\  "));
    CHECK(noLineBreak(snowman(41111111)).substr(0,14) == ("  ___   (_*_) "));
}

TEST_CASE("Test correct upper body (head and upper hands)") {
    CHECK(noLineBreak(snowman(11111111)).substr(14,7) == (" (.,.) "));
	CHECK(noLineBreak(snowman(22222222)).substr(14,7) == ("\\(o.o)/"));
    CHECK(noLineBreak(snowman(34234321)).substr(14,7) == (" (o O) "));
    CHECK(noLineBreak(snowman(12121212)).substr(14,7) == (" (..o)/"));
}

TEST_CASE("Test correct lower body (torso and lower hands)") {
    CHECK(noLineBreak(snowman(11111111)).substr(21,7) == ("<( : )>"));
	CHECK(noLineBreak(snowman(22222222)).substr(21,7) == (" (] [) "));
    CHECK(noLineBreak(snowman(12121212)).substr(21,7) == ("<( : ) "));
    CHECK(noLineBreak(snowman(23412311)).substr(21,7) == (" ( : )\\"));
}

TEST_CASE("Test correct base") {
    CHECK(noLineBreak(snowman(11111111)).substr(28,7) == (" ( : ) "));
	CHECK(noLineBreak(snowman(11111112)).substr(28,7) == (" (\" \") "));
    CHECK(noLineBreak(snowman(11111113)).substr(28,7) == (" (___) "));
    CHECK(noLineBreak(snowman(11111114)).substr(28,7) == (" (   ) "));
}

