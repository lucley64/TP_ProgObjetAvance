#ifndef DATE_H
#define DATE_H

class Date{
    public:
        int annee;
        int mois;
        int jour;

    public:
        Date(int annee, int mois, int jour);

    private:
        int getVersionInt();
};

#endif // !DATE_H