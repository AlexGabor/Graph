#include "Graph.h"

Graph::Graph()
{
    //ctor
}

void Graph::read(FILE *file) {
    int source, target, cost;
    Edge *edge;

    fscanf(file, "%d %d", &number_of_vertices, &number_of_edges);
    vertices.resize(number_of_vertices);
    for (int i=0; i<number_of_edges; ++i) {
        fscanf(file, "%d %d %d", &source, &target, &cost);
        edge = new Edge(source, &vertices[source], target, &vertices[target], cost);
        edges.push_back(edge);
        vertices[source].out.push_back(edge);
        vertices[target].in.push_back(edge);
    }
}

int Graph::getNumberOfVertices() {
    return number_of_vertices;
}

int Graph::getNumberOfEdges() {
    return number_of_edges;
}

Edge* Graph::getEdge(int source, int target) {
    if (source >= number_of_vertices)
        return NULL;
    unsigned int len = vertices[source].out.size();
    for (int i=0; i<len; ++i) {
        Edge* e = vertices[source].out[i];
        if (e->targetName == target)
            return vertices[source].out[i];
    }
    return NULL;
}

int Graph::getInDegree(int vertex) {
    if (vertex >= number_of_vertices)
        return -1;
    return vertices[vertex].in.size();
}

int Graph::getOutDegree(int vertex) {
    if (vertex >= number_of_vertices)
        return -1;
    return vertices[vertex].out.size();
}

Graph::iterator Graph::outboundBegin(int vertex) {
    /*
     *  the vertex must exists!
     */
    return vertices[vertex].out.begin();
}

Graph::iterator Graph::outboundEnd(int vertex) {
    /*
     *  the vertex must exists!
     */
    return vertices[vertex].out.end();
}

Graph::iterator Graph::inboundBegin(int vertex) {
    /*
     *  the vertex must exists!
     */
    return vertices[vertex].in.begin();
}

Graph::iterator Graph::inboundEnd(int vertex) {
    /*
     *  the vertex must exists!
     */
    return vertices[vertex].in.end();
}
