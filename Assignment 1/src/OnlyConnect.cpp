/* File: OnlyConnect.cpp
 *
 * TODO: Edit these comments to describe anything interesting or noteworthy in your implementation.
 *
 * TODO: Edit these comments to leave a puzzle for your section leader to solve!
 */
#include "OnlyConnect.h"
#include "GUI/SimpleTest.h"
using namespace std;

string onlyConnectize(string phrase) {
    /* TODO: The next few lines just exist to make sure you don't get compiler warning messages
     * when this function isn't implemented. Delete these lines, then implement this function.
     */

    // my answer
    // string result = "";

    // if (phrase == ""){
    //     return result;
    // }

    // if (isalpha(phrase[0])) {
    //     if(phrase[0]!='a' && phrase[0]!='A' && phrase[0]!='e' &&
    //         phrase[0]!='E' && phrase[0]!='i' && phrase[0]!='I' &&
    //         phrase[0]!='o' && phrase[0]!='O' && phrase[0]!='u' &&
    //         phrase[0]!='U') {
    //         result = toupper(phrase[0]);
    //     }
    // }

    // if (phrase.length() > 1) {
    //     result = result + onlyConnectize(phrase.substr(1));
    // }

    // return result;

    // ai improved
    // 辅音字母（大写）
    unordered_set<char> vowels = {'A', 'E', 'I', 'O', 'U'};

    // 递归基准条件
    if (phrase.empty()) {
        return "";
    }

    // 处理当前字符：如果是辅音，则转为大写
    char currentChar = toupper(phrase[0]);
    if (isalpha(currentChar) && vowels.find(currentChar) == vowels.end()) {
        // 递归返回辅音并拼接后续字符
        return string(1, currentChar) + onlyConnectize(phrase.substr(1));
    }

    // 如果当前字符不是辅音，直接递归继续处理下一个字符
    return onlyConnectize(phrase.substr(1));
}




/* * * * * * Provided Test Cases * * * * * */

PROVIDED_TEST("Converts lower-case to upper-case.") {
    EXPECT_EQUAL(onlyConnectize("lowercase"), "LWRCS");
    EXPECT_EQUAL(onlyConnectize("uppercase"), "PPRCS");
}

PROVIDED_TEST("Handles non-letter characters properly.") {
    EXPECT_EQUAL(onlyConnectize("2.718281828459045"), "");
    EXPECT_EQUAL(onlyConnectize("'Hi, Mom!'"), "HMM");
}

PROVIDED_TEST("Handles single-character inputs.") {
    EXPECT_EQUAL(onlyConnectize("A"), "");
    EXPECT_EQUAL(onlyConnectize("+"), "");
    EXPECT_EQUAL(onlyConnectize("Q"), "Q");
}

/* TODO: You will need to add your own tests into this suite of test cases. Think about the sorts
 * of inputs we tested here, and, importantly, what sorts of inputs we *didn't* test here. Some
 * general rules of testing:
 *
 *    1. Try extreme cases. What are some very large cases to check? What are some very small cases?
 *
 *    2. Be diverse. There are a lot of possible inputs out there. Make sure you have tests that account
 *       for cases that aren't just variations of one another.
 *
 *    3. Be sneaky. Don't just try standard inputs. Try weird ones that you wouldn't expect anyone to
 *       actually enter, but which are still perfectly legal.
 *
 * Happy testing!
 */






