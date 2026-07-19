#include <stdio.h>
#include <stdlib.h>


/**
 * create_array - creates an array of chars
 * @size: size of the array
 * @c: character to initialize the array with
 *
 * Return: pointer to the array, or NULL if it fails
 */

 char *create_array(unsigned int size, char c)
{
    char *ar
    unsigned int i;

    if(size==0)
    return (NULL)
    arr=malloc(size *sizeof(char));
    
    if(arr=NULL)
    return (NULL)

        i = 0
    while (i<size)
    {
      arr[i] = c;
		i++;  /* code */
    }
    
return (arr)
}
