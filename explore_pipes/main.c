#include <stdio.h>

#define INT_MIN -2147483648 // Define a placeholder value for initialization

void findIncreasingSubsequence(int arr[], int size, int givenNumber) {
    // Create an array to store the length of the longest increasing subsequence ending at each index
    int lis[size];

    // Initialize all LIS values to 1
    int i = 0;
    while (i < size) {
        lis[i] = 1;
        i++;
    }

    // Compute LIS values in a bottom-up manner
    i = 1;
    while (i < size) {
        int j = 0;
        while (j < i) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
            j++;
        }
        i++;
    }

    // Find the maximum value in lis array
    int maxLength = 0;
    int startIndex = -1;

    i = 0;
    while (i < size) {
        if (arr[i] == givenNumber && lis[i] > maxLength) {
            maxLength = lis[i];
            startIndex = i;
        }
        i++;
    }

    // Find the elements in the strictly increasing subsequence
    int result[maxLength];
    int currentIndex = 0;

    i = startIndex;
    while (i >= 0) {
        if (arr[i] > givenNumber) {
            result[currentIndex++] = arr[i];
            givenNumber = arr[i];
        }
        i--;
    }

    // Print the result
    printf("The longest strictly increasing subsequence starting from %d is: ", givenNumber);
    i = currentIndex - 1;
    while (i >= 0) {
        printf("%d ", result[i]);
        i--;
    }
    printf("\n");
}

int main() {
    // Example usage
    int arr[] = {5, 2, 8, 3, 1, 7, 6, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int givenNumber = 2;

    findIncreasingSubsequence(arr, size, givenNumber);

    return 0;
}


// int	main(void)
// {
// 	int	arr[] = {5, 2, 8, 3, 1, 7, 6, 4};
// 	// int	counter;
// 	int	size;

// 	// Example usage
// 	// counter = 0;
// 	size = sizeof(arr) / sizeof(arr[0]);
// 	// while (counter < 8)
// 	// 	printf("%i", arr[counter++]);
// 	findLongestIncreasingSubsequence(arr, size);
// 	return (0);
// }
