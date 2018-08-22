#include "ButtonPane.h"
#include <vector>
using namespace std;
vector<Button1> panel;

ButtonPane::ButtonPane(){}
ButtonPane::~ButtonPane() {}

void ButtonPane::add(Button1 b)
{
	panel.push_back(b);
}


