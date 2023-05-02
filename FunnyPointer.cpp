struct Cls {
    Cls(char c, double d, int i)
    {
        this->c = c;
        this->d = d;
        this->i = i;
    };
private:
    char c;
    double d;
    int i;
};

// Эта функция должна предоставить доступ к полю c объекта cls.
// Обратите внимание, что возвращается ссылка на char, т. е.
// доступ предоставляется на чтение и запись.
char &get_c(Cls &cls) {
    char &temp_c = (char&)cls;
    return temp_c;
}

// Эта функция должна предоставить доступ к полю d объекта cls.
// Обратите внимание, что возвращается ссылка на double, т. е.
// доступ предоставляется на чтение и запись.
double &get_d(Cls &cls) {
    Cls *temp = &cls;
    double *temp_d = (double *)(temp);
    return *(temp_d+1);
}

// Эта функция должна предоставить доступ к полю i объекта cls.
// Обратите внимание, что возвращается ссылка на int, т. е.
// доступ предоставляется на чтение и запись.
int &get_i(Cls &cls) {
    Cls *temp = &cls;
    int *temp_i = (int *)(temp);
    return *(temp_i+4);
}