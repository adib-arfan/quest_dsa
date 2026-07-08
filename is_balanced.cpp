#include <iostream>
using namespace std;

bool is_balanced(string input)
{
    string test;
    int len = input.size() , top = 0;

    for(int i = 0 ; i < len ; i++)
    {
       if(input[i] == '(')
       {
        test[top] = '(' ;
        top++;
       }
       else if(input[i] == '{')
       {
         test[top] = '{' ;
         top++;
       }
       else if(input[i] == '[')
       {
         test[top] = '[' ;
         top++;
       }

       else if((input[i] == ')' || input[i] == '}' || input[i] == ']') && top == 0)
       {
        return false;
       }
       
       else if(input[i] == ')')
       {
         top--;
         if(test[top] != '(')
         {
            return false;
         }
       }

       else if(input[i] == '}')
       {
         top--;
         if(test[top] != '{')
         {
            return false;
         }
       }

       else if(input[i] == ']')
       {
         top--;
         if(test[top] != '[')
         {
            return false;
         }
       }
    }

    if(top == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string input ;
    cin >> input ;

    if(is_balanced(input))
    {
        cout << input << " is balanced" ;
    }
    else
    {
        cout << input << " is not balanced" ;
    }
}