#include "test.h"

typedef struct que {
	int index;
	int value;
	int weight;
}Que;

bool cmp(Que q1, Que q2) {
	if (q2.weight > q1.weight) {
		return 0;
	} else if (q2.weight == q1.weight) {
		if (q2.index < q1.index)
			return 0;
	}
	return 1;
}

void od60_impl() {
	//lionel，我是没想好，怎么处理输入
	vector<Que> v1{ {1, 10, 1}, { 2,20,1 }, { 3,30,2 }, { 4,40,3 }};  //输出40，30，10，20
	sort(v1.begin(), v1.end(), cmp);

	for (auto c : v1) {
		cout << c.value << endl; 
	}
}


void od60()
{
	od60_impl();
}