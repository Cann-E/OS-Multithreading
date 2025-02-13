#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <string.h>

struct arguments
{
    int pos;
    int size;
    int *array;
};

void rotateLeft(int *array, int size)
{
    int first = array[0];
    for (int i = 0; i < size - 1; i++)
        array[i] = array[i + 1];
    array[size - 1] = first;
}

void *rotateArray(void *void_ptr)
{
    arguments *arg_ptr = // cast the void pointer to a struct arguments pointer
    int pos = arg_ptr->pos;
    // call the rotateLeft function once per thread to perform a left rotation

    return nullptr;
}

int main()
{
    int size;
    std::cin >> size;
    int *array = new int[size];
    for (int i = 0; i < size; i++)
        std::cin >> array[i];

    int nthreads = size / 2;
    pthread_t *tid = new pthread_t[nthreads];
    arguments *arg = new arguments[nthreads];
    for (int i = 0; i < nthreads; i++)
    {
        arg[i].pos = i;
        arg[i].size = size;
        arg[i].array = // assign the address of the array of integers
        if ( /* call pthread_create */ )
        {
            fprintf(stderr, "Error creating thread\n");
            return 1;
        }
    }

    // call pthread_join here

    // DO NOT MODIFY THE LOOP BELOW
    for (int i = 0; i < size; i++)
        std::cout << array[i] << " ";

    delete[] tid;
    delete[] arg;
    delete[] array;
    return 0;
}
