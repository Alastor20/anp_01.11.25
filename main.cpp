#include <iostream>

int **make_mtx(int r, int c);

int main()
{
    long long rows = 0, cols = 0;
    std::cin >> rows >> cols;
    if (std::cin.fail())
    {
        std::cerr << "ERROR: cant read\n";
        return 1;
    }
    int **mtx = nullptr;
    mtx = make_mtx(rows, cols);
}
