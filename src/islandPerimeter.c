/*
*  https://leetcode.com/problems/island-perimeter
*/
#include <stdio.h>
#include <stdlib.h>

int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    int offsetX[4] = {0, 1, 0, -1};
    int offsetY[4] = {-1, 0, 1, 0};
    int perimeter = 0;
    for(int i=0; i<gridSize; i++) {
        for(int j=0; j<*gridColSize; j++) {
            if(grid[i][j]) {
                for(int k = 0; k<4; k++) {
                    int newX = i+offsetX[k];
                    int newY = j+offsetY[k];
                    if(newX < 0 || newX >= gridSize || newY < 0 || newY >= *gridColSize) {
                        perimeter++;
                    } else if (!grid[newX][newY]) {
                        perimeter++;
                    }
                }
            }
        }
    }
    return perimeter;
}

int main(void) {
    int gridSize = 4;
    int gridColSize = 7;
    int **grid = (int**)malloc(sizeof(int*)*gridSize*gridColSize);
    for(int i = 0; i<gridSize; i++) {
        grid[i] = malloc(sizeof(int)*gridColSize);
        for(int j = 0; j<gridColSize; j++) {
            grid[i][j] = 0;
        }
    }
    grid[0][1] = 1;
    grid[0][2] = 1;
    grid[0][3] = 1;
    grid[0][4] = 1;
    grid[0][5] = 1;
    grid[1][5] = 1;
    grid[2][5] = 1;

    printf("Solution: %d\n", islandPerimeter(grid, gridSize, &gridColSize));
}