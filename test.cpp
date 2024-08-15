#include <string>
#include <iostream>
 
int main()
{
    std::string a = "0123456789abcdefghij";
 
    // count 为 npos ，返回 [pos, size())
    std::string sub1 = a.substr(10);
    std::cout << sub1 << '\n';
 
    // pos 和 pos+count 都在边界内，返回 [pos, pos+count)
    std::string sub2 = a.substr(5, 3);
    std::cout << sub2 << '\n';
 
    // pos 在边界内， pos+count 不在，返回 [pos, size()) 
    std::string sub4 = a.substr(a.size()-3, 50);
    // 这等效于
    // std::string sub4 = a.substr(17, 3);
    // 因为 a.size() == 20 ， pos == a.size()-3 == 17 而 a.size()-pos == 3
 
    std::cout << sub4 << '\n';
 
    try {
        // pos 在边界外，抛出
        std::string sub5 = a.substr(a.size()+3, 50);
        std::cout << sub5 << '\n';
    } catch(const std::out_of_range& e) {
        std::cout << "pos exceeds string size\n";
    }
}