//Lauren Tinkham
//Pranitha Nichanametla 
//CSC 411
//bit2.h file Program
 
#ifndef BIT2_INCLUDED
#define BIT2_INCLUDED
 
#define T Bit2_T
typedef struct T *T;
 
extern T Bit2_new(int row, int col);
 
extern int Bit2_rows(T barray);// Bit2_rows: returns the total number of rows in the array. 
extern int Bit2_cols(T barray); //Bit2_cols: returns the total number of columns in the array.
 
extern void Bit2_map_row_major(T barray, void apply(T barray, int el, int row, int col, void *cl), void *cl);
//Bit2_map_row_major: calls function apply on each element and its
//indices, along with a given closure pointer,
//going row by row. */
extern void Bit2_map_col_major(T barray, void apply(T barray, int el, int row, int col, void *cl), void *cl);
//Bit2_map_col_major: calls
//function apply on each element and its indices,
//along with a given closure pointer, going column by
//column.
                        
extern int Bit2_put(T barray, int x, int y, int z);//Bit2_at: Returns a pointer to the element of index (x, y) in a given array.
extern int Bit2_get(T barray, int x, int y);//Bit2_at: Returns a pointer to the element of index (x, y) in a given array.
 
extern void Bit2_free(T *barray); // Bit2_free: frees a given array from memory.
extern int Bit2_length(T barray); // Bit2_length: returns the total number of elements in the array.
extern int Bit2_size(T barray);//Bit2_size:  returns the  space in memory taken up by an element of the array. */
 
#undef T
#endif
 
 
/* Bit2, use get and put functions in row/col major
apply function (ask again?)*/
 
