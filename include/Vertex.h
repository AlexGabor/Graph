#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
//#include "Edge.h"
class Edge;
using namespace std;

class Vertex
{
    public:
        Vertex();
        vector<Edge*> in, out;
    protected:
    private:
};

#endif // VERTEX_H
