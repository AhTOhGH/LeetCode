#include <vector>
#include <assert.h>
#include <iostream>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums)    
    {
        if (nums.empty())
            return;

        size_t num_pos = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)            
            { 
                nums[num_pos] = nums[i];
                if(num_pos != i)
                    nums[i] = 0;            
                num_pos++;
            }
        }
    }  
};

#define SOLUTION_METHOD_TEST(INPUT_TYPE, INPUT, OUTPUT, METHOD_NAME) {Solution s; \
INPUT_TYPE in(INPUT);\
s.METHOD_NAME(in);\
assert(in==INPUT_TYPE(OUTPUT));}     

#define C ,

void moveZeroes()
{    
    SOLUTION_METHOD_TEST(std::vector<int>, {0 C 1 C 0 C 3 C 12}, {1 C 3 C 12 C 0 C 0}, moveZeroes);
    SOLUTION_METHOD_TEST(std::vector<int>, {0}, {0}, moveZeroes);
    SOLUTION_METHOD_TEST(std::vector<int>, {2 C 1}, {2 C 1}, moveZeroes);
}

int main()
{
    moveZeroes();

    std::cout<<"success!" << std::endl;
    return 0;
}
