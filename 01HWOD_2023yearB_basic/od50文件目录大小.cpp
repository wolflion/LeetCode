#include "test.h"

/*
* 一个文件目录的数据格式为：目录id,本目录中文件大小，(子目录id列表)。

其中目录id全局唯一，取值范围[1,200],本目录中文件大小范围[1,1000],子目录id列表个数[0,10]例如：1 20 (2,3)表示目录1中文件总大小是20,有两个子目录，id分别是2和3

现在输入一个文件系统中所有目录信息，以及待查询的目录id,返回这个目录和及该目录所有子目录的大小之和。

输入描述

第一行为两个数字M,N,分别表示目录的个数和待查询的目录id,

·1≤M≤100

·1≤N≤200

接下来M行，每行为1个目录的数据：

目录id本目录中文件大小(子目录id列表)

子目录列表中的子目录id以逗号分隔。

输出描述

待查询目录及其子目录的大小之和

3 1  //查1
3 15()
1 20(2)
2 10(3)

// case 2
4 2
4 20()
5 30()
2 10(4,5)
1 40()
*/

//参考LC690
typedef struct f {
	int id;
	int size;
	vector<int> subordinates;
}file;

void dfs(int id, unordered_map<int, file>& um, int& sum) {
	for (auto id : um[id].subordinates) {
		sum += um[id].size;
		dfs(id, um, sum);
	}
}

void od_50_impl(int n, vector<file> input) {
	unordered_map<int, file> um;
	for (auto c : input) {
		um[c.id] = c;
	}

	int sum = um[n].size;
	dfs(n, um, sum);
	cout << sum << endl;
}

//lionel，相当于，我要把每一行放到 file 结构体里

void od50() {
	int m = 4;
	int n = 2;
	vector<int> tmp{ 4,5 };
	vector<int> emp;
	vector<file> inputs{ {4,20,emp},{5,30,emp},{2,10,tmp},{1,40,emp} };  //输出就是60
	od_50_impl(n, inputs);  //lionel，如何用指针？
}