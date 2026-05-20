#include <stdio.h>

int main() {
    int bucket_size = 50, output_rate = 10;
    int incoming, store = 0, n;
    
    printf("Enter number of packets: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("\nEnter incoming packet size: ");
        scanf("%d", &incoming);
        
        if (incoming <= (bucket_size - store)) {
            store += incoming;
            printf("Bucket status: %d out of %d\n", store, bucket_size);
        } else {
            printf("Dropped %d packets. Bucket full!\n", incoming - (bucket_size - store));
            store = bucket_size;
        }
        
        if (store >= output_rate) {
            store -= output_rate;
            printf("Sent %d packets. Remaining: %d\n", output_rate, store);
        } else if (store > 0) {
            printf("Sent %d packets. Remaining: 0\n", store);
            store = 0;
        }
    }
    return 0;
}
