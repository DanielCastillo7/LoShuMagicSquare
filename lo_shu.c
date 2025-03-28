#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int isMagicSquare(int grid[3][3]) {
    int sum = grid[0][0] + grid[0][1] + grid[0][2];

    for (int i = 1; i < 3; i++)
        if (grid[i][0] + grid[i][1] + grid[i][2] != sum)
            return 0;

    for (int j = 0; j < 3; j++)
        if (grid[0][j] + grid[1][j] + grid[2][j] != sum)
            return 0;

    if (grid[0][0] + grid[1][1] + grid[2][2] != sum || 
        grid[0][2] + grid[1][1] + grid[2][0] != sum)
        return 0;

    return 1;
}

void generateRandomGrid(int grid[3][3]) {
    int nums[9] = {1,2,3,4,5,6,7,8,9};
    for (int i = 0; i < 9; i++) {
        int j = rand() % 9;
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    int index = 0;
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            grid[r][c] = nums[index++];
}

int main() {
    srand(time(0));
    int grid[3][3], count = 0;

    do {
        generateRandomGrid(grid);
        count++;
    } while (!isMagicSquare(grid));

    printf("Total attempts: %d\n", count);
    printf("[%d %d %d]\n[%d %d %d]\n[%d %d %d]\n", 
           grid[0][0], grid[0][1], grid[0][2], 
           grid[1][0], grid[1][1], grid[1][2], 
           grid[2][0], grid[2][1], grid[2][2]);

    return 0;
}