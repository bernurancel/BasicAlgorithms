#include<iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
//----------------------------------------------------------------
int i,j;
int ary[10][10],completed[10];
int n;
int cost=0;
//----------------------------------------------------------------
void takeInput(){
	  srand((unsigned)time( NULL ));
	  	int value=64;
	cout<<"please enter the your number greater than 3 less than 50..."<<endl<<"Enter the number of villages: ";
	cin>>n;
	if(n<3||n>50){
		cout<<endl<<"your number must be range af 3<n<50...";
		exit;
	}
    else{
    
	cout<<"\nEnter the Cost Matrix\n";
	for( i=0;i <n;i++){
		value ++;
		cout<<"\nEnter Elements of Row: "<<(char)value<<"\n";	
		for(j=0;j <n;j++){
			ary[i][j]= rand()%(((n*(n-1))/2)-(n))+n;
           cout<<ary[i][j]<<" ";
        }
		completed[i]=0;	 
	} 
	cout<<"\n\nThe cost list is:";
		
	for( i=0;i < n;i++){
		cout<<"\n";
		for(j=0;j < n;j++)
	
		cout<<"\t"<<ary[i][j];
		
	}
  } 

}
//----------------------------------------------------------------
int least(int c){
	int i,nc=999;
	int min=999,kmin;
 
	for(i=0;i < n;i++){
		if((ary[c][i]!=0)&&(completed[i]==0))
			if(ary[c][i]+ary[i][c] < min){
				min=ary[i][0]+ary[c][i];
				kmin=ary[c][i];
				nc=i;
			}
	}
	if(min!=999)
		cost+=kmin;
 
	return nc;
}
//----------------------------------------------------------------
void mincost(int city){
	int i,ncity;
	completed[city]=1;
	cout<<city+1<<"--->";
	ncity=least(city);
 
	if(ncity==999){
		ncity=0;
		cout<<ncity+1;
		cost+=ary[city][ncity];
		return;
	}
	mincost(ncity);
}
//----------------------------------------------------------------
int main(){
	takeInput();
	cout<<"\n\nThe Path is:\n";
	mincost(0); //passing 0 because starting vertex
	cout<<"\n\n Minimum cost is  "<<cost;
	return 0;
}
