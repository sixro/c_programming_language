#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define COUNT_MAX_LEN    3
#define CMD_MAX_LEN     10
#define PARAMS_MAX_LEN 200

#define TRUE  1
#define FALSE 0

#define OUT       0
#define IN_CMD    2
#define IN_PARAMS 3

struct Command {
	char command[CMD_MAX_LEN];
	char params[PARAMS_MAX_LEN];
};

void init(char s[], int len) {
	int i;
	for (int i = 0; i < len; i++)
		s[i] = '\0';
}

int main(void) {
	int c, i;
	char command[CMD_MAX_LEN];
	char params[PARAMS_MAX_LEN];
	int state;

	char counttext[COUNT_MAX_LEN];
	int count;
	int curr_cmd;
	struct Command commands[10];

	init(counttext, COUNT_MAX_LEN);
	init(command, CMD_MAX_LEN);
	init(params, PARAMS_MAX_LEN);

	count = -1;
	state = OUT;
	i = 0;

	while ((c = getchar()) != EOF) {
		if (count == -1) {
			/* printf("*** reading count...\n"); */
			if (c == '\n') {
				counttext[i] = '\0';
				count = atoi(counttext);
				/* printf("Commands to read: %d\n", count); */

				curr_cmd = 0;
				i = 0;
				state = OUT;
			} else counttext[i++] = c;
		} else {
			/* printf("*** reading command %d / %d...\n", curr_cmd, count); */
			if (curr_cmd >= count)
				break;

			/* printf("*** ...\n"); */
			if (c == '\n') {
				if (state == IN_CMD)
					command[i] = '\0';
				if (state == IN_PARAMS)
					params[i] = '\0';

				/* printf("*** curr_cmd pre-compare: %d \"%s\"\n", curr_cmd, command); */
				if (strcmp(command, "") == 0)
					continue;
			
				strcpy(commands[curr_cmd].command, command);
				strcpy(commands[curr_cmd].params, params);

				command[0] = '\0';
				params[0] = '\0';
				state = OUT;
				i = 0;

				curr_cmd++;
				/* printf("*** curr_cmd: %d\n", curr_cmd); */
			}
			else if (c == ' ') {
				state = IN_PARAMS;
				command[i] = '\0';
				i = 0;
			}
			else {
				if (state == OUT)
					state = IN_CMD;
				if (state == IN_CMD) {
					/* printf("*** adding char %c to cmd\n", c); */
					command[i++] = c;
				}
				if (state == IN_PARAMS) {
					/* printf("*** adding char %c to params\n", c); */
					params[i++] = c;
				}
			}
		}
	}

	for (i = 0; i < count; i++) {
		printf("Executing command \"%s\" with params \"%s\"\n", commands[i].command, commands[i].params);
		if (strcmp(commands[i].command, "PING") == 0)
			printf("PONG\n");
	}
}
