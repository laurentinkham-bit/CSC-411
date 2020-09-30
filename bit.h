//Lauren Tinkham
//Parnitha Nichanametla 
//CSC 411
//Bit.h file Program

#ifndef BIT2_INCLUDED
#define BIT2_INCLUDED

#define T Bit2_T
typedef struct T *T;


extern void Bit2_map_row_major(Bit2_T set, void apply(int x, int y, int bit, void  *cl), void *cl);

extern void Bit2_map_col_major(Bit2_T set,void apply(int x, int y, int bit,void  *cl), void *cl);

extern void Bit2_free(T *Bit2);

extern int Bit2_length(Bit2_T set);//returns the total number of bits in the set.

extern int Bit2_rows(Bit2_T set);//returns the total number of rows in the set.

extern int Bit2_cols(Bit2_T set);//eturns the total number of columns in the set.

extern int Bit2_get(Bit2_T set, int x, int y);//returns the bit of index (x, y) in a given array.

extern void Bit2_set(Bit2_T set, int x_lo, int x_hi, int y_lo, int y_hi);



#undef T
#endif