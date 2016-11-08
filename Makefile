OBJS = ArrayQueueSet.o Buffer.o HashSet.o main.o QueueSet.o Graph.o NodeIndex.o

all: out

out: $(OBJS)
	g++ $(OBJS) -o out

medium: all
	./out datasets/medium/mediumGraph.txt datasets/medium/mediumWorkload_FINAL.txt

small: all
	./out datasets/small/smallGraph.txt datasets/small/smallWorkload_FINAL.txt

tiny: all
	./out datasets/tiny/tinyGraph.txt datasets/tiny/tinyWorkload_FINAL.txt

ArrayQueueSet.o: QueueSet.o ArrayQueueSet.cpp ArrayQueueSet.h
	g++ -c ArrayQueueSet.cpp

Buffer.o: Buffer.cpp Buffer.h ListNode.h
	g++ -c Buffer.cpp

HashSet.o: HashSet.cpp HashSet.h Set.h
	g++ -c HashSet.cpp

main.o: Graph.o main.cpp
	g++ -c main.cpp

QueueSet.o: HashSet.o QueueSet.cpp QueueSet.h defines.h
	g++ -c QueueSet.cpp

Graph.o: NodeIndex.o QueueSet.o Buffer.o Graph.cpp Graph.h
	g++ -c Graph.cpp

NodeIndex.o: NodeIndex.cpp NodeIndex.h defines.h
	g++ -c NodeIndex.cpp

clean:
	rm -rf ./Unit/*/CMakeFiles ./Unit/*/cmake_install.cmake ./Unit/*/runTests ./Unit/*/CMakeCache.txt ./Unit/*/Makefile out *.o
