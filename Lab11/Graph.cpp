/*
 * File: Graph.cpp
 * Course: CS218-1
 * Project: Lab 11
 * Description: Implementation of the Graph class
 */

#include <queue>
#include "Graph.h"

// default constructor
Graph::Graph() {
}

// check whether there is an edge connecting x and y
bool Graph::hasEdge(char x, char y) const {
    // verify y appears in adjacency list for x
    return adjMap.at(x).find(y) != adjMap.at(x).end();
}

// insert an undirected link between x and y
void Graph::addEdge(char x, char y) {
    adjMap[x].insert(y);   // store y under x
    adjMap[y].insert(x);   // store x under y
}

// Breadth-first search to determine the minimum number of hops
// between start s and goal t.
// Returns INVALID_VERTEX (-2) if either endpoint is not present,
// returns NOPATH (-1) if s cannot reach t.
// Fills:
//   distance[k] = shortest steps from s to k
//   go_through[k] = next vertex on the route from k back toward s
int Graph::BFS(char s, char t, map<char, int>& distance, map<char, char>& go_through) const {
    // ensure both vertices are valid
    if (adjMap.find(s) == adjMap.end() || adjMap.find(t) == adjMap.end()) {
        return INVALID_VERTEX;
    }

    // initialize all distances to NOPATH
    for (map<char, set<char>>::const_iterator it = adjMap.begin(); it != adjMap.end(); ++it) {
        distance[it->first] = NOPATH;
    }

    queue<char> q;
    distance[s] = 0;
    go_through[s] = s;
    q.push(s);

    char curr;

    // BFS loop
    while (!q.empty() && curr != t) {
        curr = q.front();
        q.pop();

        for (set<char>::iterator nbr = adjMap.at(curr).begin(); nbr != adjMap.at(curr).end(); ++nbr) {
            if (distance[*nbr] == NOPATH) {
                distance[*nbr] = distance[curr] + 1;
                go_through[*nbr] = curr;
                q.push(*nbr);
            }
        }
    }

    return distance[t];
}
