#include "test.h"
/*
* 定义当一个字符串只有元音字母(a,e,i,o,u,A,E,I,O,U)组成,
称为元音字符串，现给定一个字符串，请找出其中最长的元音字符串，
并返回其长度，如果找不到请返回0，
字符串中任意一个连续字符组成的子序列称为该字符串的子串
输入描述
一个字符串其长度 0 < length ,字符串仅由字符a-z或A-Z组成
输出描述
一个整数，表示最长的元音字符子串的长度
示例一
输入
asdbuiodevauufgh
输出
3
*/

bool checkFlag(char c) {
	string str = "aeiouAEIOU";
	if (str.find(c) == str.npos) {
		return true;
	}
	return false;
}

void od82() {
	string str("asdbuiodevauufgh"); //这个输入直接 cin>>str;即可
	int tmpLen = 0;
	int maxLen = 0;
	for (auto c : str) {
		if (checkFlag(c)) {
			tmpLen++;
		} else {
			maxLen = max(maxLen, tmpLen);
			tmpLen = 0;
		}
	}
	maxLen = max(maxLen, tmpLen);
	cout << maxLen << endl;
}

//https://www.bilibili.com/read/cv23257608/

//https://blog.csdn.net/weixin_54707168/article/details/115717669
/*
* 思路
* 1、集合，包含所有元音字母
* 2、max_len，cur_len，记录最长和当前元音
* 3、逐个便历，是元音，cur_len++,max_len更新，不是就cur_len为0，
* 4、最后返回max_len
*/