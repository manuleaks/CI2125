///
/// sort_double.h
///
#ifndef SORT_DOUBLE_H
#define SORT_DOUBLE_H

#pragma once

#include <vector>

int min(int lb, int ub, const std::vector<double>& data);
int min(const std::vector<double>& data);
void selection_sort(std::vector<double>& data);

#endif 