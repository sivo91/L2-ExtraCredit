

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
