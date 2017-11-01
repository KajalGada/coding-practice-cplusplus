#include <iostream>

int func_find_connections_required(int n)
{
    return (n * (n-1) / 2);
}

int func_find_min_connected_people(int numOfPeople, int numOfConnections)
{    
    
    int connectionsReq = 0, minPeople = numOfPeople, minConnections = numOfConnections;
    bool whileFlag = 1;
    
    while (whileFlag == 1)
    {
        
        connectionsReq = func_find_connections_required(minPeople);        
        std::cout << minPeople << ' ' << minConnections << ' ' << connectionsReq << std::endl;
        
        if (minConnections >= connectionsReq)
        {
            whileFlag = 0;
            return minPeople;
        }
        else
        {
            minPeople = minPeople - 1;
            
            if (minConnections == numOfConnections)
            {
                minConnections = minConnections - 2;
            }
            else
            {
                minConnections = minConnections - 1;
            }                        
            
            if (minConnections <= (minPeople-1))
            {
                if (numOfConnections > 0)
                {
                    return 2;
                }
                else
                {
                    return 0;
                }                
            }
            
        }
        
    }
    
    return 0;
}

int main()
{
    
    int numOfTestCase, numOfPeople, numOfConnections;
    
    std::cin >> numOfTestCase;
    
    for (int testCaseInd = 0; testCaseInd < numOfTestCase; testCaseInd++)
    {
        std::cin >> numOfPeople >> numOfConnections;
        std::cout << func_find_min_connected_people(numOfPeople, numOfConnections) << std::endl;
    }
    
    return 0;
}
