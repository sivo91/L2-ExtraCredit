

#include <iostream>
#include <string>
using namespace std;

string findLongestCommonSubstring(string& A, string& B) {
    int lenA = A.size();
    int lenB = B.size();
    int startA = 0;		// starting position of the longest common substring in A
    int maxLength = 0;	// length of the longest common substring

    for (int i = 0; i < lenA; i++) {
        for (int j = 0; j < lenB; j++) {
            int length = 0;
            while (i + length < lenA && j + length < lenB && A[i + length] == B[j + length]) {
                length++;
            }

            if (length > maxLength && A.substr(i, length).find(' ') == string::npos) {
                maxLength = length;
                startA = i;
            }
        }
    }

    return A.substr(startA, maxLength);
}

int main() {
    string A = "A B C D AB C D ABC D ABCD";
    string B = "ABCD A B C D AB C D ABC D";

    string result = findLongestCommonSubstring(A, B);

    // output
    cout << "Longest Common Substring is : " << result << endl;


    return 0;
}

/*

  Longest Common Substring is : ABCD

*/



/******************************************************************************************************/



#include <iostream>
#include <string>
using namespace std;

// Recursive function to compute length of common substring starting at A[i] and B[j]
int LCSLength(const string& A, const string& B, int i, int j, int count) {
    if (i == A.size() || j == B.size()) return count;

    if (A[i] == B[j]) {
        return LCSLength(A, B, i + 1, j + 1, count + 1);
    }

    return count;
}

string findLongestCommonSubstring(const string& A, const string& B) {
    int maxLength = 0;  // max length of common substring found so far
    int startA = -1;  // starting position of longest common substring in A

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            int length = LCSLength(A, B, i, j, 0);

            // Check if the current common substring (starting at A[i] and B[j]) 
            // is longer than the longest found so far and doesn't contain space.
            if (length > maxLength && A.substr(i, length).find(' ') == string::npos) {
                maxLength = length;
                startA = i;
            }
        }
    }

    // Extract and return the longest common substring.
    return A.substr(startA, maxLength);
}

int main() {
    string A = "A B C D AB C D ABC D ABCD";
    string B = "ABCD A B C D AB C D ABC D";

    string result = findLongestCommonSubstring(A, B);

    // output
    cout << "Longest Common Substring is : " << result << endl;


    return 0;
}

/*

 Longest Common Substring is : ABCD

*/















