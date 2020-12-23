/* ColorPrint - v1.0.0.0 */
#include "ColorPrint.h"
#include <stdarg.h>

/*********************************************************************
 * �������ƣ�colorStr
 * �������ܣ�����ָ����ɫ����ʽ���ַ���
 * ���������str        - Ŀ���ַ���
 *           fontFormat - �ַ�����ʽ
 *           frontColor - ������ɫ
 *           backColor  - ������ɫ
 * ���ز�����string& ����װ�κ���ַ���
 * ��������δ�׳��쳣�����ؾ���װ�κ���ַ���
 *********************************************************************/
string ColorPrint::colorStr(const string& str, FontFormat fontFormat, FrontColor frontColor, BackColor backColor) {
	string format = to_string(fontFormat) + ";" + to_string(frontColor) + ";" + to_string(backColor) + "m";
	string styledStr = "\033[" + format + str + "\033[0m";
	return styledStr;
}


/*********************************************************************
 * �������ƣ�colorPrintf
 * �������ܣ�����ָ����ɫ����ʽ���ַ���
 * ���������format     - ��ʽ������ַ���
 *           fontFormat - �ַ�����ʽ
 *           frontColor - ������ɫ
 *           backColor  - ������ɫ
 * ���ز�����void
 * ����������ӡ������ʽ����ɫ���ַ���
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
 * �������ƣ�colorError
 * �������ܣ�����ָ����ɫ����ʽ���ַ���
 * ���������format     - ��ʽ������ַ���
 *           ...        - �ɱ䳤����
 * ���ز�����void
 * ����������ӡ����ʾ������ַ���
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
 * �������ƣ�colorError
 * �������ܣ�����ָ����ɫ����ʽ���ַ���
 * ���������format     - ��ʽ������ַ���
 *           ...        - �ɱ䳤����
 * ���ز�����void
 * ����������ӡ����ʾ��ȷ���ַ���
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
 * �������ƣ�colorError
 * �������ܣ�����ָ����ɫ����ʽ���ַ���
 * ���������format     - ��ʽ������ַ���
 *           ...        - �ɱ䳤����
 * ���ز�����void
 * ����������ӡ����ʾ������ַ���
 *********************************************************************/
void ColorPrint::colorWarning(const char* format, ...) {
	string str = colorStr(format, RESET, FRONT_YELLOW, BACK_BLACK);
	const char* colorFormat = str.c_str();

	va_list va;
	va_start(va, format);
	vprintf(colorFormat, va);
	va_end(va);
}

