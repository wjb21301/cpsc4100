#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(void) {
	int currState = 0;
	int nextState;
	int acceptedState = 2;
	char input[] = "1101100010";
	int length = strlen(input);
	for (int i = 0; i < length; i++) {
		if (currState == 0 && input[i] == '0') {
			nextState = 2;
		}
		if (currState == 0 && input[i] == '1') {
			nextState = 1;
		}
		if (currState == 1 && (input[i] == '0' || input[i] == '1')) {
			nextState = 2;
		}
		if (currState == 2 && (input[i] == '0' || input[i] == '1')) {
			nextState = 1;
		}
		currState = nextState;

	}
	if (currState == acceptedState) {
		printf("Input accepted!!");
	}
	else {
		printf("Input denied.");
	}

}