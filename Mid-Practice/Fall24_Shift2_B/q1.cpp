// Elements that appear in the second array come first.
// Among them, sort by descending frequency (how many times they appear in the first array).
// If two elements have the same frequency, keep their original order from the first array.
// Elements not in the second array appear at the end, also in their original order.

// INCORRECT CODE

#include <iostream>
#include <string>
using namespace std;

void sortArray (int nums1[], int n1, int nums2[], int n2) {
    int index = 0;
    if (n2 == 0) return;

    // calculating frequencies
    int freq[100] = {0};
    
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n1; j++) {
            if (nums1[j] == nums2[i]) freq[nums1[j]]++;     
        }    
    }

    while (index < n1) {
        int maxFreq = 0;
        for (int i = 0; i < 100; i++) {
            maxFreq = max(maxFreq, freq[i]);
        }

        for (int i = index; i < n1; i++) {
            if (freq[nums1[i]] == maxFreq) {
                int currentNum = nums1[i];
                for (int j = i; j < n1; j++) {
                    if (nums1[j] == currentNum) {
                        swap(nums1[index], nums1[j]);
                        index++;
                    } 
                }
            }
        }

        for (int i = 0; i < 100; i++) {
            if (freq[i] == maxFreq) freq[i] = 0;
        }
    }
}

int main () {
    int n1 = 7, n2 = 3;
    int nums1[7] = {5, 3, 5, 2, 3, 4, 2};
    int nums2[3] = {3, 5, 2};

    sortArray(nums1, n1, nums2, n2);    

    for (int i = 0; i < n1; i++) cout << nums1[i] << " ";
}