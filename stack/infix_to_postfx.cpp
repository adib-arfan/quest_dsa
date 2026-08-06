#include <iostream>
using namespace std;

int precedence(char c)
{
    if(c == '^')
       return 3;
    else if(c == '/' || c == '*')
       return 2;
    else
       return 1;
}

bool right_associativity_chk(char c)
{
    return c == '^';
}

string infix_to_postfix(string &s)
{
    char stck[1000];
    string postfix;
    int top = -1;


    for(int i = 0 ; i < s.length() ; i++)
    {
        char c = s[i];

        if(c >= '0' && c <= '9')
        {
            postfix += c; //jodi number pai , amra direct postfix e boshay dibo
        }

        else if(c == '(')
        {
            stck[++top] = c;
        }

        else if (c == ')')
        {
            while(top != -1 && stck[top] != '(')
            {
                postfix += stck[top--];
            }

            top--; // '(' ta baki theke gesilo , oita pop hoye gelo
        }
        
        
        // jodi kono operator hoy, +, - ,* , /
        else
        {
            while(top != -1 && stck[top] != '(' &&(precedence(stck[top]) > precedence(c)|| (precedence(stck[top]) == precedence(c) && !right_associativity_chk(c))))
            {
                postfix += stck[top--];
            }

            stck[++top] = c;
        }
    }

    while(top != -1)
    {
        postfix += stck[top--];
    }

    return postfix;
}

int main()
{
    string infix;
    cin >> infix;

    string postfix = infix_to_postfix(infix);

    cout << postfix;
}