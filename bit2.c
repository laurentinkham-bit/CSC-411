//Lauren Tinkham
//Pranitha Nichanametla 
//CSC 411
//bit2.c file Program
 
#include "array.h"
#include "mem.h"
#include "bit2.h"
#include "bit.h"
#include "assert.h"
 
#define T Bit2_T
 
struct T{
    int row;
    int col;
    Bit_T barray;
};
 
 
T Bit2_new(int row, int col){
    T barray;
    NEW(barray);
    barray->row = row;
    barray->col = col;
    barray->barray = Bit_new(row*col);
    return barray;
}
 
// Bit2_rows: returns the total number of rows in the array. 
int Bit2_rows(T barray){
    return barray->row;
}
 
//Bit2_cols: returns the total number of columns in the array.
int Bit2_cols(T barray){
    return barray->col;
}
 
void Bit2_map_row_major(T barray, void apply(T barray, int el, int row, int col, void *cl), void *cl){
    for(int r = 0; r < barray->row; r++){
        for(int c = 0; c < barray->col; c++){
            int temp = Bit2_get(barray, r, c);
            apply(barray, temp, r, c, cl);
        }
    }
}
//Bit2_map_row_major: calls function apply on each element and its
//indices, along with a given closure pointer,
//going row by row. */
 
void Bit2_map_col_major(T barray, void apply(T barray, int el, int row, int col, void *cl), void *cl){
    for(int c = 0; c < barray->col; c++){
        for(int r = 0; r < barray->row; r++){
            int temp = Bit2_get(barray, r, c);
            apply(barray, temp, r, c, cl);
            

            
        }
    }
}
//Bit2_map_col_major: calls
//function apply on each element and its indices,
//along with a given closure pointer, going column by
//column.

int Bit2_put(T barray, int row, int col, int value){
  
  assert(barray);
  assert(value== 0 || value == 1);
  int i = (row * barray->col) + col;

  assert(0 <= i && i < Bit2_length(barray));
  Bit_put(barray -> barray, i, value);
  
    return 0; //change
 
}



extern int Bit2_get(T barray, int x, int y){
   
   int i = (x * barray->col) + y;
   return Bit_get(barray -> barray, i);
   
}
 
// Bit2_free: frees a given array from memory.
void Bit2_free(T *barray){
    Bit_free(&((*barray)->barray));
    FREE(barray);
}
 
// Bit2_length: returns the total number of elements in the array.
int Bit2_length(T barray){
    return Bit_length(barray -> barray); 
    
}
 

 
#undef T
 

