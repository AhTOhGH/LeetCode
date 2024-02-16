#include <vector>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <array>

class Solution {
public:
    int thirdMax(const std::vector<int>& v)
    {
       std::array<const int*, 3> maximums;
       maximums.fill(nullptr);

       for (int i = 0; i < v.size(); ++i)
       {
          if (!maximums[0] || v[i] > *maximums[0])
          {
             if (maximums[0])
             {
                if (maximums[1])
                   maximums[2] = maximums[1];
                maximums[1] = maximums[0];
             }

             maximums[0] = &v[i];
          }
          else if (*maximums[0] != v[i])
          {
             if (!maximums[1] || v[i] > *maximums[1])
             {
                if (maximums[1])
                   maximums[2] = maximums[1];
                maximums[1] = &v[i];
             }
             else if ((!maximums[2] || v[i] > *maximums[2]) && v[i] != *maximums[1])
                maximums[2] = &v[i];
          }
       }

       return maximums[2] ? *maximums[2] : *maximums[0];
    }
};

#define SOLUTION_METHOD_TEST(INPUT_TYPE, INPUT, OUTPUT_TYPE, OUTPUT, METHOD_NAME) {Solution s; \
INPUT_TYPE in(INPUT);\
auto out = s.METHOD_NAME(in);\
assert(out==OUTPUT_TYPE(OUTPUT));}     

#define C ,

void heightChecker()
{    
    
}

int main()
{
    heightChecker();

    std::cout<<"success!" << std::endl;
    return 0;
}
