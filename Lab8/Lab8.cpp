#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cctype>
#include<list>
#include<iterator>
using namespace std;

struct node
{
	string name;
	node *parent=NULL;
	list<node> adj_list;
	int dist,start,end=-1;

	void adj(node n)
	{
		adj_list.push_back(n);
	}
};

void BFS(node);
void DFS(list<node> n);
bool DFS_visit(node s);

int timer=0;
int main()
{	//--------------variables---------------------
	int order,size; // |V|,|E| values
	int init=0; //iterate
	int r=0; //random number
	string name;

	//vector to hold vertices
	list<node> O; 
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
	for( auto i = O.begin(); i!=O.end(); i++)
		cout<<i->name<<endl;

	//randomly assign adjacent nodes
	while(size!=0)
	{
	for(auto j = O.begin(); j!=O.end(); j++)
	{	
		for(auto k= O.begin(); k!=O.end(); k++)
		{	
			r=rand()%10;
			if(r==1)
			{
				j->adj(*k);
				
				size-=1;
			}
		}
		if (size==0)
			break;
	}
	}

	//list node neighbors
	cout<<"Listing Edges: "<<endl;
	for(node i: O)
	{
		cout<<"Vertice "<<i.name<<" is connected with"<<endl;
		for(node j: i.adj_list)
			cout<<j.name<<endl;
	}

	string input;
	node temp = O.front();
	BFS(temp);
	cout<<"Find shortest paths from :"<<endl;
	cin>>input;

	for(auto i = O.begin(); i!= O.end(); i++)
	{
		if(i->name==input)
		{
			for (auto m = i->adj_list.begin(); m!=i->adj_list.end(); m++)
			{
	
				while(m->parent!=NULL)
				cout<<m->name<<endl;
				
			}
		
		}
	
	}

	

	
	
};

void BFS(node root)
{	
	int distance=0;
	queue<node> q; //create q;
	q.push(root); //push root
	root.parent=&root; //root parent=itself;
	root.dist=distance;
	while(!q.empty())
	{
		node n=q.front();
		q.pop();

		for(auto x = n.adj_list.begin(); x!=n.adj_list.end(); x++)
		{
			if(x->parent==NULL)
			{	distance=distance+1;
				x->parent=&n;
				cout<<x->parent<<" ";
				x->dist=distance;
				q.push(*x);
			}
		}
	}
	root.parent=NULL;

}

void DFS(list<node> n)
{
	for(node s: n)
	{
		if(s.parent ==NULL)
		{
			s.parent=&s;
			DFS_visit(s);
		}
	}	
}

bool DFS_visit(node s)
{
	timer++;
	s.start=timer;
	for(node v : s.adj_list)
	{
		if(v.start==-1)
		{
			v.parent=&s;
			DFS_visit(v);
		}
		else if(v.start!=-1 && v.end==-1)
		{
			cout<<"CYCLE DETECTED";
			return true;
		}
	}
	s.end=timer;
	return false;
}

