#include<bits/stdc++.h>
using namespace std;
struct word_node{
	string word;
	int num;
};
vector<word_node> words;
int sum_word(string str);
bool checkA(char c);//¼ì²â×ÖÄ¸ 
bool checkB(char c);//¼ì²âÊı×Ö 
int main(){
	string str = "Monday11 11Tuesday&Wednesday \n Thursday Friday";
	int n = sum_word(str);
	cout<<n<<"   "<<str<<endl;
}
int sum_word(string str){//
	int sum = 0;
	for(int i = 0;i < (str.size()-4);i++){
		int k = 0;
		if(checkA(str[i])){
			if(checkA(str[i+1]) && checkA(str[i+2]) && checkA(str[i+3])){ //¼ì²âÇ°ËÄÎ»ÊÇ·ñÎª×ÖÄ¸ 
				for(int j = i + 3;j < str.size();j++){
					if(str[j] == ' '||str[j] == '\n' || (!checkA(str[i])&&!checkB(str[i])) ){
						k = j;
						break;
					}
		        	k = str.size()-1;
				}
				string temp;
				temp = str.substr(i,k);
				struct word_node temp_node;
				temp_node.word = temp;
				temp_node.num = 1;
				words.push_back(temp_node);
				sum++;
				i = k;
			}
		}else if(checkB(str[i])){
			for(int j = i;j<str.size();j++){
				if(j ==18) cout<<str[j]<<endl;
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
bool checkA(char c){ //¼ì²é×ÖÄ¸ 
	if((c>64&&c<91)||(c>96&&c<123)) return true;
	else return false;
}
bool checkB(char c){ //¼ì²éÊı×Ö 
	if(c>47&&c<58) return true;
	else return false;
}
