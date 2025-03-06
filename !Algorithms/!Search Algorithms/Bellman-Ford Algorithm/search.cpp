#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

struct Node{
  const int id;
  vector<pair<int, int>> neighborsId_weight;
  int bestPath = INT_MAX;
  int bestPath2ndIteration;

  Node(const int& id) : id(id){};
};

void bellman_ford(const int& startId, vector<Node>& nodes){
  nodes.at(startId).bestPath = 0;
  
  for(int i = 0; i < nodes.size(); i++){ // First iteration
    for(Node& node : nodes){
      if(node.bestPath == INT_MAX) continue;
      for(const auto& [neighborId, pathWeight] : node.neighborsId_weight){
        Node& neighbor = nodes.at(neighborId);
        const int totalWeight = node.bestPath + pathWeight;
        if(totalWeight < neighbor.bestPath) neighbor.bestPath = totalWeight;
      }
    }
  }

  for(Node& node : nodes){ // Assign first iteration solutions to second iteration solutions
    node.bestPath2ndIteration = node.bestPath;
  }
  for(int i = 0; i < nodes.size(); i++){
    for(Node& node : nodes){ // Second iteration
      if(node.bestPath2ndIteration == INT_MAX) continue;
      for(const auto& [neighborId, pathWeight] : node.neighborsId_weight){
        Node& neighbor = nodes.at(neighborId);
        const int totalWeight = node.bestPath2ndIteration + pathWeight;
        if(totalWeight < neighbor.bestPath2ndIteration) neighbor.bestPath2ndIteration = totalWeight;
      }
    }
  }
  for(Node& node : nodes){ // Check if first iteration == second iteration. If not, assign INT_MIN
    if(node.bestPath2ndIteration != node.bestPath) node.bestPath = INT_MIN;
  }
}

int main(){
  vector<Node> nodes;
  
  ifstream fin("file.in");
  int v; fin >> v;
  for(int i = 0; i < v; i++){
    nodes.emplace_back(i);
  }
  int from, to, weight;
  while(fin >> from >> to >> weight){
    nodes.at(from).neighborsId_weight.emplace_back(to, weight);
  }
  fin.close();

  bellman_ford(0, nodes);

  for(Node& node : nodes){
    cout << "Best path from 0 to node " << node.id << ": " << node.bestPath << endl;
  }
  return 0;
}