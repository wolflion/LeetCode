#include "test.h"

void od70_impl(int hour, int count, vector<int> person) {
	int res = 0;
	int sum = 0;
	sum = accumulate(person.begin(), person.end(), sum);  //lionel，这个sum，还得给个返回值来接一下，不然sum还是0

	while ((hour - 1)*res + count < sum) {
		res++;
	}
	cout << res << endl;
}

void od70() {
	//用餐时长3，用餐之前有14份，每个时间段的用餐人数
	int hour1 = 3, count1 = 14;
	vector<int> person1{ 10,4,5 };
	od70_impl(3, 14, person1);
}


//https://blog.csdn.net/qq_23934063/article/details/131058285