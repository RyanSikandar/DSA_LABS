#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(const string &expression)
{
    stack<char> braceStack;

    for (char c : expression)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            braceStack.push(c);
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            if (braceStack.empty())
            {
                return false; // Unmatched closing brace
            }

            char topmost_element = braceStack.top();
            braceStack.pop();

            if ((c == ')' && topmost_element != '(') || (c == ']' && topmost_element != '[') || (c == '}' && topmost_element != '{'))
            {
                return false; // Mismatched closing brace
            }
        }
    }

    return braceStack.empty(); // If all are correct then empty the string
}

int main()
{
    string input1 = "1 + 2 * (3 / 4)";
    string input2 = "1 + 2 * [3 * 3 + {4 - 5 (6 (7/8/9) + 10) - 11 + (12*8)] + 14";
    string input3 = "1 + 2 * [3 * 3 + {4 - 5 (6 (7/8/9) + 10)} - 11 + (12*8) / {13 +13}] + 14";

    if (isBalanced(input1))
    {
        cout << "This expression is balanced." << endl;
    }
    else
    {
        cout << "This expression is not balanced." << endl;
    }

    if (isBalanced(input2))
    {
        cout << "This expression is balanced." << endl;
    }
    else
    {
        cout << "This expression is not balanced." << endl;
    }

    if (isBalanced(input3))
    {
        cout << "This expression is balanced." << endl;
    }
    else
    {
        cout << "This expression is not balanced." << endl;
    }

    return 0;
}
