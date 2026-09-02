SOURCE=src/*
OUT=programa.out
#OPTIONS = -IHeaders

main:
	g++ $(OPTIONS) -o $(OUT) $(SOURCE)

run:
	./$(OUT)

read:
	./$(OUT) --mode read

write:
	./$(OUT) --mode write --count 10

clean:
	rm $(OUT)

