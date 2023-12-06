/*
* 给定一个二进制数组 nums , 找到含有相同数量的 0 和 1 的最长连续子数组，并返回该子数组的长度。

 

示例 1:

输入: nums = [0,1]
输出: 2
说明: [0, 1] 是具有相同数量 0 和 1 的最长连续子数组。
示例 2:

输入: nums = [0,1,0]
输出: 2
说明: [0, 1] (或 [1, 0]) 是具有相同数量0和1的最长连续子数组。
*/

//我想的是双指针，但case没有全部通过，118 / 564 个通过的测试用例

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int left = 0;
        int right = left + 1;
        int res = 0;
        int sum = 0;
        int cur_len = 0;
        while (right < nums.size()) {
            sum = accumulate(nums.begin() + left, nums.begin() + right, 0);
            if (sum % 2 == 0) {
                cur_len = right - left + 1;
                res = max(cur_len, res);
            }
            left++;
            right++;
        }
        return res;
    }
};