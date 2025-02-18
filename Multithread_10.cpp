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

void *doubleEvenElement(void *void_ptr)
{
    arguments *arg_ptr = (struct arguments*)void_ptr;// cast the void pointer to a struct arguments pointer
    int pos = arg_ptr->pos;

    // Double the element at position `pos` only if it is even
    if(arg_ptr->array[pos]%2==0){
        arg_ptr->array[pos]*=2;
    }

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
        arg[i].pos = i * 2; // Assign only even indices
        arg[i].size = size;
        arg[i].array = array; // assign the address of the array of integers
        if ( pthread_create(&tid[i],nullptr,doubleEvenElement,&arg[i])/* call pthread_create */ )
        {
            fprintf(stderr, "Error creating thread\n");
            return 1;
        }
    }

    // call pthread_join here
    for(int i=0;i<nthreads;i++){
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
