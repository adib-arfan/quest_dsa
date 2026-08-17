#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string reverse_string(string str)
{
    string rev_str = "";
    for (int i = str.size() - 1; i >= 0; i--)
    {
        char c = str[i];
        if (c == '(') rev_str += ')';
        else if (c == ')') rev_str += '(';
        else rev_str += c;
    }
    return rev_str;
}

int precedence(char c)
{
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

bool is_right_asso(char c)
{
    return c == '^';
}

string i2pre(string infi)
{
    string rev_infi = reverse_string(infi);
    char operand_stck[1000];
    int top = -1;
    string prefix = "";

    for (int i = 0; i < rev_infi.size(); i++)
    {
        char c = rev_infi[i];

        if (isspace(c)) continue; // 1. Skip spaces

        // 2. Check for letters or digits
        if (isalnum(c))
        {
            prefix += c;
        }
        // 3. MUST use 'else if' here so operands don't fall into the operator stack
        else if (c == '(')
        {
            operand_stck[++top] = '(';
        }
        else if (c == ')')
        {
            while (top != -1 && operand_stck[top] != '(')
            {
                prefix += operand_stck[top--];
            }
            if (top != -1) top--; // Pop '('
        }
        else // Operators block
        {
            while (top != -1 && operand_stck[top] != '(' &&
                  (precedence(operand_stck[top]) > precedence(c) ||
                  (precedence(operand_stck[top]) == precedence(c) && is_right_asso(c))))
            {
                prefix += operand_stck[top--];
            }
            operand_stck[++top] = c;
        }
    }

    while (top != -1)
    {
        prefix += operand_stck[top--];
    }

    return reverse_string(prefix);
}

int main()
{
    string infix;
    getline(cin, infix); // Reads whole line including spaces

    cout << i2pre(infix) << endl;

    return 0;
}