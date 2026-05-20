#include <stdio.h>
#include <string.h>

void bit_stuffing(char* data) {
    char stuffed[200];
    int count = 0, j = 0;
    for (int i = 0; data[i]; i++) {
        stuffed[j++] = data[i];
        if (data[i] == '1') count++;
        else count = 0;
        
        if (count == 5) {
            stuffed[j++] = '0';
            count = 0;
        }
    }
    stuffed[j] = '\0';
    printf("Bit Stuffed: 01111110 %s 01111110\n", stuffed);
}

void char_stuffing(char* data) {
    char stuffed[200];
    int j = 0;
    for (int i = 0; data[i]; i++) {
        if (data[i] == 'd' && data[i+1] == 'l' && data[i+2] == 'e') {
            stuffed[j++] = 'd'; stuffed[j++] = 'l'; stuffed[j++] = 'e';
        }
        stuffed[j++] = data[i];
    }
    stuffed[j] = '\0';
    printf("Char Stuffed: dle stx %s dle etx\n", stuffed);
}

int main() {
    char data[100];
    printf("Enter binary data for bit stuffing: ");
    scanf("%s", data);
    bit_stuffing(data);
    
    printf("Enter string for char stuffing (use dle): ");
    scanf("%s", data);
    char_stuffing(data);
    return 0;
}
