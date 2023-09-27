

#include <iostream>
#include <string>

using namespace std;

// Function to find the longest common substring
string findLongestCommonSubstring(const string& str1, const string& str2, int index1, int index2, int maxLength) {
    if (index1 == 0 || index2 == 0) {
        // Base case: if either string is empty, return an empty string
        return "";
    }

    if (str1[index1 - 1] == str2[index2 - 1]) {
        // The current characters match, so extend the common substring
        string commonSubstr = findLongestCommonSubstring(str1, str2, index1 - 1, index2 - 1, maxLength + 1);
        commonSubstr += str1[index1 - 1];

        return commonSubstr;
    }
    else {
        // If the current characters don't match, reset the maxLength and start over
        if (maxLength > 0) {
            maxLength = 0;
            return "";
        }
        else {
            return "";
        }
    }
}

int main() {
    string str1 = "A B C D AB C D ABC D ABCD";
    string str2 = "ABCD A B C D AB C D ABC D";

    int maxCommonLength = 0;
    string maxCommonSubstring;
    int maxCommonSubstringIndex1 = 0;
    int maxCommonSubstringIndex2 = 0;

    for (int i = 0; i < str1.length(); ++i) {
        for (int j = 0; j < str2.length(); ++j) {
            if (str1[i] == str2[j]) {
                string commonSubstr = findLongestCommonSubstring(str1, str2, i + 1, j + 1, 0);
                if (commonSubstr.length() > maxCommonLength) {
                    maxCommonLength = commonSubstr.length();
                    maxCommonSubstring = commonSubstr;
                    maxCommonSubstringIndex1 = i;
                    maxCommonSubstringIndex2 = j;
                }
            }
        }
    }

    if (maxCommonLength > 0) {
        cout << "Longest Common Substring: " << maxCommonSubstring << endl;
        cout << "Starting position in str1: " << maxCommonSubstringIndex1 - maxCommonLength + 1 << endl;
        cout << "Starting position in str2: " << maxCommonSubstringIndex2 - maxCommonLength + 1 << endl;
    }
    else {
        cout << "No common substring found." << endl;
    }

    return 0;
}


/*

    Longest Common Substring: A B C D AB C D ABC D
    Starting position in str1: 0
    Starting position in str2: 5

*/