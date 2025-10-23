#include"checkC.h"

int **alloc2D(int n) {
    int **a = (int**)malloc(n * sizeof(int *));
    if (!a) { printf("Memory allocation failed\n"); exit(1); }
    for(int i = 0; i < n; i++) {
        a[i] = (int*)malloc(n * sizeof(int));
        if (!a[i]) { printf("Memory allocation failed\n"); exit(1); }
    }
    return a;
}

void free2D(int **a, int n) {
    for(int i = 0; i < n; i++) free(a[i]);
    free(a);
}

void printErrorAndExit(const char *msg) {
    printf("%s\n", msg);
    exit(1);
}

// Метод для нечётного n: метод Сиамского (де ла Лубер)
void fillOdd(int **sq, int n) {
    int i = 0, j = n/2;
    for(int k = 1; k <= n*n; k++) {
        sq[i][j] = k;
        int ni = (i - 1 + n) % n;
        int nj = (j + 1) % n;
        if (sq[ni][nj] != 0) {
            i = i + 1;
            if (i >= n) i = 0;
        } else {
            i = ni;
            j = nj;
        }
    }
}

// Метод для n кратного 4 (4k): «дважды‑чётный» (доуглинг)
void fillDoublyEven(int **sq, int n) {
    // заполняем по строкам
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            sq[i][j] = i * n + j + 1;
        }
    }
    // затем заменяем в блоках: по шаблону
    int nn = n*n + 1;
    int quarter = n/4;
    int threeQuarter = 3 * n / 4;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if ( (i < quarter && j < quarter) ||
                 (i < quarter && j >= threeQuarter) ||
                 (i >= threeQuarter && j < quarter) ||
                 (i >= threeQuarter && j >= threeQuarter) ||
                 (i >= quarter && i < threeQuarter && j >= quarter && j < threeQuarter) ) {
                sq[i][j] = nn - sq[i][j];
            }
        }
    }
}

// Метод для n = 4k + 2 (сингл‑чётный): метод Стрэйчи/разбиения

void fillSinglyEven_LUX(int **sq, int n) {
    int m = n / 2;               // m = 2k + 1
    int totalBlocks = m * m;     // число блоков 2×2
    // подготовка буквой матрицы размер m×m
    char *letter = (char*)malloc(m * m);
    int k = (n - 2) / 4;
    int rowsL = k + 1;
    int rowU  = rowsL;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (i < rowsL) letter[i * m + j] = 'L';
            else if (i == rowU) letter[i * m + j] = 'U';
            else letter[i * m + j] = 'X';
        }
    }
    // обмен «U» в центре с «L» над ней
    int midc = m / 2;
    char tmp = letter[rowU * m + midc];
    letter[rowU * m + midc] = letter[(rowU-1) * m + midc];
    letter[(rowU-1) * m + midc] = tmp;

    // инициализируем квадрат нулями
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            sq[i][j] = 0;

    // переменные для обхода блоков
    int r = 0, c = m/2;
    int blockNum = 1;

    // заполняем блоки
    for (int b = 0; b < totalBlocks; b++) {
        int base = (blockNum - 1) * 4 + 1;
        char ch = letter[r * m + c];
        int bigR = r * 2;
        int bigC = c * 2;

        if (ch == 'L') {
            // схема L
            sq[bigR + 0][bigC + 0] = base + 3;
            sq[bigR + 0][bigC + 1] = base + 0;
            sq[bigR + 1][bigC + 0] = base + 1;
            sq[bigR + 1][bigC + 1] = base + 2;
        } else if (ch == 'U') {
            // схема U
            sq[bigR + 0][bigC + 0] = base + 0;
            sq[bigR + 0][bigC + 1] = base + 3;
            sq[bigR + 1][bigC + 0] = base + 1;
            sq[bigR + 1][bigC + 1] = base + 2;
        } else { // ch == 'X'
            // схема X
            sq[bigR + 0][bigC + 0] = base + 0;
            sq[bigR + 0][bigC + 1] = base + 3;
            sq[bigR + 1][bigC + 0] = base + 2;
            sq[bigR + 1][bigC + 1] = base + 1;
        }

        blockNum++;

        // перемещение «вверх‑вправо» с обёрткой
        int nr = r - 1;
        int nc = c + 1;
        if (nr < 0) nr = m - 1;
        if (nc >= m) nc = 0;
        // если блок следующий уже заполнен — вниз
        if (sq[nr*2][nc*2] != 0) {
            r = r + 1;
            if (r >= m) r = 0;
        } else {
            r = nr;
            c = nc;
        }
    }

    free(letter);
}


void constructMagicSquare(int n, int **sq) {
    // инициализация нулями
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) sq[i][j] = 0;

    if (n % 2 == 1) {
        fillOdd(sq, n);
    } else if (n % 4 == 0) {
        fillDoublyEven(sq, n);
    } else {
        // n even but not divisible by 4
        fillSinglyEven_LUX(sq, n);
    }
}

void checkMagicSum(int **sq, int n) {
    long long magicSum = 0;
    for(int j = 0; j < n; j++) magicSum += sq[0][j];
    printf("Magic sum: %lld\n", magicSum);

    int ok = 1;
    for(int i = 1; i < n && ok; i++) {
        long long s = 0;
        for(int j = 0; j < n; j++) s += sq[i][j];
        if (s != magicSum) ok = 0;
    }
    for(int j = 0; j < n && ok; j++) {
        long long s = 0;
        for(int i = 0; i < n; i++) s += sq[i][j];
        if (s != magicSum) ok = 0;
    }

    if (ok) printf("All rows and columns have the same sum.\n");
    else printf("Error: rows or columns differ!\n");
}

int main() {
    printf("6 Задание Вариант 2\nВыполнил Антонюк Владислав Группа 553501\n");
    printf("Надо построить магический квадрат NxN,где N вводится пользователем\n");
    for (int go = 1; go == 1; go = repeat_c(&go))
    {
        int n = get_natural_number_c(&n);
        int **sq = alloc2D(n);
        constructMagicSquare(n, sq);
        checkMagicSum(sq, n);
        free2D(sq, n);
    }
    return 0;
}
