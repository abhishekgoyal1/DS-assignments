In this, a modified AVL tree class is designed and implemented. The modified
AVL tree stores entries with integer keys and string values (e.g. roll no and name). The
modified AVL Tree class is defined in mavl.hpp. In addition to the standard AVL Tree
functions, the MAVL class supports the additional following functions:
● delete_by_place(int i): Delete from the entry at the ith place (as determined by the order
of insertion) among the elements that are in the tree at that moment.
● get_place(int k): Return the place (which is determined by the order of insertion) of x
among the elements that are in the ADT at that moment. If x does not exist, return -1.

The new functions are implemented to be achieved in O(n) time.
