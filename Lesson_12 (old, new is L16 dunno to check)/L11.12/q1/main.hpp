/*
 Serves as template
*/

#ifndef MAIN_HPP // Header guard
#define MAIN_HPP

#include <iostream> // for access to std::streamsize type
#include <limits>   //  for access to max funcion

namespace buffer_op
{
    // Expression for stream max size, to ignore cin buffers
    inline constexpr std::streamsize max{std::numeric_limits<std::streamsize>::max()};
}

int reqUserNameNum();

void getnames(std::string name_list[], int list_size);

void print_name_list(const std::string name_list[], const int list_size);

#endif