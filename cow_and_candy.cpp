#include<iostream>
#include<cmath>
using namespace std;

int N,M;
long long cow_heights[1000010];

int main(){
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>cow_heights[i];
	}
	
	long long candy_height;
	for(int i=0;i<M;i++){
		cin>>candy_height;
		long long candy_base=0;
		for(int j=0;j<N&&candy_base<candy_height;j++){
			if(cow_heights[j]>candy_base){
				long long eat=min(candy_height,cow_heights[j])-candy_base;
				candy_base+=eat;
				cow_heights[j]+=eat;
			}
		}
	}
	
	for(int i=0;i<N;i++) cout<<cow_heights[i]<<endl;
} 
