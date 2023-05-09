
#ifndef MAP_H
#define MAP_H
#pragma once
#include <bits/stdc++.h>
#include "Point.h"
#include "Node.h"
#include "NodeConverter.h"
class Map{
    map<string,Node*>graph;

    //used for the algorithms to work on single numbers instead of the whole node
    map<int,set<int>>convertedGraph;
    map<int,string> IdToName;

public:
    Map();

    void addCity();
    void deleteCity();
    void addEdge();
    void deleteEdge();
    void deleteMap();
    void displayMap();

    map<int,set<int>> getConvertedGraph(){
        return convertedGraph;
    }
    map<int,string >getIdToName(){
        return IdToName;
    }
    map<string,Node*> getGraph(){
        return graph;
    }
    map<string,Node*>& getGraphAddress(){
        return graph;
    }
    map<int,set<int>>& getConvertedGraphAddress(){
        return convertedGraph;
    }
    map<int,string >&getIdToNameAddress(){
        return IdToName;
    }
    ~Map();
};
#endif // MAP_H
