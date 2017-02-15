# Projject

## Personal Details
[Athanasopoulos George](https://github.com/Geotha)

[Karatsenidis Konstantinos](https://github.com/gate2k1)

[Papachristou Anna](https://github.com/anniepap)

## Compile Instructions
Every part produces its own output. 
> ./out  (part1)

> ./out1 (part2)

> ./out2 (part3)

### Derive exe file
>make all

### Remove object and executable files
>make clean

## Execution Instructions
### Run tiny Dataset
>make tiny

### Run small Dataset
>make small

### Run medium Dataset
>make medium

## Implementation Environment
This project has been developed at Linux Platform but it was tested at Windows as well.

## Application Design

* __PART 1:__

In order to have minimal code design we created __defines.h__ file that gathers the values of necessary constants for the project. This makes the process of testing the project way easier, beacause we only have to make changes to this file and not everywhere.

The graph (__Graph.h__ file) is represented by two pair, one for the incoming and the other for the outcomig edges. Each pair consists of one buffer and one index to that buffer. 

The buffer (__Buffer.h__ file), other than that, consists of a table that includes list_nodes, each list_node is mainly a sum of node identifiers with a pointer to another list_node. Obviously, the pointer mentioned before is used when overflow is unavoidable. In such cases our design keeps a pointer to the last overflow instead of the first list node. Let's try to virtualize the previous sentence, if we have buckets (that contain nodes) in a row, then in our implementation the first bucket is the most recent added and the others following are already full.

The node index (__NodeIndex.h__ file) represents the connection between the starting node with all the nodes it has edges with. The design we have chosen to implement this is that the id of the starting node is the offset of the node_index array. The content of each cell is the offset of the list_node that contains the incoming/outcomig edges for this cell.

When the time comes to add an edge in a pair (__Graph.cpp__ file, void Pair::addEdge(uint32_t from, uint32_t to, uint32_t version)) we implement a hash method. This simple hash method evaluates the position where the key will be inserted by calculating the modulo of the destination node id with 2. Just for the first and second part there is no problem calling the function with only two arguments due to this line:
```c++ 
   virtual void addEdge(uint32_t from, uint32_t to, uint32_t version=0);
```

The Bidirectional Breadth First Search (__Graph.cpp__ file) is implemented by having two QueueSets, one including the nodes visited when starting at the source and the other one when starting at the target. BBFS extends the queue set with the least elements.

The variety of structures that have been implemented to examine and achieve the quickest time in Part 1 are given namely below:  
Queue, HashQueue, Set, QueueSet, HashSet

!!!!!!!!!!ΚΑΤΙ ΓΙΑ ΤΟ pair cursor!!!!!!

* __PART 2:__

An auxiliary class named UpdateIndex (__CC.h__ file) has been implemented, to simulate the idea that we need to know in O(1) if two connected components have been merged. We decided that a stack linked list is appropriate to represent this structure.

A design technique that we believe makes part 2 handy, is that we seperated the static and the dynamic graph by implementing two different classes which both inherit from class Graph.

!!!!++

The variety of structures that have been implemented to examine and achieve the quickest time in Part 2 are given namely below:  
ArrayStack, HashStack, StackLinkedList

* __PART 3:__

!!!+++

## Optimizations
* Time:

* Memory:

## Experiment Results

## Suitable Structures
