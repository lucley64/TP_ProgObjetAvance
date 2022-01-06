#include "ValoriserDate.h"

ValoriserDate::ValoriserDate(Date* d):
    dateValorisee(d) {}

int ValoriserDate::getVersionInt(){
    return (dateValorisee->annee * 10000 + dateValorisee->mois * 100 + dateValorisee->jour);
}