#include <iostream>

int main()
{
    long long a = 0, b = 0;
    std::cin >> a >> b;
    if (std::cin.fail())
    {
        std::cerr << "ERROR: cant read\n";
        return 1;
    }
}
