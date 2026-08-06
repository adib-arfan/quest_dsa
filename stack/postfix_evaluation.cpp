#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int postfix_evaluation(string postfix_expression)
{
    int len = postfix_expression.size();
    int top = -1 ;
    int stck[1000];
    char c;
    int op1, op2 , result;

    for(int i = 0 ; i < len ; i++)
    {
        c =  postfix_expression[i];

        if(c >= '0' && c <= '9')
        {
            stck[++top] = c - '0';
            continue;
        }

        op2 = stck[top--] ;
        op1 = stck[top--] ;

  
        if(c == '+')
        {
           result = op1 + op2 ;
        }

        else if(c == '-')
        {
           result = op1 - op2 ;
        }

        else if(c == '*')
        {
           result = op1 * op2 ;
        }

        else if(c == '/')
        {
           result = op1 / op2 ;
        }

        else if(c == '^') 
        {
           result = pow(op1 , op2);
        }

        stck[++top] = result;
    }

    return stck[top];
}

int main()
{
    string input ;

    cin >> input ;

    int result = postfix_evaluation(input);

    cout << result;


}