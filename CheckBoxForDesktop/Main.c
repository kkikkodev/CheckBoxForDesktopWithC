#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CheckBox.h"
#include "Util.h"

int main(int argc, char* argv[]){
	CheckBox checkBox = { 0, };
	char text[TEXT_SIZE] = { '\0', };
	int startPositionXToPrint;
	int startPositionYToPrint;
	printf("üũ �ڽ� ��� ���� ��ġ �Է� (x, y)\n�ܼ� â ũ�� ����� �ʵ��� ���� : ");
	scanf("%d %d", &startPositionXToPrint, &startPositionYToPrint);
	getchar();
	printf("üũ �ڽ� ���ڿ� �Է� : ");
	fgets(text, TEXT_SIZE, stdin);
	text[strlen(text) - 1] = '\0';
	system("cls");
	CheckBox_Create(&checkBox, text, startPositionXToPrint, startPositionYToPrint);
	CheckBox_Print(&checkBox, WHITE);
	printf("\n\nüũ ���� : %s\n", CheckBox_ProcessKey(&checkBox) ? "YES" : "NO");
	return 0;
}