
#include "dmfix_win_console.h"
#include "gtest.h"
#include <iostream>

TEST(ConsoleEncodingTest, CodePageSettings) {
#ifdef _WIN32
    EXPECT_EQ(GetConsoleOutputCP(), 65001);
    EXPECT_EQ(GetConsoleCP(), 65001);
#else
    const char* locale = std::setlocale(LC_ALL, nullptr);
    EXPECT_NE(std::strstr(locale, "utf8"), nullptr);
#endif
}

TEST(ConsoleEncodingTest, cout) {
    std::cout << "\033[34mhello world\033[0m" << std::endl;
}
