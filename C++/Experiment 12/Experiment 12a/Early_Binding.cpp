#include <iostream>
using namespace std;
class Add{
	public:
	int add(int a,int b){
		return a + b;
	}
	int add(int a,int b,int c){
		return a + b + c;
	}
};
int main(){
	Add a;
	cout<<"Sum of 10,20 is:"<<a.add(10,20)<<endl;
	cout<<"Sum of 10,20,30 is:"<<a.add(10,20,30)<<endl;
	
	return 0;
}
