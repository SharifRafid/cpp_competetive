#include <stdio.h>

// Function to print horizontal line
void printHorizontalLine(int widths[], int cols) {
    printf("+");
    for(int i = 0; i < cols; i++) {
        for(int j = 0; j < widths[i] + 2; j++) {
            printf("-");
        }
        printf("+");
    }
    printf("\n");
}

int main() {
    int colWidths[] = {12, 14, 20, 20, 25, 25, 25};
    
    // Data for 6 rows
    int observations[] = {1, 2, 3, 1, 2, 3};
    char *quantity[] = {"wire", "wire", "wire", "small sphere", "small sphere", "small sphere"};
    int lsr[] = {26, 29, 31, 24, 27, 30};
    int csr[] = {16, 19, 21, 14, 17, 20};
    float dx[] = {0.16, 0.19, 0.21, 0.14, 0.17, 0.20};
    float tsr[] = {26.16, 29.19, 31.21, 24.14, 27.17, 30.20};
    float corrected[] = {26.26, 29.29, 31.31, 24.24, 27.27, 30.30};
    
    int rows = 6;

    // Print table header
    printHorizontalLine(colWidths, 7);
    
    printf("| %-12s | %-14s | %-20s | %-20s | %-25s |", 
           "No of obs", "Quantity", "Linear Scale", "Circular Scale", "Fraction to be");
    printf(" %-50s    |\n", "Diameter Total Scale Reading");
    
    printf("| %-12s | %-14s | %-20s | %-20s | %-25s |", "", "", "", "", "");
    printf(" %-25s-|-%-25s |\n", "-------------------------", "-------------------------");
    
    printf("| %-12s | %-14s | %-20s | %-20s | %-25s  | %-25s | %-25s |\n",
           "", "", "Reading", "Reading", "added dx=csr×Lc", "Observer", "Corrected");
    printf("| %-12s | %-14s | %-20s | %-20s | %-25s | %-25s | %-25s |\n",
           "", "", "", "", "", "TSR LSR + dX", "TSR + Z.C.");
    
    printHorizontalLine(colWidths, 7);

    // Print 6 rows
    for(int i = 0; i < rows; i++) {
        printf("| %-12d | %-14s | %-20d | %-20d | %-25.2f | %-25.2f | %-25.2f |\n",
               observations[i], quantity[i], lsr[i], csr[i], dx[i], tsr[i], corrected[i]);
        if(i < rows - 1) {  // Don't print line after last row
            printf("|");
            for(int j = 0; j < 7; j++) {
                for(int k = 0; k < colWidths[j] + 2; k++) {
                    printf("-");
                }
                printf("|");
            }
            printf("\n");
        }
    }
    
    printHorizontalLine(colWidths, 7);
    
    return 0;
}