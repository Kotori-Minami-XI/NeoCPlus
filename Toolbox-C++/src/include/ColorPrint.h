#ifndef COLOR_PRINT_H
#define COLOR_PRINT_H

#include <string>

using namespace std;

class ColorPrint
{
public:
	// ͨ�ø�ʽ����:
	enum FontFormat {
		RESET = 0,      //0 ������������
		BOLD,           //1 ���� / �Ӵ�
		FADE,           //2 ����
		UNDERLINE = 4,  //4 �»���
		TWINKLE,        //5 ��˸
		REVERSE,        //7 ��ת
		HIDDEN          //8 ����
	};

	// ������ɫ
	enum FrontColor {
		FRONT_BLACK = 30, //30 ��ɫ
		FRONT_RED,        //31 ��ɫ
		FRONT_GREEN,      //32 ��ɫ
		FRONT_YELLOW,     //33 ��ɫ
		FRONT_BLUE,       //34 ��ɫ
		FRONT_VIOLET,     //35 Ʒ��
		FRONT_CYAN,       //36 ��ɫ
		FRONT_WHITE       //37 ��ɫ
	};

	// ������ɫ
	enum BackColor {
		BACK_BLACK = 40, //40 ��ɫ
		BACK_RED,        //41 ��ɫ
		BACK_GREEN,      //42 ��ɫ
		BACK_YELLOW,     //43 ��ɫ
		BACK_BLUE,       //44 ��ɫ
		BACK_VIOLET,     //45 Ʒ��
		BACK_CYAN,       //46 ��ɫ
		BACK_WHITE       //47 ��ɫ
	};

	static string& colorStr(
		string& str,
		FontFormat fontFormat = FontFormat::RESET, 
		FrontColor frontColor = FrontColor::FRONT_WHITE,
		BackColor backColor = BackColor::BACK_BLACK);
};

#endif /* COLOR_PRINT_H */


