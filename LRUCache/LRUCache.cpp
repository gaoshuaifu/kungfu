#include <iostream>
#include <vector>
#include <map>
using namespace std;

template<class K, class T>
struct Node{
  K key;
  T data;
  Node* prev;
  Node* next;
};

template<class K, class T>
class LRUCache{
private:
  Node<K, T>* nodes;
  vector<Node<K, T>* > freeNodes;
  map<K, Node<K, T>* > mapping;
  Node<K, T>* head;
  Node<K, T>* tail;

public:
  LRUCache(size_t size){
    nodes = new Node<K, T>[size];
    for(int i = 0; i < size; i++)
      freeNodes.push_back(nodes + i);
    head = new Node<K, T>;
    tail = new Node<K, T>;
    head->prev = NULL;
    head->next = tail;
    tail->prev = head;
    tail->next = NULL;
  }

  ~LRUCache(){
    delete[] nodes;
    delete head;
    delete tail;
  }

  bool containsKey(K key){
    return mapping.find(key) != mapping.end();
  }

  void put(K key, T data){
    if(mapping.find(key) != mapping.end())
      return;

    Node<K, T>* node;
    if(freeNodes.size() > 0){
      node = freeNodes.back();
      freeNodes.pop_back();
    }
    else{
      node = tail->prev;
      node->prev->next = node->next;
      node->next->prev = node->prev;
      mapping.erase(node->key);
    }

    mapping[key] = node;
    node->key = key;
    node->data = data;

    node->prev = head;
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
  }

  T get(K key){
    Node<K, T>* node = mapping[key];
    node->prev->next = node->next;
    node->next->prev = node->prev;
    node->prev = head;
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
    return node->data;
  }

  void print(){
    Node<K, T>* node = head->next;
    while(node != tail){
      cout << node->data << " ";
      node = node->next;
    }
    cout << endl;
  }
};

int main(){
  LRUCache<char, char> cache(5);

  cache.put('A', 'a');
  cache.print();

  cache.put('B', 'b');
  cache.print();

  cache.put('C', 'c');
  cache.print();

  cache.put('D', 'd');
  cache.print();

  cache.put('E', 'e');
  cache.print();

  cache.put('F', 'f');
  cache.print();

  cache.get('B');
  cache.print();

  cache.put('G', 'g');
  cache.print();

  return 0;
}
