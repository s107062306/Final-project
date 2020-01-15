#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../include/algorithm.h"

using namespace std;

/******************************************************
 * In your algorithm, you can just use the the funcitons
 * listed by TA to get the board information.(functions
 * 1. ~ 4. are listed in next block)
 *
 * The STL library functions is not allowed to use.
******************************************************/

/*************************************************************************
 * 1. int board.get_orbs_num(int row_index, int col_index)
 * 2. int board.get_capacity(int row_index, int col_index)
 * 3. char board.get_cell_color(int row_index, int col_index)
 * 4. void board.print_current_board(int row_index, int col_index, int round)
 *
 * 1. The function that return the number of orbs in cell(row, col)
 * 2. The function that return the orb capacity of the cell(row, col)
 * 3. The function that return the color fo the cell(row, col)
 * 4. The function that print out the current board statement
*************************************************************************/


void algorithm_A(Board board, Player player, int index[]){

    // cout << board.get_capacity(0, 0) << endl;
    // cout << board.get_orbs_num(0, 0) << endl;
    // cout << board.get_cell_color(0, 0) << endl;
    // board.print_current_board(0, 0, 0);

    //////////// Random Algorithm ////////////
    // Here is the random algorithm for your reference, you can delete or comment it.
    int color = player.get_color();
    int row;
    int col;
    if(board.get_cell_color(0,0) == 'w')
    {
        row = 0;
        col = 0;
    }
    else if(board.get_cell_color(0,5) == 'w')
    {
        row = 0;
        col = 5;
    }
    else if(board.get_cell_color(4,0) == 'w')
    {
        row = 4;
        col = 0;
    }
    else if(board.get_cell_color(4,5) == 'w')
    {
        row = 4;
        col = 5;
    }
    else
    {
        int m = 0;
        for(int i = 1; i < 5; i++)
        {
            if(board.get_cell_color(i,0) == 'w')
            {
                m = 1;
                row = i;
                col = 0;
            }
        }
        if(m == 0)
        {
            for(int i = 1; i < 6; i++)
            {
                if(board.get_cell_color(0,i) == 'w')
                {
                    m = 1;
                    row = 0;
                    col = i;
                }
            }
        }
        if(m == 0)
        {
            for(int i = 1; i < 6; i++)
            {
                if(board.get_cell_color(4,i) == 'w')
                {
                    m = 1;
                    row = 4;
                    col = i;
                }
            }
        }
        if(m == 0)
        {
            for(int i = 1; i < 5; i++)
            {
                if(board.get_cell_color(i,5) == 'w')
                {
                    m = 1;
                    row = i;
                    col = 5;
                }
            }
        }
        if(m == 0)
        {
            int p = 0;
            for(int i = 0; i < 5;i++)
            {
                for(int j = 0 ; j < 6; j++)
                {
                    if(board.get_cell_color(i,j) != color)continue;
                    else
                    {
                        int cur = board.get_orbs_num(i,j) + board.get_orbs_num(i+1,j) + board.get_orbs_num(i,j+1) + board.get_orbs_num(i-1,j) + board.get_orbs_num(i,j-1);
                        if(cur > p)
                        {
                            row = i;
                            col = j;
                            p = cur;
                        }
                    }
                }
            }
        }
        srand(time(NULL));
    }
    index[0] = row;
    index[1] = col;
}
