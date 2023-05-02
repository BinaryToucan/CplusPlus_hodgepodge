#include <iostream>

// Файл с функциями по второму блоку курса

char *newSizeString(char * str, unsigned size, unsigned new_size)
{
    char *new_str = new char[new_size];
    unsigned i = 0;
    str = str - size;
    while(i++ < size)
    {
        *new_str++ = *str++;
    }
    str = str - size;
    delete [] str;
    return new_str;
}

// Функция, которая считывает поток ввода посимвольно, пока не
// достигнет конца потока или не встретит символ переноса строки ('\n'), и возвращает C-style строку с прочитанными символами.
char *getline()
{
    const unsigned update = 100;
    unsigned size = update;
    unsigned i = 0;
    char c;
    char *str = new char[size];

    while(std::cin.get(c) && c != '\n')
    {
        if(i >= size){
            size += update;
            str = newSizeString(str, size - update, size);
        }
        i++;
        *str++ = c;
    }
    if(i >= size){
        size++;
        str = newSizeString(str, size - 1, size);
    }
    *str = '\0';
    str = str - i;
    return str;
}

// Функция по изменению массива с последующим освобождением памяти
char *resize(const char *str, unsigned size, unsigned new_size)
{
    char *new_str = new char[new_size];
    unsigned i = 0;
    while((++i <= new_size) && (i <= size))
    {
        *new_str++ = *str++;
    };
    new_str = new_str - i + 1;
    str = str - i + 1;
    delete [] str;
    return new_str;
}

// Функция по вычислению длины
unsigned strlen(const char *str)
{
    unsigned n = 0;
    while(*str != '\0'){
        str = str + 1;
        n++;
    }
    return n;
}

// Функция по добавлению в конец первой строки второй строки
void strcat(char *to, const char *from)
{
    while (*to) to++;
    while (*to++ = *from++);
}

// Функция вычисления наибольшего общего делителя двух положительных целых чисел (Greatest Common Divisor, GCD)
unsigned gcd(unsigned a, unsigned b)
{
    if(a == 0) return b;
    if(b == 0) return a;
    else if(a >= b) return gcd(b, a%b);
    else return gcd(a, b%a);
}

// Функция, которая сдвигает содержимое массива влево на заданное число позиций (циклический сдвиг).
void rotate(int a[], unsigned size, int shift)
{
    shift = (shift) % size;
    int fir = 0;
    int t_a = fir;
    int t = a[fir];
    int col = 0;
    do {
        do
        {
            t_a = (t_a + size - shift) % size;
            //cout << "[t_a] = " << t_a << "  a[t_a] = " << a[t_a] << endl;
            int t1 = a[t_a];
            *(a + t_a) = t;
            t = t1;
            col++;
        }
        while(t_a != fir);
        t_a++;
        fir++;
        t = a[t_a];
    }
    while(col < size);
}

// Функция, которая принимает на вход целочисленную матрицу
// M (другими словами, просто двумерный целочисленный массив) размера
// rows×cols, и возвращает транспонированную матрицу
int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    int **new_arr = new int * [cols];
    for(int i = 0; i < cols; i++){
        new_arr[i] = new int[rows];
        for(int j = 0; j < rows; j++){
            new_arr[i][j] = m[j][i];
        }
    }
    return new_arr;

}

// Функция swap_min, которая принимает на вход двумерный массив целых чисел,
// ищет в этом массиве строку, содержащую наименьшее среди всех элементов
// массива значение, и меняет эту строку местами с первой строкой массива
void swap_min(int *m[], unsigned rows, unsigned cols)
{
    int min_swap = INT_MAX;
    unsigned min_index = -1;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(min_swap > m[i][j]){
                min_swap = m[i][j];
                min_index = i;
            }
        }
    }
    int* t = m[0];
    m[0] = m[min_index];
    m[min_index] = t;
}