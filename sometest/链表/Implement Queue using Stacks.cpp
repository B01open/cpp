#include <stdio.h>
#include <stack>

using namespace std;

class MyQueue{
	public:
		void push(int x){
			stack<int> tmpStack;
			while(!data.empty()){
				tmpStack.push(data.top());
				data.pop();
			}
			tmpStack.push(x);
			while(!tmpStack.empty()){
				data.push(tmpStack.top());
				tmpStack.pop();
			}
		}
		
		int pop(){
			int x = data.top();
			data.pop();
			return x;
		}
		
		int peek(){
			return data.top();
		}
		
		bool empty(){
			return data.empty();
		}
		
	private:
		stack<int> data;
};

int main(){
	
	MyQueue qq;
	
	qq.push(1);
	qq.push(2);
	qq.push(3);
	qq.push(4);
	
	printf("%d  \n", qq.peek());
	qq.pop();
	printf("%d  \n",qq.peek());
	
} 
