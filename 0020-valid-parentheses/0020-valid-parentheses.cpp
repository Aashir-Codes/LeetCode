class Solution {
public:
    char closing_bracket(char open)
    {

        if(open == '[')
        {
            return ']';
        }
        else if(open == '{')
        {
            return '}';
        }
        else
        {
            return ')';
        }
    }

    bool isValid(string s) {

        stack<char> opening;

        for (char bracket : s )
        {
            if (bracket == '[' || bracket == '{'|| bracket == '(' )
            {
                opening.push(bracket);
            }
            else 
            {
                if(opening.empty())
                {
                    return false;
                }
                if (closing_bracket(opening.top()) != bracket)
                {
                    return false;
                }
                else 
                {
                    opening.pop();
                }
            }
        }

        return opening.empty();
        
    }
};