#include <vector>
#include <iostream>
using namespace std;

void select_sort(vector<int>& ara)
{
    int i , j , min_indx , temp;

    for(i = 0 ; i < ara.size() - 1; i++)
    {
          min_indx = i ;

          for(j = i + 1 ; j < ara.size() ; j++)
          {
            if(ara[j] < ara[min_indx])
            {
                min_indx = j;
            }
          }

          if(min_indx != i)
          {
            temp = ara[i] ;
            ara[i] = ara[min_indx];
            ara[min_indx] = temp ;
          }
    }
}

void bubbly_sort(vector<int>& ara)
{
    int i  , j , temp ;

    for(i = 0 ; i < ara.size() ; i++)
    {
        for(j = 0 ; j < ara.size() - i - 1 ; j++)
        {
            if(ara[j + 1] < ara[j])
            {
                temp = ara[j] ;
                ara[j] = ara[j + 1];
                ara[j + 1] = temp ;
            }
        }
    }
}

void insert_sort(vector<int>& ara)
{
    int i , j , temp ;

    for(i = 1 ; i < ara.size() ; i++)
    {
        temp = ara[i] ;

        for(j = i - 1 ; j >= 0 && ara[j] > temp ; j--)
        {
            ara[j + 1] = ara[j] ;
        }

        ara[j+1] = temp ;
    }
} 



int main()
{
    vector<int> my_vec = {34 , 56, 35, 23 , 15, 67} ;
    
    //select_sort(my_vec) ;

    //bubbly_sort(my_vec) ;

    //insert_sort(my_vec) ;

    for(int v : my_vec)
    {
        cout << v << " " ;
    }
}