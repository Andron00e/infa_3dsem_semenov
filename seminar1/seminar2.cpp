#include <iostream>
#include <vector>
#include <stdexcept>

using Vertex = int;

void Read (int size, vector<vector><int>)   //imnsr считывает из консоли, а Get Graph создает об кл граф



//
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
    //Get_Graph

private:
    int vertices_num_;
    std::vector<std::vector<Vertex>> edges_;
    std::vector<Vertex> all_vertices_;
};

// add dfs visitor methods as per
// https://www.boost.org/doc/libs/1_63_0/libs/graph/doc/DFSVisitor.html
class DfsVisitor { };

// write dfs, don't change signature (name, arguments and return type)
// visitor should be called as appropriate
void DepthFirstSearch(const Graph& graph, DfsVisitor& visitor) {
    throw std::runtime_error("Not implemented");
};

// implement DfsVisitor interface and GetComponentsNumber
class WeakConnectivityComponentsVisitor : public DfsVisitor {
public:
    int GetComponentsNumber() {
        throw std::runtime_error("Not implemented");
    }
};

// implement DfsVisitor interface and WasCycleFound
class CycleFinderVisitor : public DfsVisitor {
public:
    bool WasCycleFound() {
        throw std::runtime_error("Not implemented");
    }
};

// implement DfsVisitor interface and GetTopologicalSort
class TopologicalSortVisitor : public DfsVisitor {
public:
    std::vector<Vertex> GetTopologicalSort() {
        throw std::runtime_error("Not implemented");
    }
};

int main() {
    int vertices_num, edges_num;
    std::cin >> vertices_num >> edges_num;

    Graph graph(vertices_num);
    for (int i = 0; i < edges_num; ++i) {
        Vertex from, to;
        std::cin >> from >> to;
        graph.AddEdge(from, to);
    }

    WeakConnectivityComponentsVisitor conn_visitor;
    DepthFirstSearch(graph, conn_visitor);
    std::cout << "number of weakly connected components is " <<
        conn_visitor.GetComponentsNumber() << std::endl;

    CycleFinderVisitor cycle_visitor;
    DepthFirstSearch(graph, cycle_visitor);
    if (cycle_visitor.WasCycleFound()) {
        std::cout << "there's at least one cycle" << std::endl;
    } else {
        std::cout << "there're no cycles" << std::endl;
    }

    TopologicalSortVisitor sort_visitor;
    DepthFirstSearch(graph, sort_visitor);
    auto sorted = sort_visitor.GetTopologicalSort();
    std::cout << "topological sort:" << std::endl;
    for (auto v : sorted) {
        std::cout << v << ' ';
    }
    std::cout << std::endl;

    return 0;
}
