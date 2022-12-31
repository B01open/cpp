#include <stdio.h>
#include <queue>

using namespace std;

class MyStack{
	public:
		MyStack(){
		}
		
		void push(int x){
			queue<int> tmpQueue;
			tmpQueue.push(x);
			while(!data.empty()){
				tmpQueue.push(data.front());
				data.pop();
			}
			
			while(!tmpQueue.empty()){
				data.push(tmpQueue.front());
				tmpQueue.pop();
			}
		}
		
		int pop(){
			int x = data.front();
			data.pop();
			return x;
		}
		
		int top(){
			return data.front();
		}
		
		bool empty(){
			return data.empty();
		}
	private:
		queue<int> data;
};

int main(){
	
	MyStack ss;
	ss.push(1);d
	ss.push(2);
	ss.push(3);
	ss.push(4);
	printf("%d  \n", ss.pop());
	ss.push(8);
	printf("%d   \n", ss.top());
	
}
