OBJS = ../obj/HashQueue.o ../obj/Buffer.o ../obj/HashSet.o ../obj/main.o ../obj/QueueSet.o ../obj/Graph.o ../obj/NodeIndex.o ../obj/SCC.o ../obj/StackLinkedList.o ../obj/PairCursor.o ../obj/GrailIndex.o ../obj/CC.o

all: out

out: $(OBJS)
	g++ $(OBJS) -o out

../obj/GrailIndex.o: GrailIndex.cpp GrailIndex.h
	g++ -c GrailIndex.cpp -o ../obj/GrailIndex.o

../obj/CC.o: CC.cpp CC.h
	g++ -c CC.cpp -o ../obj/CC.o

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

../obj/StackLinkedList.o: StackLinkedList.cpp StackLinkedList.h
	g++ -c StackLinkedList.cpp -o ../obj/StackLinkedList.o

../obj/NodeIndex.o: ../Part1/NodeIndex.cpp ../Part1/NodeIndex.h ../Part1/defines.h SCC.h ../Part1/ListNode.h
	g++ -c ../Part1/NodeIndex.cpp -o ../obj/NodeIndex.o

../obj/SCC.o: SCC.cpp SCC.h ../Part1/defines.h ../Part1/NodeIndex.h ../Part1/Buffer.h
	g++ -c SCC.cpp -o ../obj/SCC.o

clean:
	rm -rf ./Unit/*/CMakeFiles ./Unit/*/cmake_install.cmake ./Unit/*/runTests ./Unit/*/CMakeCache.txt ./Unit/*/Makefile out *.o
