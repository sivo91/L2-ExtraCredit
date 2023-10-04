




//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    :  Longest Common Substring, L2-ExtraCredit         * 
//*                                                                     * 
//* Written by      : Peter Sivak                                       * 
//*                                                                     * 
//* Purpose         : Program is finding longest common substring of    * 
//*                   2 strings                                         * 
//*                                                                     * 
//* Inputs          : No input for user, just lunch program             * 
//*                                                                     * 
//* Outputs         : Program display common substring if there is any  * 
//*                                                                     * 
//* Calls           : No internal or external calls, other than system  * 
//*                                                                     * 
//* Structure       : BEGIN                                             * 
//*                       User lunch program                            *
//                                                                      * 
//*                   STOP                                              * 
//*                       Program display longest common substring      * 
//*---------------------------------------------------------------------* 
//* Collaboration   : Got help from Prof. John Urrutia                  * 
//*                                                                     * 
//*                                                                     * 
//*---------------------------------------------------------------------* 
//* Change Log:                                                         * 
//*                         Revision                                    * 
//*       Date    Changed  Rel Ver Mod Purpose                          * 
//*  10/02/23      psivak   000.000.000 Initial release of program      *  
//*                                                                     * 
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *



#include <iostream>
#include <string>
using namespace std;

// recursive function
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

            // check if the current common substring (starting at A[i] and B[j]) 
            // is longer than the longest found so far
            if (length > maxLength && A.substr(i, length).find(' ') == string::npos) {
                maxLength = length;
                startA = i;
            }
        }
    }

    // return longest common substring
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





