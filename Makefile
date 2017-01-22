PART1_OBJS = obj/Buffer.o obj/Graph.o obj/HashQueue.o obj/HashSet.o obj/NodeIndex.o obj/PairCursor.o obj/Queue.o obj/QueueSet.o
PART2_OBJS = obj/CC.o obj/GrailIndex.o obj/GraphPostOrderCursor.o obj/HashStack.o obj/SCC.o obj/StackLinkedList.o obj/DynamicGraph.o obj/StaticGraph.o
PART3_OBJS = obj/Job.o obj/JobScheduler.o obj/ListQueue.o
MAIN_OBJ = obj/main.o
MAIN1_OBJ = obj/main1.o
MAIN2_OBJ = obj/main2.o
WFLAGS = -Wall -Wextra -Wconversion -g -o3

all: mkdir out out1 out2

mkdir:
	mkdir -p obj

out1: $(PART1_OBJS) $(PART2_OBJS) $(PART3_OBJS) $(MAIN1_OBJ)
	g++ $(WFLAGS) $(PART1_OBJS) $(MAIN1_OBJ) -o out1

out2: $(PART1_OBJS) $(PART2_OBJS) $(PART3_OBJS) $(MAIN2_OBJ)
	g++ $(WFLAGS) $(PART1_OBJS) $(PART2_OBJS) $(MAIN2_OBJ) -o out2

out: $(PART1_OBJS) $(PART2_OBJS) $(PART3_OBJS) $(MAIN_OBJ)
	g++ $(WFLAGS) $(PART1_OBJS) $(PART2_OBJS) $(PART3_OBJS) $(MAIN_OBJ) -o out -pthread

obj/Job.o: Part3/Job.cpp Part3/Job.h
	g++ $(WFLAGS) -c Part3/Job.cpp -o obj/Job.o

obj/JobScheduler.o: Part3/JobScheduler.cpp Part3/JobScheduler.h
	g++ $(WFLAGS) -c Part3/JobScheduler.cpp -o obj/JobScheduler.o

obj/ListQueue.o: Part3/ListQueue.cpp Part3/ListQueue.h
	g++ $(WFLAGS) -c Part3/ListQueue.cpp -o obj/ListQueue.o

obj/HashStack.o: Part2/HashStack.cpp Part2/HashStack.h
	g++ $(WFLAGS) -c Part2/HashStack.cpp -o obj/HashStack.o

obj/GraphPostOrderCursor.o: Part2/GraphPostOrderCursor.cpp Part2/GraphPostOrderCursor.h
	g++ $(WFLAGS) -c Part2/GraphPostOrderCursor.cpp -o obj/GraphPostOrderCursor.o

obj/GrailIndex.o: Part2/GrailIndex.cpp Part2/GrailIndex.h
	g++ $(WFLAGS) -c Part2/GrailIndex.cpp -o obj/GrailIndex.o

obj/CC.o: Part2/CC.cpp Part2/CC.h
	g++ $(WFLAGS) -c Part2/CC.cpp -o obj/CC.o

obj/SCC.o: Part2/SCC.cpp Part2/SCC.h Part1/defines.h Part1/NodeIndex.h Part1/Buffer.h
	g++ $(WFLAGS) -c Part2/SCC.cpp -o obj/SCC.o	

obj/PairCursor.o: Part1/PairCursor.cpp Part1/PairCursor.h
	g++ $(WFLAGS) -c Part1/PairCursor.cpp -o obj/PairCursor.o

obj/Queue.o: Part1/Queue.cpp Part1/Queue.h
	g++ $(WFLAGS) -c Part1/Queue.cpp -o obj/Queue.o

obj/HashQueue.o: Part1/HashQueue.cpp Part1/HashQueue.h
	g++ $(WFLAGS) -c Part1/HashQueue.cpp -o obj/HashQueue.o

obj/Buffer.o: Part1/Buffer.cpp Part1/Buffer.h Part1/ListNode.h
	g++ $(WFLAGS) -c Part1/Buffer.cpp -o obj/Buffer.o

obj/HashSet.o: Part1/HashSet.cpp Part1/HashSet.h
	g++ $(WFLAGS) -c Part1/HashSet.cpp -o obj/HashSet.o

obj/main1.o: obj/Graph.o ./Part1/main.cpp
	g++ $(WFLAGS) -c ./Part1/main.cpp -o obj/main1.o

obj/main2.o: obj/DynamicGraph.o obj/StaticGraph.o ./Part2/main.cpp
	g++ $(WFLAGS) -c ./Part2/main.cpp -o obj/main2.o

obj/main.o: obj/DynamicGraph.o obj/StaticGraph.o ./Part3/main.cpp
	g++ $(WFLAGS) -c ./Part3/main.cpp -o obj/main.o

obj/QueueSet.o: obj/HashSet.o obj/HashQueue.o Part1/QueueSet.cpp Part1/QueueSet.h Part1/defines.h
	g++ $(WFLAGS) -c Part1/QueueSet.cpp -o obj/QueueSet.o

obj/DynamicGraph.o: obj/Graph.o Part2/DynamicGraph.cpp Part2/DynamicGraph.h
	g++ $(WFLAGS) -c Part2/DynamicGraph.cpp -o obj/DynamicGraph.o

obj/StaticGraph.o: obj/Graph.o Part2/StaticGraph.cpp Part2/StaticGraph.h
	g++ $(WFLAGS) -c Part2/StaticGraph.cpp -o obj/StaticGraph.o

obj/Graph.o: obj/NodeIndex.o obj/QueueSet.o obj/Buffer.o Part1/Graph.cpp Part1/Graph.h
	g++ $(WFLAGS) -c Part1/Graph.cpp -o obj/Graph.o

obj/StackLinkedList.o: Part2/StackLinkedList.cpp Part2/StackLinkedList.h
	g++ $(WFLAGS) -c Part2/StackLinkedList.cpp -o obj/StackLinkedList.o

obj/NodeIndex.o: Part1/NodeIndex.cpp Part1/NodeIndex.h Part1/defines.h Part2/SCC.h Part1/ListNode.h
	g++ $(WFLAGS) -c Part1/NodeIndex.cpp -o obj/NodeIndex.o

clean:
	rm -rf Unit/*/CMakeFiles Unit/*/cmake_install.cmake Unit/*/runTests Unit/*/CMakeCache.txt Unit/*/Makefile out obj
