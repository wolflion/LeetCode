#include "test.h"

/*
* 题目描述

给定一个以顺序储存结构存储整数值的 完全二叉树 序列(最多 1000 个整数)，请找出此完全二又树的所有非叶子节点部分，然后采用后序遍历方式将此部分树 (不包含叶子) 输出。

1.只有一个节点的树，此节点认定为根节点(非叶子)

2.此完全二叉树并非 满二叉树，

可能存在倒数第二层出现叶子或者无右叶子的情况其他说明: 二又树的后序遍历 Q 是基于根来说的，遍历顺序为: 左-右-根

输入描述

个通过空格分割的整数序列字符串

输出描述

非叶子部分树结构。备注: 输出数字以空格分隔
*/


void dfs(vector<int>& inputs, int root, vector<int>& res) {
	int left = 2 * root + 1;
	int right = 2 * root + 2;   //lionel，这种套跑，我是没想到的
	if (inputs.size() > left) {
		dfs(inputs, left, res);
		if (inputs.size() > right){
			dfs(inputs, right, res);  //这种dfs方式，我也不会，以及怎么组织？
		}
		
		res.push_back(inputs[root]);  //lionel，这个地方就写错了，写成了res.push_back(root)了，应该是值，inputs[root]
	}
}

void od_a36() {
	vector<int> inputs{ 1,2,3,4,5,6,7 };
	vector<int> res;

	dfs(inputs, 0, res);
	
	for (auto c : res) {
		cout << c<<" ";
	}
}


//https://zhuanlan.zhihu.com/p/641757199