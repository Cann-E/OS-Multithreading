#include <pthread.h>
#include <iostream>
#include <iomanip>
#include <algorithm> // For min() and max()
#include <cstdlib> // For abs()

#define TASKS 4

struct CalcTask
{
    int value1;
    int value2;
    int taskType;
    double result;
};

void *processTask(void *taskPtr)
{
    struct CalcTask *calcPtr = // cast taskPtr to a struct CalcTask *
    switch(calcPtr->taskType)
    {
        case 0: // Find Minimum
                break;
        case 1: // Find Maximum
                break;
        case 2: // Find Absolute Difference
                break;
        case 3: // Compute Quotient (Handle zero denominator)
                break;
    }
    return NULL;
}

int main()
{
    static struct CalcTask tasks[TASKS];
    pthread_t threadIDs[TASKS];
        
    for(int i=0; i<TASKS; i++)
    {
        tasks[i].taskType = i;
        std::cin >> tasks[i].value1;
        std::cin >> tasks[i].value2;
        if(/* Call pthread_create */) 
        {
            std::cerr << "Error creating thread\n";
            return 1;
        }		
    }
	
    // Wait for threads to complete.
    // Call pthread_join here
    
    for (int i = 0; i < TASKS; i++)
    {
        switch(tasks[i].taskType)
        {
            case 0:
                std::cout << "min(" << tasks[i].value1 << ", " << tasks[i].value2 << ") = " 
                          << std::fixed << std::setprecision(2) << tasks[i].result << std::endl;
                break;
            case 1:
                std::cout << "max(" << tasks[i].value1 << ", " << tasks[i].value2 << ") = " 
                          << std::fixed << std::setprecision(2) << tasks[i].result << std::endl;
                break;
            case 2:
                std::cout << "|" << tasks[i].value1 << " - " << tasks[i].value2 << "| = " 
                          << std::fixed << std::setprecision(2) << tasks[i].result << std::endl;
                break;
            case 3:
                std::cout << tasks[i].value1 << " / " << tasks[i].value2 << " = " 
                          << std::fixed << std::setprecision(2) << tasks[i].result << std::endl;
                break;
        }
    }
    return 0;
}
