PART1_OBJS = obj/Buffer.o obj/Graph.o obj/HashQueue.o obj/HashSet.o obj/NodeIndex.o obj/PairCursor.o obj/Queue.o obj/QueueSet.o
PART2_OBJS = obj/CC.o obj/GrailIndex.o obj/GraphPostOrderCursor.o obj/HashStack.o obj/SCC.o obj/StackLinkedList.o
PART3_OBJS = obj/Job.o obj/JobScheduler.o obj/ListQueue.o
MAIN_OBJ = obj/main.o
WFLAGS = -Wall -Wextra -Wconversion

all: mkdir out

mkdir:
	mkdir -p obj

out: $(PART1_OBJS) $(PART2_OBJS) $(PART3_OBJS) $(MAIN_OBJ)
	g++ -o2 -w $(WFLAGS) $(PART1_OBJS) $(PART2_OBJS) $(PART3_OBJS) $(MAIN_OBJ) -o out -pthread

obj/Job.o: Part3/Job.cpp Part3/Job.h
	g++ -o2 -w $(WFLAGS) -c Part3/Job.cpp -o obj/Job.o

obj/JobScheduler.o: Part3/JobScheduler.cpp Part3/JobScheduler.h
	g++ -o2 -w $(WFLAGS) -c Part3/JobScheduler.cpp -o obj/JobScheduler.o	

obj/ListQueue.o: Part3/ListQueue.cpp Part3/ListQueue.h
	g++ -o2 -w $(WFLAGS) -c Part3/ListQueue.cpp -o obj/ListQueue.o

obj/HashStack.o: Part2/HashStack.cpp Part2/HashStack.h
	g++ -o2 -w $(WFLAGS) -c Part2/HashStack.cpp -o obj/HashStack.o

obj/GraphPostOrderCursor.o: Part2/GraphPostOrderCursor.cpp Part2/GraphPostOrderCursor.h
	g++ -o2 -w $(WFLAGS) -c Part2/GraphPostOrderCursor.cpp -o obj/GraphPostOrderCursor.o

obj/GrailIndex.o: Part2/GrailIndex.cpp Part2/GrailIndex.h
	g++ -o2 -w $(WFLAGS) -c Part2/GrailIndex.cpp -o obj/GrailIndex.o

obj/CC.o: Part2/CC.cpp Part2/CC.h
	g++ -o2 -w $(WFLAGS) -c Part2/CC.cpp -o obj/CC.o

obj/SCC.o: Part2/SCC.cpp Part2/SCC.h Part1/defines.h Part1/NodeIndex.h Part1/Buffer.h
	g++ -o2 -w $(WFLAGS) -c Part2/SCC.cpp -o obj/SCC.o	

obj/PairCursor.o: Part1/PairCursor.cpp Part1/PairCursor.h
	g++ -o2 -w $(WFLAGS) -c Part1/PairCursor.cpp -o obj/PairCursor.o

obj/Queue.o: Part1/Queue.cpp Part1/Queue.h
	g++ -o2 -w $(WFLAGS) -c Part1/Queue.cpp -o obj/Queue.o

obj/HashQueue.o: Part1/HashQueue.cpp Part1/HashQueue.h
	g++ -o2 -w $(WFLAGS) -c Part1/HashQueue.cpp -o obj/HashQueue.o

obj/Buffer.o: Part1/Buffer.cpp Part1/Buffer.h Part1/ListNode.h
	g++ -o2 -w $(WFLAGS) -c Part1/Buffer.cpp -o obj/Buffer.o

obj/HashSet.o: Part1/HashSet.cpp Part1/HashSet.h
	g++ -o2 -w $(WFLAGS) -c Part1/HashSet.cpp -o obj/HashSet.o

obj/main.o: obj/Graph.o main.cpp
	g++ -o2 -w $(WFLAGS) -c main.cpp -o obj/main.o

obj/QueueSet.o: obj/HashSet.o obj/HashQueue.o Part1/QueueSet.cpp Part1/QueueSet.h Part1/defines.h
	g++ -o2 -w $(WFLAGS) -c Part1/QueueSet.cpp -o obj/QueueSet.o

obj/Graph.o: obj/NodeIndex.o obj/QueueSet.o obj/Buffer.o Part1/Graph.cpp Part1/Graph.h
	g++ -o2 -w $(WFLAGS) -c Part1/Graph.cpp -o obj/Graph.o

obj/StackLinkedList.o: Part2/StackLinkedList.cpp Part2/StackLinkedList.h
	g++ -o2 -w $(WFLAGS) -c Part2/StackLinkedList.cpp -o obj/StackLinkedList.o

obj/NodeIndex.o: Part1/NodeIndex.cpp Part1/NodeIndex.h Part1/defines.h Part2/SCC.h Part1/ListNode.h
	g++ -o2 -w $(WFLAGS) -c Part1/NodeIndex.cpp -o obj/NodeIndex.o

clean:
	rm -rf Unit/*/CMakeFiles Unit/*/cmake_install.cmake Unit/*/runTests Unit/*/CMakeCache.txt Unit/*/Makefile out obj
