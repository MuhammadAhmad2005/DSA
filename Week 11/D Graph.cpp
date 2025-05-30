#include <iostream>
#include<stack>
#include<queue>
using namespace std;

class Vertex; // Forward declaration

class Edge {
public:
	Edge(Vertex* end, Edge* next) : end(end), next(next) {}
	~Edge() {}
	Vertex* getEnd() { return end; }
	Edge* getNext() { return next; }
	void print();

private:
	Vertex* end;
	Edge* next;
};

class Vertex {
public:
	Vertex(char data, Vertex* next = nullptr) : data(data), edges(nullptr), next(next) {}
	~Vertex();
	char getData() { return data; }
	Edge* getFirstEdge() { return edges; }
	Vertex* getNext() { return next; }
	void connectTo(Vertex* dest);
	void printEdges();
	void printGraph();

private:
	char data;
	Edge* edges;
	Vertex* next;
};

void Edge::print() {
	cout << " -> " << end->getData();
}

Vertex::~Vertex() {
	while (edges) {
		Edge* temp = edges;
		edges = edges->getNext();
		delete temp;
	}
}

void Vertex::connectTo(Vertex* dest) {
	edges = new Edge(dest, edges);
}

void Vertex::printEdges() {
	Edge* curr = edges;
	while (curr) {
		curr->print();
		curr = curr->getNext();
	}
}

void Vertex::printGraph() {
	cout << data;
	printEdges();
	cout << endl;
}

class Graph {
public:
	Graph() : first(nullptr) {}
	~Graph();
	Vertex* find(char);
	bool AddVertex(char);
	bool AddEdge(char from, char to);
	void print();
	void DFS(char start);
	void BFS(char start);
private:
	Vertex* first;
};

Graph::~Graph() {
	while (first) {
		Vertex* temp = first;
		first = first->getNext();
		delete temp;
	}
}

Vertex* Graph::find(char data) {
	Vertex* curr = first;
	while (curr) {
		if (curr->getData() == data)
			return curr;
		curr = curr->getNext();
	}
	return nullptr;
}

bool Graph::AddVertex(char data) {
	if (find(data))
		return false;
	first = new Vertex(data, first);
	return true;
}

bool Graph::AddEdge(char from, char to) {
	Vertex* vFrom = find(from);
	Vertex* vTo = find(to);
	if (!vFrom || !vTo)
		return false;
	vFrom->connectTo(vTo);
	return true;
}

void Graph::print() {
	Vertex* curr = first;
	while (curr) {
		curr->printGraph();
		curr = curr->getNext();
	}
}

void Graph::DFS(char start) {
	Vertex* startVertex = find(start);
	if (!startVertex) {
		cout << "Start vertex not found.\n";
		return;
	}

	bool visited[256] = { false };
	stack<Vertex*> s;
	s.push(startVertex);

	while (!s.empty()) {
		Vertex* curr = s.top();
		s.pop();

		char data = curr->getData();
		if (visited[(unsigned char)data])
			continue;

		cout << data << " ";
		visited[(unsigned char)data] = true;

		for (Edge* e = curr->getFirstEdge(); e != nullptr; e = e->getNext()) {
			Vertex* neighbor = e->getEnd();
			if (!visited[(unsigned char)neighbor->getData()]) {
				s.push(neighbor);
			}
		}
	}
	cout << endl;
}

void Graph::BFS(char start) {
	Vertex* startVertex = find(start);
	if (!startVertex) {
		cout << "Start vertex not found.\n";
		return;
	}

	bool visited[256] = { false };
	queue<Vertex*> q;
	q.push(startVertex);
	visited[(unsigned char)startVertex->getData()] = true;

	while (!q.empty()) {
		Vertex* curr = q.front();
		q.pop();

		cout << curr->getData() << " ";

		for (Edge* e = curr->getFirstEdge(); e != nullptr; e = e->getNext()) {
			Vertex* neighbor = e->getEnd();
			char data = neighbor->getData();
			if (!visited[(unsigned char)data]) {
				visited[(unsigned char)data] = true;
				q.push(neighbor);
			}
		}
	}
	cout << endl;
}

int main() {
	Graph g;

	// Add vertices
	g.AddVertex('A');
	g.AddVertex('B');
	g.AddVertex('C');
	g.AddVertex('D');
	g.AddVertex('E');

	// Add edges (directed)
	g.AddEdge('A', 'B');
	g.AddEdge('A', 'C');
	g.AddEdge('B', 'D');
	g.AddEdge('C', 'D');
	g.AddEdge('D', 'E');

	// Print the adjacency list
	cout << "Graph Adjacency List:\n";
	g.print();

	// Perform DFS from vertex A
	cout << "\nDepth-First Search (starting from A):\n";
	g.DFS('A');

	// Perform BFS from vertex A
	cout << "\nBreadth-First Search (starting from A):\n";
	g.BFS('A');

	return 0;
}
