#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        for (int start = 0, end = s.size() - 1;start <= end;start++, end--)
        {
            if (s[start] != s[end])
            {
                return false;
            }
        }

        return true;
    }
    bool validPalindrome(string s) {

        for (int start = 0, end = s.size() - 1;start <= end;start++, end--)
        {
            if (s[start] != s[end])
            {
				string temp = s;
				temp.erase(end, 1);
                s.erase(start,1);
               
				if (isPalindrome(s) || isPalindrome(temp))
				{
					return true;
				}
				else
				{
					return false;
				}
            }
        }


        return true;
    }
};