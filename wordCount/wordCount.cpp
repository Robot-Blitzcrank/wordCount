#include<bits/stdc++.h>
#include<ca.c>
using namespace std;
struct word_node{
	string word;
	int num;
};
vector<word_node> words;
void sort_word();//单词排序 
void count_word();//统计单词频率 
int main(){
	//input();返回一个字符串 
	//统计字符数 ；返回int
	//单词总数，单词   ；返回int 返回 strcut
	//统计有效行数  ；返回int
	//单词频率  返回struct 
	string str[6]={"Monday","Monday","Tuesday","Wednesday","Thursday","Friday"};
	for(int i =0;i<6;i++){
		struct word_node temp_node;
		temp_node.word = str[i];
		temp_node.num = 1;
		words.push_back(temp_node);
	}
	count_word();
	for(int i=0;i<words.size();i++)
	cout<<words[i].word<<"  "<<words[i].num<<endl;
	return 0;
}

