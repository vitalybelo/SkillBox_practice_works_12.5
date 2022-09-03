#include <iostream>
#include <cassert>

using namespace std;

/**
 * Возвращает время в пути в минутах
 * @param distance
 * @param speed
 * @return
 */
float travelTime(float distance, float speed) {
    assert (speed > 0);
    return (distance / speed) * (float)60.0;
}

int main() {

    //system("chcp 65001");
    setlocale(LC_ALL,"Russian");
    float speed;
    float distance;

    cout << "Введите расстояние (км) = ";
    cin >> distance;
    cout << "Введите скорость (км/час) = ";
    cin >> speed;

    int timeOnWay = (int) travelTime(distance,speed);
    cout << "\nВремя в пути ::: ";
    if (timeOnWay / 60 > 0 )
        cout << timeOnWay / 60 << " часов ";
    cout << timeOnWay % 60 << " минут\n";

    return 0;
}
