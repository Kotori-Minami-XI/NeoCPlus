/* ColorPrint - v1.0.0.0 */
#include "ColorPrint.h"
#include <stdarg.h>

/*********************************************************************
 * 函数名称：colorStr
 * 函数功能：返回指定颜色和样式的字符串
 * 输入参数：str        - 目标字符串
 *           fontFormat - 字符串样式
 *           frontColor - 字体颜色
 *           backColor  - 背景颜色
 * 返回参数：string& 经过装饰后的字符串
 * 输出结果：未抛出异常，返回经过装饰后的字符串
 *********************************************************************/
string ColorPrint::colorStr(const string& str, FontFormat fontFormat, FrontColor frontColor, BackColor backColor) {
	string format = to_string(fontFormat) + ";" + to_string(frontColor) + ";" + to_string(backColor) + "m";
	string styledStr = "\033[" + format + str + "\033[0m";
	return styledStr;
}


/*********************************************************************
 * 函数名称：colorPrintf
 * 函数功能：返回指定颜色和样式的字符串
 * 输入参数：format     - 格式化输出字符串
 *           fontFormat - 字符串样式
 *           frontColor - 字体颜色
 *           backColor  - 背景颜色
 * 返回参数：void
 * 输出结果：打印出有样式和颜色的字符串
 *********************************************************************/
void ColorPrint::colorPrintf(const char* format, FontFormat fontFormat, FrontColor frontColor, BackColor backColor, ...) {
	string str = colorStr(format, RESET, FRONT_RED, BACK_BLACK);
	const char* colorFormat = str.c_str();

	va_list va;
	va_start(va, backColor);
	vprintf(colorFormat, va);
	va_end(va);
}


/*********************************************************************
 * 函数名称：colorError
 * 函数功能：返回指定颜色和样式的字符串
 * 输入参数：format     - 格式化输出字符串
 *           ...        - 可变长数组
 * 返回参数：void
 * 输出结果：打印出提示错误的字符串
 *********************************************************************/
void ColorPrint::colorError(const char* format, ...) {
	string str = colorStr(format, RESET, FRONT_RED, BACK_BLACK);
	const char* colorFormat = str.c_str();

	va_list va;
	va_start(va, format);
	vprintf(colorFormat, va);
	va_end(va);
}


/*********************************************************************
 * 函数名称：colorError
 * 函数功能：返回指定颜色和样式的字符串
 * 输入参数：format     - 格式化输出字符串
 *           ...        - 可变长数组
 * 返回参数：void
 * 输出结果：打印出提示正确的字符串
 *********************************************************************/
void ColorPrint::colorPass(const char* format, ...) {
	string str = colorStr(format, RESET, FRONT_GREEN, BACK_BLACK);
	const char* colorFormat = str.c_str();

	va_list va;
	va_start(va, format);
	vprintf(colorFormat, va);
	va_end(va);
}


/*********************************************************************
 * 函数名称：colorError
 * 函数功能：返回指定颜色和样式的字符串
 * 输入参数：format     - 格式化输出字符串
 *           ...        - 可变长数组
 * 返回参数：void
 * 输出结果：打印出提示警告的字符串
 *********************************************************************/
void ColorPrint::colorWarning(const char* format, ...) {
	string str = colorStr(format, RESET, FRONT_YELLOW, BACK_BLACK);
	const char* colorFormat = str.c_str();

	va_list va;
	va_start(va, format);
	vprintf(colorFormat, va);
	va_end(va);
}

