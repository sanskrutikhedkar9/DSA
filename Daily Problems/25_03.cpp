/*442. Find All Duplicates in an Array

Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.
You must write an algorithm that runs in O(n) time and uses only constant extra space.
*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> duplicates;
        // Iterate through each element in the array
        for(int i = 0; i < nums.size(); ++i) {
            // Find the index that corresponds to the value of the current element
            int index = abs(nums[i]) - 1; // Subtract 1 because of 0-based indexing
            // If the value at the index is negative, it means the number has been seen before
            if(nums[index] < 0) {
                duplicates.push_back(abs(nums[i])); // Add the original number to the result
            } else {
                // Mark the value at the index as seen by making it negative
                nums[index] = -nums[index];
            }
        }
        return duplicates;
    }
};