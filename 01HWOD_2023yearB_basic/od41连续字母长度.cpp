/*
* ����һ���ַ�����ֻ������д��ĸ�����ڰ���ͬһ��ĸ���Ӵ��У����ȵ�k�����Ӵ��ĳ��ȣ���ͬ��ĸֻȡ����Ǹ��Ӵ���

��������

��һ����һ���Ӵ�(1<����<=100)��ֻ������д��ĸ

�ڶ���Ϊk��ֵ

�������

����������ִ�����k�����ĸ�Ĵ���
*/

#include "test.h"

void od41() {
	string input = { "AAAAHHHBBCDHHHH" };  //��һ����A��H������4�Σ��ڶ������H��3�Σ�����Ϊ��H4�ˣ��پ���BB����2��
	int k = 3;  //���ִ�����3���

#if 0
	map<char, int> res;
	int val = 0;
	for (auto c : input) {
		//��θ���map���key�ҵ�value��
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

//https://zhuanlan.zhihu.com/p/645559519�����ȷʵ����