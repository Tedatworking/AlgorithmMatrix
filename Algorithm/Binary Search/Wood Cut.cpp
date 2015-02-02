/*
Given n pieces of wood with length L[i] (integer array).
Cut them into small pieces to guarantee you could have equal or more than k pieces with the same length.
What is the longest length you can get from the n pieces of wood? Given L & k,
return the maximum length of the small pieces.

Tip:
You couldn't cut wood into float length.

Example
For L=[232, 124, 456], k=7, return 114.

Solution
binary search, O(n log Len), where Len is the longest length of the wood.
*/
class Solution {
public:
    int calNum(vector<int> &L, int len) {
        int nums = 0;
        for (int i = 0; i < L.size(); i++) {
            nums += (L[i] / len);
        }
        return nums;
    }
    int woodCut(vector<int> L, int k) {
        int maxLen = 0;
        int sum = 0;
        for (int i = 0; i < L.size(); i++) {
            maxLen = max(maxLen, L[i]);
            sum += L[i];
        }
        if (sum < k) {
            return 0;
        } else if (sum == k) {
            return 1;
        }
        int left = 1, right = maxLen, mid;
        while (left + 1 < right) {
            mid = left + (right - left) / 2;
            int numOfPieces = calNum(L, mid);
            if (numOfPieces >= k) {
                left = mid;
            } else {
                right = mid;
            }
        }
        if (calNum(L, right) >= k) {
            return right;
        } else {
            return left;
        }
    }
};
