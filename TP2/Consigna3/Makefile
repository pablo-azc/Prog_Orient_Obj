SOURCE=src/*
OUT=programa.out
TESTOUT=prueba.out
#OPTIONS = -IHeaders

main:
	g++ $(OPTIONS) -o $(OUT) $(SOURCE) main.cpp

run:
	./$(OUT)

test:
	g++ $(OPTIONS) -o $(TESTOUT) $(SOURCE) test.cpp

clean:
	rm $(OUT)

