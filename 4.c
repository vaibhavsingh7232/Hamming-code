#include <stdio.h>
#include <math.h>

// Function to calculate the number of parity bits required
int calculateParityBits(int m) {
    int r = 0;
    while (pow(2, r) < (m + r + 1)) {
        r++;
    }
    return r;
}

// Function to insert parity bits into the data
void insertParityBits(int data[], int m, int r) {
    int hammingCode[20];  // Maximum size, adjust as needed
    int i, j = 0, k = 0;

    // Insert parity bits into the correct positions (power of 2)
    for (i = 1; i <= m + r; i++) {
        if (i == pow(2, k)) {
            hammingCode[i - 1] = 0;  // Initialize parity bits to 0
            k++;
        } else {
            hammingCode[i - 1] = data[j];
            j++;
        }
    }

    // Calculate parity bits
    for (i = 0; i < r; i++) {
        int parityPosition = pow(2, i);
        int parity = 0;
        for (j = 1; j <= m + r; j++) {
            if (j & parityPosition) {
                parity ^= hammingCode[j - 1];
            }
        }
        hammingCode[parityPosition - 1] = parity;
    }

    // Print the generated Hamming code
    printf("\nHamming Code: ");
    for (i = 0; i < m + r; i++) {
        printf("%d ", hammingCode[i]);
    }
    printf("\n");
}

// Function to detect and correct errors in the Hamming code
void detectAndCorrectError(int hammingCode[], int n, int r) {
    int errorPosition = 0;
    int i, j;

    // Calculate parity bits to detect error position
    for (i = 0; i < r; i++) {
        int parityPosition = pow(2, i);
        int parity = 0;
        for (j = 1; j <= n; j++) {
            if (j & parityPosition) {
                parity ^= hammingCode[j - 1];
            }
        }
        if (parity != 0) {
            errorPosition += parityPosition;
        }
    }

    if (errorPosition == 0) {
        printf("\nNo error detected.\n");
    } else {
        printf("\nError detected at position: %d\n", errorPosition);
        
        // Print the received Hamming Code before correction
        printf("Received Hamming Code (before correction): ");
        for (i = 0; i < n; i++) {
            if (i == errorPosition - 1) {
                printf("[%d] ", hammingCode[i]);  // Highlight the erroneous bit
            } else {
                printf("%d ", hammingCode[i]);
            }
        }
        printf("\n");

        // Correct the error by flipping the bit
        hammingCode[errorPosition - 1] ^= 1;

        // Print the corrected Hamming Code
        printf("Corrected Hamming Code: ");
        for (i = 0; i < n; i++) {
            printf("%d ", hammingCode[i]);
        }
        printf("\n");
    }
}

int main() {
    int data[20];  // Maximum size of the data
    int m, r;

    printf("Enter the number of data bits: ");
    scanf("%d", &m);

    printf("Enter the data bits (space-separated): ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &data[i]);
    }

    // Calculate the number of parity bits
    r = calculateParityBits(m);
    printf("\nNumber of parity bits required: %d\n", r);

    // Generate Hamming code
    insertParityBits(data, m, r);

    // Detect and correct error (optional, for demonstration)
    int n = m + r;
    int hammingCode[20];

    printf("\nEnter the received Hamming Code (with possible errors): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &hammingCode[i]);
    }

    // Detect and correct errors in the received Hamming code
    detectAndCorrectError(hammingCode, n, r);

    return 0;
}
