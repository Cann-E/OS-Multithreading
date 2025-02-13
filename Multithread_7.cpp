#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <string>

struct arguments
{
    int pos;
    int size;
    int *array;
};

void *squareElement(void *void_ptr)
{
    arguments *arg_ptr = (struct arguments *)void_ptr; // Cast the void pointer to a struct arguments pointer
    int pos = arg_ptr->pos;

    // Modify the array element at position `pos`
    arg_ptr->array[pos]*=arg_ptr->array[pos];

    return nullptr;
}

int main()
{
    int size;
    std::cin >> size;
    int *array = new int[size];

    for (int i = 0; i < size; i++)
        std::cin >> array[i];

    int nthreads = size ;
    pthread_t *tid = new pthread_t[nthreads];
    arguments *arg = new arguments[nthreads];

    for (int i = 0; i < nthreads; i++)
    {
        arg[i].pos = i;
        arg[i].size = size;
        arg[i].array = array;  // Assign necessary values

        if ( pthread_create( &tid[i],nullptr,squareElement,&arg[i] ) ) // Complete pthread_create parameters
        {
            fprintf(stderr, "Error creating thread\n");
            return 1;
        }
    }

    // Call pthread_join here
    for(int i =0;i<nthreads;i++){
        pthread_join(tid[i],nullptr);
    }
    

    // DO NOT MODIFY THE LOOP BELOW
    for (int i = 0; i < size; i++)
        std::cout << array[i] << " ";

    delete[] tid;
    delete[] arg;
    delete[] array;
    return 0;
}
