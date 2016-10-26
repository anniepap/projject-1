all:
	g++ Buffer.cpp Graph.cpp NodeIndex.cpp QueueSet.cpp main.cpp -g -Wall -Wextra -Wconversion -o a
	g++ Buffer.cpp Graph.cpp NodeIndex.cpp QueueSet.cpp main2.cpp -g -Wall -Wextra -Wconversion -o b
	g++ Buffer.cpp Graph.cpp NodeIndex.cpp QueueSet.cpp main3.cpp -g -Wall -Wextra -Wconversion -o c
