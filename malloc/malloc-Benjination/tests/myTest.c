#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main()
{
    int count = 10000;
    int blocksize = 2500;
    char *ptrs[count];
    
    clock_t start, end;
    double time;
    
    start = clock(); 
    for(int i = 0;i<count;i++)
    {
        ptrs[i] = (char *)malloc(blocksize);
    }
    for(int i = 0;i<count;i++)
    {
        free(ptrs[i]);
    }
    end = clock();
    time = end - start;
    printf("The time is %.0f ticks\n", time);

    return 0;
}
