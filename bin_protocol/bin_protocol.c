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

typedef struct {
	char command[CMD_MAX_LEN];
	char params[PARAMS_MAX_LEN];
} Command;

void init(char s[], int len) {
	int i;
	for (i = 0; i < len; i++)
		s[i] = '\0';
}

int get_count() {
	int c, i;
	char line[COUNT_MAX_LEN];

	init(line, CMD_MAX_LEN);
	i = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			if (i == 0)
				break;
			return atoi(line);
		}
		line[i++] = c;
	}
	return -1;
}

void get_command(Command *cmd) {
	int c, i;
	char command[CMD_MAX_LEN];
	char params[PARAMS_MAX_LEN];
	int state;
	
	init(command, CMD_MAX_LEN);
	init(params, PARAMS_MAX_LEN);

	state = OUT;
	i = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			if (state == IN_CMD)
				command[i] = '\0';
			if (state == IN_PARAMS)
				params[i] = '\0';

			strcpy(cmd->command, command);
			strcpy(cmd->params, params);
			break;
		}
		else if (c == ' ' && state == IN_CMD) {
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

int main(void) {
	int i;
	int count;
	Command commands[10];

	count = -1;
	i = 0;

	while (1 == 1) {
		count = get_count();
		if (count < 0) break; /* interrupt the program */
		if (count == 0) continue; /* new attempt to get a count */

		for (i = 0; i < count; i++)
			get_command(& commands[i]);

		for (i = 0; i < count; i++) {
			printf("*** Executing command \"%s\" with params \"%s\"\n", commands[i].command, commands[i].params);
			if (strcmp(commands[i].command, "PING") == 0)
				printf("*** PONG\n");
		}
	}
}
