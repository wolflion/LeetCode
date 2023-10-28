#include "test.h"

void od65() {
	//n=26的a次方+10的b次方
	int x = 2600, y = 1;  //26,1输出1   2600，1输出2

	//总人数
	int sum = pow(26, y);

	//数字个数
	int dig = 1;
	//y个字母
	while (sum * pow(10, dig) < x) {
		dig++;
	}

	cout << dig << endl;
}

//https://blog.csdn.net/weixin_43428283/article/details/127110879


//https://blog.csdn.net/wj_phm/article/details/132473224