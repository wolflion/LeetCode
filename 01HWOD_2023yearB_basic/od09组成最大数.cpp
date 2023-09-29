#include "test.h"

#if 0
bool cmp(int num1, int num2) {
	string s1=to_string(num1);
	string s2 = to_string(num2);//lionel，这个不会
	int len1 = s1.length();
	int len2 = s2.length();
	if (len1 == len2) {
		return s2.compare(s1);
	}

	int minValue = min(len1, len2);
	for (int i = 0; i < minValue; i++) {
		char c1 = s1[i];
		char c2 = s2[i];
		if (c1 != c2) {
			return c2 - c1;
		}
	}

	if (len1 > len2) {
		//cout<<"s1[0] - s1[minValue];"<< s1[0] << ","<<s1[minValue] << endl;
		return s1[0] - s1[minValue];
	} else {
		//cout << "s2[0] - s2[minValue];" << s2[0] <<"," << s2[minValue] << endl;
		if (s2[minValue] - s2[0] < 0) {
			return 0;
		}else
		{
			return 1;
		}
		//return s2[minValue] - s2[0];
	}
}
#endif

bool cmp(int n1, int n2) {   // lionel，这个比较规则，是我没有想到的 
	string s1 = to_string(n1);
	string s2 = to_string(n2);

	string tmp1 = s1 + s2;
	string tmp2 = s2 + s1;
	if (tmp1 < tmp2) {
		return 0;
	}

	return 1;
}

void od09_impl(vector<int> inputs) {
	sort(inputs.begin(), inputs.end(), cmp);
	string s;
	for (auto c : inputs) {
		s += to_string(c);
	}
	cout << stoll(s) << endl; //lionel，是不是要考虑个越界的问题？
}

void od09() {
	vector<int> inputs1{ 22,221 };
	od09_impl(inputs1);
}