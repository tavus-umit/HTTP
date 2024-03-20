
# Author : Muhammed Ümit TAVUS
# ID: 22203317
# Section : 2
# Homework : 2
# Description : Makefile


simulator: main.cpp Computer.cpp Request.cpp RequestHeap.cpp ComputerLinkedList.cpp Simulator.cpp
	g++ main.cpp Computer.cpp Request.cpp RequestHeap.cpp ComputerLinkedList.cpp Simulator.cpp -o simulator

run: simulator
	./simulator log1.txt 5 > output1.txt
	./simulator log2.txt 15 > output2.txt
	./simulator log3.txt 46 > output3.txt
	./simulator log3.txt 17 > output4.txt
