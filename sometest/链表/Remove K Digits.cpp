#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

class Solution{
	public:
		string removeKdigits(string num, int k){
			vector<int> S;
			string result = "";
			for(int i = 0; i < num.length(); i++){
				int number = num[i] - '0';
				while(S.size() != 0 && S[S.size()-1] > number && k > 0){
					S.pop_back();
					k--;
				}
				if(number != 0 || S.size() != 0){
					S.push_back(number);
				}
			}
			while(S.size() != 0 && k > 0){
				S.pop_back();
				k--;
			}
			for(int i = 0; i < S.size(); i++){
				result.append(1,'0'+S[i]);
			}
			if(result == ""){
				result = "0";
			}
			return result;
		}
};

int main(){
	Solution solve;
	string result = solve.removeKdigits("1432219", 3);
	printf("%s\n", result.c_str());
	string result2 = solve.removeKdigits("100200", 1);
	printf("%s\n", result2.c_str());
	return 0;
}
