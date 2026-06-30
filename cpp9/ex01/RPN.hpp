#pragma once

#ifndef __RPN_HPP__
#define __RPN_HPP__

#include <iostream>
#include <stack>
#include <cstdlib>

bool isOperator(char c);
int doOperation(char c, std::stack<int>& st);

#endif