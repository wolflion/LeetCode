/*
* ����һ��Ԫ������ΪСд�ַ��������飬���������û����ͬ�ַ���Ԫ�س��ȳ˻������ֵ.

���û�з�������������Ԫ�أ����� 0��

��������

����Ϊһ����Ƕ��ŷָ���Сд�ַ��������飬2<= ���鳤��<=100��0< �ַ�������<= 50

�������

����û����ͬ�ַ���Ԫ�س��ȳ˻������ֵ

����
*/

#include "test.h"

//���ڶ�����Ŀ�ˣ�ֻ��iwdvpbn����hkû����ͬ���ַ���  hk��kadgpf����ͬ��k
#if 0

int strLen(string s) {
	int max = 0;
	int first = 0, last = 1;
	while (first < last) {
		if (last > s.size())
			break;

		if (s[first] != s[last]) {
			last++;
			max = last - first > max ? last - first : max;
		}
		first++;
		last++;
	}
	return max;
}

void od66_impl(vector<string> inputs) {
	vector<int> res;
	//����forѭ��
	for (int i = 0; i < inputs.size(); i++) {
		for (int j = i + 1; j < inputs.size(); j++) {
			for (int k = 0; k < inputs[i].size(); k++) {
				if (inputs[j].find(inputs[i][k])!=inputs[j].npos) {
					cout << "equal" << endl;
					break;
				} 
			}
			res.emplace_back(inputs[i].size());
			res.emplace_back(inputs[j].size());
		}
	}

	for (auto c : res) {
		cout << c << endl;
	}
}
#endif

int mul(string s1, string s2) {
	for (int i = 0; i < s1.size(); i++) {
		for (int j = 0; j < s2.size(); j++) {
			if (s1[i] == s2[j]) {
				return 0;
			}
		}
	}
	return s1.size() * s2.size();
}

void od66_impl(vector<string> inputs) {
	int res=0;
	for (int i = 0; i < inputs.size() - 1; i++) {
		res = max(res, mul(inputs[i], inputs[i + 1]));
	}
	cout << res << endl;
}

void od66() {
	vector<string> inputs1{ "iwdvpbn","hk","iuop","iikd","kadgpf" };  //5���ַ���,iwdvpbn��hkû����ͬ�ַ���������������ͬ�ַ�
	od66_impl(inputs1);  //lionel��������2��forѭ�����
}

//https://blog.csdn.net/jidanzai666/article/details/128348739  �ο����Լ�������˼·�ģ�ֻ����û���Գ�������