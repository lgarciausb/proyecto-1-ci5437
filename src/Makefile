CC = gcc
CXX = g++
OPT = -Wall -O3 -Wno-unused-function -Wno-unused-variable
PSVNOPT = --no_state_map --no_abstraction --backwards_moves --history_len=0

all: ../bin/24puzzle ../bin/15puzzle ../bin/rubik ../bin/topspin12 ../bin/topspin14 ../bin/topspin17 ../bin/hanoi12 ../bin/hanoi14 ../bin/hanoi18
	rm -f ./psvn2c_core.c ./psvn2c_state_map.c ./psvn2c_abstraction.c

../bin/15puzzle: 15puzzle.c solver.c
	$(CC) $(OPT) solver.c -include $< -o $@
	rm -f 15puzzle.c
15puzzle.c: N_puzzle/15puzzle.psvn psvn2c_core.c psvn2c_state_map.c psvn2c_abstraction.c
	../psvn/psvn2c $(PSVNOPT) --name=$(*F) < $< > $@

../bin/24puzzle: 24puzzle.c solver.c
	$(CC) $(OPT) solver.c -include $< -o $@
	rm -f 24puzzle.c
24puzzle.c: N_puzzle/24puzzle.psvn psvn2c_core.c psvn2c_state_map.c psvn2c_abstraction.c
	../psvn/psvn2c $(PSVNOPT) --name=$(*F) < $< > $@

../bin/rubik: rubik.c solver.c
	$(CC) $(OPT) solver.c -include $< -o $@
	rm -f rubik.c
rubik.c: RubiksCube/rubik.psvn psvn2c_core.c psvn2c_state_map.c psvn2c_abstraction.c
	../psvn/psvn2c $(PSVNOPT) --name=$(*F) < $< > $@

../bin/topspin12: topspin12.c solver.c
	$(CC) $(OPT) solver.c -include $< -o $@
	rm -f topspin12.c
topspin12.c: TopSpin/topspin12.psvn psvn2c_core.c psvn2c_state_map.c psvn2c_abstraction.c
	../psvn/psvn2c $(PSVNOPT) --name=$(*F) < $< > $@

../bin/topspin14: topspin14.c solver.c
	$(CC) $(OPT) solver.c -include $< -o $@
	rm -f topspin14.c
topspin14.c: TopSpin/topspin14.psvn psvn2c_core.c psvn2c_state_map.c psvn2c_abstraction.c
	../psvn/psvn2c $(PSVNOPT) --name=$(*F) < $< > $@

../bin/topspin17: topspin17.c solver.c
	$(CC) $(OPT) solver.c -include $< -o $@
	rm -f topspin17.c
topspin17.c: TopSpin/topspin17.psvn psvn2c_core.c psvn2c_state_map.c psvn2c_abstraction.c
	../psvn/psvn2c $(PSVNOPT) --name=$(*F) < $< > $@

../bin/hanoi12: hanoi12.c solver.c
	$(CC) $(OPT) solver.c -include $< -o $@
	rm -f hanoi12.c
hanoi12.c: Towers_of_Hanoi/hanoi12.psvn psvn2c_core.c psvn2c_state_map.c psvn2c_abstraction.c
	../psvn/psvn2c $(PSVNOPT) --name=$(*F) < $< > $@

../bin/hanoi14: hanoi14.c solver.c
	$(CC) $(OPT) solver.c -include $< -o $@
	rm -f hanoi14.c
hanoi14.c: Towers_of_Hanoi/hanoi14.psvn psvn2c_core.c psvn2c_state_map.c psvn2c_abstraction.c
	../psvn/psvn2c $(PSVNOPT) --name=$(*F) < $< > $@

../bin/hanoi18: hanoi18.c solver.c
	$(CC) $(OPT) solver.c -include $< -o $@
	rm -f hanoi18.c
hanoi18.c: Towers_of_Hanoi/hanoi18.psvn psvn2c_core.c psvn2c_state_map.c psvn2c_abstraction.c
	../psvn/psvn2c $(PSVNOPT) --name=$(*F) < $< > $@



psvn2c_core.c:
	cp ../psvn/psvn2c_core.c ./psvn2c_core.c

psvn2c_state_map.c:
	cp ../psvn/psvn2c_state_map.c ./psvn2c_state_map.c

psvn2c_abstraction.c:
	cp ../psvn/psvn2c_abstraction.c ./psvn2c_abstraction.c


.PHONY: clean
clean:
	rm -fr rubik psvn2c_core.c psvn2c_state_map.c psvn2c_abstraction.c *.dSYM *.o *~
