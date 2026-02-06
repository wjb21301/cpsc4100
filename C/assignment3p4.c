//These comments are for me to keep track of what i've made states.
// 0 -> start state (even zero, no ones) (accepted)
// 1 -> odd zero, zero 1s
// 2 -> odd zero, one 1s
// 3 -> even zero, one 1s (accepted)
// 5 -> even zero, 2 ones (accepted)
// 6 -> odd zero. 2 ones (accepted
// 7 -> even zero, more than two ones -> dead
// 8 -> odd zero, more than two ones. -> dead
// 4 was omitted due to me making the same state twice...
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(void) {
	int currState = 0;
	int acceptedState = 0;
	int nextState;
	char input[] = "000111";

	int length = strlen(input);
	for (int i = 0; i < length; i++) {
		if (currState == 7 || currState == 8) {
			printf("Dead state reached \n");
			break;
		}
		if (currState == 0 && input[i] == '0') {
			nextState = 1;
		}
		else if (currState == 0 && input[i] == '1') {
			nextState = 3;
		}
		else if (currState == 1 && input[i] == '0') {
			nextState = 0;
		}
		else if (currState == 1 && input[i] == '1') {
			nextState = 2;
		}
		else if (currState == 2 && input[i] == '0') {
			nextState = 3;
		}
		else if (currState == 2 && input[i] == '1') {
			nextState = 6;
		}
		else if (currState == 3 && input[i] == '0') {
			nextState = 2;
		}
		else if (currState == 3 && input[i] == '1') {
			nextState = 5;
		}
		else if (currState == 5 && input[i] == '0') {
			nextState = 6;
		}
		else if (currState == 5 && input[i] == '1') {
			nextState = 7;
		}
		else if (currState == 6 && input[i] == '0') {
			nextState = 5;
		}
		else if (currState == 6 && input[i] == '1') {
			nextState = 8;
		}
		currState = nextState;


	}
	if (currState == 0 || currState == 3 || currState == 5 || currState == 6) {
		printf("Input accepted! \n");

	}
	else {
		printf("input denied.");
	}
}