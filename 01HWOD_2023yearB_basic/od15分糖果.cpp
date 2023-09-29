#include "test.h"

int od15_impl(int input) {
	int res = 0;
	if (input == 1) {
		 res++;
		 return res;//lionel，这个地方有问题，return res++（只是返回4），拆成2句就是5，**其实左加和右加还是有区别的**
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