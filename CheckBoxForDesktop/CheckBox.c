#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "CheckBox.h"
#include "Util.h"

enum KeyCode{
	SPACE_BAR = 32, ENTER = 13
};

enum Boolean{
	False, True
};

void CheckBox_Create(CheckBox* checkBox, char* text, int startPositionXToPrint, int startPositionYToPrint){
	TextItem_Create(&checkBox->text, text);
	checkBox->isChecked = False;
	checkBox->width = TextItem_GetTotalByte(checkBox->text);
	checkBox->height = 1;
	checkBox->startPositionToPrint.x = startPositionXToPrint;
	checkBox->startPositionToPrint.y = startPositionYToPrint;
}

void CheckBox_Print(CheckBox* checkBox, int color){
	int i;
	int j;
	Point startPositionToPrint = checkBox->startPositionToPrint;
	checkBox->width = checkBox->width % 2 == 1 ? checkBox->width + 1 : checkBox->width;
	CursorUtil_GotoXY(startPositionToPrint.x, startPositionToPrint.y++);
	FontUtil_ChangeFontColor(WHITE);
	printf("旨收旬");
	CursorUtil_GotoXY(startPositionToPrint.x, startPositionToPrint.y++);
	printf("早%s早", checkBox->isChecked ? "∵" : "  ");
	CursorUtil_GotoXY(startPositionToPrint.x, startPositionToPrint.y++);
	printf("曲收旭");
	startPositionToPrint.x += 7;
	startPositionToPrint.y -= 3;
	CursorUtil_GotoXY(startPositionToPrint.x, startPositionToPrint.y++);
	for (i = 0; i < checkBox->height; i++){
		CursorUtil_GotoXY(startPositionToPrint.x, startPositionToPrint.y++);
		FontUtil_ChangeFontColor(WHITE);
		FontUtil_ChangeFontColor(color);
		printf("%s", TextItem_GetText(&checkBox->text));
		for (j = 0; j < checkBox->width - TextItem_GetTotalByte(checkBox->text); j++){
			printf(" ");
		}
		FontUtil_ChangeFontColor(WHITE);
	}
}

int CheckBox_ProcessKey(CheckBox* checkBox){
	while (True){
		if (_kbhit()){
			int key = _getch();
			if (key == SPACE_BAR){
				checkBox->isChecked = !checkBox->isChecked;
				CheckBox_Print(checkBox, WHITE);
			}
			else if (key == ENTER){
				break;
			}
		}
	}
	return checkBox->isChecked;
}
