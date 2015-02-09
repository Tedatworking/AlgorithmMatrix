/*
Maximum Subarray Difference
Given an array with integers.
Find two non-overlapping subarrays A and B, which |SUM(A) - SUM(B)| is the largest.
Return the largest difference.
Note
The subarray should contain at least one number
Example
For [1, 2, -3, 1], return 6
Challenge
O(n) time and O(n) space.
*/
class Solution{
public:
    int maxDiffSubArraysHelper(vector<int> &nums) {
        if (nums.size() <= 1) {
            return 0;
        }
        vector<int> subA(nums.size(), 0);
        vector<int> subB(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            subA[i] = nums[i];
            subB[i] = nums[i];
        }
        int res = nums[0];
        int cur = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (cur < 0) {
                cur = 0;
            }
            cur += nums[i];
            res = _max(res, cur);
            subA[i] = res;
        }
        res = nums[nums.size() - 1];
        cur = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (cur > 0) {
                cur = 0;
            }
            cur += nums[i];
            res = _min(res, cur);
            subB[i] = res;
        }
        int results = 0;
        for (int i = 1; i < nums.size(); i++) {
            results = _max(results, abs(subA[i - 1] - subB[i]));
        }
        return results;
    }
    int maxDiffSubArrays(vector<int> nums) {
        // write your code here
        int res = maxDiffSubArraysHelper(nums);
        reverse(nums.begin(), nums.end());
        res = _max(res, maxDiffSubArraysHelper(nums));
        return res;
    }
};
