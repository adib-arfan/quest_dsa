#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string reverse_infix(string infix)
{
    int length = infix.size();
    char c;
    string rev_infi;

    for(int i = length - 1 ; i >= 0 ; i--)
    {
        c = infix[i];

        if(c == ')')
        {
            rev_infi += '(';
        }

        else if(c == '(')
        {
            rev_infi += ')';
        }

        else
        {
            rev_infi += c;
        }
    }

    return rev_infi;
}


int precedence(char c)
{
    if(c == '^')
      return 3;
    else if(c == '*' || c == '/')
      return 2;
    else if(c == '+' || c == '-')
      return 1;
}


bool is_right_associative(char c)
{
    return c == '^';
}




string infix_to_prefix(string infix)
{
    string rev_inf = reverse_infix(infix);

    char c;
    string prefix;
    char operand_stck[100];
    int top = -1;
    int len = infix.size();

    for(int i = 0 ; i < len ; i++)
    {
        c = rev_inf[i];

        if(c >= '0' && c <= '9')
        {
            prefix += c;
        }

        else if(c == '(')
        {
            operand_stck[++top] = c;
        }

        else if(c == ')')
        {
            while (top != -1 && operand_stck[top] != '(')
            {
                prefix += operand_stck[top--];
            }
           top--; 
        }

        else
        {
            while (top != -1 && operand_stck[top] != '(' &&(precedence(operand_stck[top]) > precedence(c) ||(precedence(c) == precedence(operand_stck[top]) && !is_right_associative(c))))
            {
               prefix += operand_stck[top--];
            }
            
            operand_stck[++top] = c;
        }
    }

    while(top != -1)
    {
        prefix += operand_stck[top--];
    }
  

    string og_prefix = reverse_infix(prefix);

    return og_prefix;

}

int main()
{
    string infix;
    cin >> infix;

    string prefix;
    prefix = infix_to_prefix(infix);

    cout << prefix << endl ;
}