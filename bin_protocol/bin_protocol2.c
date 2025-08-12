#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define COUNT_MAX_LEN    3
#define CMD_MAX_LEN     10
#define PNAME_MAX_LEN   10
#define PVAL_MAX_LEN   200

#define TRUE 1

#define OUT       0
#define IN_CMD    2
#define IN_PARAMS 3

typedef struct {
	char name[PNAME_MAX_LEN];
	char value[PVAL_MAX_LEN];
} Param;

void init(char s[], int len) {
	int i;
	for (i = 0; i < len; i++)
		s[i] = '\0';
}

void get_command(char line[]) {
	int c, i;

	init(line, CMD_MAX_LEN);
	i = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			if (i > 0)
				line[i] = '\0';
			break;
		}
		line[i++] = c;
	}
}

int get_count() {
	int c, i;
	char line[COUNT_MAX_LEN];

	init(line, COUNT_MAX_LEN);
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

void get_param(Param *p) {
	int c, i;
	char name[PNAME_MAX_LEN];
	char value[PVAL_MAX_LEN];
	int state;
	
	init(name, PNAME_MAX_LEN);
	init(value, PVAL_MAX_LEN);

	state = OUT;
	i = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			if (state == IN_CMD)
				name[i] = '\0';
			if (state == IN_PARAMS)
				value[i] = '\0';

			strcpy(p->name, name);
			strcpy(p->value, value);
			break;
		}
		else if (c == ' ' && state == IN_CMD) {
			state = IN_PARAMS;
			name[i] = '\0';
			i = 0;
		}
		else {
			if (state == OUT)
				state = IN_CMD;
			if (state == IN_CMD) {
				/* printf("*** adding char %c to cmd\n", c); */
				name[i++] = c;
			}
			if (state == IN_PARAMS) {
				/* printf("*** adding char %c to params\n", c); */
				value[i++] = c;
			}
		}
	}
}

int main(void) {
	int i;
	int count;
	char cmd[CMD_MAX_LEN];
	Param params[10];

	count = -1;
	i = 0;

	while (1 == 1) {
		get_command(cmd);
		printf("*** cmd: %s\n", cmd);

		count = get_count();
		printf("*** count: %d\n", count);
		if (count == 0) continue; /* new attempt to get a count */

		for (i = 0; i < count; i++)
			get_param(& params[i]);

		printf("*** Executing command \"%s\"\n", cmd);
		for (i = 0; i < count; i++) {
			printf("*** ... with param \"%s\" valued to \"%s\"\n", params[i].name, params[i].value);
			if (strcmp(cmd, "PING") == 0)
				printf("*** PONG\n");
		}
	}
}
