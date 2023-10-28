#include"test.h"

void od85() {
	string str = "bcdefa";//找到a,跟b换一下，输出acdefb

	string s2 = str;
	sort(s2.begin(), s2.end());

	char min = s2[0];
	int place = 0, change = 0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == min) {//找到原串中最小的位置
			place = i;
			break;
		}
	}

	for (int j = 0; j < str.size(); j++) {
		if (str[j] != min) {  //这个地方取原串，未排序的
			change = j;//记下排序后，不等的地方
			break;
		}
	}

	if (place > change) {
		swap(str[place], str[change]);
	}

	cout << str << endl;
}

//https://blog.csdn.net/G1useppE/article/details/125025845