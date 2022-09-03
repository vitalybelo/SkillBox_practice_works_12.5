#include <iostream>
using namespace std;

int main() {

    string tenantsNames[10];
    for (int i = 0; i < 10; i++) {
        cout << "Введите фамилию жильца = ";
        cin >> tenantsNames[i];
    }
    int indexFlat;
    for (int i = 0; i < 3; i++)
    {
        do {
            cout << "Введите номер квартиры (1-10) : ";
            cin >> indexFlat;
            if (indexFlat < 1 || indexFlat > 10) {
                cout << "\tНеправильный номер квартиры\n";
            } else break;
        } while (true);

        cout << "\tВ квартире № " << indexFlat << " проживает ";
        cout <<  tenantsNames[indexFlat - 1] << endl;
    }

    return 0;
}
