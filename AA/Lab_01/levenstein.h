#pragma once

#include <string_view>

#include "../matrix.hpp"

using container::Matrix;

Matrix<std::size_t> DamerauLevenstein(std::string_view, std::string_view);
Matrix<std::size_t> Levenstein(std::string_view, std::string_view);
std::size_t RecursiveLevenstein(std::string_view, std::string_view);
Matrix<std::size_t> RecursiveMatrLevenstein(std::string_view, std::string_view);

