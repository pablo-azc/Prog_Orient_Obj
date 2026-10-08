SOURCE=clientcmd.cpp
HEAD=inc/*
LIB=lib/*

OUT=Cliente2.out
TESTOUT=prueba.out
#OPTIONS = -IHeaders

main:
	g++ $(OPTIONS) -o $(OUT) $(HEAD) $(LIB) $(SOURCE)

run:
	./$(OUT)

test:
	g++ $(OPTIONS) -o $(TESTOUT) $(SOURCE) test.cpp
	./$(TESTOUT)

clean:
	rm $(OUT)
