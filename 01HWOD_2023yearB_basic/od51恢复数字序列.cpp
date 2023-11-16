/*
* 对于一个连续正整数组成的序列，可以将其拼接成一个字符串，再将字符串里的部分字符打乱顺序。如序列8 9 10 11 12，拼接成的字符串为89101112，打乱一部分字符后得到90811211，原来的正整数10就被拆成了0和1。

现给定一个按如上规则得到的打乱字符的字符串，请将其还原成连续正整数序列，并输出序列中最小的数字。

输入描述
输入一行，为打乱字符的字符串和正整数序列的长度，两者间用空格分隔，字符串长度不超过200，正整数不超过1000，保证输入可以还原成唯一序列。
*/
#include "test.h"
void od51() {
	string input("90811211");
	int k = 5;
	int start = 1;//窗口起始位置
	int end = 1000 - k + 1;

	//第一步：开始把input存到map里
	unordered_map<char, int> value;
	for (char c : input) {
		value[c]++;
	}


	while (start <= end)
	{
		//lionel，每5个一统计
		unordered_map<char, int> count;//记录每个字符出现的次数
		for (int j = start; j < start + k; j++)  //lionel，这个地方是start，不是其它  【表示左边开始的 k个大小的区间】
		{
			string num = to_string(j);
			for (char c : num)
				count[c]++;
		}

		//lionel，然后check一下
		bool isMatch = true;
		for (auto p : value) {
			char c = p.first;
			if (count[c] != value[c]) {
				isMatch = false;
				break;
			}
		}

		if (isMatch) {
			cout << start << endl;
			return;
		}

		start++;
	}


}

//https://blog.csdn.net/weixin_42450130/article/details/131991831   [java]

//https://www.nowcoder.com/discuss/533314399520489472?sourceSSR=post  [cpp]