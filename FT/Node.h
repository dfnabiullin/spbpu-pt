#ifndef NODE_H
#define NODE_H

namespace nabiullin
{
  struct Node
  {
    size_t key_;
    char value_;
    Node* left_;
    Node* right_;
    Node() = default;
    Node(char value, size_t key) : key_(key), value_(value), left_(nullptr), right_(nullptr) {}
    Node(size_t key, char value, Node* left, Node* right) : key_(key), value_(value), left_(left), right_(right) {}
    Node(Node* left, Node* right)
    {
      value_ = '\0';
      left_ = left;
      right_ = right;
      key_ = left->key_ + right->key_;
    }
  };

  bool sortNode(Node* first, Node* second);
}
#endif
