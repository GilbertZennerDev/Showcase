#include <stdio.h>
#include <stdlib.h>

// Function to change the value pointed to by a pointer
void change_value(int *ptr, int newvalue)
{
    *ptr = newvalue;  // Dereference ptr and assign the new value
}

// Function to free memory and set the pointer to NULL
void kill_pointer(int **ptr)
{
    free(*ptr);  // Free the memory pointed to by *ptr
    *ptr = NULL;  // Set the pointer itself to NULL
    printf("Pointer deleted\n");
 
    // Verify that ptr is now NULL
    if (ptr == NULL) 
    {
        printf("ptr is now NULL\n");
    }
    else
    {
        printf("ptr is not NULL (this shouldn't happen)\n");
    }
 
}

int main(void)
{
    // Dynamically allocate memory for an integer
    int *ptr = malloc(sizeof(int));
    
    // Check if memory allocation was successful
    if(ptr == NULL)
    {
        printf("memory alloc failed!\n");
        return 1;  // Exit the program with an error code
    }
    
    *ptr = 0;  // Initialize the allocated memory to 0
    printf("Before change *ptr = %d\n", *ptr);
    
    change_value(ptr, 1);  // Change the value to 1
    printf("After change *ptr = %d\n", *ptr);
    
    kill_pointer(&ptr);  // Free the memory and set ptr to NULL   
   
    return 0;  // Exit the program successfully
}
