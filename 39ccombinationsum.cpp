class Solution {
public:
    void findcomb(int index, vector<int>& candidates, int target,
                  vector<vector<int>> &ans, vector<int> &ds) {

        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        if (index == candidates.size() || target < 0) {
            return;
        }

        ds.push_back(candidates[index]);
        findcomb(index, candidates, target - candidates[index], ans, ds);
        ds.pop_back();

        findcomb(index + 1, candidates, target, ans, ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> ds;

        findcomb(0, candidates, target, ans, ds);

        return ans;
    }
};

/*
Pattern: Backtracking (Pick / Not Pick)

Pick      -> Stay at same index (reuse allowed)
Not Pick  -> Move to next index

Base Cases:
- target == 0  -> Store answer
- target < 0   -> Return
- index == n   -> Return

Backtracking:
push_back() -> recurse -> pop_back()

TC: Exponential
SC: O(target / min(candidates))
*/