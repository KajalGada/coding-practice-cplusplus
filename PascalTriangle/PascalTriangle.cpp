#include <iostream>
#include <vector>

unsigned long long int func_factorial_modified(unsigned long long int num, unsigned long long int numStop)
{
    unsigned long long int temp;
    if (num == 0)
    {
        return 1;
    }
    if (num == numStop)
    {
        return numStop;
    }
    else
    {
        temp = num * func_factorial_modified(num-1,numStop);
        return temp;
    }
}

void func_print_pascal_triangle(int num)
{
    unsigned long long int element, numElement, denElement;
    
    for (int n = 0; n < num; n++)
    {
        std::vector<unsigned long long int> row;
        
        for (int r = 0; r <= n; r++)
        {                        
            if (r==0)
            {
                element = 1;
            }
            else if (r==n)
            {
                element = 1;
            }
            else 
            {
                if (r>(n-r))
                {
                    numElement = func_factorial_modified(n,(r+1));
                    denElement = func_factorial_modified((n-r),1);
                }                
                else
                {
                    numElement = func_factorial_modified(n,(n-r+1));
                    denElement = func_factorial_modified(r,1);
                }
                element = numElement/denElement;
            }
            
            row.push_back(element);
        }
        
        for (int rowInd = 0; rowInd < row.size(); rowInd++)
        {
            std::cout << row[rowInd] << ' ';
        }
        
        std::cout << ' ' << std::endl;
        
    }
}

int main()
{
    int num;
    std::cin >> num;   
    
    func_print_pascal_triangle(num);
    
    return 0;
}
