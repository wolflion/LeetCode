#include "test.h"

struct prize {
	string nation;
	int gold;
	int silver;
	int bronze;
};

bool cmp77(struct prize p1, struct prize p2) {
	if (p1.gold > p2.gold) {
		return 1;
	} else if (p1.gold == p2.gold && p1.silver > p2.silver) {
		return 1;
	} else if (p1.silver == p2.silver && p1.bronze > p2.bronze) {
		return 1;
	} else if (p1.bronze == p2.bronze) {
		if (p1.nation.compare(p2.nation) > 1)
			return 1;
	}
	//lionel,第一遍（0912）写的时候，cmp写的有问题，这时用结构体存的，我0922再写的时候，想到可以用vector<pair<string,vector<int>>>这样的形式，
#if 0
	else if () {
		return 1;
	} else if (p1.bronze > p2.bronze) {
		return 1;
	} else if (p1.nation.compare(p2.nation)>1) { //lionel，string的比较，直接用compare函数
		return 1;
	}
#endif

	return 0;
}

void od77_impl(int n, vector<prize> input) {
	sort(input.begin(), input.end(), cmp77);
#if 0
	for (auto c : input) {
		cout << c.nation << endl;
	}
#endif
	for (int i = 0; i < 3; i++) {
		cout << input[i].nation << endl;
	}
}

void od77() {
	int n1 = 5;
	vector<prize> inputs{ {"china",32,28,34}, {"England",12,34,22}, {"France",23,33,2},{"Japan",12,34,25},{"Russia",23,43,0} };
	od77_impl(n1, inputs);
}