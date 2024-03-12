GC=gcc
FLAGS=
BIN=../bin/
HOUSE=house/
TRAVEL=travel/
MORSE=morse/

all: house travel

house: $(HOUSE)house.c $(HOUSE)calc_house.c
	$(GC) $(FLAGS) $(HOUSE)house.c $(HOUSE)calc_house.c -o $(BIN)house

travel: $(TRAVEL)travel.c $(TRAVEL)calc_travel.c
	$(GC) $(FLAGS) $(TRAVEL)travel.c $(TRAVEL)calc_travel.c -o $(BIN)travel

clean:
	rm -f $(BIN)*

rebuild: 
	clean all

