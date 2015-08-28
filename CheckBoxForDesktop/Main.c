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
	printf("체크 박스 출력 시작 위치 입력 (x, y)\n콘솔 창 크기 벗어나지 않도록 주의 : ");
	scanf("%d %d", &startPositionXToPrint, &startPositionYToPrint);
	getchar();
	printf("체크 박스 문자열 입력 : ");
	fgets(text, TEXT_SIZE, stdin);
	text[strlen(text) - 1] = '\0';
	system("cls");
	CheckBox_Create(&checkBox, text, startPositionXToPrint, startPositionYToPrint);
	CheckBox_Print(&checkBox, WHITE);
	printf("\n\n체크 여부 : %s\n", CheckBox_ProcessKey(&checkBox) ? "YES" : "NO");
	return 0;
}