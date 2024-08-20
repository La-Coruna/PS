/* 
[Valid Palindrome]
- date: 24.08.20
- Topics: Two Pointers, String
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length()-1;
        while(true){
            while(!isalnum(s[left]) && left < right){
                left++;
            }
            while(!isalnum(s[right]) && left < right){
                right--;
            }
            if(left >= right)
                break;
            if(tolower(s[left]) != tolower(s[right]))
                return false;
            left++;
            right--;
        }
        return true;
    }
};