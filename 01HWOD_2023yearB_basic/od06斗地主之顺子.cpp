#include "test.h"

#if 0
//顺序还得是3-A,2，2比较大
void od06_impl(vector<char> input) {
	vector<char>data;
	for (auto value : input)
		data.emplace_back(value);
	vector<string> res;
	sort(data.begin(), data.end());
	//cout << data << endl;
}

void od06() {
	//ector<char>input1{'2','9','J','\10','3','4','K','A','7','Q','A','5','6'"};//10不能被当做字符
	vector<char>input1;
	od06_impl(input1);
}
#endif
int Str2Int(string val) {
	if (val == "J")
		return 11;
	else if (val == "Q")
		return 12;
	else if (val == "K")
		return 13;
	else if (val == "A")
		return 14;
	else
		return stoi(val);
}

string Int2Str(int num) {
	switch (num){
	case 11:
		return "J";
	case 12:
		return "Q";
	case 13:
		return "K";
	case 14:
		return "A";
	default:
		return to_string(num);
	}
}

void od06() {
	vector<int> nums;
#if 0
	string str;
	while (cin >> str) {
		int val = Str2Int(str);
		if (val > 2) {
			nums.push_back(val);
		}
	}
#endif
	vector<string> inputs{ "2","9","J","10","3","4","K","A","7","Q","A","5","6" };
	for (auto c : inputs) {
		int val = Str2Int(c);
		if (val > 2) {
			nums.push_back(val);
		}
	}

	sort(nums.begin(), nums.end());

	vector<vector<int>> res;
	vector<int> path;
	while (nums.size() >= 5) {
		path.push_back(nums[0]);
		nums.erase(nums.begin());

		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == path.back()) {  //lionel，这个没懂
				continue;
			}

			//lionel，我就这个地方没懂，根因是啥？
			if (nums[i] == path.back() + 1) {  //lionel，还是用了这个规则，back()，我也是搜的
				path.push_back(nums[i]);
				nums.erase(nums.begin() + i);
				i--; //i--是表示nums[i]的下标
			}
			//这个地方是多余的
#if 0
			else {
				//if (path.size() >= 5) {
					//res.push_back(path);
				//}
				//path.clear();
			}
#endif
		}

		//表示一轮结束，存一下
		if (path.size() >= 5) {
			res.push_back(path);
		}
		path.clear();
	}

	if (res.empty()) {
		cout << "No" << endl;
		return;
	}

	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++) {
		for (auto c : res[i]) {
			string val = Int2Str(c);
			cout << val << " ";
		}
		cout << endl;
	}

}

//https://blog.nowcoder.net/n/d723de86c2fb493aa1f8d725ac1d220a   【主要参考的这个，当然也有错，我debug出来了】

//https://www.nowcoder.com/discuss/470703763133571072  【这个排版不行，不想看】