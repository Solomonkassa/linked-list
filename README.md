# Linked List

A linked list is a linear data structure in which elements are stored in a non-contiguous manner. Each element, also known as a node, consists of a data field and a reference to the next node in the list. The first node is called the head of the list, while the last node has a reference to null.

## Implementations

- [Singly Linked List](./singly-linked-list.md)
- [Doubly Linked List](./doubly-linked-list.md)
- [Circular Linked List](./circular-linked-list.md)

## Operations

The following operations can be performed on a linked list:

- **Insertion**: Add a new node to the list.
- **Deletion**: Remove a node from the list.
- **Traversal**: Traverse the list and perform an operation on each node.
- **Searching**: Find a node with a given value.
- **Sorting**: Sort the list in ascending or descending order.
- **Merging**: Merge two lists into a single list.
- **Reversing**: Reverse the order of the list.
- **Splitting**: Split the list into two smaller lists.

## Advantages

- Dynamic size: A linked list can grow or shrink in size during runtime.
- Efficient insertion and deletion: Since elements are not stored in contiguous memory locations, adding or removing elements from a linked list only requires updating the references of neighboring nodes.
- No wastage of memory: The size of a linked list can be determined at runtime, and it only uses the amount of memory required to store its elements.

## Disadvantages

- Random access is not possible: To access a node at a particular index, the entire list must be traversed.
- Extra memory required for references: Each node in a linked list requires an additional reference to the next node, which can increase memory usage.

## Applications

- Implementing stacks, queues, and hash tables.
- Managing dynamic memory allocation in operating systems.
- Text editors and compilers.
- Image processing and computer graphics.

## References

- [Linked list - Wikipedia](https://en.wikipedia.org/wiki/Linked_list)
- [Linked List Data Structure - GeeksforGeeks](https://www.geeksforgeeks.org/data-structures/linked-list/)
- [Data Structures: Linked Lists - YouTube](https://www.youtube.com/watch?v=oiW79L8VYXk&list=PLdnONIhPScST0Vy4LrIZiYKpFNoxgyH7J&index=7)

