/*287. Find the Duplicate Number

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and uses only constant extra space.
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise=nums[0];
        int hare=nums[0];
        do{
            tortoise=nums[tortoise];
            hare=nums[nums[hare]];
        }while(tortoise!=hare);
        tortoise=nums[0];
        while(tortoise!=hare){
            tortoise=nums[tortoise];
            hare=nums[hare];
        }
        return hare;
    }
};