#include<iostream>
#include<windows.h> 
using namespace std;
int main(){
	int n=0,x=0,y=0;
	while(n<=103){
		cout<<"*";
		n++;
	}
	cout<<"\r";
	while(x<=100){
		cout<<x<<"%";
		while(y<x){
			cout<<"-";
			y++;
		}
		x++;
		y=0;
		cout<<"\r";
		if(x==100) Sleep(5000) ;
		else if(x==79) Sleep(3000);
		else Sleep(100);
	}
	return 0;
}
//Try to implement a progress bar with escape characters.（为了能够查看到变化，可以使用Sleep()函数） 
