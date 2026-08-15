#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

        for (int i = 0;i < s.size();i++)
        {
			if ((s[i] < 'a' || s[i] > 'z' ) &&(s[i]<'A' || s[i] > 'Z') && (s[i] < '0' || s[i] > '9'))
			{
				s.erase(i, 1);
				i--;
			}
			else if (s[i] >= 'A' && s[i] <= 'Z')
			{
				s[i] = s[i] + 32;
			}
        }
        for (int start = 0, end = s.size() - 1;start <= end;start++, end--)
        {
            if (s[start] != s[end])
            {
                return false;
            }
        }

        return true;
    }
};