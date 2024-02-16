#include <vector>
#include <assert.h>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int heightChecker(std::vector<int>& heights) 
    {
       auto expected = heights;
        std::sort(expected.begin(), expected.end());
        int count = 0;
        for(int i = 0; i < heights.size(); i++)
        {
            if(heights[i] != expected[i])
            {
                count++;
            }
        }
        
        return count;
    }
};

#define SOLUTION_METHOD_TEST(INPUT_TYPE, INPUT, OUTPUT_TYPE, OUTPUT, METHOD_NAME) {Solution s; \
INPUT_TYPE in(INPUT);\
auto out = s.METHOD_NAME(in);\
assert(out==OUTPUT_TYPE(OUTPUT));}     

#define C ,

void heightChecker()
{    
    SOLUTION_METHOD_TEST(std::vector<int>, {1 C 1 C 4 C 2 C 1 C 3}, int, 3, heightChecker);
    SOLUTION_METHOD_TEST(std::vector<int>, {5 C 1 C 2 C 3 C 4}, int, 5, heightChecker);
    SOLUTION_METHOD_TEST(std::vector<int>, {1 C 2 C 3 C 4 C 5}, int, 0, heightChecker);
}

int main()
{
    heightChecker();

    std::cout<<"success!" << std::endl;
    return 0;
}
