
class Solution{
public:
    int randomPartition(vector<int> &nums, int left, int right) {
        int povit = (rand() % (right - left + 1)) + left;
        swap(nums[povit], nums[right]);

        int j = left;
        int sentinel = nums[right];
        for (int i = left; i <= right; i++) {
            if (nums[i] < (sentinel)) {
                swap(nums[j++], nums[i]);
            }
        }
        swap(nums[j], nums[right]);
        return j;
    }
    /*
    start: 0, end: nums.size() - 1;, k : the rank of nums, not the index
    */
    int findKth(vector<int> &nums, int start, int end, int k) {
        if (start <= end) {
            int pivot = randomPartition(nums, start, end);
            if (pivot - start + 1 == k) {
                return nums[pivot];
            } else if (pivot - start + 1 < k) {
                return findKth(nums, pivot + 1, end, k - (pivot - start + 1));
            } else {
                return findKth(nums, start, pivot - 1, k);
            }
        }
        return 0;
    }
};
