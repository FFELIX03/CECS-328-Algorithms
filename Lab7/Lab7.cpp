#include<iostream>
#include<vector>
using namespace std;

struct node
{
	string name;
	node *parent;
	vector<node> adj_list;


	void adj(node n)
	{
		adj_list.push_back(n);
	}
};


int main()
{	//--------------variables---------------------
	int order,size; // |V|,|E| values
	int init=0; //iterate
	int r=0; //random number
	string name;

	//vector to hold vertices
	vector<node> O; 
	//User input
	cout<<"Enter the number order |V| or the graph"<<endl;
	cin>>order;
	cout<<"Enter the size |E| of graph"<<endl;
	cin>>size;

	//Dynamically create nodes and name them
	while(init <order)
	{
		cout<< "Enter name of node"<<endl;
		cin>>name;
		node *n= new node{name,NULL};
		
		O.push_back(*n);
		init+=1;
	}
	
	//listing node names
	cout<<"Name of nodes: "<<endl;
	for(auto i=O.begin(); i!=O.end(); i++)
		cout<<i->name<<endl;

	//randomly assign adjacent nodes
	for(auto j =O.begin(); j!=O.end(); j++)
	{
		for(auto k = O.begin(); k!=O.end(); k++)
		{	
			if(size==0)
				break;
			r=rand()%10;
			if(r==1)
			{
				j->adj(*k);
				k->adj(*j);
				
				size-=1;
			}
		}
		if (size==0)
			break;
	}
	
	//list node neighbors
	cout<<"Listing Edges: "<<endl;
	for(auto i=O.begin(); i<O.end(); i++)
	{
		cout<<"Vertice "<<i->name<<" is connected with"<<endl;
		for(auto j = i->adj_list.begin(); j< i->adj_list.end(); j++)
			cout<<j->name<<endl;
	}


	

}
