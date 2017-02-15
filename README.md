# Projject

## Personal Details
[Athanasopoulos George](https://github.com/Geotha)

[Karatsenidis Konstantinos](https://github.com/gate2k1)

[Papachristou Anna](https://github.com/anniepap)

## Compile Instructions
Every part produces its own output. 
> ./out  (part3)

> ./out2 (part2)

> ./out1 (part1)

### Derive exe file
>make all

### Remove object and executable files
>make clean

## Execution Instructions
### Run Dataset
> ./out graph.txt workload.txt

## Implementation Environment
This project has been developed at Linux Platform.

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

We considered necessary to create a structure (__PairCursor.h__ file) that iterates the Pair structure to find the neighbours of a specific id.

We implemented unit testing by using [googletest](https://github.com/google/googletest).

* __PART 2:__

An auxiliary class named UpdateIndex (__CC.h__ file) has been implemented, to simulate the idea that we need to know in O(1) if two connected components have been merged. We decided that a stack linked list is appropriate to represent this structure.

A design technique that we believe makes part 2 handy, is that we seperated the static and the dynamic graph by implementing two different classes which both inherit from class Graph.

We chose to simulate the dfs search that recursion is doing in Tarjan algorithm (__SCC.cpp__ file) by implementing a stack. The last element inserted in stack is being compared with the neighbour nodes according to their lowlink and index values.

The function for creating hypergraph is being implemented in __SCC.cpp__ file with purose to use it later in grail.

A useful approach to implement the Graph Post Order Cursor (__GraphPostOrderCursor.h__ file) was to make the class Collection that is being used to fastly produce random order for selecting the starting point of Grail.

The variety of structures that have been implemented to examine and achieve the quickest time in Part 2 are given namely below:  
ArrayStack, HashStack, StackLinkedList

The quickest time of storing and accessing data has been proven to be HashStack.

In order to satisfy the demands of the project we implemented the idea that when two nodes are not in the same strongly connected component then we ask grail according to their ids on hypergraph. Though the running seemed to be higher so these lines are commented and not included in the calculation of the result.

* __PART 3:__

Both (__Job.h__ file) and (__JobScheduler.h__ file) include classes that have been implemented in such a way that is easily adaptable to other projects.

Every thread is working in one job of the query, if there are no jobs then the thread blocks until other threads terminate.

A (__ListQueue.h__ file) has been implemented beacause we thought it was the ideal structure to have quickly access to the query of jobs.

## Optimizations

* __Time:__

The Bidirectional Breadth First Search (__Graph.cpp__ file) is implemented by having two QueueSets, one including the nodes visited when starting at the source and the other one when starting at the target. BBFS extends the queue set with the least elements rather than extending each side once at a time. This method helps to minimize the execution time because we expect having more "no" than "yes".

This code below is fragment optimizations that reduces comparisons.
```c++ 
   // return rank!=0 && min_rank!=0;
   return rank & min_rank;
   
   // if (start.visited(id) == false && sccNid == sccId)
   if (sccNid == sccId && start.visited(id) == false) {...}
```

* Memory:

## Experiment Results

We were curious if a bfs would do the job as quick as a bbfs, so we implemented a bfs and executed the algorithm. The results proved that a bbfs algorithm was clearly more efficient for large datasets.

The execution of the project gives results always lower than 1.5gb for the static and 3.5gb for the dynamic input.

Threashold constant value is set to 0.03 because it is a reasonable value for medium dataset but for large datasets there is no point giving threashod a value because the number of queries to index is negligible. Just because the value of 0.03 is pretty small there is no difference in execution time.

Experiments also proved that when the value of NUMBEROFLABELS is set higher (e.g. 4 instead of 2) in large datasets the execution time is better. On the other hand, for smaller datasets higher value is better to be avoided. 

As far as the constants in __defines.h__ file are considered, we chose that the NODEHASH has value 2 only because this value the project authors demanded. Also LISTNODECAPACITY value is set to 5 based on the experiments we executed. A higher value would allocate huger amount of memory which would slow down the computer during the execution.

## Suitable Structures

Initially, Set and Queue are abstract classes that contribute to the implementation of a variety of structures thar are given namely below:
HashQueue, ArrayQueue, LinkedListQueue

The purpose was to examine and achieve the quickest time. We conluded that HashQueue was the ideal structure based on access time.
