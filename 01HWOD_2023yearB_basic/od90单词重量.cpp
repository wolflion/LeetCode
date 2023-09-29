#include "test.h"

void od90_impl(string input) {
	//https://zhuanlan.zhihu.com/p/426939341  ��������û�뵽�ģ��ַ���split����find�Ļ���Ҫ����ѭ��
    std::string s;
    char delim = ' ';
    s.append(1, delim);
    std::regex reg(s);
    std::vector<std::string> elems(std::sregex_token_iterator(input.begin(), input.end(), reg, -1),
        std::sregex_token_iterator());
    
    vector<int> res;
    for (auto c : elems) {
        res.emplace_back(c.size());
    }

    int sum = 0.0;
    sum = accumulate(res.begin(), res.end(), sum);
    cout << fixed<<setprecision(2)<<(sum*1.0) / res.size() << endl; //https://blog.csdn.net/abilix_tony/article/details/106956204  lionel��2�������⣬setprecison(2)��fixed��̫��Ϥ
}

void od90() {
	string input1{ "who love solo" };
	od90_impl(input1);
}