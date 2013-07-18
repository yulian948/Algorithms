#include "floyd.h"

Floyd::Floyd() :distances(NULL),routes(NULL){}
Floyd::Floyd(int n):number(n)
{
	distances = new int*[number];
	routes = new unsigned int*[number];
	for(unsigned int i = 0;i<number;i++)
	{
		distances[i]=new int[number];
		routes[i]=new unsigned int[number];
	}
	for(unsigned int i = 0;i<number;i++)
	{
		for(unsigned int j = 0;j<number;j++)
		{
			routes[i][j]=j+1;
		}
	}
}
Floyd::~Floyd()
{
	for(unsigned int i = 0;i<number;i++)
	{
		delete []distances[i];
		delete []routes[i];
	}
	delete []distances;
	delete []routes;
}
Floyd::Floyd(Floyd& f)
{
	number = f.number;
	distances = new int*[number];
	routes = new unsigned int*[number];
	for(unsigned int i = 0;i<number;i++)
	{
		distances[i]=new int[number];
		routes[i]=new unsigned int[number];
	}
	for(unsigned int i = 0;i<number;i++)
		for(unsigned int j = 0;j<number;j++)
		{
			distances[i][j]=f.distances[i][j];
			routes[i][j]=f.routes[i][j];
		}
}
void Floyd::setNumber(int n)
{
	number = n;
}
void Floyd::input()
{
	cout<<"Input adjacency matrix (infinite = max(a[i][j])+1) : "<<endl;
	for(unsigned int i = 0;i<number;i++)
		for(unsigned int j = 0;j<number;j++)
		{
			cin>>distances[i][j];
		}
}
void Floyd::output()
{
	cout<<"Distances matrix: "<<endl;
	for(unsigned int i = 0;i<number;i++)
	{
		for(unsigned int j = 0;j<number;j++)
		{
			cout.width(3);
			cout<<distances[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Routes matrix: "<<endl;
	for(unsigned int i = 0;i<number;i++)
	{
		for(unsigned int j = 0;j<number;j++)
		{
			cout.width(3);
			cout<<routes[i][j]<<" ";
		}
		cout<<endl;
	}

}
int Floyd::min(int a,int b)
{
	return a<=b?a:b;
}
void Floyd::solve()
{
	static int l=1;
	if(l == number)
	{
		output();
	}
	else 
	{
		for(unsigned int i = 0;i<number;i++)
			for(unsigned int j = 0;j<number;j++)
			{
				if(i!=l && j!=l)
				{
					int lastDist = distances[i][j];
					distances[i][j] = min(distances[i][j],(distances[i][l]+distances[l][j]));
					if(distances[i][j]<lastDist)
					{
						routes[i][j] = l;
					}
				}
			}
		l++;
		solve();
	}
}