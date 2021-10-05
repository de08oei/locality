/*
    Kristin Ng (kng04) and Deanna Oei (doei01)
    Homework 2
    This is the header file for our UArray2 implementation.
*/

#ifndef UARRAY2_INCLUDED
#define UARRAY2_INCLUDED

typedef struct UArray2_T *UArray2_T;

/*
    Description: Allocates a new UArray2 on the heap and initializes with
                the given width, height, and size of each element. It will
                be unboxed and will contain 0s
    Input:
        Int width of array
        Int height of array
        Int size of each element
    Output: New UArray2_T allocated on the heap
    Logical expectations: None of the inputs can be negative
*/
UArray2_T UArray2_new(int width, int height, int size);

/*
    Description: Frees the allocated space in the array
    Input: pointer to UArray2
    Output: none
    Logical expectations: uarray cannot be null
*/
void UArray2_free(UArray2_T *uarray2);

/*
    Description: applies the function apply() to each element in the UArray2
                by going through each row
    Input:
        UArray2
        Function to be applied to each element in the array
        cl: closure pointer passed to apply function
    Output: none
    Logical expectations: UArray2 is not null
*/
void UArray2_map_row_major(UArray2_T uarray2, 
                           void apply(int row, int col, UArray2_T array, 
                                    void *current, void *cl), 
                           void *cl);

/*
    Description: applies the function apply() to each element in the UArray2
                by going through each column. The difference between this and
                UArray2_map_row_major() is the order in which the cells are 
                visited
    Input: 
        UArray2
        Function to be applied to each element in the array
        cl: closure pointer passed to apply function
    Output: none
    Logical expectations: UArray2 is not null
*/
void UArray2_map_col_major(UArray2_T uarray2, 
                           void apply(int row, int col, UArray2_T array,
                                    void *current, void *cl), 
                           void *cl);

/*
    Description: Returns width of array
    Input: UArray2
    Output: int representing the width of the array
    Logical expectations: UArray2 is not null
*/
int UArray2_width(UArray2_T uarray2);

/*
    Description: Returns height of array
    Input: UArray2
    Output: int representing height of array
    Logical expectations: UArray2 is not null
*/
int UArray2_height(UArray2_T uarray2);

/*
    Description: Returns size of each element in the array
    Input: UArray2
    Output: int representing size of each element in the array
    Logical expectations: UArray2 is not null
*/
int UArray2_size(UArray2_T uarray2);

/*
    Description: fetches element at row r and column c
    Input:
        UArray2
        Int representing which row the element is in
        Int representing which column the element is in
    Output: Pointer to element at position [r,c]
    Logical expectations:
        Uarray2 cannot be null
        Ints r and c are nonnegative
*/
void *UArray2_at(UArray2_T uarray2, int row, int col);

#endif