#include<bits/stdc++.h>
using namespace std;
const double err=1e-8;
#define coutp cout<<fixed<<setprecision(6)
double m,n;
double sol(double x,double l,double r){
	while(r-l>err){
		double mid=l+(r-l)/2;
		if(pow(mid,3)>=x) r=mid;
		else l=mid;
	}
	return l;
}
int main(){
	cin>>m;
	if(m>=1) coutp<<sol(m,1,m);
	else if(m>=0&&m<1) coutp<<sol(m,m,1);
	else if(m<0&&m>-1) coutp<<-sol(-m,-m,1);
	else if(m<=-1) coutp<<-sol(-m,1,-m);
} 
