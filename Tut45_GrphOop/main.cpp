/*
 * main.cpp
 *
 *  Created on: Nov 2, 2016
 *      Author: modys
 */
#include"Graph.h"

int main()
{
	// create the graph given in above fugure
	int V = 4;
	Graph g(V);

	//  making above shown graph
	g.addEdge(0, 1, 2);
	g.addEdge(1, 2, 4);
	g.addEdge(1, 3, 1);
	g.addEdge(2, 3, 5);
	g.addEdge(3, 0, 3);

	g.displayGraph();

	cout<<"path"<<endl;
	g.getShortestPath(0);

	return 0;
}




