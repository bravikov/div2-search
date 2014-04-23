//     Дата: 01 сентября 2012
//    Автор: Дмитрий Бравиков (bravikov@gmail.com)
//   Сборка: gcc -Wall div2-search-test.c div2-search.c -o div2-search-test
//    Вызов: ./div2-search-test <size> [free_position]
// Описание: size - количество позиций, free_position - свободная позиция.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "div2-search.h"

unsigned size;
unsigned free_position;

int main(int argc, char *argv[])
{
    bool free_position_specify = false;
    
    if (argc > 1)
    {
        int s = atoi( argv[1] );
        if (s < 0)
        {
            printf("error arguments: size should not be less than zero\n");
            return 0;
        }
        size = s;
    }
    
    if (argc > 2)
    {
        int fp = atoi( argv[2] );
        
        if (fp < 0)
        {
            printf("error arguments: free position should not be less than zero\n");
            return 0;
        }
        
        free_position = fp;
        
        if (free_position >= size)
        {
            printf("error arguments: free position must be less than size\n");
            return 0;
        }

        free_position_specify = true;
    }
    
    printf("size = %i, ", size);
    
    if (free_position_specify)
    {
        printf("free position = %i; test...\n", free_position);
        int result = div2_search_free_position(0, size);
        if (result == free_position)
            printf(" ok, ");
        else
            printf(" fall, ");
        printf("free position = %i, ", result);
        printf("iterations = %i\n", div2_search_iteration_count);
        return 0;
    }
    
    printf("free position = 0...%i; test...\n", size-1);
    
    int fall_count = 0;
    
    for(free_position = 0; free_position < size; free_position++)
    {
        int result = div2_search_free_position(0, size);
        if (result == free_position)
            printf(" ok, ");
        else
        {
            fall_count++;
            printf(" fall, ");
        }
        printf("free position = %i, ", result);
        printf("iterations = %i\n", div2_search_iteration_count);
    }
    
    printf("fall = %i\n", fall_count);
    
    return 0;
}

bool div2_search_is_data(const int id, const unsigned position)
{
    if (position < free_position)
        return true;
    return false;
}

