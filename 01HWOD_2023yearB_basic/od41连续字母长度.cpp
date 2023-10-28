/*
* 给定一个字符串，只包含大写字母，求在包含同一字母的子串中，长度第k长的子串的长度，相同字母只取最长的那个子串。

输入描述

第一行有一个子串(1<长度<=100)，只包含大写字母

第二行为k的值

输出描述

输出连续出现次数第k多的字母的次数
*/

#include "test.h"

void od41() {
	string input = { "AAAAHHHBBCDHHHH" };  //第一多是A和H，都是4次，第二多的是H，3次，但因为有H4了，再就是BB，是2次
	int k = 3;  //出现次数第3多的

#if 0
	map<char, int> res;
	int val = 0;
	for (auto c : input) {
		//如何根据map里的key找到value；
		auto iter = res.find(c);
		if (iter != res.end()) {
			val = iter->second;
		}

		if(val>0)
	}
#endif

#if 0
	vector<pair<char, int>> pci;
	int l = 0, r = l + 1;
	while (l < r  && r<input.size()) {
		char ch = input[l];
		if (input[r] == ch) {
			r++;
		} else {
			pci.push_back(make_pair(ch, r - l));
			l = r;
			r = l + 1;
		}
	}

	for (auto c : pci) {
		cout << c.first<<","<<c.second << endl;
	}
#endif

	char pre = input[0];
	int len = 0;
	vector<pair<char, int>> pci;
	int val = 0;
	map<char, int> res;
	for (int i = 0; i < input.size(); i++) {
		char ch = input[i];
		if (ch == pre)
			len++;
		else {
			auto iter = res.find(pre);
			if (iter != res.end()) 
				val = iter->second;

			if (iter != res.end() || res[pre] < len)
				res[pre] = len;

			len = 1;
			pre = ch;
		}
	}

	vector<int> arr;
	for (auto m : res) {
		arr.push_back(m.second);
	}

	if (k > arr.size()) {
		cout << "-1" << endl;
	} else
	{
		sort(arr.begin(), arr.end(),greater<int>());
		cout<<arr[k - 1]<<endl;
	}
}

//https://zhuanlan.zhihu.com/p/645559519，这个确实不会