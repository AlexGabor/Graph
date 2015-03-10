#include "Edge.h"

Edge::Edge()
{
    //ctor
}

Edge::Edge(Vertex *source, Vertex *target, int cost) {
    this->source = source;
    this->target = target;
    this->cost = cost;
}

Edge::Edge(int sourceName, Vertex *source, int targetName, Vertex *target, int cost) {
    this->sourceName = sourceName;
    this->targetName = targetName;
    this->source = source;
    this->target = target;
    this->cost = cost;
}
