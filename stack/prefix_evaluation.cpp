#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int prefix_evaluate(string prefix)
{
    int len = prefix.size();
    int operand_stck[1000];
    int top = -1;
    int op1, op2 , result;
    char c;

    for(int i = len - 1 ; i >= 0 ; i--)
    {
       c =  prefix[i];

       if(c >= '0' && c <= '9')
       {
          operand_stck[++top] = c - '0';
          continue;
       }

       op1 = operand_stck[top--];
       op2 = operand_stck[top--];

       
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

        operand_stck[++top] = result;
    }

    return operand_stck[top];
    
}

int main()
{
    string input ;

    cin >> input ;

    int result = prefix_evaluate(input);

    cout << result;


}