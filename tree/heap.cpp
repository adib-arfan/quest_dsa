#include <bits/stdc++.h>
using namespace std;

class heap
{
   public:

    vector<int> heap_ara;

    void insert(int val)
    {
        heap_ara.push_back(val);
        int i = heap_ara.size()  - 1;

        while(i > 0)
        {
            int parent = (i - 1) / 2;

            if(heap_ara[parent] >= heap_ara[i])
                break;

            swap(heap_ara[parent] , heap_ara[i]);

            i = parent;
        }
    }




    void heapify(int n , int i)
    {

      while(true){  
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;


        if(left < n  && heap_ara[left] > heap_ara[largest])
        {
            largest = left ;
        }

        if(right < n  && heap_ara[right] > heap_ara[largest])
        {
            largest = right ;
        }


        if(largest == i)
           break;

           swap(heap_ara[largest] , heap_ara[i]);

           i = largest ;

    }

    }



    int delete_root()
    {
        int root = heap_ara[0];

        heap_ara[0] = heap_ara.back();
        heap_ara.pop_back();

        heapify(heap_ara.size() , 0);

       return root;
    }






};



int main()
{
    heap h;

    vector<int> test = {20 , 15 , 30 , 10 , 8 , 50 , 16};

    for(int v : test)
       h.insert(v);


       vector<int> sorted;

       while(!h.heap_ara.empty())
       {
          int v = h.delete_root();
          sorted.push_back(v);
       }


       for(int v : sorted)
         cout <<" " << v;
    
    // for(int v : h.heap_ara)
    //    cout << v << " ";


}