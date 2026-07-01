class Solution {
public:
    void form(vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds, unordered_map<int, int> &mpp){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(mpp[i] == 0){
                mpp[i] = 1;
                ds.push_back(nums[i]);

                form(nums, ans, ds, mpp);

                ds.pop_back();
                mpp[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> ds;
        unordered_map<int, int> mpp;

        form(nums, ans, ds, mpp);

        return ans;
    }
};

/*
Pattern: Backtracking (Pick → Recurse → Backtrack)

Summary:

1. Start with an empty permutation.
2. Loop through all elements.
3. If an element is not used, mark it as used and add it to the current permutation.
4. Recursively build the remaining positions.
5. When ds.size() == nums.size(), a complete permutation is formed,
   so store it in the answer.
6. Backtrack by removing the last element and marking it as unused,
   then continue trying the remaining elements.

Time Complexity: O(n × n!)
Space Complexity: O(n) (excluding the output vector)
*/