/*
    Kristin Ng (kng04) and Deanna Oei (doei01)
    Homework 2
    This is the UArray2 implementation.
    Representation of the 2D Array: 
        Use the 1D array by utilizing the formula index = col + (row * width)
*/
#include <stdio.h>
#include <stdlib.h>
#include "uarray2.h"
#include <uarray.h>
#include <except.h>
#include <assert.h>

struct UArray2_T {
    int width;
    int height;
    int size;
    UArray_T data;
};

/*
    Description: Allocates a new UArray2 on the heap and initializes
                with the given width, height, and size of each element.
                It will be unboxed and will contain 0s.
    Input
        Int width of array
        Int height of array
        Int size of each element
    Output: New UArray2_T allocated on the heap
    Logical expectations: None of the inputs can be negative
*/
UArray2_T UArray2_new(int width, int height, int size)
{
    assert(width > 0);
    assert(height > 0);
    assert(size > 0);
    /* make heap space */ 
    UArray2_T uarray2 = (UArray2_T) malloc(sizeof(*uarray2));
    assert(uarray2 != NULL);
    /* intitialize data */
    uarray2->width = width;
    uarray2->height = height;
    uarray2->size = size;
    uarray2->data = UArray_new(width*height, size);
    
    return uarray2;
}

/*
    Description: Frees the allocated space in the array
    Input: pointer to UArray2
    Output: none
    Logical expectations: uarray cannot be null
*/
void UArray2_free(UArray2_T *uarray2)
{
    assert(*uarray2 != NULL);
    if (((*uarray2)->data) != NULL) {
        UArray_free((&(*uarray2)->data));
    }
    free(*uarray2);
}

/*
    Description: applies the function apply() to each element in the
                UArray2 by going through each row.
    Input:
        Pointer to UArray2
        Function to be applied to each element in the array
    cl: closure pointer passed to apply function
    Output: none
    Logical expectations: UArray2 is not null
*/
void UArray2_map_row_major(UArray2_T uarray2, 
                           void apply(int row, int col, 
                                    UArray2_T array, void *current, 
                           void *cl), void *cl)
{
    assert(uarray2 != NULL);
    assert(uarray2->data != NULL);
    for ( int row = 0; row < uarray2->height; row++ ) { 
        for ( int col = 0; col < uarray2->width; col++) { 
            apply(row, col, uarray2, 
                    UArray_at(uarray2->data, col + (row * uarray2->width)),
                    cl);
        }
    }
}

/*
    Description: applies the function apply() to each element in the
                UArray2 by going through each column. The difference between
                this and UArray2_map_row_major() is the order in which the
                cells are visited
    Input: 
        Pointer to UArray2
        Function to be applied to each element in the array
    cl: closure pointer passed to apply function
    Output: none
    Logical expectations: UArray2 is not null
*/
void UArray2_map_col_major(UArray2_T uarray2, 
                           void apply(int row, int col, 
                                    UArray2_T array, void *current,
                           void *cl), void *cl)
{
    assert(uarray2 != NULL);
    assert(uarray2->data != NULL);
    for ( int col = 0; col < uarray2->width; col++ ) {
        for ( int row = 0; row < uarray2->height; row++) {
            apply(row, col, uarray2, 
                    UArray_at(uarray2->data, col + (row * uarray2->width)),
                    cl);
        }
    }
}

/*
    Description: Returns width of array
    Input: UArray2
    Output: int representing the width of the array
    Logical expectations: UArray2 is not null
*/
int UArray2_width(UArray2_T uarray2)
{
    assert(uarray2 != NULL);
    return uarray2 -> width;
}

/*
    Description: Returns height of array
    Input: UArray2
    Output: int representing height of array
    Logical expectations: UArray2 is not null
*/
int UArray2_height(UArray2_T uarray2)
{
    assert(uarray2 != NULL);
    return uarray2 -> height;
}

/*
    Description: Returns size of each element in the array
    Input: UArray2
    Output: int representing size of each element in the array
    Logical expectations: UArray2 is not null
*/
int UArray2_size(UArray2_T uarray2)
{
    assert(uarray2 != NULL);
    return uarray2 -> size;
}

/*
    Description: fetches element at row r and column c
    Input:
        Pointer to UArray2
        Int representing which row the element is in
        Int representing which column the element is in
    Output: Pointer to element at position [r,c]
    Logical expectations:
        Uarray2 cannot be null
        Ints r and c are nonnegative
*/
void *UArray2_at(UArray2_T uarray2, int row, int col) 
{
    /*edge cases for if uarray is null, or out of bounds*/
    assert(uarray2 != NULL);
    assert(row < uarray2 -> height && row >= 0);
    assert(col < uarray2 -> width && col >= 0);
    return UArray_at(uarray2 -> data, col + (row * uarray2 -> width));
}