/* 58. Length of Last Word
Given a string s consisting of words and spaces, return the length of the last word in the string.
A word is a maximal  substring consisting of non-space characters only.*/

#include<iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length()-1;
        int ans=0;
        while(n>=0 and s[n]==' '){
            n--;
        }
        while(n>=0 and s[n]!=' '){
            ans++;
            n--;
        }
        return ans;
    }
};