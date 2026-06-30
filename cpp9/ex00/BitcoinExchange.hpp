#pragma once

#ifndef __BITCOINEXCHANGE_HPP__
#define __BITCOINEXCHANGE_HPP__

#include <iostream>
#include <algorithm>
#include <iterator>
#include <map>
#include <fstream>
#include <string>
#include <iomanip>
#include <time.h>

void create_map(std::map<std::string, float>& data);
bool validDate(std::string date);
bool validValue(float value);
int find_exchange_rate(char **argv, std::map<std::string, float>& data);

#endif