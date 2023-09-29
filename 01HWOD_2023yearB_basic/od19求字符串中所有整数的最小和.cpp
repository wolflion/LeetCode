#include "test.h"

//所有整数的最小和，先看看有没有-号，有负号先找
#if 0
uint32_t add(string val) {
	int sum = 0;
	vector<char> v;
	if (val[0] == '-') {
		for (int i = 1; i < val.size(); i++) {
			if (isdigit(val[i])) {
				v.emplace_back(val[i]);
			}
		}
	} else{
		for (auto c : val) {
			if (isdigit(c)) {
				sum += (c - '0');
			}
		}
	}
	return sum;
}

void od19_impl(string val) {
	size_t pos = val.find("-");
	if (pos != val.npos) {
		string first = val.substr(0, pos);
		//od19_impl(first);
		string last = val.substr(pos + 1, val.size());
		//od19_impl(last);
	}
	int res = add(val);

	cout<<res<<endl;
}
#endif

// 感觉自己想复杂了，直接用双指针
void od19_impl(string val) {
	int sum = 0;
	int first = 0, last = 0;
	bool minFlag = false;
	for (int i = 0; i < val.size(); i++) {
		if (val[i] == '+') {
			break;
		}
		if (val[i] == '-') {
			//int first = i;
			//int last = 0;
			//if (isdigit(val[i + last])) {
			//	last++;
			//	cout << last << endl;
			//} else {
			//	string s = val.substr(i, i + last-1);
			//	//cout << -stoi(s) << endl;
			//	sum += (stoi(s));
			//	i += last;
			//}
			minFlag = true;
			first = i;
		}
		if (isdigit(val[i])) {
			//cout << val[i] << endl;
			if()
			sum += (val[i] - '0');
		}
	}
	cout << sum << endl;
}

void od19() {
	string input1 = "bb1234aa";
	//od19_impl(input1); //这个输出10，没问题

	string input2 = "bb12-34aa";
	od19_impl(input2); //-34+1+2

	string input3 = "bb12-34aa2";
	od19_impl(input3); //-34+1+2+2
}