#include "test.h"

bool cmp13(string s1, string s2) {
#if 0
	//班级划分，班级前5位
	string class1 = s1.substr(0, 5);
	string class2 = s2.substr(0, 5);
	if (class1.compare(class2)) {
		return 1;
	}
	return 0;
#endif

	//http://c.biancheng.net/view/1447.html compare函数
	int m = s1.compare(0, 5, s2, 0, 5);
	if (m > 1)
		return 1;
	else {
		// m==0，班级名称一样
		return 0;
	}
		
}

void od13_impl(vector<pair<string, int>> input1, vector<pair<string, int>> input2) {
	vector<string> res;
	//同时选修了2门，就是在1，和2都有一样的学号
	for (int i = 0; i < input1.size(); i++) {
		//cout << input1[i].first << endl;
		for (int j = 0; j < input2.size(); j++) {
			if (input1[i].first == input2[j].first) {
				//cout << input1[i].first << endl;
				res.emplace_back(input1[i].first);
			}
		}
	}
	sort(res.begin(), res.end(), cmp13);

	for (int i = 0; i < res.size()-1; i++) {
		if (res[i].compare(0, 5, res[i + 1], 0, 5) == 0) {
			cout << res[i].substr(0, 5) << endl;
			cout << res[i] <<"," << res[i + 1] << endl;
		} else {
			cout << res[i].substr(0, 5)<<endl;
			cout << res[i] << endl;
		}
	}
}

void od13() {
	vector<pair<string, int>> inputs11{ {"01202021",75},{"01201033",95},{"01202008",80},{"01203006",90},{"01203088",100} };
	vector< pair<string, int>> inputs12{{"01202008",70},{"01203088",85},{"01202111",80},{"01202021",75},{"01201100",88}};
	od13_impl(inputs11, inputs12);
}

//https://blog.csdn.net/AlgorithmHero/article/details/132685914

//https://zhuanlan.zhihu.com/p/644628293