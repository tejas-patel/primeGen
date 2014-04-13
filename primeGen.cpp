#include<iostream>
#include<stdlib.h>
using namespace std;

int main(int argc,char ** argv){

	int prime[100001];
	long long l,r;
	if((argc-1)%2!=0) cout<<"Invalid arguments: One limit missing"<<endl;



	for(long i=0;i<=100001;++i)
		prime[i]=1;
	prime[0]=prime[1]=0;
	for(long i=2;i*i<=100000;++i){
		if(prime[i]==1){
			for(long j=i+i;j<=100000;j=j+i)
				prime[j]=false;
		}
	}


	int cnt=1;
	while(cnt<argc){
		l=atol(argv[cnt]);
		r=atol(argv[cnt+1]);
		cnt=cnt+2;

	
	int f=1;
	if(r<=100000){
			
		for(long i=l;i<=r;++i){
			if(prime[i]){
				cout<<i<<endl;
			}
		}
		cout<<endl;
		f=0;
	}
	if(!f) continue;
	bool ans[100000]={true};
	long long temp=r;

	while(temp>l){
		r=min(temp,l+100000);
		for(long long i=0;i<100000;++i) ans[i]=true;
		for(long long i=2;i*i<=r;++i){
			if(prime[i]){
				long k=l/i;
				k=k*i;
				if(k<l) k+=i;
				if(k==i) k+=i;
				for(;k<=r;k=k+i){
					ans[k-l]=false;

				}
			}
		   
	
		}
		for(long i=0;i<r-l+1;++i)
			if(ans[i]) cout<<l+i<<endl;

		cout<<endl;
		l=l+100001;

	}
	}
}
