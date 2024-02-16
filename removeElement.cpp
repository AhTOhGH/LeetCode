//https://leetcode.com/problems/remove-element/?envType=study-plan-v2&envId=top-interview-150
#include <vector>
#include <assert.h>
#include <iostream>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) 
    {
        //  Если встретили элемент перемещаем его в конец и сдвигаем границу влево
        int actualSize = nums.size();
        for(int i = 0; i<actualSize; i++)
        {
            if(nums[i] == val)
            {
                for(int j = i; j < actualSize-1; j++)
                {
                   std::swap(nums[j], nums[j+1]);
                }
                actualSize--;
                i--;
            }
        }

        return actualSize;
    }

    int removeElement2(std::vector<int>& nums, int val) 
    {
        //  Если нашли элемент то все следующие сдвигаем влево
        const int sorceSize = nums.size();
        int nCountMatches = 0;
        for(int i = 0; i<sorceSize; i++)
        {
            if(nums[i] == val)
            {
                nCountMatches++;
                continue;
            }

            if(nCountMatches)
                nums[i-1] = nums[i];            
        }

        return sorceSize - nCountMatches;
    }

    int removeElement3(std::vector<int>& nums, int val) 
    {
        //  Если нашли элемент меняем его с последним
        int actualSize = nums.size();
        for(int i = 0; i<actualSize; i++)
        {
            if(nums[i] == val)
            {
                std::swap(nums[i], nums[actualSize-1]);
                actualSize--;
                i--;
            }
        }

        return actualSize;
    }

};

int testRemoveElements(std::vector<int>& arr, int val)
{
    Solution s;
    return s.removeElement(arr, val);
}

int testRemoveElements2(std::vector<int>& arr, int val)
{
    Solution s;
    return s.removeElement2(arr, val);
}

int testRemoveElements3(std::vector<int>& arr, int val)
{
    Solution s;
    return s.removeElement3(arr, val);
}

void testRemoveElement()
{    
    {
        std::vector<int> arr={3,2,2,3};
        int val = 3; 
        int k = testRemoveElements(arr, val);
        assert(k==2);        
    }

    {
        std::vector<int> arr={0,1,2,2,3,0,4,2};
        int val = 2; 
        int k = testRemoveElements(arr, val);
        assert(k==5);        
    }
}

void testRemoveElement2()
{    
    {
        std::vector<int> arr={3,2,2,3};
        int val = 3; 
        int k = testRemoveElements2(arr, val);
        assert(k==2);        
    }

    {
        std::vector<int> arr={0,1,2,2,3,0,4,2};
        int val = 2; 
        int k = testRemoveElements2(arr, val);
        assert(k==5);        
    }
}

void testRemoveElement3()
{    
    {
        std::vector<int> arr={3,2,2,3};
        int val = 3; 
        int k = testRemoveElements3(arr, val);
        assert(k==2);        
    }

    {
        std::vector<int> arr={0,1,2,2,3,0,4,2};
        int val = 2; 
        int k = testRemoveElements3(arr, val);
        assert(k==5);        
    }
}

int main()
{
    //testRemoveElement();
    //testRemoveElement2();
    testRemoveElement3();

    std::cout<<"succes!" << std::endl;
    return 0;
}
