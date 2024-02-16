#include <vector>
#include <assert.h>
#include <iostream>
#include <limits>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) 
    {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return 1;

        size_t last_unique_element_index = 0;
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[last_unique_element_index])
            {
                last_unique_element_index++;
                nums[last_unique_element_index] = nums[i];
            }            
        }
        return last_unique_element_index + 1;
    }  
};

#define SOLUTION_METHOD_TEST(INPUT_TYPE, INPUT, OUTPUT_TYPE, OUTPUT, METHOD_NAME) {Solution s; \
INPUT_TYPE in(INPUT);\
auto out = s.METHOD_NAME(in);\
assert(out==OUTPUT_TYPE(OUTPUT));}     

#define C ,

void removeDuplicates()
{    
    SOLUTION_METHOD_TEST(std::vector<int>, {1 C 1 C 2}, int, 2, removeDuplicates);
    SOLUTION_METHOD_TEST(std::vector<int>, {0 C 0 C 1 C 1 C 1 C 2 C 2 C 3 C 3 C 4}, int, 5, removeDuplicates);
}

int main()
{
    removeDuplicates();

    std::cout<<"success!" << std::endl;
    return 0;
}
