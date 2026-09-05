#include <iostream>
using namespace std;


void merge(int arra[] , int lb , int mid , int ub)
{
    int i = lb ;
    int j = mid + 1 ;
    int k = lb ;
    int arra_b[ub + 1];

    while(i <= mid && j <= ub)
    {
        if(arra[i] <= arra[j])
        {
            arra_b[k++] = arra[i++];
        }
        else
        {
            arra_b[k++] = arra[j++];
        }
    }

    if(i > mid)
    {
        while (j <= ub)
        {
            arra_b[k++] = arra[j++];
        }   
    }

    
    if(j > ub)
    {
        while (i <= mid)
        {
            arra_b[k++] = arra[i++];
        }   
    }

    for(k = lb ; k <= ub ; k++)
    {
        arra[k] =  arra_b[k] ;
    }
}


void mergesort(int arra[] , int lb , int ub)
{
    if(lb < ub)
    {
        int mid = (lb + ub) / 2 ;
        mergesort(arra , lb , mid);
        mergesort(arra , mid + 1 , ub);
        merge(arra, lb , mid , ub);
    }
}

int main()
{
    int arra[] = {15 , 5 , 24 , 8 , 1 , 3 , 16 , 10 , 20};

    mergesort(arra , 0 , 8);

    for(int i = 0 ; i < 9 ; i++)
    {
        cout << arra[i] << "  ";
    }
}