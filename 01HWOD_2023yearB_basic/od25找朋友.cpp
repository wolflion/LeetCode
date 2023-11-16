#include "test.h"

/*
* 
* 题目描述

在学校中，N个小朋友站成一队，第i个小朋友的身高为height[i]第i个小朋友可以看到的第一个比自己身高更高的小朋友j，那么是的好朋友(要求j>i)。清重新生成一个列表，对应位置的输出是每个小朋友的好朋友位置，如果没有看到好朋友，请在该位置用0代替。小朋友人数范围是[0,40000].

输入描述

第一行输入N，N表示有N个小朋友

第二行输入N个小朋友的身高height[i]，都是整数

输出描述

输出N个小朋友的好朋友的位置
*/

void od25() {
	int N=8;
	//cin >> N;
	vector<int> input{ 123,124,125,121,119,122,126,123 };
#if 0
	//验证过，可以输入
	vector<int> tmp;
	int N1 = N;
	int num;
	while (N1-- && cin>>num){
		tmp.push_back(num);
	}
#endif
	
	vector<int> res(N);
	stack<int> stk;
	for (int i = N - 1; i >= 0; i--) {
		//栈顶元素比当前小，则弹出
		while (!stk.empty() && input[stk.top()] < input[i]) {
			stk.pop();
		}

		//如果栈为空，则说明右边没有比当前大的数
		if (stk.empty()) {
			res[i] = 0;   //在没有 vector<int> res(N);进行初始化时，下标操作，肯定会crash的
		} else {
			res[i] = stk.top();
			//stk.pop();   //lionel，为啥这个可以不用pop();
		}

		stk.push(i);
	}

	//output
	for (int i = 0; i < N; i++) {
		cout << res[i] << " ";  //lionel，为啥这个可以直接输出  1 2 6 5 5 6 0 0
	}
}


//https://blog.csdn.net/wj_phm/article/details/132477921
// 
//https://zhuanlan.zhihu.com/p/645550229