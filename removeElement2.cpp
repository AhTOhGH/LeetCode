#include <vector>
#include <assert.h>
#include <iostream>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val)   
    {
        size_t counter = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] == val)
            {
                counter++;
            }
            else
            {
                std::swap(nums[i], nums[i-counter]);
            }
        }

        return nums.size() - counter;
    }
};

void removeElement()
{    
    std::vector<int>test_case({3,2,2,3});
    assert(Solution().removeElement(test_case, 3) == 2);
}

int main()
{
    removeElement();

    std::cout<<"success!" << std::endl;
    return 0;
}
