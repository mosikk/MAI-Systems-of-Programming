// lexer.h 2021
#ifndef LEXER_H
#define LEXER_H

#include "baselexer.h"

class tLexer : public tBaseLexer {
public:
    // конструктор
    tLexer() : tBaseLexer() {
        //создать автоматы:

        // вещественное
        addrange(Adec, 0, '0', '9', 1);
        addstr(Adec, 0, "+-", 5);
        addrange(Adec, 1, '0', '9', 1);
        addstr(Adec, 1, "eE", 2);
        addstr(Adec, 1, ".", 6);
        addstr(Adec, 2, "+-", 3);
        addrange(Adec, 3, '0', '9', 4);
        addrange(Adec, 4, '0', '9', 4);
        addrange(Adec, 5, '0', '9', 1);
        addrange(Adec, 6, '0', '9', 7);
        addstr(Adec, 7, "eE", 2);
        addrange(Adec, 7, '0', '9', 7);
        Adec.final(4);

        // идентификатор
        addrange(Aid, 0, 'a', 'z', 1);
        addrange(Aid, 0, 'A', 'Z', 1);
        addstr(Aid, 0, "!", 1);
        addstr(Aid, 0, "?", 2);
        addrange(Aid, 1, 'a', 'z', 1);
        addrange(Aid, 1, 'A', 'Z', 1);
        addrange(Aid, 1, '0', '9', 1);
        addstr(Aid, 1, "!", 1);
        addstr(Aid, 1, "?", 2);
        addstr(Aid, 1, "-", 3);
        addrange(Aid, 2, 'a', 'z', 1);
        addrange(Aid, 2, 'A', 'Z', 1);
        addrange(Aid, 2, '0', '9', 1);
        addstr(Aid, 2, "!", 1);
        addstr(Aid, 2, "?", 2);
        addstr(Aid, 2, "-", 3);
        addrange(Aid, 3, 'a', 'z', 1);
        addrange(Aid, 3, 'A', 'Z', 1);
        addrange(Aid, 3, '0', '9', 1);
        addstr(Aid, 3, "!-", 1);
        addstr(Aid, 3, "?", 4);
        addrange(Aid, 4, 'a', 'z', 1);
        addrange(Aid, 4, 'A', 'Z', 1);
        addrange(Aid, 4, '0', '9', 1);
        addstr(Aid, 4, "!", 1);
        addstr(Aid, 4, "?", 2);
        Aid.final(1);

        // идентификатор предиката
        addrange(Aidq, 0, 'a', 'z', 1);
        addrange(Aidq, 0, 'A', 'Z', 1);
        addstr(Aidq, 0, "!", 1);
        addstr(Aidq, 0, "?", 2);
        addstr(Aidq, 0, "-", 3);
        addrange(Aidq, 1, 'a', 'z', 1);
        addrange(Aidq, 1, 'A', 'Z', 1);
        addrange(Aidq, 1, '0', '9', 1);
        addstr(Aidq, 1, "!", 1);
        addstr(Aidq, 1, "?", 2);
        addstr(Aidq, 1, "-", 3);
        addrange(Aidq, 2, 'a', 'z', 1);
        addrange(Aidq, 2, 'A', 'Z', 1);
        addrange(Aidq, 2, '0', '9', 1);
        addstr(Aidq, 2, "!", 1);
        addstr(Aidq, 2, "?", 2);
        addstr(Aidq, 2, "-", 3);
        addrange(Aidq, 3, 'a', 'z', 1);
        addrange(Aidq, 3, 'A', 'Z', 1);
        addrange(Aidq, 3, '0', '9', 1);
        addstr(Aidq, 3, "-", 1);
        addstr(Aidq, 3, "?", 2);
        Aidq.final(2);
    }
};

#endif
