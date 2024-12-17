#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    // https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/?envType=study-plan-v2&envId=top-interview-150
    // Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.
    int current_streak = 0;
    int prev_value = nums[0];
    int manual_index = 1;
    for (int index = 1; index < nums.size(); ++index) {
        if (nums[index] > prev_value) {
            current_streak = 0;
            prev_value = nums[index];
            nums[manual_index] = nums[index];
            manual_index++;
        }
        else {
            current_streak++;
            if (current_streak == 1) {
                nums[manual_index] = nums[index];
                manual_index++;
            }
        }
    }
    std::cout << "K: " << manual_index - 1 << std::endl;
    for (int i = 0; i < nums.size(); ++i) {
        std::cout << nums[i] << " ";
    }
    return manual_index - 1;
}