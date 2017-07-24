/* Пульт дистанционного управления должен дублировать органы управления телевизора. 
Многие из его методов могут быть реализованы с помощью методов класса Тѵ. 
Но, кроме того, пульт дистанционного управления позволяет переключиться на произвольный канал. 
То есть можно сразу перейти со 2-го на 20-й канал, не перебирая все промежуточные. Многие пульты дистанционного управления могут работать в двух и 
более режимах, например, управление телевизором и управление DVD-плеером. 
На основе этих рассуждений можно написать определения, приведенные в листинге 15.1. В них имеются несколько констант, определенных как перечисления. 
Следующий оператор делает Remote дружественным классом: 
friend class Remote; 
Объявление дружественной конструкции может находиться в открытом, закрытом или защищенном разделе — место не имеет значения. 
Поскольку класс Remote ссылается на класс Тѵ, компилятор должен знать о классе Тѵ до начала обработки класса Remote. 
Самый простой способ — определить класс Тѵ первым. Либо можно использовать объявление forward; мы рассмотрим эту возможность позже. 
Листинг 15.1. tv.h */
// tv.h — классы Тѵ и Remote 
#ifndef TV_H_
#define TV_H_

class Tv
{
    public:
        friend class Remote;        // Remote имеет доступ к закрытой части Тѵ 
        enum {Off, On};
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

class Remote
{
    private:
        int mode;
    public:
        Remote(int m = Tv::TV) : mode(m) {}
        bool volup(Tv &t) {return t.volup();}
        bool voldown(Tv &t) {return t.voldown();}
        void onoff(Tv &t) { t.onoff();}
        void chanup(Tv &t) { t.chanup();}
        void chandown(Tv &t) {t.chandown();}
        void set_chan(Tv &t, int c) {t.channel = c;}
        void set_mode(Tv &t) {t.set_mode();}
        void set_input(Tv &t) {t.set_input();}
};
#endif 
// Большинство методов в листинге 15.1 определено встроенным образом. 
// Обратите внимание, что каждый метод класса Remote, отличный от конструктора, принимает в качестве параметра ссылку на объект Тѵ — т.е. 
// пульт дистанционного управления должен быть нацелен на конкретный телевизор. 