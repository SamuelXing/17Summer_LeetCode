**B-Tree**

According to Knuth's definition, a B-tree of order m is a tree which satisfies the following properties:

1. Every node has at most m children.
2. Every non-leaf node (except root) has at least ⌈m/2⌉ children.
3. The root has at least two children if it is not a leaf node.
4. A non-leaf node with k children contains k−1 keys.
5. All leaves appear in the same level

Each internal node’s keys act as separation values which divide its subtrees. For example, if an internal node has 3 child nodes (or subtrees) then it must have 2 keys: a1 and a2. All values in the leftmost subtree will be less than a1, all values in the middle subtree will be between a1 and a2, and all values in the rightmost subtree will be greater than a2.

**B+ Tree**

[B+ Tree wiki](https://en.wikipedia.org/wiki/B%2B_tree)

**B* Tree**

[B* Tree wiki](https://www.quora.com/What-are-B*trees)

**R Tree**

[R Tree wiki](https://en.wikipedia.org/wiki/R-tree)

**Comparison**

[B, B+, B*, R Tree comparison](http://blog.csdn.net/v_JULY_v/article/details/6530142)

**Red Black Tree**

[Blog Article](http://blog.csdn.net/v_july_v/article/details/6124989)
