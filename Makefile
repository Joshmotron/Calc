a.exe: Calculator.o testCalculator.o
	g++ -o a.exe Calculator.o testCalculator.o

Calculator.o: Calculator.cc Calculator.h
	g++ -c Calculator.cc

testCalculator.o: testCalculator.cc Calculator.h
	g++ -c testCalculator.cc
