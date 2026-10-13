#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &ara , int left , int mid , int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid ;

    vector<int> lv(n1) , rv(n2);

    for(int i = 0 ; i < n1 ; i++)
       lv[i] = ara[left + i];

    for(int i = 0 ; i < n2 ; i++)
       rv[i] = ara[mid + 1 + i];



    int i = 0 , j = 0 , k = left;

    while(i < n1 && j < n2)
    {
        if(lv[i] < rv[j])
        {
            ara[k++] = lv[i++];
        }
        else if(rv[j] < lv[i])
        {
            ara[k++] = rv[j++];
        }
    }

   while(i < n1)
   {
     ara[k++] = lv[i++];
   }

   while(j < n2)
   {
     ara[k++] = rv[j++];
   }

}


void mergesort(vector<int> &ara , int left , int right)
{
    if(left >= right)
    {
        return;
    }


    int mid = (left + right) / 2 ;

    mergesort(ara ,left , mid);
    mergesort(ara , mid + 1 , right);
    merge(ara , left , mid , right);


}



int main()
{
    vector<int> ara = {34 , 5, 2,11, 58, 29, 10};

    mergesort(ara , 0 , ara.size() - 1 );

    for(int v : ara)
    {
        cout << v <<  "  ";
    }
}