GC=gcc
FLAGS=-Wall -Wextra -Werror
BIN=../bin/
HOUSE=house_task/
TRAVEL=travel_task/
MORSE=morse_task/

all: house travel morse

house: $(HOUSE)house.c $(HOUSE)calc_house.c
	$(GC) $(FLAGS) $(HOUSE)house.c $(HOUSE)calc_house.c -o $(BIN)house

travel: $(TRAVEL)travel.c $(TRAVEL)calc_travel.c
	$(GC) $(FLAGS) $(TRAVEL)travel.c $(TRAVEL)calc_travel.c -o $(BIN)travel

morse: $(MORSE)morse_crypt.c
	$(GC) $(FLAGS) $(MORSE)morse_crypt.c -o $(BIN)morse

clean:
	rm -f $(BIN)*

rebuild: clean all