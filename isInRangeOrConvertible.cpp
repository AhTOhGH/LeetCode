#include <vector>
#include <assert.h>
#include <iostream>
#include <unordered_set>


class Solution {
public:
    bool validMountainArray(std::vector<int>& arr)
    {
        
    }  

    
};

#define SOLUTION_METHOD_TEST(INPUT_TYPE, INPUT, OUTPUT, METHOD_NAME) {Solution s; \
INPUT_TYPE in(INPUT);\
auto out = s.METHOD_NAME(in);\
assert(out==OUTPUT);}     

#define C ,

void validMountainArray()
{    
    SOLUTION_METHOD_TEST(std::vector<int>, {3 C 5 C 5}, false, validMountainArray);
    SOLUTION_METHOD_TEST(std::vector<int>, {0 C 3 C 2 C 1}, true, validMountainArray);
    SOLUTION_METHOD_TEST(std::vector<int>, {1 C 3 C 2}, true, validMountainArray);
    SOLUTION_METHOD_TEST(std::vector<int>, {0 C 1 C 2 C 3 C 4 C 5 C 6 C 7 C 8 C 9}, false, validMountainArray);
}
void validMountainArray2()

int main()
{
    //validMountainArray();
    validMountainArray2();

    std::cout<<"succes!" << std::endl;
    return 0;
}