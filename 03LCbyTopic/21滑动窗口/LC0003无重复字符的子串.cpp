/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

 

示例 1:

输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/

//2023-12-01，这只是抄出来的，其实并没有完全理解  【比如unorder_set的语法不熟熟悉，也不够熟练】

/*
算法思路：
1、用hash去存，没问题， 每次进来一个之前，先查一下，是不是有重复的，如果有，就去掉前面一个【也就是left++】
2、如果没有重复的，就插入到hash里，同时求一下当前的值（i-left+1） 【子串的个数】，是不是也可以用hash的size()来看？
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        //int right=left+1;//2、一想到滑窗就想到了右边，但也想到是不是要用for循环的
        unordered_set<char> lookup; //1、我就没想到用set，想到的是map
        //input.push_back(s[left]);
        int maxStr=0;
        //map里有第一个元素，right要先查一下是不是在map里
        for(int i=0;i<s.size();i++){
            while(lookup.find(s[i]) != lookup.end()){ //3、这个地方要用while，为啥是while呢，因为可能不止一个，要不断查找？
                lookup.erase(s[left]);
                left++;
            }
            maxStr=max(maxStr,i-left+1);
            lookup.insert(s[i]);
        }
        return maxStr;
    }
};