#include "test.h"

int od15_impl(int input) {
	int res = 0;
	if (input == 1) {
		 res++;
		 return res;//lionel������ط������⣬return res++��ֻ�Ƿ���4�������2�����5��**��ʵ��Ӻ��Ҽӻ����������**
	}

	if (input % 2) {
		input += 1;
	} else{
		input /= 2;
		res++;
	}

	cout << input << endl;
	res += od15_impl(input);
}

void od15() {
	int input1 = 15;
	cout<<od15_impl(input1)<<endl;
}