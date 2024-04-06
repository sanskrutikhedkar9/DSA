/* 1249. Minimum Remove to Make Valid Parentheses

Given a string s of '(' , ')' and lowercase English characters.
Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.
Formally, a parentheses string is valid if and only if:
It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
    std::vector<bool> isValid(s.length(), true);  // Initially, assume all characters are valid
    int balance = 0;  // Tracks the balance of parentheses

    // Left to Right pass to mark invalid ')'
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            ++balance;
        } else if (s[i] == ')') {
            if (balance > 0) {
                --balance;
            } else {
                isValid[i] = false;  // Mark as invalid
            }
        }
    }

    balance = 0;  // Reset balance for the Right to Left pass

    // Right to Left pass to mark invalid '('
    for (int i = s.length() - 1; i >= 0; --i) {
        if (s[i] == ')') {
            ++balance;
        } else if (s[i] == '(') {
            if (balance > 0) {
                --balance;
            } else {
                isValid[i] = false;  // Mark as invalid
            }
        }
    }

    // Build the result string
    std::string result;
    for (int i = 0; i < s.length(); ++i) {
        if (isValid[i]) {
            result += s[i];
        }
    }

    return result;

    }
};