#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &leftarray, vector<int> &rightarray, vector<int> &nums){

    int leftsize = leftarray.size();
    int rightsize = rightarray.size();
    int numssize = nums.size();

    int i = 0, l = 0, r = 0;

    while(l < leftsize && r < rightsize){
        if(leftarray[l] < rightarray[r]){
            nums[i] = leftarray[l];
            i++;
            l++;
        }else{
            nums[i] = rightarray[r];
            i++;
            r++;
        }
    }

    while(l < leftsize){
        nums[i] = leftarray[l];
        i++;
        l++;
    }

    while(r < rightsize){
        nums[i] = rightarray[r];
        i++;
        r++;
    }
}

void mergeSort(vector<int> &nums){

    int n = nums.size();

    if(n <= 1) return;

    int mid = n/2;
    vector<int> leftarray(mid);
    vector<int> rightarray(n - mid);

    int i = 0, j = 0;

    for( ; i < n; i++){
        if(i < mid){
            leftarray[i] = nums[i];
        }else{
            rightarray[j] = nums[i];
            j++;
        }
    }

    mergeSort(leftarray);
    mergeSort(rightarray);
    merge(leftarray, rightarray, nums);
 
}



int main(){

    vector<int> nums = {3,5,7,8,8,9,1,2};
    

    mergeSort(nums);

    for(int i = 0; i < nums.size(); i++){
        cout<<"index: "<<i<<" element: "<<nums[i]<<endl;
    }

    return 0;
}

/*
Merge Sort (Divide and Conquer)

1. Divide the array into two halves.
2. Recursively sort the left half.
3. Recursively sort the right half.
4. Merge the two sorted halves into one sorted array.

Time Complexity:
Best Case  : O(n log n)
Average Case: O(n log n)
Worst Case : O(n log n)

Space Complexity: O(n)
*/