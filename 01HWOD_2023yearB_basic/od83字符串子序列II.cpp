#include "test.h"

void od83_impl(string target, string source) {
	//for (int i = target.size(); i > 0; i--) {  //lionel���������2��forѭ���ģ����ֿ����Ż���Ҳ�ǲο���
	int cur = target.size();
		for (int j = source.size(); j > 0; j--) {
			if (source[j] == target[cur]) {
				cur--;
				if (cur < 0)
				{
					cout << j << endl;
					break;
				}
					
			}
		}
	//}
}

void od83() {
	string target1 = "abc";
	string source1 = "abcaybec";

	od83_impl(target1, source1);
}

//https://zhuanlan.zhihu.com/p/645391206  �����и��򵥵ģ�
/*
* def result():
    i = len(target)-1
    j = len(source)-1
    while i >= 0:
        if target[i] == source[j]:
            i -= 1
        j -= 1
    return j+1 # ��Ϊ��һ��ѭ���Ѿ���ȥ1�ˡ�
result()
*/