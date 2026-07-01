class Solution {
public:

    void form(int index, vector<int> &nums, vector<vector<int>> &ans){

        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i = index; i < nums.size(); i++){

            swap(nums[index], nums[i]);      // Choose

            form(index + 1, nums, ans);      // Explore

            swap(nums[index], nums[i]);      // Backtrack
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;

        form(0, nums, ans);

        return ans;
    }
};

/*
Pattern: Backtracking + Swapping

Summary:
- 'index' is the position to fill.
- Try every remaining element at that position.
- Swap -> Recurse -> Swap Back.
- Base case: when index == nums.size(), one permutation is formed.

Time Complexity: O(n × n!)
Space Complexity: O(n) (recursion stack only, excluding output)
*/