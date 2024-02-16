#include <string>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <array>

class Solution {
public:
    std::string convert(std::string s, int numRows) 
    {
        
    }
};

#define SOLUTION_METHOD_TEST(INPUT_TYPE, INPUT, OUTPUT_TYPE, OUTPUT, METHOD_NAME) {Solution s; \
INPUT_TYPE in(INPUT);\
auto out = s.METHOD_NAME(in);\
assert(out==OUTPUT_TYPE(OUTPUT));}     

#define C ,

void convert()
{    
    std::cout << Solution().convert("A", 2) << std::endl;
}

int main()
{
    convert();

    std::cout<<"success!" << std::endl;
    return 0;
}
