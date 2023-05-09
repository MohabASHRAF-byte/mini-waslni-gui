
#ifndef NODE_H
#define NODE_H
#include"Point.h"
#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    Point point;
    Node(string name, int x, int y) {
        this->name = name;
        this->point.x = x;
        this->point.y = y;
    }
    int id;
    string name;
    map<string, int> edges; // {to , distance }
};
#endif // NODE_H
