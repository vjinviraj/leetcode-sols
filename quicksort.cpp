#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &array, int start, int end){


    int pivot = array[end];
    int i = start - 1;

    for(int j = start; j <= end - 1; j++){
        if(array[j] < pivot){
            i++;
            swap(array[i] , array[j]);
        }
    }

    i++;
    swap(array[i] , array[end]);

    return i;
}

void quicksort(vector<int> &array, int start, int end){

    if(end <= start) return;

    int pivot = partition(array, start, end);
    quicksort(array, start, pivot - 1);
    quicksort(array, pivot + 1, end);

}

int main(){

    vector<int> array = {3,5,7,8,8,9,1,2};
    

    quicksort(array, 0, array.size() - 1);

    for(int i = 0; i < array.size(); i++){
        cout<<"index: "<<i<<" element: "<<array[i]<<endl;
    }

    return 0;
}

/*
Quick Sort (Divide and Conquer)

1. Choose the last element as the pivot.
2. Place the pivot in its correct sorted position.
3. Elements smaller than the pivot go to the left.
4. Elements greater than the pivot go to the right.
5. Recursively sort the left and right subarrays.

Time Complexity:
Best Case   : O(n log n)
Average Case: O(n log n)
Worst Case  : O(n²)    // When pivot is always the smallest or largest element

Space Complexity:
Average Case: O(log n) // Recursion stack
Worst Case  : O(n)
*/