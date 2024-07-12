#include <bits/stdc++.h>
#define array vector
#define uset unordered_set
using namespace std;

// @author: Thawan Ribeiro, 2024-07-12
// @algorithm: Kahn for Competitive Programming
// @url: https://github.com/thawan-xyz

class Graph {
private:
    const int VERTICES;
    array<uset<int>> adjacency;
    array<int> rank;

    bool is_ranked(int x) const {
        return rank[x];
    }

    void raise_rank(int x) {
        rank[x]++;
    }

    void lower_rank(int x) {
        rank[x]--;
    }

public:
    Graph(const int N) : VERTICES(N), adjacency(N), rank(N) {}

    ~Graph() = default;

    bool has_edge(int x, int y) const {
        return adjacency[x].count(y);
    }

    void set_edge(int x, int y) {
        adjacency[x].insert(y); raise_rank(y);
    }

    void del_edge(int x, int y) {
        adjacency[x].erase(y); lower_rank(y);
    }

    int num_vertices() const {
        return VERTICES;
    }

    array<int> kahn() {
        priority_queue<int, array<int>, greater<int>> priority;
        for (int x = 0; x < VERTICES; ++x) {
            if(!is_ranked(x)) priority.push(x);
        }

        array<int> result;
        while (!priority.empty()) {
            int x = priority.top(); priority.pop(); result.push_back(x);
            for (int y : adjacency[x]) {
                lower_rank(y);
                if(!is_ranked(y)) priority.push(y);
            }
        }

        if (result.size() > VERTICES) cout << "Error: There exists a cycle in the graph";
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cerr << "Thawan";
    return 0;
}
