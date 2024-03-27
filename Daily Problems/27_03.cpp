/*713. Subarray Product Less Than K

Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.
*/
#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;  // Since the product of any non-empty subarray is at least 1, we can immediately return 0 if k <= 1.
        int left = 0, right = 0;  // Use two pointers to represent the sliding window's boundaries.
        int prod = 1;  // Initialize the product variable.
        int count = 0;  // This will hold the final count of subarrays.

        while (right < nums.size()) {
        
            prod *= nums[right];

            while (prod >= k && left <= right) {
                prod /= nums[left];
                left++;
            }

            count += (right - left + 1);

            right++;
        }

        return count;
    }
};
