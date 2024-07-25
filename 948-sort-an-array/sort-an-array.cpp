//  ***** Merge Sort *****
// TC= O(N)


class Solution{
public:
    void merge(vector<int> &arr, int start, int mid, int end)
    {
         // [start ....  mid]     [mid+1    end]

         vector<int> temp;
         int left= start;
         int right= mid+1;

         while(left <= mid && right <= end)
         {
              if(arr[left] <= arr[right])
              {
                  temp.push_back(arr[left]);
                  left++;
              }
              else
              {
                  temp.push_back(arr[right]);
                  right++;
              }
         }

         // if some elements left in one subarray and other is finished..
         while(left<= mid)
         {
            temp.push_back(arr[left]);
            left++;
         }

         while(right <= end)
         {
            temp.push_back(arr[right]);
            right++;
         }

        // Now copy content from temp to original array...
        for(int i=start; i<=end; i++)
        {
            arr[i]= temp[i-start];
        }  
    }

    void mergeSort(vector<int>&arr, int start, int end)
    {
        // base case
        if(start >= end){
            return;
        }
        
        int mid= (start+end)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);

        merge(arr,start,mid,end);
    }

    vector<int> sortArray(vector<int>& arr) {
        int n= arr.size();
         mergeSort(arr,0,n-1);
         return arr;
    }
};









//  -----  TLE ------

//  ***** Quick Sort  *****  Giving TLE bcoz pivot= arr[lb]
//   ---- use pivot element as pivot..

// In avg case TC- O(N log N)
// Worst case TC= O(N^2)

/*

class Solution {
public:
   int findPivot(vector<int> &arr, int lb, int ub)
   {
        int pivot= arr[lb];
        int start= lb;
        int end= ub;

        while(start< end)
        {
           while(start <= ub && arr[start] <= pivot)
           {
              start++;
           }

           while(end >= lb  && arr[end] > pivot)
           {
              end--;
           }

           if(start < end)
           {
              swap(arr[start], arr[end]);
           }
        }

        swap(arr[lb], arr[end]);
        return end;
   }


    vector<int> quickSort(vector<int> &arr, int lb, int ub)
    {
        int partition;
        if(lb < ub)
        {
          partition= findPivot(arr,lb,ub);
          quickSort(arr, lb, partition-1);
          quickSort(arr, partition+1, ub);
        }
        return arr;
    }
 

    vector<int> sortArray(vector<int>& arr) {
        int n= arr.size();
        return quickSort(arr,0,n-1);
    }
};

*/