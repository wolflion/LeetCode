#include"test.h"

/*
* 给定一个由若干整数组成的数组nums，请检查数组是否是由某个子数组重复循环拼接而成，请输出这个最小的子数组。

输入描述

第一行输入数组中元素个数n，1 <= n <= 100000

第二行输入数组的数字序列nums，以空格分割，0 <= nums[i] <= 10

输出描述

输出最小的子数组的数字序列，以空格分割;

备注

数组本身是其最大的子数组，循环1次可生成的自身
*/

void getNext(int *next, string s) {
	next[0] = 0;
	int j = 0;
	for (int i = 1; i < s.size(); i++) {
		while (j > 0 && s[i] != s[j]) {
			j = next[j - 1];
		}
		if (s[i] == s[j]) {  //lionel，next数组这个差不多了，这个地方写错了，把==写成了=
			j++;
		}
		next[i] = j;
	}
}

void od_a33_impl(int n, vector<int> nums) {
	if (nums.size() == 0) {
		cout << "null" << endl;
		return;
	}

	int next[10]; //lionel，必须是常量
	string tmp;
	for (auto c : nums) {
		tmp += to_string(c);
	}
	getNext(next, tmp);
	int len = tmp.size();
	int L = len - next[len - 1];//lionel，重点还在于 理解 什么是**最小循环节**
	while (L--) {
		cout << tmp[L] << " ";
	}

#if 0
	//这个不知道抄的谁的
	cout << tmp[next[1]] << "," << next[2] << "," << next[3] << endl;
	//if (next[len - 1] != 0 && len % (len - next[len - 1]) == 0)
		//cout << next << endl;
#endif
}

void od_a33() {
	int n = 9;
	vector<int> nums{ 1,2,1,1,2,1,1,2,1 };
	od_a33_impl(n, nums);
}

//https://blog.csdn.net/weixin_45830552/article/details/129736966   LC459  重复的子字符串

//https://blog.csdn.net/u013190417/article/details/123810465 

//https://blog.nowcoder.net/n/7459ca2934ae43f99d92a7a6b5486778?from=nowcoder_improve

//https://www.cnblogs.com/grandyang/p/6992403.html