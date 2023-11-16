#include "test.h"

/*
* 跳房子，也叫跳飞机，是一种世界性的儿童游戏

游戏参与者需要分多个回合按顺序跳到第1格直到房子的最后一格。

跳房子的过程中，可以向前跳，也可以向后跳。

假设房子的总格数是count，小红每回合可能连续跳的步教都放在数组steps中，请问数组中是否有一种步数的组合，可以让小红两个回合跳到量后一格?如果有，请输出索引和最小的步数组合.

注意:

数组中的步数可以重复，但数组中的元素不能重复使用

。提供的数据保证存在满足题目要求的组合，且索引和最小的步数组合是唯一的

输入描述

第一行输入为房子总格数count，它是int整数类型。

第二行输入为每回合可能连续跳的步数，它是int整数数组类型

输出描述

返回索引和最小的满足要求的步数组合(顺序保持steps中原有顺序
*/

void od62() {
	vector<int> house{ 1,4,5,2,2 };
	int step = 7;

	int min = INT_MAX;
	vector<int> res(2);

	for (int i = 0; i < house.size(); i++) {
		for (int j = 1; j < house.size(); j++) {
			if (house[i]+house[j] == step  && i+j<min) {
				min = i + j;
				res[0] = house[j];
				res[1] = house[i];
			}

			if (house[i] + house[j] > step) {
				break;
			}
		}
	}
	cout << res[0] << "," << res[1] << endl;
}

//amoscloud.com上的0253题