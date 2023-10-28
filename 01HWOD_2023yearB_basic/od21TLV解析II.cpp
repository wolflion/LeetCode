#include "test.h"
/*
* 题目描述

两端通过TLV格式的报文来通信，现在收到对端的一个TLV格式的消息包，要求生成匹配后的(tag, length, valueOffset)列表。具体要求如下：

(1)消息包中多组tag、length、value紧密排列，其中tag,length各占1字节(uint8_t),value所占字节数等于length的值

(2)结果数组中tag值已知，需要填充每个tag对应数据的length和valueOffset值(valueOffset为value在原消息包中的起始偏移量(从0开始，以字节为单位)),

即将消息包中的tag与结果数组中的tag进行匹配(可能存在匹配失败的情况，若结果数组中的tag在消息包中找不到，则length和

valueOffset都为0)

(3)消息包和结果数组中的tag值都按升序排列，且不重复

(4)此消息包未被篡改，但尾部可能不完整，不完整的一组TLV请丢弃掉

输入描述

第一行：一个字符串，代表收到的消息包。字符串长度在10000以内。

·说明1字符串使用十六进制文本格式(字母为大写)来展示消息包的数据，如0F04ABABABAB代表一组TLV前两个字符(0F)代表

tag值为15,接下来两个字符(04)代表length值为4字节，接下来8个字符即为4字节的value。

·说明2:输入字符串中，每一组TLV紧密排列，中间无空格等分隔符

第二行：需要匹配的tag数量n(O<n<1000)。

后面n行：需要匹配的n个tag值(十进制表示),递增排列。

输出描述

和需要匹配的n个tag对应的n行匹配结果，每一行由长度和偏移量组成
*/

//lionel解读，长度就是0x4，偏移量就是0xF0x4就是2个偏移量，8个字符，就是4字节，

void od21() {
	string s = "0F04ABABABAB";
	//getline(cin, s);
	int n = 1;
	int tag = 15;
	//int n=2,tag就有2个值，15，17

	//lionel，不会，用map来记录需要匹配的tag和其解析后的[起始点，结束点]
	map<int, vector<int>> tagOffset;
	for (int i = 0; i < n; i++) {
		vector<int> tmp = { 0,0 };
		tagOffset[tag] = tmp;
	}

	int bound = s.size();
	int left = 0;
	int right = 2;
	int offset = 2;
	while (left < bound) {  //lionel,这个地方，作者写的是left<=bound，我改成了left<bound
		//一开始匹配的就是tag
		//https://blog.csdn.net/ma_minmin/article/details/126908825  [stoi(tmp,0,16)]
		string tmp = s.substr(left, right);//https://blog.csdn.net/zjl2222/article/details/112135497  [C++的16进制，转在10进制]
		int tag = stoi(tmp,0,16);  //lionel，get到了这个

		int length = stoi(s.substr(left + 2, right + 2));

		//判断tag是否匹配
		if (tagOffset.find(tag) != tagOffset.end() && ((offset + length) * 2 <= bound)) {  //lionel，这个地方，作者写的是<bound，我改成<=了
			tagOffset[tag] = { length,offset };
		}

		//根据长度来更新偏移量
		offset = offset + length + 2;
		left += (length * 2) + 4;
		right += (length * 2) + 4;
	}

	for (auto c : tagOffset) {
		cout << c.second[0] << " " << c.second[1] << endl;
	}
}


//https://zhuanlan.zhihu.com/p/647335136

//https://blog.csdn.net/wj_phm/article/details/132422947