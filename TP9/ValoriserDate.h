#ifndef VALORISER_DATE_H
#define VALORISER_DATE_H

#include "Date.h"

class ValoriserDate{
    public:
        Date* dateValorisee;

    public:
        ValoriserDate(Date* d);

        int getVersionInt();
};

#endif // !VALORISER_DATE_H