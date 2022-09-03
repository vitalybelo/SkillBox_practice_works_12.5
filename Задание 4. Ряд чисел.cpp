#include <iostream>
using namespace std;

int main() {

    int size = 15;
    int numbers[15] {114, 111, 106, 107, 108, 105, 115, 108,
                     110, 109, 112, 113, 116, 117, 118};

    int dublicate;
    int numberMin = numbers[0];
    for (int i = 0; i < size; i++)
    {
        if (numbers[i] < numberMin) numberMin = numbers[i];
        for (int n = i + 1; n < size; n ++)
            if (numbers[i] == numbers[n]) dublicate = numbers[i];
    }
    cout << "Минимальное число X = " << numberMin << endl;
    cout << "Повторяющееся число = " << dublicate << endl;

    return 0;

}
