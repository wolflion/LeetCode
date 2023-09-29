#include "test.h"

void od80_impl(vector<int> input, int taskNum) {
	int time = 0;
	int remain = 0;
	for (auto count : input) {
		if (count + remain > taskNum) {  //remain��һ��ֻ��˳��������Ļ���Ҫ������������
			remain = count + remain - taskNum;
		} else {
			remain = 0;
		}
		time++;
	}

	time += remain / taskNum; //ʣ�µĻ�Ҫ����

	if (remain % taskNum > 0) //���ʣ�µĻ������µģ�˵������Ҫһ��
		time++;

	cout << time << endl;
}

void od80() {
	vector<int> inputs1{ 1,2,3,4,5 };
	int n1 = 3;//ÿ��ִ�м�������
	od80_impl(inputs1,n1);
}