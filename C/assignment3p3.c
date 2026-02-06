#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(void) {
	int currState = 0;
	int acceptedState = 0;
	int nextState;
	int deadState = 3;
	char input[] = "10000000";
	int length = strlen(input);
	for (int i = 0; i < length; i++) {
		if (currState == deadState) {
			printf("Dead state reached. \n");
			break;
		}
		nextState = deadState;
		if (currState == 0 && input[i] == '1') {
			nextState = 1;

		}
		else if (currState == 0 && input[i] == '0') {
			nextState = 0;
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
			nextState = 0;
		}
		currState = nextState;
	}
	if (currState == acceptedState) {
		printf("input accepted");
	}
	else {
		printf("input denied.");
	}
}