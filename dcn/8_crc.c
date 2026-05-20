#include <stdio.h>
#include <string.h>

int main() {
    char data[100], poly[] = "10001000000100001", crc[20];
    int dlen, plen = strlen(poly);

    printf("Enter data: ");
    scanf("%s", data);
    dlen = strlen(data);

    for (int i = 0; i < plen - 1; i++) data[dlen + i] = '0';
    data[dlen + plen - 1] = '\0';
    strcpy(crc, data);

    for (int i = 0; i < dlen; i++) {
        if (crc[i] == '1') {
            for (int j = 0; j < plen; j++) {
                crc[i + j] = (crc[i + j] == poly[j]) ? '0' : '1';
            }
        }
    }
    printf("CRC Checksum: %s\n", &crc[dlen]);
    return 0;
}
