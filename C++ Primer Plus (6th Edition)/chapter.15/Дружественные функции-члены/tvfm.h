/* Здесь вызывается метод Тѵ, и поэтому компилятор должен заранее просмотреть объявление класса Тѵ, чтобы знать, какие методы он содержит. 
Но, как мы видели, за этим объявлением должно следовать объявление Remote. Решением в данном случае может быть объявление методов Remote до определения класса Тѵ и их непосредственные определения после класса Тѵ. 
Это приводит к такой последовательности: 
class Тѵ;               // упреждающее объявление 
class Remote { ... };   // методы, использующие Тѵ, в виде только прототипов 
class Тѵ { ... }; 
// Определения методов Remote 
Прототипы Remote выглядят следующим образом: 
void onoff (Tv & t); 
Для обработки этого прототипа компилятору нужно лишь знать, что Тѵ является классом, и упреждающее объявление предоставляет ему эту информацию. 
Когда компилятор дойдет до непосредственных определений методов, объявление класса Тѵ им уже прочитано, и он будет располагать информацией, необходимой для компиляции этих методов. 
Ключевое слово inline в определениях методов также позволяет сделать методы встроенными. В листинге 15.4 показан модифицированный заголовочный файл. 
Листинг 15.4. tvfm.h */
// tvfm.h -- классы Тѵ и Remote и дружественная функция-член 
#ifndef TVFM_H_
#define TVFM_H_

class Tv;           // упреждающее объявление 
class Remote
{
    public:
        enum State{Off, On};
        enum {MinVal, MaxVal = 20};
        enum {Antenna, Cable};
        enum {TV, DVD};
    private:
        int mode;
    public:
        Remote(int m = TV) : mode(m) {}
        bool volup(Tv &t);              // только прототип 
        bool voldown(Tv &t);
        void chanup(Tv &t);
        void chandown(Tv &t);
        void set_mode(Tv &t);
        void set_input(Tv &t);
        void set_chan(TV &t, int c);
};

class Tv
{
    public:
        friend void Remote::set_chan(Tv &t, int c);
        enum State{Off, On};
        enum {MinVal, MaxVal = 20};
        enum {Antenna, Cable};
        enum {TV, DVD};
        Tv(int s = Off, int mc = 125) : state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV) {}
        void onoff() {state = (state == On)? Off : On;}
        bool ison() const {return state == On;}
        bool volup();
        bool voldown();
        void chanup();
        void chandown();
        void set_mode() {mode = (mode == Antenna)? Cable : Antenna;}
        void set_input() {input = (input == TV)? DVD : TV;}
        void settings() const;          // отображение всех настроек 
    private:
        int state;                      // On или Off 
        int volume;                     // дискретные уровни громкости 
        int maxchannel;                  // максимальное количество каналов 
        int channel;                    // текущий канал 
        int mode;                       // эфирное или кабельное телевидение 
        int input;                      // TV или DVD 
};

// Методы Remote как встроенные функции 
inline bool Remote::volup(Tv &t) {return t.volup();}
inline bool Remote::voldown(Tv &t) {return t.voldown();}
inline bool Remote::onoff(Tv &t) {t.onoff();}
inline bool Remote::chanup(Tv &t) {t.chanup();}
inline bool Remote::chandown(Tv &t) {t.chandown();}
inline bool Remote::set_mode(Tv &t) {t.set_mode();}
inline bool Remote::set_input(Tv &t) {t.set_input();}
inline bool Remote::set_chan(Tv &t, int c) {t.channel = c;}

#endif
/*
Если в файлах tv.cpp и use_tv.cpp включить tvfm.h вместо tv.h, результирующая программа будет вести себя так же, как исходная. 
Разница лишь в том, что теперь дружественным по отношению к классу Тѵ будет только один метод класса Remote, a не все. Эта разница показана на рис. 15.1. 
Вспомните, что встроенные функции имеют внутреннее связывание, т.е. определения функций должны находиться в том же файле, где они используются. 
Здесь встроенные определения находятся в заголовочном файле, поэтому при включении этого файла в файл, использующий определения, эти определения попадут в нужное место. 
Можно поместить определения и в файл реализации, но тогда нужно удалить ключевое слово inline, чтобы выполнялось внешнее связывание функций. 
Кстати, если сделать дружественным весь класс Remote, упреждающее объявление станет ненужным, т.к. объявление друга само определяет Remote как класс. 
*/