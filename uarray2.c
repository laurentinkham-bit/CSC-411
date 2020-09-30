//Lauren Tinkham
//Pranitha Nichanametla 
//CSC 411
//uarray2.c file Program
 
#define T UArray2_T
 
#include "array.h"
#include "mem.h"
#include "uarray2.h"
 
//typedef struct T *T;
struct T{
    int row;
    int col;
    Array_T uarray;
};
 
T UArray2_new(int row, int col, int size){
    T uarray;
    NEW(uarray);
    uarray->row = row;
    uarray->col = col;
    uarray->uarray = Array_new(row*col, size);
    return uarray;
}
 
// UArray2_rows: returns the total number of rows in the array. 
int UArray2_rows(T uarray){
    return uarray->row;
}
 
//UArray2_cols: returns the total number of columns in the array.
int UArray2_cols(T uarray){
    return uarray->col;
}
 
void UArray2_map_row_major(T uarray, 
    void apply(T uarray, void *el, int row, int col, void *cl), void *cl){
    for(int r = 0; r < uarray->row; r++){
        for(int c = 0; c < uarray->col; c++){
            apply(uarray, UArray2_at(uarray, r, c), r, c, cl);
        }
    }
}
//UArray2_map_row_major: calls function apply on each element and its
//indices, along with a given closure pointer,
//going row by row. */
 
void UArray2_map_col_major(T uarray, void apply(T uarray, void *el, int row, int col, void *cl), void *cl){
    for(int c = 0; c < uarray->col; c++){
        for(int r = 0; r < uarray->row; r++){
            apply(uarray, UArray2_at(uarray, r, c), r, c, cl);
        }
    }
}
//UArray2_map_col_major: calls
//function apply on each element and its indices,
//along with a given closure pointer, going column by
//column.
 
//UArray2_at: Returns a pointer to the element of index (x, y) in a given array.                        
void *UArray2_at(T uarray, int row, int col){
    int i = (row * uarray->col) + col;
    return Array_get(uarray, i);
}
 
// UArray2_free: frees a given array from memory.
// First frees the array in struct, then frees the struct
void UArray2_free(T *uarray){
    Array_free(&((*uarray)->uarray));
    FREE(uarray);
}
 
// UArray2_length: returns the total number of elements in the array.
int UArray2_length(T uarray){
    return Array_length(uarray);
}
 
//UArray2_size:  returns the  space in memory taken up by an element of the array. */
int UArray2_size(T uarray){
    return Array_size(uarray);
}
 
#undef T