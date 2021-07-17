#include <iostream>
using namespace std;

#define INFINTY 9999

int startNode;
int v=7;
int vertex[]={1,2,3,4,5,6,7};
int distance[7];
int parent[7];
int cost[][]={{}}
bool visitedNodes[7];

void init(){
	for(int i=0;i<v;i++){
		parent[i]=i;
		distance[i]=INFINITY;
	}
	distance [startNode]=0;
	
}

int getNearest(){
	int minVal=INFINITY;
	int minNode=0;
	for (int i=0;i<v;i++){
		if(!visitedNodes[i] && distance[i]<minVal){
			minVal=distance[i];
			minNode=i;
		}
	}
	return minNode;
	
}

void dijkstra(){
	for(int i=0;i<v;i++){
		int nearest=getNearest();
		visitedNodes[nearest]=true;
		
		for(adj=0;adj<v;adj++){
			 if(cost[nearest][adj]!=INFINITY  && distance[adj]>distance[nearest]+cost[nearest][adj]){
			 	distance[adj]=distance[nearest]+cost[nearest][adj];
			 	parent[adj]=nearest;
			 }
		}
	}
}

void display(){
	cout<<"Node\t\t\tCost\t\t\tPath";
	for (int i=o;i<v;i++){
		cout<<i<<"\t\t\t"<<distance[i]<<"\t\t\t"<<" ";
		cout<<i<<" ";
		int parNode=parent[i];
		while(parNode!=startNode){
			cout<<"<--"<<parNode<<" ";
			parNode=parent[parNode];
		}
		cout<<endl;
	}
}


int main(){
	cin>>startNode;
	
	
	
	
	return -1;
}
