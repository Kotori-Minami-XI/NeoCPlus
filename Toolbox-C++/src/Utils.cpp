#include "Utils.h"

string& ColorPrint::colorStr(string& str, FontFormat fontFormat, FrontColor frontColor, BackColor backColor) {
	string format = to_string(fontFormat) + ";" + to_string(frontColor) + ";" + to_string(backColor) + "m";
	str = "\033[" + format + str + "\033[0m";
	return str;
}
