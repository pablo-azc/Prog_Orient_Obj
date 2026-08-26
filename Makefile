SOURCE=src/*
OUT=programa.out
#OPTIONS = -IHeaders

main:
	g++ $(OPTIONS) -o $(OUT) $(SOURCE)

run:
	./$(OUT)

clean:
	rm $(OUT)

