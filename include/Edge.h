#ifndef EDGE_H
#define EDGE_H

//#include "Vertex.h"
class Vertex;
class Edge
{
    public:
        Edge();
        Edge(Vertex*, Vertex*, int);
        Edge(int, Vertex*, int, Vertex*, int);
        int cost;
        int sourceName, targetName;
        Vertex *source, *target;
    protected:
    private:
};

#endif // EDGE_H
