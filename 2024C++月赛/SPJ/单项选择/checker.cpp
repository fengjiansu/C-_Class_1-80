#include "testlib.h"
#include <cctype>

int main(int argc, char* argv[]) {
    // ��ʼ��
    registerTestlibCmd(argc, argv);

    // �ӱ�׼���ļ��ж�ȡ��ȷѡ��
    std::string correctAnswer = ans.readToken();

    // �Ӳ���������ļ��ж�ȡ�����ߵ�ѡ��
    std::string userAnswer = ouf.readToken();

    // ���������Ƿ�����������
    if (!ouf.seekEof()) {
        quitf(_pe, "�����ߵ����������������ݡ�");
    }

    // ����ת��Ϊ��д��ĸ�����Դ�Сд�������Ҫ���ִ�Сд������ȥ���ⲿ�֣�
    if (correctAnswer.length() != 1 || userAnswer.length() != 1) {
        quitf(_pe, "��ӦΪ�����ַ���");
    }

    char correctChar = std::toupper(correctAnswer[0]);
    char userChar = std::toupper(userAnswer[0]);

    // �����Ƿ�Ϊ��Ч��ѡ��� A��B��C��D��
    if (correctChar < 'A' || correctChar > 'D') {
        quitf(_fail, "��׼���е�ѡ�� '%c' ��Ч��ӦΪ A-D ֮�����ĸ��", correctChar);
    }

    if (userChar < 'A' || userChar > 'D') {
        quitf(_wa, "�����ߵ�ѡ�� '%c' ��Ч��ӦΪ A-D ֮�����ĸ��", userChar);
    }

    // �Ƚϲ����ߵĴ𰸺ͱ�׼��
    if (userChar == correctChar) {
        quitf(_ok, "����ȷ��������ѡ����ѡ�� '%c'��", userChar);
    } else {
        quitf(_wa, "�𰸴�����ȷ���� '%c'��������ѡ���� '%c'��", correctChar, userChar);
    }

    return 0;
}
