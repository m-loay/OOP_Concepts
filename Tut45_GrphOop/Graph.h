/*
 * Graph.h
 *
 *  Created on: Nov 2, 2016
 *      Author: modys
 */

#ifndef GRAPH_H_
#define GRAPH_H_
#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility>
#include <map>
#include <set>
#include<vector>
#define INF 1000
using namespace std;
typedef map<int, int> *graph_p ,graph_t;
typedef set<pair<int,int> >setd;

class Graph
{
public:
	Graph(int v)
{
		numVert=v;
		numEdge=0;
		graph = new graph_t[v];
		cout<<"Graph Called"<<endl;
}

	virtual ~Graph()
	{
		cout<<"~Graph Called"<<endl;
		delete []graph;

	}

	void addEdge(int src , int dest , int weight)
	{
		pair<graph_t::iterator,bool> ret;
		ret =graph[src].insert(graph_t::value_type(dest,weight));
		if(ret.second == true)
			numEdge++;
	}

	void removeEdge(int src , int dest)
	{
		graph_t::iterator it;
		it = graph[src].find(dest);
		if(it!=graph[src].end())
		{
			graph[src].erase(it);
			numEdge--;
		}
	}

	void removeVertex(int src)
	{
		int num;
		num = graph[src].size();
		numEdge-=num;
		numVert--;
		graph[src].clear();
	}

	void getShortestPath (int src)
	{

		setd setds;
		vector<int> dist(numVert, INF);
		set <int>* parent = new set<int>[numVert];

		setds.insert(make_pair(0, src));
		dist[src] = 0;
		parent[0].insert(0);

		while (!setds.empty())
		{
			/*Get the minmum distance node (label,weight) from the stored set*/
			pair<int, int> tmp = *(setds.begin());
			setds.erase(setds.begin());

			int u = tmp.second;

			// 'i' is used to get all adjacent vertices of a vertex
			graph_t::const_iterator i;
			for (i = graph[u].begin(); i != graph[u].end(); i++)
			{
				if(!graph[u].empty())
				{

					int v = i->first;
					int weight = i->second;

					if (dist[v] > dist[u] + weight)
					{
						if (dist[v] != INF)
							setds.erase(setds.find(make_pair(dist[v], v)));

						// Updating distance of v
						//parent[v]  = u;
						dist[v] = dist[u] + weight;
						setds.insert(make_pair(dist[v], v));
						parent[v].insert(u);
					}
				}
			}
		}

		cout<<"Vertex   Distance from Source"<<endl;
		for (int i = 0; i < numVert; ++i)
			cout<<i<<" "<<dist[i]<<endl;
	}


	void displayGraph()const
	{
		graph_t::const_iterator it;
		for(int i=0;i<numVert;i++)
		{
			if(!graph[i].empty())
			{
				it = graph[i].begin();
				cout<<i<<": ";
				while(it!=graph[i].end())
				{
					cout<<it->first<<" ";
					it++;
				}
				cout<<endl;
			}
		}

	}


	int getNumVert()const
	{
		return numVert;
	}

	int getNumEdge()const
	{
		return numEdge;
	}

private:
	graph_p graph;
	int numVert;
	int numEdge;

};


#endif /* GRAPH_H_ */
