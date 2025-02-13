#include <pthread.h>
#include <iostream>
#include <iomanip>

#define TASKS 4

struct MathTask
{
    int number1;
    int number2;
    int operationType;
    double output;
};

void *computeResult(void *taskPointer)
{
    struct MathTask *mathPtr = (struct MathTask *) taskPointer;
    switch(mathPtr->operationType)
    {
        case 0: mathPtr->output=mathPtr->number1+mathPtr->number2;
                break;
        case 1: mathPtr->output=mathPtr->number1-mathPtr->number2;// Perform Subtraction
                break;
        case 2: mathPtr->output=mathPtr->number1*mathPtr->number2;// Perform Multiplication
                break;
        case 3: if(mathPtr->output != 0)
                    mathPtr->output=mathPtr->number1/mathPtr->number2;
                else
                    mathPtr->output=0;// Perform Division (Handle zero denominator)
                break;
    }
    return NULL;
}

int main()
{
    static struct MathTask tasks[TASKS];
    pthread_t threadIDs[TASKS];
        
    for(int i=0; i<TASKS; i++)
    {
        tasks[i].operationType = i;
        std::cin >> tasks[i].number1;
        std::cin >> tasks[i].number2;
        if(pthread_create(&threadIDs[i],NULL,computeResult,&tasks[i])/* Call pthread_create */) 
        {
            std::cerr << "Error creating thread\n";
            return 1;
        }		
    }
	for(int i=0;i<TASKS;i++){
        pthread_join(threadIDs[i],nullptr);
    }
    // Wait for threads to complete.
    // Call pthread_join here
    //
    
    for (int i = 0; i < TASKS; i++)
    {
        switch(tasks[i].operationType)
        {
            case 0: std::cout << tasks[i].number1 << " + " << tasks[i].number2 << " = " 
                              << std::fixed << std::setprecision(2) << tasks[i].output << std::endl;
                    break;
            case 1: std::cout << tasks[i].number1 << " - " << tasks[i].number2 << " = " 
                              << std::fixed << std::setprecision(2) << tasks[i].output << std::endl;
                    break;
            case 2: std::cout << tasks[i].number1 << " * " << tasks[i].number2 << " = " 
                              << std::fixed << std::setprecision(2) << tasks[i].output << std::endl;
                    break;
            case 3: std::cout << tasks[i].number1 << " / " << tasks[i].number2 << " = " 
                              << std::fixed << std::setprecision(2) << tasks[i].output << std::endl;
                    break;
        }
    }
    return 0;
}
