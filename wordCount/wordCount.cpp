#include<bits/stdc++.h>
using namespace std;
struct word_node{
	string word;
	int num;
};
vector<word_node> words;
string str;//保存的字符串 
void sort_word();//单词排序 
void count_word();//统计单词频率 
int count_characters();//统计行数 
int sum_word();//单词计数 
bool checkA(char c);//检测字母 
bool checkB(char c);//检测数字 
int main(int argc, char *argv[]){
	int in, out, m = 0, n = 10, i, get, count=0;//count统计共有多少个换行符
    char ch;
    char* ff;
    string strpp;//输入后单词存入strp中，其间以‘ ’分隔
 /*    for (i = 1; i < argc; i++) {
          cout << argv[i] << endl;
     }
 *///测试用码
    for (i = 1; i < argc; i++) {
        ff = argv[i];
        if ((get = strcmp("-i", ff)) == 0) {
            in = i + 1;
        }
        if ((get = strcmp("-o", ff)) == 0) {
            out = i + 1;
        }
        if ((get = strcmp("-m", ff)) == 0) {
            m = atoi(argv[i + 1]);
        }
        if ((get = strcmp("-n", ff)) == 0) {
            n = atoi(argv[i + 1]);
        }
    }
    fstream infile(argv[in], ios::in);       //指定输入文件流对象
    fstream outfile(argv[out], ios::out);     //指定输出文件流对象.
    //连续读入单词，中间以空格分割
    infile >> str; 
    while (infile >> strpp) {
        str = str + ' ' +  strpp;
    }

    infile.clear();
    infile.seekg(0, ios::beg);
    while (1) {
        if ((ch = infile.get()) == '\n') {
            count++;
        }
        else if (ch == EOF) {
            break;
        }
    }
	//
	int characters = count_characters();
	int wordssum = sum_word();
	count_word();
	outfile << "characters:" << characters << endl;
    outfile << "words:" << wordssum << endl;
    outfile << "lines:" << ++count << endl;
    if(n>words.size()) n = words.size();
    for(i = 0;i<n;i++){
    	outfile << '<' << words[i].word << '>'<<':' << words[i].num<<endl;
	}
	return 0;
}
int count_characters(){	

	int num = 0;
	for(int i=0;i<str.length();i++){
		if(str[i]>=0&&str[i]<=127)
		num++;
	}
	return num;
}
int sum_word(){//
	int sum = 0;
	for(int i = 0;i < (str.size()-4);i++){
		int k = 0;
		if(checkA(str[i])){
			if(checkA(str[i+1]) && checkA(str[i+2]) && checkA(str[i+3])){ //检测前四位是否为字母 
				for(int j = i + 3;j < str.size();j++){
					if(str[j] == ' '||str[j] == '\n' || (!checkA(str[i])&&!checkB(str[i])) ){
						k = j;
						break;
					}
		        	k = str.size()-1;
				}
				string temp;
				temp = str.substr(i,k-i+1);
				struct word_node temp_node;
				temp_node.word = temp;
				temp_node.num = 1;
				words.push_back(temp_node);
				sum++;
				i = k;
			}
		}else if(checkB(str[i])){
			for(int j = i;j<str.size();j++){
				if(str[j] == ' '||str[j] == '\n' || (!checkA(str[j])&&!checkB(str[j])) ){
					k = j;
					break;
					
				}
				k = str.size()-1;
			}
			i = k;
		}
	}
	return sum;
}
bool checkA(char c){ //检查字母 
	if((c>64&&c<91)||(c>96&&c<123)) return true;
	else return false;
}
bool checkB(char c){ //检查数字 
	if(c>47&&c<58) return true;
	else return false;
}
void count_word(){//统计单词频率
	for(int i =0;i<words.size();i++){
		transform(words[i].word.begin(), words[i].word.end(), words[i].word.begin(), ::tolower);
	}
	for(int i = 0;i < (words.size()-1);i++){
		for(int j = i+1;j < words.size();j++){
			if(words[i].word == words[j].word){
				words[j] = words[(words.size()-1)];
				words.pop_back();
				words[i].num++;
			}
		}
	}
	sort_word();
} 
void sort_word(){//单词排序 
    for(int i = 0;i < (words.size()-1); i++){
    	for(int j = i+1;j < words.size();j++){
    		if((words[i].num < words[j].num)||(words[i].word > words[j].word)){
    			struct word_node temp_node;
    			temp_node = words[i];
    			words[i] = words[j];
    			words[j] = temp_node;
			}
		}
	}
}

