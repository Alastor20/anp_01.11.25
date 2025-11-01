#include <iostream>
#include <cstddef>

int **make_mtx(int r, int c);
void output(const int *const *mtx, int r, int c);
void rm(int **mtx, int r);
int **convert(const int *t, size_t n, const size_t *lns, size_t rows);

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

    if (std::cin.fail())
    {
        std::cerr << "ERROR: cant read\n";
        rm(mtx, rows);
        return 1;
    }
    output(mtx, rows, cols);
    rm(mtx, rows);
}

void rm(int **mtx, size_t r)
{
    for (size_t i = 0; i < r; ++i)
    {
        delete[] mtx[i];
    }
    delete[] mtx;
}

int **make_mtx(size_t r, const size_t *c)
{
    int **mtx = new int *[r];
    for (size_t i = 0; i < r; ++i)
    {
        try
        {
            mtx[i] = new int[c[i]];
        }
        catch (const std::bad_alloc &e)
        {
            rm(mtx, i);
            throw;
        }
    }
    return mtx;
}

void output(const int *const *mtx, size_t r, size_t *c)
{
    for (size_t i = 0; i < r; ++i)
    {
        for (size_t j = 0; j < c[i]; ++j)
        {
            std::cout << mtx[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

int **convert(const int *t, size_t n, const size_t *lns, size_t rows)
{
    size_t k = 0;
    int **mas = nullptr;
    mas = make_mtx(rows, lns);
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < lns[i]; ++j)
        {
            mas[i][j] = t[k++];
        }
    }
    return mas;
}
