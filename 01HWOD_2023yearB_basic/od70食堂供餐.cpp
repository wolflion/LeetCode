#include "test.h"

void od70_impl(int hour, int count, vector<int> person) {
	int res = 0;
	int sum = 0;
	sum = accumulate(person.begin(), person.end(), sum);  //lionel�����sum�����ø�������ֵ����һ�£���Ȼsum����0

	while ((hour - 1)*res + count < sum) {
		res++;
	}
	cout << res << endl;
}

void od70() {
	//�ò�ʱ��3���ò�֮ǰ��14�ݣ�ÿ��ʱ��ε��ò�����
	int hour1 = 3, count1 = 14;
	vector<int> person1{ 10,4,5 };
	od70_impl(3, 14, person1);
}


//https://blog.csdn.net/qq_23934063/article/details/131058285