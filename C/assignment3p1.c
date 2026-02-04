
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	int currState = 0;
	int nextState;
	int deadState = 4;
	int acceptedState = 3;
	char input[] = "010100000";
	int length = sizeof(input) / sizeof(input[0]);
	for (int i = 0; i < length; i++) {
		nextState = deadState;
		if (currState == deadState) {
			printf("Dead state reached.");
			return;
		}
		if (currState == acceptedState) {
			printf("Input accepted!!");
			return;
		}
		if (currState == 0 && (input[i] == '1' || input[i] == '0')) {
			nextState = 1;
		}
		if (currState == 1 && (input[i] == '1' || input[i] == '0')) {
			nextState = 2;
		}
		if (currState == 2 && input[i] == '0') {
			nextState = 3;
		}
		if (currState == 2 && input[i] == '1') {
			nextState = 4;
		}
		currState = nextState;

	}
	

}




