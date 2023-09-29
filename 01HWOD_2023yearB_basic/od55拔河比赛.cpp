#include "test.h"

typedef struct person {
	int heigth;
	int weight;
}Person;

bool cmp(Person p1, Person p2) {
	if (p1.heigth > p2.heigth) {
		return 1;
	} else if (p1.heigth == p2.heigth) {
		if (p1.weight > p2.weight) {
			return 1;
		}
	}

	return 0;
}
void od55_impl(vector<vector<int>> inputs) {
	vector<Person> res;
	for (auto c : inputs) {
		//for (int i = 0; i < c.size(); i++) {
			Person tmp;
			tmp.heigth = c[0];
			tmp.weight = c[1];
			res.push_back(tmp);
		//}
	}
	sort(res.begin(), res.end(), cmp);

	for (int i = 0; i < 10; i++) {
		cout << res[i].heigth << "," << res[i].weight << endl;
	}
}

void od55() {
	vector<vector<int>> inputs1{ {181, 70}, { 182,70 }, { 183,70 }, { 184,70 }, { 185,70 }, { 186,70 }, { 180,71 }, { 180,72 }, { 180,73 }, { 180,74 }, { 180,75 }};
	od55_impl(inputs1);
}

//https://blog.csdn.net/AlgorithmHero/article/details/132687598