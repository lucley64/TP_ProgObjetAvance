#include "Date.h"

Date::Date(int annee, int mois, int jour):
    annee(annee),
    mois(mois),
    jour(jour){}

int Date::getVersionInt(){
    return (annee * 10000 + mois * 100 + jour);
}