HEAD=inc/*
LIB=lib/*
SOURCE=server.cpp
OUT=Servidor.out
TESTOUT=prueba.out
#OPTIONS = -IHeaders

main:
	g++ $(OPTIONS) -o $(OUT) $(HEAD) $(LIB) $(SOURCE)

run:
	./$(OUT)

test:
	g++ $(OPTIONS) -o $(OUT) $(HEAD) $(LIB) $(SOURCE) test.cpp
	./$(TESTOUT)

clean:
	rm $(OUT)
