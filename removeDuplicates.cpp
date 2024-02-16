#include <vector>
#include <assert.h>
#include <iostream>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums)
    {
        // Наиваная реализация

        if(nums.size()<=1)
            return -1;
        
        int actualSize = nums.size();
        for (size_t i = 1; i < actualSize; i++)
        {
            if(nums[i] == nums[i-1])
            {
                for (size_t j = i; j < actualSize-1; j++)
                {
                    std::swap(nums[j], nums[j+1]);
                }                
                i--;
                actualSize--;   //  В конце ненужная копия
            }
        }

        return actualSize;        
    }

    int removeDuplicates2(std::vector<int>& nums)
    {
        if(nums.empty())
            return 0;

        if(nums.size()==1)
            return 1;
        const int lastIndex = nums.size()-1;
        int lastBigElem = 0;
        size_t i = 0;
        for (;i < nums.size(); i++)
        {
            while (nums[i] == nums[lastBigElem])
            {
                lastBigElem++;              
                if(lastBigElem > lastIndex)    
                    return i + 1;          
            }

            const int next = i+1;
            if (lastBigElem > lastIndex)
            {
                return next;
            }  

            nums[next] = nums[lastBigElem];
            if (lastBigElem == lastIndex)
            {
                return next + 1;
            }  

        }     
        return i + 1;
    }
};

int removeDuplicates(std::vector<int>& arr)
{
    Solution s;
    return s.removeDuplicates(arr);
}

void testRemoveDuplicates()
{    
    {
        std::vector<int> arr={1,1,2};
        int k = removeDuplicates(arr);
        assert(k==2);        
    }

    {
        std::vector<int> arr={0,0,1,1,1,2,2,3,3,4};
        int k = removeDuplicates(arr);
        assert(k==5);        
    }

    {
        std::vector<int> arr={1};
        int k = removeDuplicates(arr);
        assert(k==1);        
    }

}

int removeDuplicates2(std::vector<int>& arr)
{
    Solution s;
    return s.removeDuplicates2(arr);
}

void testRemoveDuplicates2()
{    
    {
        std::vector<int> arr={1,1,2};
        int k = removeDuplicates2(arr);
        assert(k==2);        
    }

    {
        std::vector<int> arr={0,0,1,1,1,2,2,3,3,4};
        int k = removeDuplicates2(arr);
        assert(k==5);        
    }

    {
        std::vector<int> arr={1};
        int k = removeDuplicates2(arr);
        assert(k==1);        
    }

    {
        std::vector<int> arr={1, 1};
        int k = removeDuplicates2(arr);
        assert(k==1);        
    }

}

int main()
{
    //testRemoveDuplicates();
    testRemoveDuplicates2();

    std::cout<<"succes!" << std::endl;
    return 0;
}