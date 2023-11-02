#include "test.h"

/*
* 张兵和王武是五子棋迷，工作之余经常切磋棋艺。 走了一会儿，轮到张兵了，他对着一条线思考起来了，这条线上的棋子分布如下： 用数组表示： -1 0 1 1 1 0 1 0 1 -1

棋子分布说明:

-1 代表白子，0 代表空位，1 代表黑子；
数组长度 L, 满足 1 < L < 40, 且 L 为奇数；
请帮他写一个程序，算出最有利的出子位置。

最有利定义：

找到一个空位 (0)，用棋子 (1/-1) 填充该位置，可以使得当前子的最大连续长度变大；
如果存在多个位置，返回最靠近中间的较小的那个坐标；
如果不存在可行位置，直接返回 -1；
连续长度不能超过 5 个(五子棋约束)；
输入描述
第一行: 当前出子颜色 第二行: 当前的棋局状态

输出描述
1 个整数，表示出子位置的数组下标

示例一
输入
1
-1 0 1 1 1 0 1 0 1 -1 1
输出
5
*/

//-1白子，0空位，1黑子

void od46_impl(int currentColor, vector<int> input) {

	int len = input.size();
	int middle = (len - 1) / 2;
	int res = -1, max = 0;
	for (int i = 0; i < len; i++) {
		if (input[i] == currentColor) {
			int right = i + 1;

			//找出连续的当前颜色的连续棋子到哪里结束
			while (right < len && input[right] == currentColor) {
				right++;
			}

			int tmpLen = right - i;
			//如果旗子放在right指向的位置
			if (right < len && input[right] == 0) {
				if (tmpLen == max && abs(right - middle) < abs(middle - res)) {
					//替换后的字符长度和之前的替换结果相等，且right更接近中心位置
					res = right;
				} else if (tmpLen > max) {
					//替换后的字符长度是最长的
					max = tmpLen;
					res = right;
				}
			}

			//如果旗子放在 i-1 指向的位置
			if (i-1 >= 0 && input[i-1] == 0) {
				if (tmpLen == max && abs(i-1 - middle) < abs(middle - res)) {
					//替换后的字符长度和之前的替换结果相等，且right更接近中心位置
					res = i-1;
				} else if (tmpLen > max) {
					//替换后的字符长度是最长的
					max = tmpLen;
					res = i-1;
				}
			}

			//更新i
			i = right;
		}
	}

	cout << res << endl;
#if 0
	int left = 0, right = left+1;
	while (left < right) {
		if (right > input.size())
			break;

		if (input[left] != currentColor && input[left] != 0) {
			left++;
			right++;
		} else if (input[left] == currentColor && input[right] == currentColor) {
			right++;
		}
	}
#endif
}

void od46() {
	int currentColor1 = 1;
	vector<int> inputs{ -1,0,1,1,1,0,1,0,1,-1,1 };
	od46_impl(currentColor1, inputs);
}

void input()
{
	int cur;
	cin >> cur;
	vector<int> inputs;
	int num;
	while (cin>>num)
	{
		inputs.push_back(num);
		if (cin.get() == '\n')
			break;
	}
}

//https://blog.csdn.net/wj_phm/article/details/132941144

//LC424，替换后最长重复字符

//csdn，半生程序员，weixin_42450130

//ctrl+k,ctrl+c   [ctrl+k, ctrl+u]