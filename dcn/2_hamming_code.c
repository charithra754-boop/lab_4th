#include <stdio.h>

int main() {
    int data[10], rec[10], c, c1, c2, c3;
    printf("Enter 4-bit data word (one by one): ");
    scanf("%d %d %d %d", &data[3], &data[5], &data[6], &data[7]);

    data[1] = data[3] ^ data[5] ^ data[7];
    data[2] = data[3] ^ data[6] ^ data[7];
    data[4] = data[5] ^ data[6] ^ data[7];

    printf("Encoded data: ");
    for(int i = 1; i <= 7; i++) printf("%d ", data[i]);
    
    printf("\nEnter 7-bit received data: ");
    for(int i = 1; i <= 7; i++) scanf("%d", &rec[i]);

    c1 = rec[1] ^ rec[3] ^ rec[5] ^ rec[7];
    c2 = rec[2] ^ rec[3] ^ rec[6] ^ rec[7];
    c3 = rec[4] ^ rec[5] ^ rec[6] ^ rec[7];
    c = c3 * 4 + c2 * 2 + c1;

    if(c == 0) printf("No error.\n");
    else {
        printf("Error at position %d\n", c);
        rec[c] = !rec[c]; // correct the error
        printf("Corrected data: ");
        for(int i = 1; i <= 7; i++) printf("%d ", rec[i]);
        printf("\n");
    }
    return 0;
}
