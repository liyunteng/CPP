// arithmetic_parsing.hpp - arithmetic_parsing

#ifndef ARITHMETIC_PARSING_HPP
#define ARITHMETIC_PARSING_HPP
#include <stack>
#include <string>
#include <vector>

class parser
{

public:
    parser()  = default;
    ~parser() = default;
    float parse(const std::string &input);

private:
    float eval(std::stack<std::string> &, std::stack<std::string> &);
    float eval_cs(const std::string &input);
    bool is_sub(const std::string &input);
    float parse_sub(const std::string &input, bool &valid);
    bool find_cs(const std::string &input, std::string::size_type start,
                 std::string::size_type &end, std::stack<std::string> &s1,
                 std::stack<std::string> &s2, bool &valid);
    bool find_pair(const std::string &input, std::string::size_type start,
                   std::string::size_type &end);

private:
    const std::vector<std::string> double_operators = {"+", "-", "*", "/"};
    const std::vector<std::string> single_operators = {"sin", "cos"};
    constexpr const static char prefix              = '(';
    constexpr const static char suffix              = ')';
    std::stack<float> val_stack;
};
#endif
