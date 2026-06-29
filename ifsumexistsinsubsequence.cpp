#include <bits/stdc++.h>
using namespace std;

bool subs(int i, vector<int> &num, int arr[], int n, int k){
    
    if(i >= n){
        
        int sum = 0;
        
        for(int j = 0; j < num.size(); j++){
            sum = sum + num[j];
        }
        
       return (sum == k);
    }
    
    num.push_back(arr[i]);
    if (subs(i+1, num, arr, n, k)) return true;
    
    num.pop_back();
    if (subs(i+1, num, arr, n, k)) return true;
    
    return false;
}

int main(){
    
    int arr[] = {3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> num;
    int k = 2;
    
    
    bool value = subs(0, num, arr, n, k);
    
    cout<<value<<endl;
}