#include <bits/stdc++.h>
using namespace std;

void subs(int i, vector<int> &num, int arr[], int n){
    
    if(i >= n){
        for(int j = 0; j < num.size(); j++){
            cout<<num[j]<<endl;
        }
        cout<<"fin"<<endl;
        return;
    }
    
    num.push_back(arr[i]);
    subs(i+1, num, arr, n);
    
    num.pop_back();
    subs(i+1, num, arr, n);
}

int main(){
    
    int arr[] = {3,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> num;
    
    subs(0, num, arr, n);
}


/*
Recursion Flow:

1. Include the current element in the subset.
2. Recurse for the next index.
3. Backtrack by removing the last element.
4. Exclude the current element.
5. Recurse again for the next index.

Time Complexity: O(2^n)
Space Complexity: O(n)  // Recursion stack + current subset
*/