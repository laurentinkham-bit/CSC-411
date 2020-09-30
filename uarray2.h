//Lauren Tinkham
//Pranitha Nichanametla 
//CSC 411
//uarray2.h file Program
 
#ifndef UARRAY2_INCLUDED
#define UARRAY2_INCLUDED
 
#define T UArray2_T
 
typedef struct T *T;
 
extern T UArray_new(int length, int size); //creates a new 2D array
extern int UArray2_rows(T uarray);// UArray2_rows: returns the total number of rows in the array. 
extern int UArray2_cols(T uarray); //UArray2_cols: returns the total number of columns in the array.
 
extern void UArray2_map_row_major(T uarray, void apply(T uarray, void *el, int row, int col, void *cl), void *cl);//UArray2_map_row_major: calls function apply on each element and its
                          //indices, along with a given closure pointer,
                          //going row by row. */
extern void UArray2_map_col_major(T uarray, void apply(T uarray, void *el, int row, int col, void *cl), void *cl);//UArray2_map_col_major: calls
                        //function apply on each element and its indices,
                        //along with a given closure pointer, going column by
                        //column.
                        
extern void *UArray2_at(T uarray, int x, int y);//UArray2_at: Returns a pointer to the element of index (x, y) in a given array.
extern void UArray2_free(T *uarray); // UArray2_free: frees a given array from memory.
extern int UArray2_length(T uarray); // UArray2_length: returns the total number of elements in the array.
extern int UArray2_size(T uarray);//UArray2_size:  returns the  space in memory taken up by an element of the array. */
 
#undef T
#endif
