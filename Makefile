all: output

output: Book.o Customer.o BookStore.o CmdLineParser.o Transaction.o GBookStore.o Test.o
	g++ Book.o Customer.o BookStore.o CmdLineParser.o Transaction.o GBookStore.o Test.o -o output

Book.o: Book.cpp
	g++ -c Book.cpp

Customer.o: Customer.cpp
	g++ -c Customer.cpp

BookStore.o: BookStore.cpp
	g++ -c BookStore.cpp

CmdLineParser.o: CmdLineParser.cpp
	g++ -c CmdLineParser.cpp

Transaction.o: Transaction.cpp
	g++ -c Transaction.cpp

GBookStore.o: GBookStore.cpp
	g++ -c GBookStore.cpp

Test.o: Test.cpp
	g++ -c Test.cpp

clean:
	rm *o output