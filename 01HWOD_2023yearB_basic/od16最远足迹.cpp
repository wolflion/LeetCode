/*
* 某探险队负责对地下洞穴进行探险。探险队成员在进行探险任务时，随身携带的记录器会不定期地记录自身的坐标，但在记录的间隙中也会记录其他数据。探索工作结束后，探险队需要获取到某成员在探险过程中相对于探险队总部的最远的足迹位置

1.仪记录坐标时，坐标的数据格式为(x,y)，如(1,2)、(100,200)，其中0<x<1000，0<y<1000。同时存在非法坐标，如(01,1)、(1,01)，(0,100)属于非法坐标。

2.设定探险队总部的坐标为(0,0)，某位置相对总部的距离为:x*x+y*y。

3.若两个座标的相对总部的距离相同，则第一次到达的坐标为最远的足迹。

4.若记录仪中的坐标都不合法，输出总部坐标(0,0)。

备注:

不需要考虑双层括号嵌套的情况，比如sfsdfsd((1,2))。

输入描述

字符串，表示记录仪中的数据

如:ferga13fdsf3(100,200)f2r3rfasf(300,400)

输出描述

字符串，表示最远足迹到达的坐标如:(300,400)
*/

#include "test.h"

bool cmp16(pair<int, int> m1, pair<int, int> m2) {
	int sum1 = (m1.first - 0) * (m1.second - 0);
	int sum2 = (m2.first - 0) * (m2.second - 0);

	if (sum1 > sum2) {
		return 1;
	}
	return 0;
}

void od16_impl(string input) {
	vector <pair<int, int>> res;
	//lionel，用啥去过滤，先找(，然后固定长度即可
#if 0
	auto pos = input.find('(');
	auto posR = input.find(')');
	string tmp = input.substr(pos + 1, posR-pos-1);
	cout << tmp << endl;
#endif

	//查找所有的话，用while
	char flagL = '(';
	char flagR = ')';
	int pos = 0;
	int i=0;
	vector<int> left;
	while ((pos = input.find(flagL, pos)) != string::npos) {
		left.emplace_back(pos);
		pos++;
		i++;
	}

	vector<int> right;
	pos = 0;
	i = 0;
	while ((pos = input.find(flagR, pos)) != string::npos) {
		right.emplace_back(pos);
		pos++;
		i++;
	}
	
	vector<string> val;
	//lionel，这个风险就在左右如果不匹配怎么办？
	for (int i = 0; i < right.size(); i++) {
		string tmp = input.substr(left[i] + 1, right[i] - left[i] - 1);
		val.emplace_back(tmp);
	}

	for (auto s : val) {
		auto pos = s.find(',');
		int left = stoi(s.substr(0, pos-0)); //substr的用法是啥，最后一个是长度
		int right = stoi(s.substr(pos+1, s.size()-pos-1));
		//cout << left << "," << right << endl;
		res.emplace_back(make_pair(left, right));
	}

	sort(res.begin(), res.end(), cmp16);

	//lionel，我觉得更简单的方式用栈即可
	cout << res[0].first << "," << res[0].second << endl;
}

void od16() {
	string inputs1{ "ferg(3,10)a13fdsf3(3,4)f2r3rfasf(5,10)" };
	od16_impl(inputs1);
}