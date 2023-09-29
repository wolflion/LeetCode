#include "test.h"

void od84_impl(string s1, string s2) {
	//求s1的全排列,使用next_permutation
	vector<char> res_helper;
	vector<char> res;
	vector<vector<char>> resout;
	res_helper.assign(s1.begin(), s1.end());
	sort(res_helper.begin(), res_helper.end());
	do {
		for (int i = 0; i < res_helper.size(); i++) {
			//cout << res_helper[i];
			res.emplace_back(res_helper[i]);
		}
		
	} while (next_permutation(res_helper.begin(), res_helper.end()));
	resout.emplace_back(res);

	vector<string> sVect;
	for (auto h : resout) {
		string s{ h.begin(), h.end() };
		for (int i = 0; i < s.size(); i+=3) {
			sVect.emplace_back(s.substr(i, 3)); //lionel,substr的用法，还是不熟啊
		}
	}

	for (auto c : sVect) {
		//cout << c << endl;
		auto pos = s2.find(c);
		if (pos != s2.npos) {
			cout << pos << endl;
		}
		//auto it = find(s2.begin(), s2.end(), c);//lionel，太习惯用find算法后，不太会用string里面的find了
		//if (it != s2.end())
			//cout << *it << endl;
	}
}

void od84() {
	string str11{ "abc"};
	string str12{ "efghicbaili" };
	od84_impl(str11, str12);
}

//https://blog.csdn.net/whitehat110/article/details/113405296  C++全排列实现方法