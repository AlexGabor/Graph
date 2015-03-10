#ifndef GRAPH_H
#define GRAPH_H

#include <cstdio>
#include "Vertex.h"
#include "Edge.h"


class Graph
{

    public:
        typedef vector<Edge*>::iterator iterator;
        Graph();
        void read(FILE*);
        int getNumberOfVertices();
        int getNumberOfEdges();
        Edge *getEdge(int source, int target);
        int getInDegree(int vertex);
        int getOutDegree(int vertex);
        iterator outboundBegin(int vertex);
        iterator outboundEnd(int Vertex);
        iterator inboundBegin(int vertex);
        iterator inboundEnd(int Vertex);
    protected:
    private:
        int number_of_vertices, number_of_edges;
        vector<Edge*> edges;
        vector<Vertex> vertices;
};

#endif // GRAPH_H
