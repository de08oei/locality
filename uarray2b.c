/*
    Lexi Shewchuk (ashewc01) and Deanna Oei (doei01)
    Homework 2
    This is the UArray2 implementation.
    Representation of the uarray2b Array: 
        Use the 1D array by utilizing the formula ______INSERT HERE_____
*/

#include <stdio.h>
#include <stdlib.h>
#include "uarray2.h"
#include <uarray.h>
#include <except.h>
#include <assert.h>
#include "uarray2b.h"

#define T UArray2b_T

/*
 * UArray2b_new
 * Behavior: 
 * Parameters: 
 * Returns: 
 * Expectations/errors: 
 */
T UArray2b_new (int width, int height, int size, int blocksize)
{
    
}

/*
 * UArray2b_new_64K_block
 * Behavior: 
 * Parameters: 
 * Returns: 
 * Expectations/errors: 
 */
T UArray2b_new_64K_block(int width, int height, int size)
{

}

/*
 * UArray2b_free
 * Behavior: 
 * Parameters: 
 * Returns: 
 * Expectations/errors: 
 */
void UArray2b_free (T *array2b)
{

}

/*
 * UArray2b_width
 * Behavior: 
 * Parameters: 
 * Returns: 
 * Expectations/errors: 
 */
int UArray2b_width (T array2b)
{

}

/*
 * UArray2b_height
 * Behavior: 
 * Parameters: 
 * Returns: 
 * Expectations/errors: 
 */
int UArray2b_height (T array2b)
{
    
}

/*
 * UArray2b_size
 * Behavior: 
 * Parameters: 
 * Returns: 
 * Expectations/errors: 
 */
int UArray2b_size (T array2b)
{

}

/*
 * UArray2b_blocksize
 * Behavior: 
 * Parameters: 
 * Returns: 
 * Expectations/errors: 
 */
int UArray2b_blocksize(T array2b)
{
    
}

/*
 * UArray2b_at
 * Behavior: 
 * Parameters: 
 * Returns: 
 * Expectations/errors: 
 */
void *UArray2b_at(T array2b, int column, int row)
{
    
}

/*
 * UArray2b_map
 * Behavior: visits every cell in one block before moving to another block
 * Parameters: 
 * Returns: 
 * Expectations/errors: 
 */
void UArray2b_map(T array2b,
                void apply(int col, int row, T array2b,
                void *elem, void *cl),
                void *cl)
{
    
}