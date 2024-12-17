#include <iostream>
#include <vector>

int trap(std::vector<int>& height) {
    //first slow solution
    //https://leetcode.com/problems/trapping-rain-water/?envType=study-plan-v2&envId=top-interview-150
    // Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
    int capacity = 0;
    int tide = 0;
    int max_height = 0;
    int current_height = 0;
    for (int i = 0; i < height.size(); ++i) {
        if (height[i] > max_height) {
            max_height = height[i];
        }
    }
    while (current_height < max_height) {
        int left_index = -1;
        for (int i = 0; i < height.size(); ++i) {
            left_index = i;
            if (height[i] > current_height) {
                break;
            }

        }
        for (int i = left_index + 1; i < height.size(); ++i) {
            if (height[i] > current_height) {
                left_index = i;
                capacity += tide;
                tide = 0;
            }
            else {
                tide++;
            }
        }
        tide = 0;
        current_height++;
    }
    return capacity;
}

int trap2(std::vector<int>& height) {
    int capacity = 0;
    int left_index = 0;
    int right_index = height.size() - 1;
    int left_max = height[left_index];
    int right_max = height[right_index];

    while (left_index < right_index) {
        if (left_max < right_max) {
            left_index++;
            left_max = (left_max < height[left_index]) ? height[left_index] : left_max;
            capacity += left_max - height[left_index];
        }
        else {
            right_index--;
            right_max = (right_max < height[right_index]) ? height[right_index] : right_max;
            capacity += right_max - height[right_index];
        }
    }
    return capacity;
}