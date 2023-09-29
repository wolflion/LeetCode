#include "test.h"

#if 0
void od30_impl(vector<int> input) {
	vector<int>result { 0 };//lionel，本意是把input.size()的大小，都赋值成0
	int res = 0;
	for (int i = 0; i < input.size(); i++) {
		if((i==0 || i==1) && input[i]<0){
			res += 0;
		} else {
			if (input[i] < result[i]) {
				result[i] = res;
				res += result[i];
			} else {
				result[i] = res;
				res += input[i];
			}
		}
			
		}
	}
}
#endif

void od30_impl(vector<int> input) {
	//vector<int>result(input.size());//lionel，本意是把input.size()的大小，都赋值成0，vector<int>result { 0 };这种写法是错误的
	//int res = 0;
	int maxValue = 0;
	vector<int> score;
	for (int i = 0; i < input.size(); i++) {
		if (i < 3) {
			maxValue = max(input[i], 0);
			score.emplace_back(0);
		} else {
			maxValue = max(input[i]+maxValue, score[i - 3]);
			score.emplace_back(maxValue);  //lionel，也是突然之间改对了，境加了一个score的vector类型，把每次的比较，result[i-3]改成了score[i-3]
			//res += maxValue;
		}
		//cout << maxValue << endl;
	}
	cout << maxValue << endl;
}

void od30() {
	vector<int> inputs1{ 1,-5,-6,4,3,6,-2 };
	od30_impl(inputs1);
}