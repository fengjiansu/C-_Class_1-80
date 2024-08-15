#include <string>
#include <iostream>
 
int main()
{
    std::string a = "0123456789abcdefghij";
 
    // count Ϊ npos ������ [pos, size())
    std::string sub1 = a.substr(10);
    std::cout << sub1 << '\n';
 
    // pos �� pos+count ���ڱ߽��ڣ����� [pos, pos+count)
    std::string sub2 = a.substr(5, 3);
    std::cout << sub2 << '\n';
 
    // pos �ڱ߽��ڣ� pos+count ���ڣ����� [pos, size()) 
    std::string sub4 = a.substr(a.size()-3, 50);
    // ���Ч��
    // std::string sub4 = a.substr(17, 3);
    // ��Ϊ a.size() == 20 �� pos == a.size()-3 == 17 �� a.size()-pos == 3
 
    std::cout << sub4 << '\n';
 
    try {
        // pos �ڱ߽��⣬�׳�
        std::string sub5 = a.substr(a.size()+3, 50);
        std::cout << sub5 << '\n';
    } catch(const std::out_of_range& e) {
        std::cout << "pos exceeds string size\n";
    }
}