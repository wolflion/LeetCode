#include "test.h"

void od65() {
	//n=26��a�η�+10��b�η�
	int x = 2600, y = 1;  //26,1���1   2600��1���2

	//������
	int sum = pow(26, y);

	//���ָ���
	int dig = 1;
	//y����ĸ
	while (sum * pow(10, dig) < x) {
		dig++;
	}

	cout << dig << endl;
}

//https://blog.csdn.net/weixin_43428283/article/details/127110879


//https://blog.csdn.net/wj_phm/article/details/132473224