#include "test.h"

void od28_impl() {
	;
}
typedef struct person {
	int index;  //lionel，自定义排序，核心还是加个索引
	int height;
	int weight;
}Person;

bool comp(Person p1, Person p2) {
	if (p1.height < p2.height) {
		return 1;
	} else if (p1.height == p2.height && p1.weight < p2.weight) {
		return 1;
	}
	return 0;
}

bool equal(Person p1, Person p2) {
	if (p1.height == p2.height && p1.weight == p2.weight) {
		return 1;
	}
	return 0;
}

void od28() {
	//把输入的2行当成结构体好了
	Person p[4] = { {1,100,40},{2,100,30},{3,120,60},{4,130,50} };
	vector<Person> vp;
	vp.emplace_back(p[0]);
	vp.emplace_back(p[1]);
	vp.emplace_back(p[2]);
	vp.emplace_back(p[3]);
	vector<Person> old_vp{ vp };
	vector<int> num;

	sort(vp.begin(), vp.end(),comp);  //lionel，问题是，如何输出序号？

	//auto it = find(vp.begin(), vp.end(), p[0]);
	//cout << it-vp.begin() << endl;


	for (auto c : vp) {
		cout << c.index << endl;
	}
#if 0
	for (auto c : old_vp) {
		auto it = find_if(vp.begin(), vp.end(), [=](Person tmp) {return
			tmp.height == c.height && tmp.weight == c.weight; });
		cout << it - vp.begin() << endl;
	}
#endif	
}

//https://blog.csdn.net/jidanzai666/article/details/128348894

//find_if的使用， https://blog.csdn.net/sinat_14854721/article/details/106039610