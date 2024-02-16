#include <vector>
#include <assert.h>
#include <iostream>

class Solution {
public:
    std::vector<int> sortArrayByParity(std::vector<int>& nums)   
    {
        for (size_t i = 0; i < nums.size()-1; i++)
        {
            if (nums[i]%2 != 0)
            {
                for (size_t j = i+1; j < nums.size(); j++)
                {
                    if (nums[j]%2 == 0)
                    {
                        std::swap(nums[i], nums[j]);
                        break;
                    }                    
                }                
            }            
        }
        return nums;
    }  

    std::vector<int> sortArrayByParity3(std::vector<int>& nums)   
    {
        size_t counter = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 != 0)
            {
                counter++;
            }
            else
            {
                std::swap(nums[i], nums[i-counter]);
            }
        }

        return nums;
    }
};

#define SOLUTION_METHOD_TEST(INPUT_TYPE, INPUT, OUTPUT, METHOD_NAME) {Solution s; \
INPUT_TYPE in(INPUT);\
s.METHOD_NAME(in);\
assert(in==INPUT_TYPE(OUTPUT));}     

#define C ,

void sortArrayByParity()
{    
    SOLUTION_METHOD_TEST(std::vector<int>, {3 C 1 C 2 C 4}, {2 C 4 C 3 C 1}, sortArrayByParity);
    SOLUTION_METHOD_TEST(std::vector<int>, {3}, {3}, sortArrayByParity);
}
void sortArrayByParity3()
{    
    SOLUTION_METHOD_TEST(std::vector<int>, {3 C 1 C 2 C 4}, {2 C 4 C 3 C 1}, sortArrayByParity3);
    SOLUTION_METHOD_TEST(std::vector<int>, {3}, {3}, sortArrayByParity3);
}

int main()
{
    sortArrayByParity();
    sortArrayByParity3();
    std::cout<<"success!" << std::endl;
    return 0;
}
