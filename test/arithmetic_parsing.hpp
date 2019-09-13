// arithmetic_parsing.hpp - arithmetic_parsing

#ifndef ARITHMETIC_PARSING_HPP
#define ARITHMETIC_PARSING_HPP
#include <string>
#include <vector>
#include <stack>


class parser {

public:
    parser() = default;
    float eval(const std::string input);
    int find_sub(const std::string input);


private:
    const std::vector<std::string> double_operators = {"+", "-", "*", "/"};
    const std::vector<std::string> single_operators = {"sin", "cos"};
    constexpr const static char prefix = '(';
    constexpr const static char suffix = ')';
    std::stack<std::string> operator_stack;
    std::stack<std::string> operand_stack;

};
#endif
