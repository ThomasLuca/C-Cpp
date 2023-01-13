CC=g++
TARGET=a
FLAGS= -std=c++14 -static-libgcc 

19:
	$(CC) ${FLAGS} ./ex19/19.cpp ./ex19/rechthoek.cpp ./ex19/gekleurd.cpp ./ex19/vierkant.cpp -o $(TARGET) && ./$(TARGET)
	
20:
	$(CC) ${FLAGS} ./20.cpp ./ex19/rechthoek.cpp ./ex19/gekleurd.cpp ./ex19/vierkant.cpp -o $(TARGET) && ./$(TARGET)

21:
	$(CC) ${FLAGS} ./21.cpp -o $(TARGET) && ./$(TARGET)

22:
	$(CC) ${FLAGS} ./22.cpp -o $(TARGET) && ./$(TARGET)

23:
	$(CC) ${FLAGS} ./ex23/23.cpp ./ex23/gekleurdvierkant.cpp ./ex23/gekleurd.cpp ./ex19/vierkant.cpp ./ex19/rechthoek.cpp -o $(TARGET) && ./$(TARGET)

clean:
	rm $(TARGET)
