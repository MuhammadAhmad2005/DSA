#include <iostream>
using namespace std;

#define MAXVER 5

// Static Array Representation
struct vertex {
    string label; // Simple information associated with each vertex
};

struct edge {
    bool adj = false; // Whether there's an edge
    int weight = 0;   // Weight of the edge
};

class graph {
private:
    vertex vertices[MAXVER];
    edge g[MAXVER][MAXVER];
    bool adj[MAXVER][MAXVER] = { false }; // Adjacency matrix

public:
    void join(int vertex1, int vertex2) {
        adj[vertex1][vertex2] = true;
        g[vertex1][vertex2].adj = true;
        g[vertex1][vertex2].weight = 1; // default weight
    }

    void remove(int vertex1, int vertex2) {
        adj[vertex1][vertex2] = false;
        g[vertex1][vertex2].adj = false;
        g[vertex1][vertex2].weight = 0;
    }

    bool adjacent(int vertex1, int vertex2) {
        return adj[vertex1][vertex2];
    }

    void jointwt(int vertex1, int vertex2, int wt) {
        adj[vertex1][vertex2] = true;
        g[vertex1][vertex2].adj = true;
        g[vertex1][vertex2].weight = wt;
    }

    void InsertEdge(vertex v, vertex u) {
        int vIndex = -1, uIndex = -1;
        for (int i = 0; i < MAXVER; i++) {
            if (vertices[i].label == v.label) vIndex = i;
            if (vertices[i].label == u.label) uIndex = i;
        }
        if (vIndex != -1 && uIndex != -1) {
            join(vIndex, uIndex);
        }
        else {
            cout << "Vertex not found\n";
        }
    }

    void DeleteEdge(vertex v, vertex u) {
        int vIndex = -1, uIndex = -1;
        for (int i = 0; i < MAXVER; i++) {
            if (vertices[i].label == v.label) vIndex = i;
            if (vertices[i].label == u.label) uIndex = i;
        }
        if (vIndex != -1 && uIndex != -1) {
            remove(vIndex, uIndex);
        }
        else {
            cout << "Vertex not found\n";
        }
    }

    void IsEmpty() {
        bool empty = true;
        for (int i = 0; i < MAXVER; i++) {
            for (int j = 0; j < MAXVER; j++) {
                if (adj[i][j]) {
                    empty = false;
                    break;
                }
            }
        }
        if (empty) cout << "Graph is empty\n";
        else cout << "Graph is not empty\n";
    }

    // Optional: for testing or display
    void AddVertex(int index, string label) {
        if (index >= 0 && index < MAXVER) {
            vertices[index].label = label;
        }
    }

    void PrintGraph() {
        cout << "Adjacency Matrix with Weights:\n";
        for (int i = 0; i < MAXVER; i++) {
            for (int j = 0; j < MAXVER; j++) {
                if (g[i][j].adj)
                    cout << g[i][j].weight << "\t";
                else
                    cout << "0\t";
            }
            cout << "\n";
        }
    }

    void printAdjMatrix() {
        cout << "\nAdjacency Matrix (1 = edge exists, 0 = no edge):\n";
        for (int i = 0; i < MAXVER; i++) {
            for (int j = 0; j < MAXVER; j++) {
                cout << (adj[i][j] ? 1 : 0) << "\t";
            }
            cout << endl;
        }
    }

    void printWeightMatrix() {
        cout << "\nWeight Matrix (0 = no edge):\n";
        for (int i = 0; i < MAXVER; i++) {
            for (int j = 0; j < MAXVER; j++) {
                cout << g[i][j].weight << "\t";
            }
            cout << endl;
        }
    }


};

int main() {
    graph g;

    // Step 1: Add some vertices with labels
    g.AddVertex(0, "A");
    g.AddVertex(1, "B");
    g.AddVertex(2, "C");

    // Step 2: Check if graph is empty
    g.IsEmpty(); // Should print "Graph is empty"

    // Step 3: Join A -> B and A -> C with default weight
    g.join(0, 1); // A to B
    g.join(0, 2); // A to C

    // Step 4: Check adjacency
    cout << "A is adjacent to B: " << (g.adjacent(0, 1) ? "Yes" : "No") << endl;
    cout << "B is adjacent to C: " << (g.adjacent(1, 2) ? "Yes" : "No") << endl;

    // Step 5: Add weighted edge from B -> C
    g.jointwt(1, 2, 5); // B to C with weight 5

    // Step 6: Check if graph is empty again
    g.IsEmpty(); // Should print "Graph is not empty"

    // Step 7: Print the graph
    g.PrintGraph();

    // Step 8: Insert edge using vertex labels
    vertex v1, v2;
    v1.label = "C";
    v2.label = "A";
    g.InsertEdge(v1, v2); // Insert edge C -> A

    // Step 9: Print the updated graph
    cout << "\nAfter inserting edge C -> A:\n";
    g.PrintGraph();

    // Step 10: Delete edge C -> A
    g.DeleteEdge(v1, v2);

    // Step 11: Print the graph after deletion
    cout << "\nAfter deleting edge C -> A:\n";
    g.PrintGraph();
    g.printAdjMatrix();
    g.printWeightMatrix();

    return 0;
}
