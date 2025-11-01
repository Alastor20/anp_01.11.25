#include <iostream>

int **make_mtx(int r, int c);
void input(int **mtx, int r, int c);
void output(const int *const *mtx, int r, int c);
void rm(int **mtx, int r);

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
    try
    {
        mtx = make_mtx(rows, cols);
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "ERROR: alloc\n";
        return 2;
    }
    input(mtx, rows, cols);
    if (std::cin.fail())
    {
        std::cerr << "ERROR: cant read\n";
        rm(mtx, rows);
        return 1;
    }
    output(mtx, rows, cols);
    rm(mtx, rows);
}

void rm(int **mtx, int r)
{
    for (size_t i = 0; i < r; ++i)
    {
        delete[] mtx[i];
    }
    delete[] mtx;
}

int **make_mtx(int r, int c)
{
    int **mtx = new int *[r];
    for (size_t i = 0; i < c; ++i)
    {
        try
        {
            mtx[i] = new int[c];
        }
        catch (const std::bad_alloc &e)
        {
            rm(mtx, i);
            throw;
        }
    }
    return mtx;
}

void input(int **mtx, int r, int c)
{
    for (size_t i = 0; i < r; ++i)
    {
        for (size_t j = 0; j < c; ++j)
        {
            std::cin >> mtx[i][j];
        }
    }
}

void output(const int *const *mtx, int r, int c)
{
    for (size_t i = 0; i < r; ++i)
    {
        for (size_t j = 0; j < c; ++j)
        {
            std::cout << mtx[i][j] << ' ';
        }
        std::cout << '\n';
    }
}
