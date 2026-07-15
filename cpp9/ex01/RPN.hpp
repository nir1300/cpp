#pragma once

#ifndef __RPN_HPP__
#define __RPN_HPP__

#include <iostream>
#include <stack>


bool isOperator(char c);
int doOperation(char c, std::stack<int>& st);
bool errorHandling(int argc, char **argv);
int executeRPN(std::string arg, std::stack<int> st);

#endif