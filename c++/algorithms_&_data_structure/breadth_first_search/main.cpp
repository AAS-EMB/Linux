#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

static bool isSeller(const std::string &name) { return name.back() == 'm'; }

template <class T>
static bool search(const T &name,
                   const std::unordered_map<T, std::vector<T>> &graph) {
  std::queue<T> search_queue;
  std::unordered_set<T> searched;

  // add all friends to search queue
  for (auto &&friend_name : graph.find(name)->second)
    search_queue.push(friend_name);

  while (!search_queue.empty()) {
    T &person = search_queue.front();
    search_queue.pop();

    if (searched.find(person) == searched.end()) {
      if (isSeller(person)) {
        std::cout << person << " is a mango seller!" << std::endl;
        return true;
      }

      // add all friends of a person to search queue
      for (auto &&friend_name : graph.find(person)->second)
        search_queue.push(friend_name);

      // mark this person as searched
      searched.insert(person);
    }
  }

  return false;
}

int main(int argc, char *argv[]) {
  std::unordered_map<std::string, std::vector<std::string>> graph;
  graph.insert({"you", {"alice", "bob", "claire"}});
  graph.insert({"bob", {"anuj", "peggy"}});
  graph.insert({"alice", {"peggy"}});
  graph.insert({"claire", {"thom", "jonny"}});
  graph.insert({"anuj", {}});
  graph.insert({"peggy", {}});
  graph.insert({"thom", {}});
  graph.insert({"jonny", {}});

  std::string name = "you";
  bool result = search(name, graph);
  std::cout << "Found mango seller: " << result << std::endl;
  return 0;
}