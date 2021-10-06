#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <stack>

using Vertex = int;

class Graph {
public:
    explicit Graph(int vertices_num) :
        vertices_num_(vertices_num), edges_(vertices_num), all_vertices_(vertices_num) {
            for (int i = 0; i < vertices_num; ++i) {
                all_vertices_[i] = i;
            }
        };

    void AddEdge(Vertex from, Vertex to) {
        edges_[from].push_back(to);
    };

    const std::vector<Vertex>& GetAllVertices() {
        return all_vertices_;
    };

    const std::vector<Vertex>& GetAdjacentVertices(Vertex vertex) {
        return edges_[vertex];
    };

private:
    int vertices_num_;
    std::vector<std::vector<Vertex>> edges_;
    std::vector<Vertex> all_vertices_;
};

class GraphReader {
public:
    virtual void Read() = 0;
    virtual Graph GetGraph() = 0;
};

class GraphReaderEdges: public GraphReader {
public:
    GraphReaderEdges(int vertices_num) : vertices_num_(vertices_num), graph_(vertices_num_) {};

    void Read() override {
        int edges_num;
        std::cin >> edges_num;
        Vertex from, to;
        for (int i = 0; i < edges_num; ++i){
                std::cin >> from >> to;
                graph_.AddEdge(from, to);
        }

    };

    Graph GetGraph() override {
       return graph_;
    };

private:
    int number_of_vertices_;
    Graph graph;
};

class GraphReaderAdjacency: public GraphReader {
public:
    GraphReaderAdjacency(int vertices_num) : number_of_vertices_(vertices_num), graph_(number_of_vertices_) {};

    void Read() override {
        int num;
        Vertex to;
        for (int from = 0; from < edges_num; ++from) {
            std::cin >> num;
            for (int j = 0; j < num; ++j) {
                std::cin >> to;
                graph.AddEdge(i, to);
            }
        }
    };

    Graph GetGraph() override {
        return graph;
    };

private:
    int number_of_vertices_;
    Graph graph;
};

class GraphReaderMatrix: public GraphReader {
public:
    GraphReaderMatrix(int vertices_num) {
        this->vertices_num = vertices_num;
        AdjMatrix = new bool*[vertices_num];
        for (int i = 0; i < vertices_num; ++i) {
            AdjMatrix[i] = new bool[vertices_num];
            for (int j = 0; j < vertices_num; ++j)
                AdjMatrix[i][j] = false;
        }
    }

    void RemoveEdge(int i, int j) {
        AdjMatrix[i][j] = false;
        AdjMatrix[j][i] = false;
    }

    void IsEdge(int i, int j) {
        return AdjMatrix[i][j];
    }

    Graph GetGraph() override {
        return graph;
    };

private:
    bool** AdjMatrix;
    int vertices_num;
    Graph graph;
};

enum class NodeState { kNotSeen, kSeen, Visited };

void DepthFirstSearch(int vertex, Graph& graph,
                       std::vector<kNodeState>& states, std::stack<int>& stack) {
                           if (states[vertex] == kNodeState::kNotSeen) {
                               states[vertex] == kNodeState::kSeen;
                               for (int i = 0; i < graph.GetAdjacentVertices(vertex).size(); i++)
                                DepthFirstSearch(graph.GetAdjacentVertices(vertex)[i], graph, states, stack);
                               states[vertex] = kNodeState::Visited;
                               stack.push(vertex);
                               }

}

void TopologicalSearch(Graph& graph, int vertices_num)
{
    std::vector<kNodeState> states (vertices_num, kNodeState::kNotSeen);
    std::stack<int> stack;
    for (int next = 0; next < vertices_num; ++next) {
        if (states[next] == kNodeState::kNotSeen) {
            DepthFirstSearch(next, graph, states);
            if (states[next] == kNodeState::kNotSeen) {
                states[next] = kNodeState::Visited;
                std::stack.push(next);
            }
        }
    }
    std::cout << "Sorted graph";
    while (stack.empty() != true) {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    throw std::runtime_error("Not implemented");
}

int main() {
    std:::string type;
    Vertex vertices_num, edges_num;
    std::cin >> type;
    std::cin >> vertices_num;
    Graph graph(vertices_num);
    if (type == "Edge") {
        GraphReaderEdges edge(vertices_num);
        graph = edge.GetGraph();
        TopologicalSearch(graph, vertices_num);
    }
    if (type == "Adjacency") {
        GraphReaderAdjacency adjacency(vertices_num);
        graph = adjacency.GetGraph();
        TopologicalSearch(graph, vertices_num);
    }
    if (type == "Matrix") {
        GraphReaderMatrix matrix(vertices_num);
        graph = matrix.GetGraph();
        TopologicalSearch(graph, vertices_num);
    }

    return 0;
}
