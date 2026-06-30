class Solution {
public:
    void form(int index, vector<int> &nums, vector<int> &ds, vector<vector<int>> &store){

        store.push_back(ds);

        for(int i = index; i < nums.size(); i++){

            if(i > index && nums[i] == nums[i - 1]) continue;

            ds.push_back(nums[i]);
            form(i + 1, nums, ds, store); 
            //here i changed the value of index defining the new start point to search from
            ds.pop_back();
            
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> store;
        vector<int> ds;

        sort(nums.begin(), nums.end());

        form(0, nums, ds, store);

        return store;
        
    }
};

/*
Summary:

1. Sort the array so duplicates are adjacent.
2. At each recursive call, store the current subset.
3. Use a for loop to try every possible next element starting from 'index'.
4. After choosing nums[i], recurse with i + 1 so future choices only come after it.
5. Skip duplicate values at the same recursion level using:
      if(i > index && nums[i] == nums[i - 1]) continue;
   This prevents generating duplicate subsets.

Time Complexity: O(n × 2^n)
Space Complexity: O(n) (excluding the output)
*/