/*
* ���������ÿ���˵�������һ�������Ҫ������Ŷӵ��������ֵΪN��ÿ���Ŷӿ�����һ�˻���������ɣ���һ����ֻ�ܲμ�һ���Ŷӣ�������������ɳ�����ֻ����Ҫ��Ķ��顣

��������

��һ�д�������������Χ1-500000

�ڶ����������ÿ���˵����������С����Χ1-500000��Ԫ��ȡֵ����Χ1-500000

��������ֵΪ�Ŷ�Ҫ����������ֵ����Χ1-500000

�������

�������ɳ����Ŷ�����

����
*/


#include "test.h"
void od35_impl(int sum, vector<int> input, int ability) {
	sort(input.begin(), input.end());
	int left = 0, right = input.size() - 1;
	int res = 0;
	while (left < right) {
		if (input[right] >= ability) {
			res++;
			right--;
		} else {
			if (input[right] + input[left] >= ability) {
				res++;
				right--;
				left++;
			} else
			{
				left++;
			}
		}
	}
	cout << res << endl;
}

void od35(){
	int sum1 = 5;
	vector<int>inputs1{ 3,1,5,7,9 };
	int ability1 = 8;
	od35_impl(sum1, inputs1, ability1);
}