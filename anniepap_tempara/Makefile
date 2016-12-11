OBJS = HashQueue.o Buffer.o HashSet.o main.o Queue.o QueueSet.o Graph.o NodeIndex.o SCC.o StackLinkedList.o

all: out

out: $(OBJS)
	g++ $(OBJS) -o out

HashQueue.o: Queue.o HashQueue.cpp HashQueue.h
	g++ -c HashQueue.cpp

Queue.o: Queue.h Queue.h
	g++ -c Queue.cpp

Buffer.o: Buffer.cpp Buffer.h ListNode.h
	g++ -c Buffer.cpp

HashSet.o: HashSet.cpp HashSet.h Set.h
	g++ -c HashSet.cpp

main.o: Graph.o main.cpp
	g++ -c main.cpp

QueueSet.o: HashSet.o HashQueue.o QueueSet.cpp QueueSet.h defines.h
	g++ -c QueueSet.cpp

Graph.o: NodeIndex.o QueueSet.o Buffer.o Graph.cpp Graph.h
	g++ -c Graph.cpp

StackLinkedList.o: StackLinkedList.cpp StackLinkedList.h
	g++ -c StackLinkedList.cpp

NodeIndex.o: NodeIndex.cpp NodeIndex.h defines.h SCC.h ListNode.h
	g++ -c NodeIndex.cpp

SCC.o: SCC.cpp SCC.h defines.h NodeIndex.h Buffer.h
	g++ -c SCC.cpp

clean:
	rm -rf ./Unit/*/CMakeFiles ./Unit/*/cmake_install.cmake ./Unit/*/runTests ./Unit/*/CMakeCache.txt ./Unit/*/Makefile out *.o
