#include "test.h"
/*
* 非严格递增连续数字序列
题目描述
输入一个字符串仅包含大小写字母和数字
求字符串中包含的最长的非严格递增连续数字序列长度
比如：
12234属于非严格递增数字序列

输入描述
输入一个字符串仅包含大小写字母和数字

输出描述
输出字符串中包含的最长的非严格递增连续数字序列长度

示例一
输入
abc2234019A334bc
输出
4
*/

//https://www.jianshu.com/p/936a64ce681b

void od91() {
	string str("abc2234019A334bc");
	int first = 0, last = 1;
	int num = 0, res = 0;//int num=1; lionel，不知道跟这个有没有关系
	while (first < last) {
		if (last > str.size())
			break;
		if (isdigit(str[last]) && isdigit(str[first])) {
			if (str[last] > str[first]) {
				num++;
				if (num > res) {
					res = num;
				} 
			}
		} else {
			first = last;
			last++;
			num = 0;//num=1;
		}
		first++;
		last++;
	}
	cout << res << endl;
}

//https://ac.nowcoder.com/discuss/1050006

//https://blog.nowcoder.net/n/cdfc391fce2f4b779a8729b96e22756c