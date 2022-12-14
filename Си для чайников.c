#include <stdio.h> // Библиотека, которую нужно вызвать для использования определённых функций (напр., printf)
#include <stdbool.h> // Библиотека для булевых значений
// #include <locale.h> // Библиотека, отвечающая за локализацию (на CLion для русского языка не нужна)
#include <windows.h> // Библиотека, нужная для CLion для вывода текста в консоли на русском языке (для использования UTF-8)

#define const 1 // Таким образом задаются константы, которые потом можно использовать как числа.

int main() { // С функции main начинается каждая программа в языке C

// setlocale(LC_ALL, "Rus"); // Устанавливает язык C в программу (на CLion для русского языка достаточно использовать символы из UTF-8)
SetConsoleOutputCP(CP_UTF8); // Теперь консоль выводит всё в символах из UTF-8

// Однострочный комментарий

/*
Многострочный комментарий
*/

// \n - перевод строки
// Завершение строки (;), не распространяется на тело функции (внутри { })

    { // Переменные

        /* Объявление переменной:
         * Тип переменной, потом название переменной, затем можно либо
         * присвоить этой переменной значение (=), либо
         * закрыть строку (;), тем самым просто запомнив эту переменную.
         * После этого с этой переменной можно производить любые операции.
         */
        int num_first = 1;

        // Типы данных
        // int - целочисленный тип данных
        num_first = 6;
        // short - также целочисленный тип данных, но с меньшим диапазоном (от -32768 до 32768), зато использует в 2 раза меньше памяти
        short sh = 32000;
        // Также есть long (и ещё long long), который имеет в разы больший диапазон, нежели int, но и памяти также использует в 2 раза больше
        long ln = 126379781;

        /* К переменным с целочисленным типом можно приписывать unsigned, что лишает переменную всех отрицательных значений,
         * но использует столько же памяти (т.е. диапазон в положительную сторону увеличивается)
         */

        // float - вещественный тип данных (число с плавающей точкой), точность - 7 разрядов
        float num_float = 1.012393f; // В float надо на конце писать f
        // double - также вещественный тип данных, но с большей точностью (15 разрядов)
        // Также есть long double, имеющий точность 21 разряд

        // char - символьный тип данных (можно поместить только один символ)
        char c = 'c' // При переменной типа char символ нужно помещать именно в одинарные кавычки (')

        // bool - булевый тип данных, имеющий только 2 значения - true и false (работает только если призвать библиотеку <stdbool.h>)
        bool fls = false
        // Вместо true и false можно использовать 1 и 0 соответственно

        // Можно объявлять сразу несколько переменных:
        int x, y, z;
        int p = 10, q = 9, r, t;

        // С типами int и float (вещественный тип данных) можно производить различные математические операции:
        r = p + q;

        // Производить можно + (сложение), - (вычитание), * (умножение), / (деление), % (остаток от деления).

        /* Производя вычисления над одной и той же переменной, можно сокращать синтаксис:
        * x = x + 5 это то же самое, что и x += 5.
        * ++ - прибавление к переменной единицы (+1), инкремент (аналогично, -- - декремент, уменьшение на 1).
        * Инкременты и декременты можно использовать как перед переменной, так и после неё, но есть отличия.
        */

        int x = 5;
        int y = ++x; // x = 6 и 6 присваивается переменной y

        int x = 5;
        int y = x++; // x = 6, но переменной y присваивается 5
    }

    { // Ввод и вывод символов

        // getchar и putchar - функции ввода-вывода одного символа
            int c = getchar(); // Прочитает один символ (самый первый, если была введена строка)
            putchar(c); // Выведет один символ

        // EOF - константа в библиотеке <stdio.h>, означающая конец файла (End Of File)

        // scanf - функция ввода
            double lol1, lol2;
            scanf("%f", &lol1); // & - адресация переменной в scanf
            // Знак *, помещенный после % и перед спецификатором формата, считывает данные указанного типа, но подавляет их присваивание.
                scanf("%f%*c%f", &lol1, &lol2); // При вводе 10/20 символ / проигнорируется, и 10 и 20 присвоятся lol1 и lol2 соответственно.
            // Строки и массивы можно писать без адресации (&)

        // printf - функция вывода
            printf("Hi %c %d %s\n", 'c', 10, "there!"); // Выведется Hi c 10 there!
            /* %c - символ типа char,
             * %s - строка символов
             * %d и %i - десятичное целое число со знаком,
             * %u - десятичное целое число без знака
             * %f - десятичное число с плавающей точкой,
             * %o - восьмеричное число без знака
             * %x и %X - шестнадцатеричное целое число без знака (какой регистр у X, такой регистр и у букв в 16-ричной с. с.)
             */

            /* Чтобы указать, сколько чисел после запятой (в вещественном типе данных) должно выводиться при функции printf,
             * нужно просто перед f поставить точку, и после неё число знаков после запятой:
             */
                float fl1 = 9.9, fl2 = 2.4, del;
                del = fl1 / fl2;
                printf("Result: %.2f\n", del);
    }

    { // Массивы

        // Объявление массива:
            /* Сначала указываем тип всех элементов массива,
         * затем называем массив,
         * после этого в квадратных скобках пишем количество элементов в массиве.
         * Также можно сразу присвоить каждому элементу значение, это делается за счёт фигурных скобок.
         * Если сразу присваиваем значения элементам, необязательно писать количество элементов в квадратных скобках.
         */
            int arr[] = {1, 3, 5, 7, 9};

        // Отсчёт по элементам в массиве начинается с 0, т.е. 1 элемент имеет индекс [0] и т.д.
            printf("%d\n", arr[2]) // Выведет 3 элемент, т.е. 2

        // Можно и переприсвоить значение элементу массива:
            arr[2] = 2;

        // С помощью массивов можно создавать строки:
            char word[] = {'S','o','m','e'}; // То же самое, что и:
                char words[] = "Some"; // В строках используем обязательно двойные кавычки (")

            /* Для справки: тип данных String (строка) не существует в языке C,
             * т.к. этот язык очень старый, и вместо него используется тип данных char.
             * По факту String в других языках программирования - это тот же самый массив, что я и описал выше.
             */

            words[1] = 'a'; // Заменили вторую букву в строке words
            printf("%s", words); // Выведет строку words, т.е. Same

        // Двумерный массив
            int array[3][4] = {
                {4, 5, 6, 7},
                {7, 8, 9, 10},
                {4, 6, 8, 10}
            }; /* Двумерный массив - своеобразная матрица из различных элементов, выстроенная в столбцы и ряды.
                * В двумерных массивах обязательно надо обозначать размерность.
                * Первая скобка отвечает за то, сколько маленьких массивов будет внутри большого (двумерного) массива.
                * Вторая скобка отвечает за то, сколько элементов будет в маленьких массивах.
                * Работа с двумерными массивами почти не отличается от работы с обычными, надо просто писать два аргумента.
                */
            // Также существуют трёхмерные и четырёхмерные массивы.
    }

    { // Условные операторы

        // Как используется условный оператор if:
            int x = 5;
            if(x == 5) { /* Идёт проверка условия.
                     * Если условие истинно, выполнится тело условия.
                     * Если условие ложно, то тело условия не выполнится.
                     */
                printf("x равно 5\n");
            } else if(x > 5) { // Дополнительная проверка, которая выполняется в том случае, если if не выполнилось.
                printf("x больше, чем 5\n");
            } else { // else выполняется только в том случае, если if и все else if не выполнились.
                printf("x меньше, чем 5\n");
            } // else и else if пишутся после if (если else или else if используются). else if всегда помещается между if и else.
            // Если в теле условия используется всего одна строка, фигурные скобки ({}) можно не использовать.
            // Также можно использовать новое условие в теле другого условия:
                if(x >= 5) {
                    if (x == 5) printf("Yes");
                    else printf("No");
                }

        // Все операторы сравнения: == (равно), != (не равно), < (меньше), > (больше), <= (меньше или равно), >= (больше или равно)
        // Логические операторы: || (логическое ИЛИ), && (логическое И), ! (логическое НЕ)

        // Условные операторы также позволяют работать с булевыми значениями:
            bool istrue = true;
            bool isfalse = false;
            if (istrue && !isfalse) printf("Hi!");
            /* Тело будет выполняться, если булево значение истинно (при ! - ложно),
             * причём достаточно просто написать название булевой переменной
             */
            else printf("Bye!");

        // Оператор принятия решений switch-case
            int x = 6;
            switch(x) { // В switch-case можно проверять только на точное совпадение значений
                case 5:
                    printf("5");
                    break; // Проверяет от case до break, т.е. следующие case уже не проверяются.
                case 9:
                    printf("9");
                    break;
                case 2:
                    printf("2");
                    break;
                default: // default сработает в том случае, если каждый из case не был выполнен
                    printf("ok");
                    break;
            // switch-case намного короче и удобнее для проверки определённой переменной на соответствие различным значениям.
        }
    }

    { // Циклы

        // Цикл с параметром for
            for(int i = 0; i < 10; i++) { /* В цикле for используется 3 операции внутри скобок:
                                           * Первая операция отвечает за инициализацию
                                           * (обозначаем переменную-параметр, который будет использоваться в цикле)
                                           * Эта переменная будет использована только в цикле и не будет запомнена в самой программе.
                                           * Вторая операция отвечает за условие
                                           * (цикл будет работать, пока условие выполняется (т.е. является истинным)).
                                           * Третья операция отвечает за модификацию
                                           * (как будет изменяться значение переменной-параметра).
                                           */
                printf("%d\n", i);
            } // Этот цикл выведет в консоль все числа от 0 до 9.

        // Цикл с условием while
            bool t = true;
            while(t) { // В цикле while используется 1 операция внутри скобок - условие
                scanf("%d", &x);
                if(x == 1)
                    t = false
            } // Этот цикл закончится, если в консоли ввести число 1.

        // Как из цикла while можно сделать цикл for:
            int i = 0
            while(i < 10) {
                printf("%d\n", i);
                i++;
            } // Этот цикл аналогичен тому, что я написал выше, где описывал цикл с параметром.

        // Цикл с условием do-while
            /* Отличие цикла do-while от цикла while в том, что
             * цикл do-while сначала выполняет тело цикла, а затем проверяет условие, а не наоборот, как в случае с while.
             */
            bool f = false
            do {
                print("Hi");
            } while(f) // Этот цикл выполнится 1 раз, т.к. условие не выполняется.

        // Операторы внутри циклов
            for(int x = 0; x < 10; x++) {
                if(x == 5)
                    break; // Оператор break незамедлительно завершает цикл, игнорируя последующие строки кода в теле цикла.
                if(x % 2 == 0)
                    continue; /* Оператор continue пропускает одну итерацию в цикле,
                               * т.е. игнорирует последующие строки кода в теле цикла, перемещаясь к следующему оператору.
                               * Например, в данном случае цикл будет пропускать все чётные числа.
                               */
                printf("%d", x);
            } // На экран выведутся числа 1 и 3.

        // С массивами также можно производить различные операции в циклах
            int array[] = {3, 0, 9, 10, -90, -24};
            for(int i = 0; i < 6; i++)
                printf("%d", array[i]); // Этот цикл выведет в консоль все элементы массива
            int min = array[0];
            for(int i = 0; i < 6; i++){
                if(array[i] < min)
                    min = array[i]; // Цикл по нахождению минимального по значению элемента в массиве
            }
    }

    { // Функции

        // Функции - это подпрограммы, в которые можно вносить повторяющийся код, а после этого вызывать их, выполняя код внутри функции.
        // Чтобы создать функцию, необходимо прописать её до функции main.
            // Сначала необходимо прописать тип данных, который будет возвращён самой функцией.
                // Чтобы функция что-либо возвращала, надо указать определённый тип данных, который эта функция будет возвращать:
                    double mult(double a, double b) {
                        double res = a * b;
                        return res;
                    }
                    // Внутри main это будет задействовано следующим образом:
                        int main() {
                        double x = 5.5, y = 9.2;
                        printf("%f\n", mult(x, y))
                        return 0; /* На ключевом слове return и числе 0 заканчивается любая программа в языке C,
                                   * в которой использовалось int перед main.
                                   * return 0 необязательно использовать в конце функции main в C99 или C11, но обязательно в C89.
                                   * Также вместо int main можно использовать void main.
                                   */
                        };
                // Если функция ничего не возвращает, то тип данных указывается void.
                    void info() {
                        printf("Привет\n");
                    }
            // Внутри функции можно использовать свои переменные, их просто нужно задать в скобках:
                void sum(int a, int b) {
                    int res = a + b;
                    printf("%d\n", res);
                } // Заданные в функции переменные не будут распространяться на всю остальную программу
                // Внутри кода переменные используются следующим образом:
                    int main() {
                        sum(20, 50);
                        int x = 9, y = 2;
                        sum(x, y);
                    } // Т.е. вместо a и b можно вставить любое число или переменную того же типа.
                // Также внутри функции можно передать и массив:
                    void string(char arr[]) {
                        printf("%s\n", arr);
                    }
                    // Вызывается эта функция следующим образом:
                        int main() {
                            string("Hello");
                            string({'w','e','l'});
                            char word = "Hi man";
                            string(word);
                        };
        // Чтобы вызвать функцию, надо внутри функции main обратиться к функции по имени:
            int main() {
                info();
            }
        // Функцию можно прописать и после функции main, но для этого нужно обратиться к ней до функции main:
            void info(void); // Если обращаемся к функции до main и внутри неё нет параметров, надо указать в скобках void.
            int main() {
                info();
                return 0;
            }
            void info() {
                printf("Привет\n");
            }
        // Также функции можно прописывать при помощи заголовочных файлов:
            /* Необходимо создать заголовочный файл с расширением .h (как у библиотек),
             * затем нужно прописать в этом файле функцию, которую мы хотим использовать,
             * после этого этот код можно использовать и в основной программе,
             * нужно просто до функции main написать #include "(название_файла).h" (без скобок и в двойных кавычках),
             * а затем вызвать функцию по её названию уже внутри main.
             */
                #include "functions.h"
                int main() {
                    info();
                }
    }

    { // Структуры данных

        /* Структура — это объединение нескольких объектов,
         * возможно, различного типа под одним именем, которое является типом структуры.
         * В качестве объектов могут выступать переменные, массивы, указатели и другие структуры.
         */

        // Структура прописывается до функции main. Также после структуры надо ставить точку с запятой (;).

        struct Structure {
            int per;
            char name[50];
            double fl;
        };

        /* Чтобы использовать структуру, нужно, назвать объект этой структуры уже внутри программы.
         * После этого вместе с объектом можно будет использовать все элементы из структуры.
         */
            int main() {
                struct Structure my_str1;
                my_str1.per = 250;
                my_str1.fl = 23.45;
                // Чтобы установить массив символов внутрь объекта, надо использовать функцию strcpy:
                    strcpy(my_str1.name, "NAME");
                // Можно создавать множество объектов на основе одной структуры:
                    struct Structure my_str2 = {300, "NAME_02", 12.35};
                    // Можно присвоить все переменные разом, главное записать всё в том порядке, в котором они расположены в структуре.
            };

    }

    { // Указатели

        // Указатель - это некоторая переменная, которая содержит адрес другого объекта. Указатели сильно оптимизируют код.

        int num;
        scanf("%d", &num); // & - указатель, с помощью него в функцию передаётся не значение переменной, а её адрес.

        int num = 0;
        printf("%p", &num); // Выведется адрес переменной num

        int *pNum = &num; // Называем указатель (перед ним ставим *) и присваиваем ему адрес переменной, которую мы хотим использовать.
            // Если используем указатель без *, то мы используем адрес переменной, а не отсылаемся к нему.
        printf("%p", pNum); // То же самое, что и printf("%p", &num).
        printf("%d", *pNum); // Мы отсылаемся к адресу переменной num и выводим её значение.

        // Через указатель можно поменять значение переменной:
            *pNum = 10;

        // Применение указателя в действии:
            struct Abs {
                int w, h;
            };
            void calc(struct Abs *obj) { // То же самое, что и void calc(struct Abs obj), но с использованием указателя
                int res = obj->w * obj->h; // То же самое, что и int res = obj.w * obj.h, но с использованием указателя
                printf("%d\n", res);
            }
            int main() {
                struct Abs square = {5, 7};
                calc(&square); // То же самое, что и calc(square), но с использованием адреса
            }
    }
  
    { // Динамическое выделение памяти
      
        // Функции динамического выделения памяти находят в оперативной памяти непрерывный участок требуемой длины и возвращают начальный адрес этого участка.
        
        void* malloc(size); // Выделяет size байт
        void* calloc(n, size); // Выделяет n элементов, каждый с size байт памятью, и затем автоматически зануляет их
      
        free(ptr); // Освобождает указатель на выделенную память
    }

    { // Работа с файлами

        // Необходимо создать указатель с типом данных FILE:
            FILE *file = fopen("text.txt", "a");
            /* Первый аргумент fopen - путь до файла.
             * Если просто написать название файла, то он будет искать его в той директории, в которой находится файл программы.
             * Второй аргумент fopen - режим открытия файла.
             * "r" — открыть файл для чтения (файл должен существовать);
             * "w" — открыть пустой файл для записи; если файл существует, то его содержимое теряется;
             * "a" — открыть файл для записи в конец (для добавления); файл создается, если он не существует;
             * "r+" — открыть файл для чтения и записи (файл должен существовать);
             * "w+" — открыть пустой файл для чтения и записи; если файл существует, то его содержимое теряется;
             * "a+" — открыть файл для чтения и дополнения, если файл не существует, то он создаётся.
             */

            // Чтобы записывать данные в файл, нужно использовать функцию fprintf:
                fprintf(file, "Hello\nWorld");
                /* Первый аргумент - название файла, в который записываются данные;
                 * второй аргумент - то, что мы хотим записать в файл.
                 * При режиме "w" данные перезаписываются, при режиме "a" данные добавляются к существующим.
                 */

            // Чтобы считывать данные с файла, нужно для начала создать массив символов:
                char line[255];
            /* После этого нужно воспользоваться функцией fgets,
             * которая позволяет в определённый массив записать определённое количество символов.
             */
                fgets(line, 255, file);
                /* Первый аргумент - массив, куда мы хотим записать символы,
                 * второй аргумент - количество символов, которые мы хотим считать из файла,
                 * третий аргумент - название файла, откуда мы хотим считывать символы.
                 * Функция fgets работает только в режиме "r".
                 * Функция fgets считывает файл лишь построчно.
                 */
                printf("%s", line); // Выведутся первые 255 символов первой строки файла (или вся строка, если в ней символов меньше)
                // Чтобы считать следующую строку файла, нужно вызвать функцию fgets повторно (или воспользоваться циклом).

            fclose(file); // Необходимо закрывать файл в конце программы для её оптимизации.
    }
}
