#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

long long countPalindromicSubstrings(const string &s) {
    unordered_map<int, int> maskCount;
    int mask = 0;
    long long result = 0;

    // Initialize with mask 0 (to handle palindromes starting at the beginning)
    maskCount[0] = 1;

    for (char c : s) {
        // Update the mask by flipping the bit for the current character
        mask ^= (1 << (c - 'a'));

        // Add substrings with the same mask
        result += maskCount[mask];

        // Check for substrings with one odd character (one bit flipped)
        for (int i = 0; i < 26; i++) {
            int flippedMask = mask ^ (1 << i);
            if (maskCount.count(flippedMask)) {
                result += maskCount[flippedMask];
            }
        }

        // Increment the count of the current mask
        maskCount[mask]++;
    }

    return result;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string S;
        cin >> S;
        cout << countPalindromicSubstrings(S) << endl;
    }
    return 0;
}
