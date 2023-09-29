#include "test.h"

void od80_impl(vector<int> input, int taskNum) {
	int time = 0;
	int remain = 0;
	for (auto count : input) {
		if (count + remain > taskNum) {  //remain第一次只是顺带，后面的话，要代入带来处理的
			remain = count + remain - taskNum;
		} else {
			remain = 0;
		}
		time++;
	}

	time += remain / taskNum; //剩下的还要几次

	if (remain % taskNum > 0) //如果剩下的还有余下的，说明还需要一次
		time++;

	cout << time << endl;
}

void od80() {
	vector<int> inputs1{ 1,2,3,4,5 };
	int n1 = 3;//每次执行几个任务
	od80_impl(inputs1,n1);
}