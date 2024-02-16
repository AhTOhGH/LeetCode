#include <vector>
#include <assert.h>
#include <iostream>
#include <unordered_set>

class Solution {
public:
    bool checkIfExist(std::vector<int>& arr)
    {
        //  Наивная реализация
        if (arr.empty())
            return false;   
        if(arr.size() == 1)
            return false;

        for (size_t i = 0; i < arr.size(); i++)
        {
            for (size_t j = i + 1; j < arr.size(); j++)
            {
                if(arr[i] == 2*arr[j])
                    return true;
                if(2*arr[i] == arr[j])
                    return true;
            }            
        }    

        return false;    
    }    

    bool checkIfExist2(std::vector<int>& arr)
    {
        std::unordered_set<int> values;
        for (size_t i = 0; i < arr.size(); i++)
        {
            if(arr[i]%2==0) 
            {
                if(values.count(arr[i]/2))
                    return true;
            }

            if(values.count(arr[i]*2))
                return true;

            values.insert(arr[i]);
        }
        return false;
    }    
};

int checkIfExist(std::vector<int>& arr)
{
    Solution s;
    return s.checkIfExist(arr);
}

void checkIfExist()
{    
    {
        std::vector<int> arr={10,2,5,3};
        bool k = checkIfExist(arr);
        assert(k==true);        
    }

    {
        std::vector<int> arr={3,1,7,11};
        bool k = checkIfExist(arr);
        assert(k==false);        
    }

    {
        std::vector<int> arr={0,1,7,11};
        bool k = checkIfExist(arr);
        assert(k==false);        
    }

    {
        std::vector<int> arr={7,1,14,11};
        bool k = checkIfExist(arr);
        assert(k==true);        
    }

    {
        std::vector<int> arr={-10,12,-20,-8,15};
        bool k = checkIfExist(arr);
        assert(k==true);        
    }

    {
        std::vector<int> arr={4,-7,11,4,18};
        bool k = checkIfExist(arr);
        assert(k==false);        
    }

}

int checkIfExist2(std::vector<int>& arr)
{
    Solution s;
    return s.checkIfExist2(arr);
}

void checkIfExist2()
{    
    {
        std::vector<int> arr={10,2,5,3};
        bool k = checkIfExist2(arr);
        assert(k==true);        
    }

    {
        std::vector<int> arr={3,1,7,11};
        bool k = checkIfExist2(arr);
        assert(k==false);        
    }

    {
        std::vector<int> arr={0,1,7,11};
        bool k = checkIfExist2(arr);
        assert(k==false);        
    }

        {
        std::vector<int> arr={7,1,14,11};
        bool k = checkIfExist2(arr);
        assert(k==true);        
    }
    
    {
        std::vector<int> arr={-10,12,-20,-8,15};
        bool k = checkIfExist2(arr);
        assert(k==true);        
    }

    {
        std::vector<int> arr={4,-7,11,4,18};
        bool k = checkIfExist2(arr);
        assert(k==false);        
    }

}

int main()
{
    checkIfExist();
    checkIfExist2();

    std::cout<<"succes!" << std::endl;
    return 0;
}