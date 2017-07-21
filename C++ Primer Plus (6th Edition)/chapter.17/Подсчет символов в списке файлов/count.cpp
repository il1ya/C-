/*
Код в листинге 17.17 сочетает технологию командной строки с технологиями файловых потоков для подсчета количества символов в файлах, перечисленных в командной строке. 
Листинг 17.17. count.срр */
// count.срр — подсчет символов в списке файлов 
#include <iostream>
#include <fstream>
#include <cstdlib>                      // для exit() 
int main(int argc, char *argv[])
{
        using namespace std;
        if(argc == 1)                   // выход при отсутствии аргументов 
        {
            cerr << "Usage: " << argv[0] << " filename[s]\n";
            exit(EXIT_FAILURE);
        }
        ifstream fin;                   // открытие потока 
        long count;
        long total = 0;
        char ch;
        for(int file = 1; file < argc; file++)
        {
            fin.open(argv[file]);       // подключение потока к argv[file] 
            if(!fin.is_open())
            {
                cerr << "Could not open " << argv[file] << endl;    // не удается открыть файл 
                fin.clear();
                continue;
            }
            count = 0;
            while(fin.get(ch))
                count++;
                            // количество символов в файле 
            cout << count << " characters in " << argv[file] << endl;
            total += count;
            fin.clear();
            fin.close();
        }
        cout << total << " characters in all files\n";  // количество символов во всех файлах 
        return 0;
}
/*
Некоторые реализации C++ требуют вызова fin.clear() в конце программы, а другие — нет. 
Это зависит от того, сбрасывается ли состояние потока автоматически при ассоциировании нового файла с объектом типа ifstream. 
Использование fin.clear() не повредит, даже если в этом нет необходимости. 
Обратите внимание, что программа использует сerr для вывода сообщений об ошибках. 
Небольшой нюанс заключается в том, что сообщение использует argv[0] вместо count.exe: 
cerr << "Usage: " << argv[0] « " filename[s]\n"; 
Это дает возможность программе в случае изменения имени исполняемого файла автоматически использовать новое имя. 
Программа применяет метод is_open() для проверки того, что запрошенный файл удалось открыть. Рассмотрим этот момент подробнее. 
*/