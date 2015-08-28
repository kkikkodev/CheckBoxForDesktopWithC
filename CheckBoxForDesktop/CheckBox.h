#ifndef _CHECK_BOX_H
#define _CHECK_BOX_H

#include "TextItem.h"
#include "Point.h"

typedef struct _checkBox{
	TextItem text;
	int isChecked;
	int width;
	int height;
	Point startPositionToPrint;
}CheckBox;

void CheckBox_Create(CheckBox* checkBox, char* text, int startPositionXToPrint, int startPositionYToPrint);
void CheckBox_Print(CheckBox* checkBox, int color);
int CheckBox_ProcessKey(CheckBox* checkBox);

#endif