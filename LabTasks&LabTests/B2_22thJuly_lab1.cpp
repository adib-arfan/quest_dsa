//we had been given an array , told to identify the duplicate elements 
//if there two occurences of an element, we just let it be 
//if more than two occurences , we keep the first and the last element and delete the rest

// #include<iostream>
// #include<climits>
// using namespace std;




// int delete_from_middle(int arra[] , int Size , int index)
// {
//     for(int i = index ; i < Size - 1; i++)
//     {
//         arra[i] = arra[i + 1];
//     }

//     return Size - 1;
// }



// void special_duplicate_removal_func(int arra[] , int size)
// {
//     int count = 0 ;
//     int min_count = 0;

//     for(int i = 0 ; i < size ; i++)
//     {
//         for(int j = i + 1 ; j < size ; j++)
//         {
//             if(arra[i] == arra[j])
//             {
//                 count++;
//             }
//         }

//         if(count <= 2)
//         {
//             continue;
//         }
        
//         else if(count > 2)
//         {
//             int *index_arra = new int[count];
            
//                 for(int k = 0 ; k < count ; k++)
//                 {
//                     for(int l = 0 ; l < size ; l++)
//                     {
//                         if(arra[l] == arra[i])
//                         {
//                             index_arra[k] == l;
//                         }
//                     }
//                 }
            
//                 for(int m = 1 ; m < count - 1 ; m++)
//                 {
//                     arra[index_arra[m]] = INT_MIN;
//                     min_count++;
//                 }
           
//                 count = 0;
//         }

//     }

//     while(min_count != 0)
//     {
//         int new_size;

        
//     }

    


// }





// int main()
// {
//     int arra[] = {1, 2,2 ,2, 2, 3, 4, 4, 5, 6, 6, 6, 7, 3, 4, 9 };
//     int Size = sizeof(arra)/sizeof(int);
// }

