#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int blocks[25][25];

void find(int i, int*a, int*b) {
	int j,k;

	for(j=0; j<n; j++) {
		for(k=1; k<=blocks[j][0]; k++) {
			if (blocks[j][k]==i) {
				*a = j;
				*b = k;
				return;
			}
		}
	}
}

void returnblocks(int a, int b) {
	int i;

	for(i=b; i<=blocks[a][0]; i++) {
		blocks[blocks[a][i]][0] = 1;
		blocks[blocks[a][i]][1] = blocks[a][i];
	}
	blocks[a][0] = b-1;
}




int main(void) {
	int a,b;
	char line[100];
	int xa,xb,ya,yb;
	int p,i;

	fgets(line, 100, stdin);
	sscanf(line, "%d", &n);

	for(i=0; i<n; i++) {
		blocks[i][0] = 1;
		blocks[i][1] = i;
	}

	while(1) {
		char command[10],type[10];

		fgets(line, 100, stdin);
		sscanf(line, "%s %d %s %d", command, &a, type, &b);
		if (!strcmp(command, "quit")) {
			break;
		}
		find(a, &xa, &ya);
		find(b, &xb, &yb);
		if (xa==xb || a==b) {
			continue;
		}

		if (!strcmp(command, "move")) {
			returnblocks(xa, ya+1);
		}
		if (!strcmp(type, "onto")) {
			returnblocks(xb, yb+1);
		}

		yb = blocks[xb][0];
		for(p=0; ya<=blocks[xa][0]; p++) {
			blocks[xb][++yb] = blocks[xa][ya++];
		}
		blocks[xa][0] -= p;
		blocks[xb][0] = yb;

	}
	for(i=0; i<n; i++) {
		printf("%d:", i);
		for(p=1; p<=blocks[i][0]; p++) {
			printf(" %d", blocks[i][p]);
		}
		printf("\n");
	}
	return 0;
}