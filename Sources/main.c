#include <unistd.h>
#include <math.h>

int line_len;

int ft_isspace(char c)
{
    return (c == ' ' ||
    c == '\f' ||
    c == '\n' ||
    c == '\r' ||
    c == '\t' ||
    c == '\v');
}

int ft_strlen(const char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int ft_putstr(const char *str)
{
    write(1, str, ft_strlen(str));
    return 0;
}

void putcharrep(char c, int n)
{
    while (n--)
        write(1, &c, 1);
}

void putsep(void)
{
    const int sq = sqrt(line_len);
    ft_putstr("|");
    putcharrep('-', line_len + sq - 1);
    ft_putstr("|");
    ft_putstr("\n");
}

int print_solution(const char *grid)
{
    static int f = 0;
    if (f)
        write(1, "\n", 1);
    f = 1;
    const int sq = sqrt(line_len);
    for (int i = 0; i < line_len; i++)
    {
        if (i % sq == 0)
            putsep();
        for (int j = 0; j < sq; j++)
        {
            if (!j)
                ft_putstr("|");
            write(1, &grid[i * line_len + j * sq], sq);
            ft_putstr("|");
        }
        write(1, "\n", 1);
    }
    putsep();
    return 1;
}

int isinline(char *argv[], int index, char c)
{
    for (int i = 0; i < line_len; i++)
        if (argv[2][(int)(index / line_len) * line_len + i] == c)
            return 1;
    return 0;
}

int isincolumn(char *argv[], int index, char c)
{
    const int x = index % line_len;

    for (int y = 0; y < line_len; y++)
        if (argv[2][y * line_len + x] == c)
            return 1;
    return 0;
}

int isinsquare(char *argv[], int index, char c)
{
    const int sq = sqrt(line_len);
    const int x0 = index % line_len - index % sq;
    const int y0 = index / line_len - index / line_len % sq;

    for (int y = 0; y < sq; y++)
        for (int x = 0; x < sq; x++)
            if (argv[2][(y0 + y) * line_len + (x0 + x)] == c)
                return 1;
    return 0;
}   

int can_put(char *argv[], int index, char c)
{
    if (
    isinline(argv, index, c) ||
    isincolumn(argv, index, c) ||
    isinsquare(argv, index, c))
        return 0;
    return 1;
}

int solve(char *argv[], int index)
{
    if (index == line_len * line_len)
        return print_solution(argv[2]);
    if (argv[2][index] != '0')
        solve(argv, index + 1);
    if (argv[2][index] == '0')
        for (int i = 0; i < line_len; i++)
            if (can_put(argv, index, argv[1][i]))
            {
                argv[2][index] = argv[1][i];
                solve(argv, index + 1);
                argv[2][index] = '0';
            }
    return 0;
}

int hasdupli(const char *list)
{
    for (int i = 0; i < ft_strlen(list) - 1; i++)
        for (int i2 = 1; i + i2 < ft_strlen(list); i2++)
            if (list[i] == list[i + i2])
                return 1;
    return 0;
}

int isvalidlist(const char *list)
{
    if (!list[0])
        return 0;
    for (int i = 0; list[i]; i++)
        if (list[i] == '0' || ft_isspace(list[i]))
            return 0;
    if (hasdupli(list))
        return 0;
    return ((int)sqrt(ft_strlen(list)) == sqrt(ft_strlen(list)));    
}

void myswap(char *a, char *b)
{
    const char c = *a;

    *a = *b;
    *b = c;
}

void sortgrid(char *argv[])
{
    for (int i = 0; i < ft_strlen(argv[2]); i++)
        for (int j = 0; j < ft_strlen(argv[2]) - 1; j++)
            if (ft_isspace(argv[2][j]))
                myswap(&argv[2][j], &argv[2][j + 1]);
}

int has(const char *list, char c)
{
    for (int i = 0; list[i]; i++)
        if (list[i] == c)
            return 1;
    return 0;
}

int isvalidgrid(char *argv[])
{
    int count = 0;

    for (int i = 0; argv[2][i]; i++)
        if (ft_isspace(argv[2][i]))
            continue;
        else if (!has(argv[1], argv[2][i]) && argv[2][i] != '0')
            return 0;
        else
            count++;
    return (line_len * line_len == count);
}

//0 and isspace characters cannot be in the valid characters list
int main(int argc, char *argv[])
{    
    (void)argc;
    line_len = ft_strlen(argv[1]);
    if (!isvalidlist(argv[1]))
        return ft_putstr("Error: invalid character list.\n") + 1;
    if (!isvalidgrid(argv))
        return ft_putstr("Error: invalid grid.\n") + 1;
    sortgrid(argv);
    solve(argv, 0);
}
