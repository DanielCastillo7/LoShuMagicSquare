#include <stdio.h>

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

int main() {
    int magicSquare[3][3] = {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}};
    int notMagicSquare[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    printf("Checking valid Magic Square: %s\n", isMagicSquare(magicSquare) ? "YES" : "NO");
    printf("Checking invalid Magic Square: %s\n", isMagicSquare(notMagicSquare) ? "YES" : "NO");

    return 0;
}