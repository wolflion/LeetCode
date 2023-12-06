/*
* ����һ������������ nums , �ҵ�������ͬ������ 0 �� 1 ������������飬�����ظ�������ĳ��ȡ�

 

ʾ�� 1:

����: nums = [0,1]
���: 2
˵��: [0, 1] �Ǿ�����ͬ���� 0 �� 1 ������������顣
ʾ�� 2:

����: nums = [0,1,0]
���: 2
˵��: [0, 1] (�� [1, 0]) �Ǿ�����ͬ����0��1������������顣
*/

//�������˫ָ�룬��caseû��ȫ��ͨ����118 / 564 ��ͨ���Ĳ�������

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