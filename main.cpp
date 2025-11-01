#include <iostream>
#include <cstddef>

int **make_mtx(size_t r, size_t *c);
void output(const int *const *mtx, size_t r, size_t *c);
void rm(int **mtx, size_t r);
int **convert(const int *t, size_t n, const size_t *lns, size_t rows);

int main()
{
    size_t rows = 0;
    std::cin >> rows;
    size_t *lns = nullptr;
    try
    {
        lns = new size_t[rows];
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "ERROR: alloc\n";
        return 2;
    }
    for (size_t i = 0; i < rows; ++i)
    {
        std::cin >> lns[i];
    }
    if (std::cin.fail())
    {
        std::cerr << "ERROR: cant read\n";
        delete[] lns;
        return 1;
    }
    size_t n = 0;
    int *t = nullptr;
    std::cin >> n;
    try
    {
        t = new int[n];
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "ERROR: alloc\n";
        delete[] lns;
        return 2;
    }
    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> t[i];
    }
    if (std::cin.fail())
    {
        std::cerr << "ERROR: cant read\n";
        delete[] lns;
        delete[] t;
        return 1;
    }
    int **res = nullptr;
    try
    {
        res = convert(t, n, lns, rows);
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "ERROR: alloc\n";
        delete[] lns;
        delete[] t;
        return 2;
    }

    output(res, rows, lns);
    rm(res, rows);
    delete[] lns;
    delete[] t;
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
