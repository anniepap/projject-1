OBJS = ../obj/HashQueue.o ../obj/Buffer.o ../obj/HashSet.o ../obj/main.o ../obj/QueueSet.o ../obj/Graph.o ../obj/NodeIndex.o ../obj/SCC.o ../obj/PairCursor.o ../obj/GrailIndex.o ../obj/CC.o ../obj/GraphPostOrderCursor.o ../obj/HashStack.o ../obj/StackLinkedList.o ../obj/Job.o ../obj/JobScheduler.o ../obj/ListQueue.o

# parapanw prepei na fugei to StackLinkedList an telika den to xrisimopoihsoume

all: mkdir out

mkdir:
	mkdir -p ../obj

out: $(OBJS)
	g++ $(OBJS) -o out -pthread

../obj/Job.o: Job.cpp Job.h
	g++ -c Job.cpp -o ../obj/Job.o

../obj/JobScheduler.o: JobScheduler.cpp JobScheduler.h
	g++ -c JobScheduler.cpp -o ../obj/JobScheduler.o	

../obj/ListQueue.o: ListQueue.cpp ListQueue.h
	g++ -c ListQueue.cpp -o ../obj/ListQueue.o

../obj/HashStack.o: ../Part2/HashStack.cpp ../Part2/HashStack.h
	g++ -c ../Part2/HashStack.cpp -o ../obj/HashStack.o

../obj/GraphPostOrderCursor.o: ../Part2/GraphPostOrderCursor.cpp ../Part2/GraphPostOrderCursor.h
	g++ -c ../Part2/GraphPostOrderCursor.cpp -o ../obj/GraphPostOrderCursor.o

../obj/GrailIndex.o: ../Part2/GrailIndex.cpp ../Part2/GrailIndex.h
	g++ -c ../Part2/GrailIndex.cpp -o ../obj/GrailIndex.o

../obj/CC.o: ../Part2/CC.cpp ../Part2/CC.h
	g++ -c ../Part2/CC.cpp -o ../obj/CC.o

../obj/SCC.o: ../Part2/SCC.cpp ../Part2/SCC.h ../Part1/defines.h ../Part1/NodeIndex.h ../Part1/Buffer.h
	g++ -c ../Part2/SCC.cpp -o ../obj/SCC.o	

../obj/PairCursor.o: ../Part1/PairCursor.cpp ../Part1/PairCursor.h
	g++ -c ../Part1/PairCursor.cpp -o ../obj/PairCursor.o

../obj/HashQueue.o: ../Part1/HashQueue.cpp ../Part1/HashQueue.h
	g++ -c ../Part1/HashQueue.cpp -o ../obj/HashQueue.o

../obj/Buffer.o: ../Part1/Buffer.cpp ../Part1/Buffer.h ../Part1/ListNode.h
	g++ -c ../Part1/Buffer.cpp -o ../obj/Buffer.o

../obj/HashSet.o: ../Part1/HashSet.cpp ../Part1/HashSet.h
	g++ -c ../Part1/HashSet.cpp -o ../obj/HashSet.o

../obj/main.o: ../obj/Graph.o main.cpp
	g++ -c main.cpp -o ../obj/main.o

../obj/QueueSet.o: ../obj/HashSet.o ../obj/HashQueue.o ../Part1/QueueSet.cpp ../Part1/QueueSet.h ../Part1/defines.h
	g++ -c ../Part1/QueueSet.cpp -o ../obj/QueueSet.o

../obj/Graph.o: ../obj/NodeIndex.o ../obj/QueueSet.o ../obj/Buffer.o ../Part1/Graph.cpp ../Part1/Graph.h
	g++ -c ../Part1/Graph.cpp -o ../obj/Graph.o

../obj/StackLinkedList.o: ../Part2/StackLinkedList.cpp ../Part2/StackLinkedList.h
	g++ -c ../Part2/StackLinkedList.cpp -o ../obj/StackLinkedList.o

../obj/NodeIndex.o: ../Part1/NodeIndex.cpp ../Part1/NodeIndex.h ../Part1/defines.h ../Part2/SCC.h ../Part1/ListNode.h
	g++ -c ../Part1/NodeIndex.cpp -o ../obj/NodeIndex.o

clean:
	rm -rf ./Unit/*/CMakeFiles ./Unit/*/cmake_install.cmake ./Unit/*/runTests ./Unit/*/CMakeCache.txt ./Unit/*/Makefile out ../obj/*.o
