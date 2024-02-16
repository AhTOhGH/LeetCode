#include <vector>
#include <assert.h>
#include <iostream>
#include <limits>

class Solution {
public:
    std::vector<int> replaceElements(std::vector<int>& arr)
    {
        if (arr.empty())        
            return arr;
        
        for (size_t i = 0; i < arr.size()-1; i++)
        {
            int max = std::numeric_limits<int>::min();   //  Вообще если справа только положительные числа, то можно проинициализировать -1 и избавиться от arr[arr.size()-1] = -1;
            for (size_t j = i + 1; j < arr.size(); j++)
            {
               if (max < arr[j])
                   max = arr[j];                
            }            

            arr[i] = max;
        }
        
        arr[arr.size()-1] = -1;

        return arr;
    }  
    //  Можно запомнить на каком месте находится максимальный справа и если текущий не он, то не искать
    std::vector<int> replaceElements2(std::vector<int>& arr)
    {
        if (arr.empty())        
            return arr;
        
        size_t index_max = 0;
        int max = std::numeric_limits<int>::min();   
        for (size_t i = 0; i < arr.size()-1; i++)
        {
            if (i >= index_max)
            {
                max = std::numeric_limits<int>::min();
                
                for (size_t j = i + 1; j < arr.size(); j++)
                {
                    if (max < arr[j])
                        max = arr[j];   

                    if (max == arr[j])
                        index_max = j;
                }  
            }            

            arr[i] = max;
        }
        
        arr[arr.size()-1] = -1;

        return arr;
    }  

    std::vector<int> replaceElements3(std::vector<int>& arr)
    {
        if (arr.empty())        
            return arr;

        int max = arr[arr.size()-1];
        arr[arr.size()-1] = -1;
        for (size_t i = arr.size() - 2; i < arr.size() ; i--)
        {
            if (arr[i] > max)
                std::swap(arr[i], max);       
            else
                arr[i] = max;            
        }
        
        return arr;
    }
};

#define SOLUTION_METHOD_TEST(INPUT_TYPE, INPUT, OUTPUT_TYPE, OUTPUT, METHOD_NAME) {Solution s; \
INPUT_TYPE in(INPUT);\
auto out = s.METHOD_NAME(in);\
assert(out==OUTPUT_TYPE(OUTPUT));}     

#define C ,

void replaceElements()
{    
    SOLUTION_METHOD_TEST(std::vector<int>, {17 C 18 C 5 C 4 C 6 C 1}, std::vector<int>, {18 C 6 C 6 C 6 C 1 C -1}, replaceElements);
    SOLUTION_METHOD_TEST(std::vector<int>, {400}, std::vector<int>, {-1}, replaceElements);
}
void replaceElements2()
{    
    SOLUTION_METHOD_TEST(std::vector<int>, {17 C 18 C 5 C 4 C 6 C 1}, std::vector<int>, {18 C 6 C 6 C 6 C 1 C -1}, replaceElements2);
    SOLUTION_METHOD_TEST(std::vector<int>, {400}, std::vector<int>, {-1}, replaceElements2);
}
void replaceElements3()
{    
    SOLUTION_METHOD_TEST(std::vector<int>, {17 C 18 C 5 C 4 C 6 C 1}, std::vector<int>, {18 C 6 C 6 C 6 C 1 C -1}, replaceElements3);
    SOLUTION_METHOD_TEST(std::vector<int>, {400}, std::vector<int>, {-1}, replaceElements3);
}

int main()
{
    replaceElements();
    replaceElements2();
    replaceElements3();

    std::cout<<"success!" << std::endl;
    return 0;
}
