#include <pthread.h>
#include <iostream>
#include <iomanip>

#define TASK_COUNT 4

struct Calculation
{
    int num1;
    int num2;
    int operation;
    double result;
};

// Function to be executed by threads
void *compute(void *arg)
{
    struct Calculation *calc_ptr = (struct Calculation *)arg; // (1) Cast arg to struct Calculation *

    switch (calc_ptr->operation)
    {
        case 0: 
            calc_ptr->result = calc_ptr->num1 + calc_ptr->num2; // Addition
            break;
        case 1: 
            calc_ptr->result = calc_ptr->num1 - calc_ptr->num2; // Subtraction
            break;
        case 2: 
            calc_ptr->result = calc_ptr->num1 * calc_ptr->num2; // Multiplication
            break;
        case 3: 
            if (calc_ptr->output != 0) // Division with zero check
                calc_ptr->result = static_cast<double>(calc_ptr->num1) / calc_ptr->num2;
            else
                calc_ptr->result = 0.00; 
            break;
    }
    return NULL;
}

int main()
{
    static struct Calculation calculations[TASK_COUNT];
    pthread_t threads[TASK_COUNT];

    // Read input values
    for (int i = 0; i < TASK_COUNT; i++)
    {
        calculations[i].operation = i;
        std::cin >> calculations[i].num1;
        std::cin >> calculations[i].num2;
        
        if (pthread_create(&threads[i], NULL, compute, &calculations[i]))
        {
            std::cerr << "Error creating thread\n";
            return 1;
        }
    }

    // Wait for threads to complete
    for (int i = 0; i < TASK_COUNT; i++)
    {
        pthread_join(threads[i], nullptr);
    }

    // Display results
    for (int i = 0; i < TASK_COUNT; i++)
    {
        switch (calculations[i].operation)
        {
            case 0:
                std::cout << calculations[i].num1 << " + " << calculations[i].num2 << " = " 
                          << std::fixed << std::setprecision(2) << calculations[i].result << std::endl;
                break;
            case 1:
                std::cout << calculations[i].num1 << " - " << calculations[i].num2 << " = " 
                          << std::fixed << std::setprecision(2) << calculations[i].result << std::endl;
                break;
            case 2:
                std::cout << calculations[i].num1 << " * " << calculations[i].num2 << " = " 
                          << std::fixed << std::setprecision(2) << calculations[i].result << std::endl;
                break;
            case 3:
                std::cout << calculations[i].num1 << " / " << calculations[i].num2 << " = " 
                          << std::fixed << std::setprecision(2) << calculations[i].result << std::endl;
                break;
        }
    }
    return 0;
}
