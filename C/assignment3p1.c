#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int currState = 0;
    int nextState;
    int deadState = 5;
    int acceptedState1 = 1;
    int acceptedState2 = 4;
    char input[] = "010100000";
    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        nextState = deadState;
        if (currState == deadState) {
            printf("Dead state reached.\n");
            break;
        }
        else if (currState == 0 && input[i] == '0') {
            nextState = 1;
        }
        else if (currState == 0 && input[i] == '1') {
            nextState = 3;
        }
        else if (currState == 1 && (input[i] == '0' || input[i] == '1')) {
            nextState = 2;
        }
        else if (currState == 2 && (input[i] == '0' || input[i] == '1')) {
            nextState = 1;
        }
        else if (currState == 3 && (input[i] == '0' || input[i] == '1')) {
            nextState = 4;
        }
        else if (currState == 4 && (input[i] == '0' || input[i] == '1')) {
            nextState = 3;
        }
        currState = nextState;
    }
    if (currState == acceptedState1 || currState == acceptedState2)
        printf("Input accepted!!\n");
    else
        printf("Input rejected.\n");
    return 0;
}




