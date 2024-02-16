#include <vector>
#include <assert.h>
#include <iostream>
#include <unordered_set>


class Solution {
public:
    bool validMountainArray(std::vector<int>& arr)
    {
        if(arr.size() < 3)
            return false;

        // Пока Пердыдущее < чем нынешнее и не равно (подъём)
        // Пока предыдущее > текущего и не равно

        size_t i = 1;
        for (; i < arr.size() - 1 && arr[i] > arr[i-1]; i++)
        {
            if(arr[i] == arr[i-1])
                return false;
        }
        
        if(i == arr.size() - 1)
            return false;

        for (; i < arr.size() && arr[i] < arr[i-1]; i++);

        return (i != arr.size() - 1);
    }  

    bool validMountainArray2(std::vector<int>& arr)
    {
        if(arr.size() < 3)
            return false;

        // Пока Пердыдущее < чем нынешнее и не равно (подъём)
        // Пока предыдущее > текущего и не равно

        //  peak - индекс вершины
        size_t peak = arr.size()/2;
        while (true)
        {     
            //  Если вершина в самом конце, то последовательность постоянно возрастает
            if (peak >= arr.size() - 1)
                return false;
                                    
            //  Если вершина в самом начале, то последовательность постоянно убывает
            if (peak <= 0)
                return false;
    
            if (arr[peak] > arr[peak-1] && arr[peak] < arr[peak+1])
            {
                //  Нашли индекс вершины. Надо проверить слева и справа монотонность без повторений
                //  Проверим наименьшую сторону горы в надежде именно там найти ошибку 
                int mid = arr.size()/2;
                if (peak > mid)
                {
                    // Проверим справа
                    for (size_t i = peak; i < arr.size(); i++)
                    {
                        //  Все элементы в этом диапазоне должны быть меньше предыдущего
                        if (arr[i] > arr[i+1])
                        {
                            return false;
                        }                        
                    }                

                    //  Если мы здесь, то надо пройти по левой стороне, т.к. справа всё хорошо

                    //  Проверим слева
                    for (size_t i = 0; i < peak; i++)
                    {
                        //  Все элементы в этом диапазоне должны быть больше предыдущего
                        if (arr[i] < arr[i+1])
                        {
                            return false;
                        }                        
                    }                
                }
                else
                {
                    //  Проверим слева
                    for (size_t i = 0; i < peak; i++)
                    {
                        //  Все элементы в этом диапазоне должны быть больше предыдущего
                        if (arr[i] < arr[i+1])
                        {
                            return false;
                        }                        
                    }                
                    //  Если мы здесь, то надо пройти по правой стороне, т.к. слева всё хорошо

                    // Проверим справа
                    for (size_t i = peak; i < arr.size(); i++)
                    {
                        //  Все элементы в этом диапазоне должны быть меньше предыдущего
                        if (arr[i] > arr[i+1])
                        {
                            return false;
                        }                        
                    }                

                    return true;
                }
            }            
            else if (arr[peak] > arr[peak-1])
            {
                //  Последователь в данной точке растёт
                //  Значит ищем вершину справа
                peak = peak + (arr.size() - peak) / 2;
                continue;
            }
            else if(arr[peak] < arr[peak+1])
            {
                //  Последовательность в данной точке убывает
                //  Значит ищем вершину слева
                peak /= 2;
                continue;
            }

            //  Если мы здесь, то значит дублирование элемента в массиве
            return false;
        }
        
        return false;
    }    
    
    bool is_descent_on_the_left(const std::vector<int>& arr, size_t current)
    {
        for (size_t i = current; i > 0; i--)
        {
            if (arr[i] <= arr[i-1])
                return false;
        }            

        return true;
    };
    
    bool is_mountain_on_the_left(const std::vector<int>& arr, size_t current)
    {
        for (size_t i = current; i > 0; i--)
        {
            if (arr[i] == arr[i-1])
                return false;
            else if(arr[i] > arr[i-1])
                return is_descent_on_the_left(arr, i-1);
        }
        return false;
    };

    bool is_descent_on_the_right(const std::vector<int>& arr, size_t current)
    {
        for (size_t i = current; i < arr.size() - 1; i++)
        {
            if (arr[i] <= arr[i+1])
                return false;
        }            

        return true;
    };

    bool is_mountain_on_the_right(const std::vector<int>& arr, size_t current)
    {
        for (size_t i = current; i < arr.size() - 1; i++)
        {
            if (arr[i] == arr[i+1])
                return false;
            else if(arr[i] > arr[i+1])
                return is_descent_on_the_right(arr, i+1);
        }
        return false;
    };
    

    bool validMountainArray3(std::vector<int>& arr)
    {
        if(arr.size() < 3)
            return false;

        size_t mid = arr.size() / 2;        

        if (arr[mid] > arr[mid-1])
        {
            // Идёт спуск, подъёма быть не дожно
            return is_descent_on_the_left(arr, mid-1) && is_mountain_on_the_right(arr, mid);
        }
        else if (arr[mid] < arr[mid-1])
        {
            // Идёт подъём. После него только спуск
            return is_mountain_on_the_left(arr, mid-1) && is_descent_on_the_right(arr, mid);
        }
        else
            return false;
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
{    
    SOLUTION_METHOD_TEST(std::vector<int>, {3 C 5 C 5}, false, validMountainArray2);
    SOLUTION_METHOD_TEST(std::vector<int>, {0 C 3 C 2 C 1}, true, validMountainArray2);
    SOLUTION_METHOD_TEST(std::vector<int>, {1 C 3 C 2}, true, validMountainArray2);
    SOLUTION_METHOD_TEST(std::vector<int>, {0 C 1 C 2 C 3 C 4 C 5 C 6 C 7 C 8 C 9}, false, validMountainArray2);
}
void validMountainArray3()
{    
    SOLUTION_METHOD_TEST(std::vector<int>, {3 C 5 C 5}, false, validMountainArray3);
    SOLUTION_METHOD_TEST(std::vector<int>, {0 C 3 C 2 C 1}, true, validMountainArray3);
    SOLUTION_METHOD_TEST(std::vector<int>, {1 C 3 C 2}, true, validMountainArray3);
    SOLUTION_METHOD_TEST(std::vector<int>, {0 C 1 C 2 C 3 C 4 C 5 C 6 C 7 C 8 C 9}, false, validMountainArray3);
    SOLUTION_METHOD_TEST(std::vector<int>, {0 C 1 C 2 C 4 C 2 C 1}, true, validMountainArray3);
}

int main()
{
    //validMountainArray();
    //validMountainArray2();
    validMountainArray3();
    
    std::cout<<"success!" << std::endl;
    return 0;
}