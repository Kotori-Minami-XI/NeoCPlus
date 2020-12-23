#ifndef COLOR_PRINT_H  /* ColorPrint - v1.0.0.0 */
#define COLOR_PRINT_H

#include <string>
#include <stdarg.h>

using namespace std;

// 通用格式控制:
enum FontFormat {
	RESET = 0,      //0 重置所有属性
	BOLD,           //1 高亮 / 加粗
	FADE,           //2 暗淡
	UNDERLINE = 4,  //4 下划线
	TWINKLE,        //5 闪烁
	REVERSE,        //7 反转
	HIDDEN          //8 隐藏
};

// 字体颜色
enum FrontColor {
	FRONT_BLACK = 30, //30 黑色
	FRONT_RED,        //31 红色
	FRONT_GREEN,      //32 绿色
	FRONT_YELLOW,     //33 黄色
	FRONT_BLUE,       //34 蓝色
	FRONT_VIOLET,     //35 品红
	FRONT_CYAN,       //36 青色
	FRONT_WHITE       //37 白色
};

// 背景颜色
enum BackColor {
	BACK_BLACK = 40, //40 黑色
	BACK_RED,        //41 红色
	BACK_GREEN,      //42 绿色
	BACK_YELLOW,     //43 黄色
	BACK_BLUE,       //44 蓝色
	BACK_VIOLET,     //45 品红
	BACK_CYAN,       //46 青色
	BACK_WHITE       //47 白色
};

class ColorPrint
{
public:

	static string colorStr(
		const string& str,
		FontFormat fontFormat = FontFormat::RESET,
		FrontColor frontColor = FrontColor::FRONT_WHITE,
		BackColor backColor = BackColor::BACK_BLACK);

	static void colorPrintf(
		const char* format,
		FontFormat fontFormat,
		FrontColor frontColor,
		BackColor backColor, ...);

	static void colorError(const char* format, ...);

	static void colorPass(const char* format, ...);

	static void colorWarning(const char* format, ...);


};

#endif /* COLOR_PRINT_H */


