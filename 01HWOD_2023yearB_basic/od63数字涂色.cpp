#include "test.h"


void od63_impl(int n, vector<int> inputs) {
	vector<int> res;
	int min = inputs[0];
	res.push_back(min);
	for (int i = 1; i < inputs.size(); i++) {
		if (inputs[i] % min != 0) {
			res.push_back(inputs[i]);
		} else
		{
			break;
		}

	}
	cout << res.size() << endl;
}
#if 0
void od63_impl(int n, vector<int> inputs) {
	static int count = 0;
	if (n==0) {
		cout << count << endl;
		return;
	}
	count++;
	sort(inputs.begin(), inputs.end());
	int min = inputs[0];
	for (int i = 0; i < inputs.size(); i++) {
		//cout << inputs[i] << endl;
		if (inputs[i] % min == 0) {
			--n;
			inputs.erase(inputs.begin() + i);
		}
	}
	od63_impl(n, inputs);
}
#endif

void od63() {
	int n1 = 3;
	vector<int> inputs1{ 2,4,6 };  //除最小的2，都能被整除，所以输出1
	od63_impl(n1, inputs1);

	int n2 = 5;
	vector<int> inputs2{ 2,3,4,6,9 };  //要除以2和3，所以输出2
	od63_impl(n2, inputs2);
}


//https://blog.csdn.net/goldarmour/article/details/131732972 数字涂色，没刷出来，差点儿意思

//https://blog.csdn.net/zhizhengguan/article/details/127045383  人家说本质上求质数？我没想到，我的思路是 算上不能被第1个除的数量？