//Lauren Tinkham
//Pranitha Nichanametla 
//CSC 411
//Sudoku Program
#include <stdio.h>
#include <stdlib.h>
#include <pnmrdr.h>
#include <except.h>
#include <math.h> //do we need this?
#include <assert.h>
#include "uarray2.h"
#include "array.h"
 
const int sudoku_size = 9;
FILE *input_file(int argc, char *argv[]);
void store_pixels(UArray2_T puzzle, Pnmrdr_T x, int row, int col);
int check_row_col(UArray2_T puzzle, void *el, int row, int col, void *cl); //will use for apply
int check_sub_map(UArray2_T p, Array_T values); //keeps list of elements parsed
void check_doubles(Array_T puzzle);
//Set_T get_subset (UArray2_T p, int x_low, int x_high, int y_low, int y_high);
//void print_set (const void *member, void *cl);
 
 
int main(int argc, char *argv[]){
    // UArray2_T puzzle;
    //make sure input is either in command line or standard input
    assert(argc <= 2);
    FILE *input;
    input = input_file(argc, argv);
 
    Pnmrdr_T x = Pnmrdr_new(input);
    Pnmrdr_mapdata data = Pnmrdr_data(x);
 
    //make sure data in map is a sudoku puzzle
    if(data.width != 9 || data.height != 9 || data.denominator != 9){
        exit(1);
    }
 
    // -------------Confirmed sudoku puzzle--------------
    int row = data.height;
    int col = data.width;
    UArray2_T puzzle = UArray_new(row * col, 4);
    store_pixels(puzzle, x, row, col);
 
    //check rows 
    //check cols
    

    Array_T row_1 = Array_new(9, sizeof(int));

    //rows
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){

            int *temp = UArray2_at(puzzle, i, j);
            int *temp2 =Array_get(row_1, j);
            //might be problem 
            
            *temp2 = *temp; //problem
            
        }
        check_doubles(row_1);
    }
    //cols 
    for(int i= 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
                int *temp_1 =UArray2_at(puzzle, j, i);
                int *temp_2 = Array_get(row_1, i);
                //might be problem 


                *temp_2 = *temp_1;
            }
            check_doubles(row_1);
    }

    Array_free(&row_1);
    UArray2_free(&puzzle);
    exit(0);

}
 
 
FILE *input_file(int argc, char *argv[]){
    //make sure at most 1 argument is given
    assert(argc <= 2);
    FILE *input;
    //open file with name
    if (argc == 2){
        input = fopen(argv[1], "rb");
        if (!input){
            exit(1);
        }
    }else{
        input = stdin;
    }
    return input;
}
 
 
void store_pixels(UArray2_T puzzle, Pnmrdr_T x, int row, int col){
    int numerator = 0;
    int *p;
    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            numerator = Pnmrdr_get(x);
            p = UArray2_at(puzzle, r, c);
            *p = numerator;
        }
    }
}
 
 
void check_doubles(Array_T puzzle){
    int count = 9;

    for (int i = 0; i < count - 1; i++) { 
        for (int j = 0; j < count; j++) {
            if (Array_get(puzzle, i*)) {
                exit (1);
            }
        }
    }

}


void check_cols(){

}

void check_rows(){
    
}

//list, checks to see if doubles

//take array of length 9
//checks to see if there are any doubles in that list of arrays

//go through every row and feed the row into that function
//go through every col and feed the col into that function
//feed every block