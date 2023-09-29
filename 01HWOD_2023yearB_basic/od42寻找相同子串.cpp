/*
* 题目描述

给你两个字符串和p，要求从t中找到一个和p相同的连续子串，并输出该子串第一个字符的下标.

输入描述

输入文件包括两行分别表示字符串和p

保证t的长度不小于p

且t的长度不超过1000000

p的长度不超过10000

输出描述

如果能从中找到一个和p相等的连续子串，则输出该子串第一个字符在t中的下标，下

标从左到右依次为123,...;

如果不能，则输出“No”

如果含有多个这样的子串，则输出第一个字符下标最小的

用例

输入

AVERDXIVYERDIAN
RDXI
输出

4
*/

#include "test.h"

void od42_impl(string source, string target) {
	//auto res = find_first_of(source.begin(), source.end(), target.begin(), target.end());  //lionel，用法不对
	cout << source.find_first_of(target) + 1 << endl;  //lionel，这个地方要加1吗？
	//cout << *res << endl;
}

void od42() {
	string source1 = "AVERDXIVYERDIAN";
	string target1 = "RDXI";
	od42_impl(source1, target1);
}