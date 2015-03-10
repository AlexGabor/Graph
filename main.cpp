#include <cstdio>
#include <vector>

#include "Graph.h"

using namespace std;

Graph graph;

void exists(int source, int target) {
    Edge *edge = graph.getEdge(source, target);
    if (edge == NULL)
        printf("The edge (%d, %d) doesn't exist\n", source, target);
    else
        printf("The edge (%d, %d, %d) exists\n", source, target, edge->cost);
}

void degree(int vertex) {
    printf("Vertex: %d In: %d, Out: %d\n", vertex, graph.getInDegree(vertex), graph.getOutDegree(vertex));
}

void outbound(int vertex) {
    printf("Outbound of vertex %d are: ", vertex);
    for (Graph::iterator it = graph.outboundBegin(vertex); it != graph.outboundEnd(vertex); ++it) {
        printf("%d ", (*it)->targetName);
    }
    printf("\n");
}

void inbound(int vertex) {
    printf("Inbound of vertex %d are: ", vertex);
    for (Graph::iterator it = graph.inboundBegin(vertex); it != graph.inboundEnd(vertex); ++it) {
        printf("%d ", (*it)->sourceName);
    }
    printf("\n");
}

int main () {

    FILE *file = fopen("graph1m.txt", "r");
    //FILE *file = fopen("data.in", "r");

    graph.read(file);
    printf("V: %d E: %d\n", graph.getNumberOfVertices(), graph.getNumberOfEdges());

    exists(0, 0);
    exists(0, 1);
    exists(1, 2);
    exists(2, 1);
    exists(1, 3);
    exists(2, 3);

    exists(9, 9);
    exists(5, 0);

    printf("\n");

    degree(0);
    degree(1);
    degree(2);
    degree(3);
    degree(4);

    printf("\n");

    outbound(0);
    outbound(1);
    outbound(2);
    outbound(3);
    outbound(4);

    printf("\n");

    inbound(0);
    inbound(1);
    inbound(2);
    inbound(3);
    inbound(4);

    printf("\n");



    return 0;
}

