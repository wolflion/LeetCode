#include "test.h"

/*
* 【We Are A Team】

总共有 n 个人在机房，每个人有一个标号（1<=标号<=n），他们分成了多个团队，需要你根据收到的 m 条消息判定指定的两个人是否在一个团队中，具体的：

1、消息构成为 a b c，整数 a、b 分别代表两个人的标号，整数 c 代表指令

2、c == 0 代表 a 和 b 在一个团队内

3、c == 1 代表需要判定 a 和 b 的关系，如果 a 和 b 是一个团队，输出一行’we are a team’,如果不是，输出一行’we are not a team’

4、c 为其他值，或当前行 a 或 b 超出 1~n 的范围，输出‘da pian zi’

输入描述

第一行包含两个整数 n，m(1<=n,m<100000),分别表示有 n 个人和 m 条消息
随后的 m 行，每行一条消息，消息格式为：a b c(1<=a,b<=n,0<=c<=1)
输出描述: 1、c ==1,根据 a 和 b 是否在一个团队中输出一行字符串，在一个团队中输出‘we are a team‘,不在一个团队中输出’we are not a team’ 2、c 为其他值，或当前行 a 或 b 的标号小于 1 或者大于 n 时，输出字符串‘da pian zi‘
如果第一行 n 和 m 的值超出约定的范围时，
*/

vector<int> fa;//没想到要用 typedef 或者 using，来省略一下，lionel
void init(int len) {
	fa.resize(len+1);//lionel，这个地方给的size太小了，导致越界，但根因是不是这个，不确定
	for (int i = 0; i < len; i++) {
		fa[i] = i;
	}
}

int find(int x) {
	if (x != fa[x]) {
		fa[x] = find(fa[x]);
	}
	return fa[x];
}

void merge(int x, int y) {

	int mx = find(x);
	int my = find(y);
	//lionel，不需要判断？
	fa[x] = y;
	//lionel，后面是我根据正规写的，也是可以运行
#if 0
	x = find(x);
	y = find(y);
	if (x > y) {
		fa[x] = y;
	} else {
		fa[y] = x;
	}
#endif
}

void od_a04_impl(int n, int m, vector<vector<int>> input) {
	init(n);//总共多少人
	for (int i = 0; i < m; i++) {
		int x = input[i][0];
		int y = input[i][1];
		int p = input[i][2];

		//lionel，核心在这个地方，我没懂搞的是，啥时候要merge()，啥时候要find()，后来看代码，又看看题意，逻辑都在题干上，要多看看
		if (x<1 || x>n || y<1 || y>m) {
			cout << "da pian zi" << endl;
		} else {
			if (p == 0) {
				merge(x, y);
			} else if (p == 1) {
				if (find(x) == find(y)) {
					cout << "we are team" << endl;
				} else {
					cout << "we are not team" << endl;
				}
			} else {
				cout << "da pian zi" << endl;
			}
		}
			
	}
}

void od_a04() {
	int n1 = 5, m1 = 7;
	vector<vector<int>> inputs1{ {1,2,0},{4,5,0},{2,3,0},{1,2,1},{2,3,1},{4,5,1},{1,5,1} };
	od_a04_impl(n1,m1,inputs1);
}