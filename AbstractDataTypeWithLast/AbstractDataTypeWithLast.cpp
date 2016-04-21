#include <iostream>
#include <map>
using namespace std;

template <class K, class V>
struct Node {
  K k;
  V v;
  Node* prev;
  Node* next;
};

template <class K, class V>
class AbstractDataTypeWithLast {
public:
  void put(K k, V v) {
    Node<K, V>* node = touch(k);
    node->v = v;
    mp[k] = node;
  }

  V get(K k) {
    Node<K, V>* node = touch(k);
    return node->v;
  }

  void remove(K k) {
    Node<K, V>* node = touch(k);
    head = node->next;
    delete node;
    mp.erase(mp.find(k));
  }

  K last() {
    return head->k;
  }

private:
  map<K, Node<K, V>* > mp;

  Node<K, V>* head;

  Node<K, V>* touch(K k) {
    Node<K, V>* node;
    if(mp.find(k) == mp.end()) {
      node = new Node<K, V>();
      node->k = k;
    } else {
      node = mp.find(k)->second;
    }

    if(node->prev) {
      node->prev->next = node->next;
    }

    if(node->next) {
      node->next->prev = node->prev;
    }

    if(node != head) {
      node->prev = NULL;
      node->next = head;
      head = node;
    }
    return node;
  }
};

int main() {
  AbstractDataTypeWithLast<string, int> data;
  data.put("a", 1);
  cout << data.last() << endl;

  data.put("b", 2);
  cout << data.last() << endl;

  cout << data.get("a") << endl;
  cout << data.last() << endl;

  cout << data.get("b") << endl;
  cout << data.last() << endl;

  data.remove("b");
  cout << data.last() << endl;

  data.put("c", 3);
  cout << data.last() << endl;

  return 0;
}
