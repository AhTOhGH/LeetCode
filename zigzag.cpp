#include <string>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <array>

class Solution {
public:
    std::string convert(std::string s, int numRows) 
    {
        if (numRows == 1 || numRows >= s.size())
            return s;

        std::string res;
        res.reserve(s.size());
        for (size_t i = 0; i < numRows; i++)
        {
            res += s[i];
            for (size_t j = 1; j <= s.size() / numRows; j++)
            {
                int x = i + j * 2 * (numRows - 1);
                if (i > 0 && i < (numRows - 1))
                {
                    int x_ = x - 2 * i;
                    if (x_ < s.size())            
                    res += s[x_];            
                }
                if (x < s.size())         
                    res += s[x];         
            }
        }

        return res;
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
