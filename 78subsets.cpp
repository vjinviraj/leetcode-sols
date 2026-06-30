class Solution {
public:
    void form(int index, vector<int> &nums, vector<int> &ds, vector<vector<int>> &store){

        if(index == nums.size()){
            store.push_back(ds);
            return;
        }

        ds.push_back(nums[index]);
        form(index + 1, nums, ds, store);

        ds.pop_back();
        form(index + 1, nums, ds, store);

    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> store;
        vector<int> ds;

        sort(nums.begin(), nums.end());

        form(0, nums, ds, store);

        return store;
        
    }
};

/*
Summary:

1. Start from index 0.
2. For every element, there are two choices:
   - Pick it.
   - Don't pick it.
3. Recursively explore both choices.
4. When index == nums.size(), all decisions have been made,
   so store the current subset.
5. Repeat until every possible combination has been explored.

Time Complexity: O(n × 2^n)
Space Complexity: O(n) (excluding the output vector)
*/