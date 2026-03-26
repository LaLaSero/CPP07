#include "iter.hpp"
#include <string>

template <typename T>
static void func(T& t) {
    std::cout << "variable version called: " << t << std::endl;
}

template <typename T>
static void func(const T& t) {
    std::cout << "const version called: " << t << std::endl;
}

static void add_suffix(std::string& s) {
    s += "!";
}

static void add_one(int& n) {
    n += 1;
}

int main(void)
{
    std::string arry_str[] = {"hell" , "o" ,"world"};
    size_t len_s = 3;
    std::cout << "== string before ==" << std::endl;
    iter(arry_str,len_s,&func);
    iter(arry_str,len_s,&add_suffix);
    std::cout << "== string after add_suffix ==" << std::endl;
    iter(arry_str,len_s,&func);

    int arry_m[] = {10, 20, 30};
    std::cout << "== int before ==" << std::endl;
    iter(arry_m, len_s, &func);
    iter(arry_m, len_s, &add_one);
    std::cout << "== int after add_one ==" << std::endl;
    iter(arry_m, len_s, &func);

    const int  arry_n[] = {1,2,3};
    std::cout << "== const int ==" << std::endl;
    iter(arry_n,len_s,&func);

    return (0);
}
