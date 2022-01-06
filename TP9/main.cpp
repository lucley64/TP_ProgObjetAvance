#include <iostream>
#include "Date.h"
#include "ValoriserDate.h"

using namespace std;

int main(){
    Date dateX(2022, 1, 3);

    ValoriserDate vD(&dateX);

    cout << "Date : " << vD.getVersionInt() << endl;

    return 0;
}