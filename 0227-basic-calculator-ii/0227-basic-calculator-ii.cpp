#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

class Solution
{
public:
    bool is_operand(char character)
    {
        return (character >= '0' and character <= '9') or (character >= 'a' and character <= 'z') or (character >= 'A' and character <= 'Z');
    }

    bool is_operator(char character)
    {
        return !(is_operand(character));
    }

    int precedence(char character)
    {
		if (character == '+' or character == '-')
		{
			return 1;
		}
		else if (character == '*' or character == '/')
		{
			return 2;
		}
		else if (character == '^')
		{
			return 3;
		}

        return 0;
        
    }

    bool has_no_operater(string expression)
    {
        size_t size = expression.size();


        for(int i=0;i<size;i++)
            if (is_operator(expression[i]))
            {
                return false;
            }

        return true;
    }

    int calculate(string s)
    {
        

        size_t size = s.size();
        vector<string> expression;
        stack<char> symbol;
        

        for (int i = 0; i < size; i++)
        {
            if (is_operand(s[i]))
            {
				int number = 0;
				string operand = "";

                for (int j = i; j < size && is_operand(s[j]); j++)
                {
                    number = (number * 10) + (s[j] - '0');
                }
                operand = to_string(number);
                expression.push_back(operand);

				i += operand.size() - 1;
     

                continue;
            }
            if (s[i] == ' ')
            {
                continue;
            }
            if (is_operator(s[i]))
            {
                if (symbol.empty())
                {
                    symbol.push(s[i]);
                }

                else if (!symbol.empty() and precedence(s[i]) <= precedence(symbol.top()))
                {
                    while (!symbol.empty() and precedence(s[i]) <= precedence(symbol.top()))
                    {
                        expression.push_back(string(1, symbol.top()));
                        symbol.pop();
                    }
                    symbol.push(s[i]);
                }
                else
                {
                    symbol.push(s[i]);
                }
            }
        }

        while (!symbol.empty())
        {
            expression.push_back(string(1, symbol.top()));
            symbol.pop();
        }

        stack<int> result;

        for (int i = 0; i < expression.size(); i++)
        {
            if (is_operand(expression[i][0]))
            {
                result.push(stoi(expression[i]));
            }
            else
            {
                int operand2 = result.top();
                result.pop();
                int operand1 = result.top();
                result.pop();

                switch (expression[i][0])
                {
                case '+':
                    result.push(operand1 + operand2);
                    break;
                case '-':
                    result.push(operand1 - operand2);
                    break;
                case '*':
                    result.push(operand1 * operand2);
                    break;
                case '/':
                    result.push(operand1 / operand2);
                    break;
                case '^':
                    result.push(pow(operand1, operand2));
                    break;
                }
            }
        }
        return result.top();
    }
};
