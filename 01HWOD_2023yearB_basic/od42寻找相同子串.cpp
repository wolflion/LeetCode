/*
* ��Ŀ����

���������ַ�����p��Ҫ���t���ҵ�һ����p��ͬ�������Ӵ�����������Ӵ���һ���ַ����±�.

��������

�����ļ��������зֱ��ʾ�ַ�����p

��֤t�ĳ��Ȳ�С��p

��t�ĳ��Ȳ�����1000000

p�ĳ��Ȳ�����10000

�������

����ܴ����ҵ�һ����p��ȵ������Ӵ�����������Ӵ���һ���ַ���t�е��±꣬��

�����������Ϊ123,...;

������ܣ��������No��

������ж���������Ӵ����������һ���ַ��±���С��

����

����

AVERDXIVYERDIAN
RDXI
���

4
*/

#include "test.h"

void od42_impl(string source, string target) {
	//auto res = find_first_of(source.begin(), source.end(), target.begin(), target.end());  //lionel���÷�����
	cout << source.find_first_of(target) + 1 << endl;  //lionel������ط�Ҫ��1��
	//cout << *res << endl;
}

void od42() {
	string source1 = "AVERDXIVYERDIAN";
	string target1 = "RDXI";
	od42_impl(source1, target1);
}