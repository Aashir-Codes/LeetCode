class Solution {
public:

    int maxDepth(string s) {
        

        stack<char> opening;
        int depth=0;

        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                opening.push('(');

            }
            if(s[i]==')')
            {
           
                if(depth<=opening.size())
                {
                    depth=opening.size();
                }
                 opening.pop();
            }
        }

        return depth;

   
    }
};