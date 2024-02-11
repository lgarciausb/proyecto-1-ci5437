/* This program reads a state from stdin and prints out its successors.

Copyright (C) 2013 by the PSVN Research Group, University of Alberta
*/

#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <assert.h>
#include <sys/time.h>

#include <iostream>
#include <list>

#include <chrono>

using namespace std::chrono_literals;
using Clock = std::chrono::system_clock;

int main(int argc, char **argv ) {


    int goal_num;
    ruleid_iterator_t iter; 
    int ruleid; 
    int childCount;
    int history;

    int n_nodes = 1;
    //int max_depth = 4;

    state_t* state;
    std::list<state_t*> currentStates = {new state_t};
    std::list<int> currentHistories = {init_history};
    std::list<int> nextHistories;
    std::list<state_t*> nextStates;


    first_goal_state( currentStates.front(), &goal_num );
    

    printf("estado inicial\n\n");
    print_state(stdout, currentStates.front());
    printf("\n\n");

    auto timeLimit = Clock::now() + 900s;

    for (int i = 0; i>-1; i++) {

        //std::cout << "nivel " << i+1 << std::endl;

        while (!currentStates.empty()) {

            state = currentStates.front();
            currentStates.pop_front();
            history = currentHistories.front();
            currentHistories.pop_front();
            init_fwd_iter(&iter, state);

            while( (ruleid = next_ruleid(&iter)) >= 0 ) {

                if( fwd_rule_valid_for_history(history, ruleid) == 0 ) continue;

                nextStates.push_back(new state_t);
                apply_fwd_rule(ruleid, state, nextStates.back());

                nextHistories.push_back(next_bwd_history(history, ruleid));

                n_nodes++;

            }

            delete state;

            if (Clock::now() >= timeLimit) {printf("BROOOOO");exit(0);}
            
        }

        for (const auto& s : nextStates) {
            currentStates.push_back(s);
        }
        nextStates.clear();

        for (const auto& s : nextHistories) {
            currentHistories.push_back(s);
        }
        nextHistories.clear();

        std::cout << currentHistories.size() << " " << static_cast<double>(n_nodes-1)/(n_nodes -  currentHistories.size()) << std::endl; //(cantidad de estados) (factor de ramificación)


    }


    return 0;
}

