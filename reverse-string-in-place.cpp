#include <iostream>
#include <string>

// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

void reverse(string& str)
{
    // reverse the input string in place
    if(str.empty()) {
        return;
    }
    
    size_t leftIndex = 0;
    size_t rightIndex = str.length() -1;
    
    while(leftIndex < rightIndex) {
        // swap characters
        swap(str[leftIndex], str[rightIndex]);
        
        // move inwards towards middle
        ++leftIndex;
        --rightIndex;
    }

}











// ------------------------------------------------------------






// tests

const lest::test tests[] = {
    {CASE("empty string") {
        const string expected;
        string actual;
        reverse(actual);
        EXPECT(actual == expected);
    }},
    {CASE("single character string") {
        const string expected("A");
        string actual("A");
        reverse(actual);
        EXPECT(actual == expected);
    }},
    {CASE("longer string") {
        const string expected("EDCBA");
        string actual("ABCDE");
        reverse(actual);
        EXPECT(actual == expected);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}




// tests results
//empty string                   passed: actual == expected for "" == ""
//single character string        passed: actual == expected for "A" == "A"
//longer string                  passed: actual == expected for "EDCBA" == "EDCBA"
//All 3 selected tests passed.