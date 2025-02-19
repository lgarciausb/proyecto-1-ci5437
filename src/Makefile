CC = gcc
CXX = g++
OPT = -Wall -O3 -Wno-unused-function -Wno-unused-variable
PSVNOPT = --no_state_map --no_abstraction --backwards_moves --history_len=0

all: ../bin/$(CODE) ../bin/$(CODE)/24puzzle ../bin/$(CODE)/15puzzle ../bin/$(CODE)/rubik ../bin/$(CODE)/topspin12 ../bin/$(CODE)/topspin14 ../bin/$(CODE)/topspin17 ../bin/$(CODE)/hanoi12 ../bin/$(CODE)/hanoi14 ../bin/$(CODE)/hanoi18
	rm -f ./psvn2c_core.c ./psvn2c_state_map.c ./psvn2c_abstraction.c

../bin/$(CODE)/15puzzle: 15puzzle.c $(CODE)
	$(CC) $(OPT) $(CODE) -include $< -o $@
	rm -f 15puzzle.c
15puzzle.c: N_puzzle/15puzzle.psvn psvn2c_core.c psvn2c_state_map.c psvn2c_abstraction.c
	../psvn/psvn2c $(PSVNOPT) --name=$(*F) < $< > $@

../bin/$(CODE)/24puzzle: 24puzzle.c $(CODE)
	$(CC) $(OPT) $(CODE) -include $< -o $@
	rm -f 24puzzle.c
24puzzle.c: N_puzzle/24puzzle.psvn psvn2c_core.c psvn2c_state_map.c psvn2c_abstraction.c
	../psvn/psvn2c $(PSVNOPT) --name=$(*F) < $< > $@

../bin/$(CODE)/rubik: rubik.c $(CODE)
	$(CC) $(OPT) $(CODE) -include $< -o $@
	rm -f rubik.c
rubik.c: RubiksCube/rubik.psvn psvn2c_core.c psvn2c_state_map.c psvn2c_abstraction.c
	../psvn/psvn2c $(PSVNOPT) --name=$(*F) < $< > $@

../bin/$(CODE)/topspin12: topspin12.c $(CODE)
	$(CC) $(OPT) $(CODE) -include $< -o $@
	rm -f topspin12.c
topspin12.c: TopSpin/topspin12.psvn psvn2c_core.c psvn2c_state_map.c psvn2c_abstraction.c
	../psvn/psvn2c $(PSVNOPT) --name=$(*F) < $< > $@

../bin/$(CODE)/topspin14: topspin14.c $(CODE)
	$(CC) $(OPT) $(CODE) -include $< -o $@
	rm -f topspin14.c
topspin14.c: TopSpin/topspin14.psvn psvn2c_core.c psvn2c_state_map.c psvn2c_abstraction.c
	../psvn/psvn2c $(PSVNOPT) --name=$(*F) < $< > $@

../bin/$(CODE)/topspin17: topspin17.c $(CODE)
	$(CC) $(OPT) $(CODE) -include $< -o $@
	rm -f topspin17.c
topspin17.c: TopSpin/topspin17.psvn psvn2c_core.c psvn2c_state_map.c psvn2c_abstraction.c
	../psvn/psvn2c $(PSVNOPT) --name=$(*F) < $< > $@

../bin/$(CODE)/hanoi12: hanoi12.c $(CODE)
	$(CC) $(OPT) $(CODE) -include $< -o $@
	rm -f hanoi12.c
hanoi12.c: Towers_of_Hanoi/hanoi12.psvn psvn2c_core.c psvn2c_state_map.c psvn2c_abstraction.c
	../psvn/psvn2c $(PSVNOPT) --name=$(*F) < $< > $@

../bin/$(CODE)/hanoi14: hanoi14.c $(CODE)
	$(CC) $(OPT) $(CODE) -include $< -o $@
	rm -f hanoi14.c
hanoi14.c: Towers_of_Hanoi/hanoi14.psvn psvn2c_core.c psvn2c_state_map.c psvn2c_abstraction.c
	../psvn/psvn2c $(PSVNOPT) --name=$(*F) < $< > $@

../bin/$(CODE)/hanoi18: hanoi18.c $(CODE) 
	$(CC) $(OPT) $(CODE) -include $< -o $@
	rm -f hanoi18.c
hanoi18.c: Towers_of_Hanoi/hanoi18.psvn psvn2c_core.c psvn2c_state_map.c psvn2c_abstraction.c
	../psvn/psvn2c $(PSVNOPT) --name=$(*F) < $< > $@

../bin/$(CODE):
	mkdir -p ../bin/$(CODE)

psvn2c_core.c:
	cp ../psvn/psvn2c_core.c ./psvn2c_core.c

psvn2c_state_map.c:
	cp ../psvn/psvn2c_state_map.c ./psvn2c_state_map.c

psvn2c_abstraction.c:
	cp ../psvn/psvn2c_abstraction.c ./psvn2c_abstraction.c


.PHONY: clean
clean:
	rm -fr rubik psvn2c_core.c psvn2c_state_map.c psvn2c_abstraction.c *.dSYM *.o *~
