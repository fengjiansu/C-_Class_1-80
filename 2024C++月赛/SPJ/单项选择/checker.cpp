#include "testlib.h"
#include <cctype>

int main(int argc, char* argv[]) {
    // 初始化
    registerTestlibCmd(argc, argv);

    // 从标准答案文件中读取正确选项
    std::string correctAnswer = ans.readToken();

    // 从参赛者输出文件中读取参赛者的选项
    std::string userAnswer = ouf.readToken();

    // 检查参赛者是否多输出了内容
    if (!ouf.seekEof()) {
        quitf(_pe, "参赛者的输出包含多余的内容。");
    }

    // 将答案转换为大写字母，忽略大小写（如果需要区分大小写，可以去掉这部分）
    if (correctAnswer.length() != 1 || userAnswer.length() != 1) {
        quitf(_pe, "答案应为单个字符。");
    }

    char correctChar = std::toupper(correctAnswer[0]);
    char userChar = std::toupper(userAnswer[0]);

    // 检查答案是否为有效的选项（如 A、B、C、D）
    if (correctChar < 'A' || correctChar > 'D') {
        quitf(_fail, "标准答案中的选项 '%c' 无效，应为 A-D 之间的字母。", correctChar);
    }

    if (userChar < 'A' || userChar > 'D') {
        quitf(_wa, "参赛者的选项 '%c' 无效，应为 A-D 之间的字母。", userChar);
    }

    // 比较参赛者的答案和标准答案
    if (userChar == correctChar) {
        quitf(_ok, "答案正确，参赛者选择了选项 '%c'。", userChar);
    } else {
        quitf(_wa, "答案错误，正确答案是 '%c'，参赛者选择了 '%c'。", correctChar, userChar);
    }

    return 0;
}
