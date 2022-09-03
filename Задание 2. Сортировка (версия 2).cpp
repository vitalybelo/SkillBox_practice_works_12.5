#include <iostream>
using namespace std;
/**
 * Выполняет пузырьковую сортировку массива. Максимальные значения
 * сдвигаются влево, то есть к начальным индексам массива, так чтобы
 * после выполнения всех проходов (= размер массива - 1) числа выстроились
 * в порядке убывания значений. Максимум = heap[0], Минимум = heap[last]
 * @param heap - массив - несортированная куча значений для анализа
 * @param length - длина массива (число элементов массива)
 * @param numPass - номер прохода = итерация цикла проходов от нуля
 * Сложность в лучшем случае: O(n).
 * Сложность в худшем случае: O(n2).
 */
void bubleSortMaxFirst (float heap[], int length, int numPass) {

    int startPos = length - 1;      // стартовая позиция (с конца)
    int finalPos = 0 + numPass;     // конечная позиция

    for (int i = startPos; i > finalPos; i--)
        if (heap[i] > heap[i - 1]) swap(heap[i], heap[i - 1]);
}
/**
 * Выполняет пузырьковую сортировку массива. Максимальные значения
 * сдвигаются вправо, то есть к начальным индексам массива, так чтобы
 * после выполнения всех проходов (= размер массива - 1) числа выстроились
 * в порядке возростания значений. Минимум = heap[0], Максимум = heap[last]
 * @param heap
 * @param length
 * @param numPass
 */
void bubleSortMinFirst (float heap[], int length, int numPass) {

    int finalPos = length - numPass - 1;     // конечная позиция

    for (int i = 0; i < finalPos; i++)
        if (heap[i] > heap[i + 1]) swap(heap[i], heap[i + 1]);
}

int main() {

    int size = 15;
    float heap[15]{2.13,4.01,1.12,3.31,4.87,6.50,3.65,7.75,
                   4.84,5.91,3.13,5.16,6.12,7.31,5.40};

    cout.precision(2);
    cout << "У нас есть массив с такими параметрами\n";
    for (float i : heap) cout << fixed << i << " ";
    cout << endl << endl;

    for (int i = 0; i < size - 1; i++)
        bubleSortMaxFirst(heap,size,i);

    cout << "Отсортированный массив (MAX --> MIN)\n";
    for (int i = 0; i < size; i++) cout << fixed << heap[i] << " ";
    cout << endl;

    for (int i = 0; i < size - 1; i++)
        bubleSortMinFirst(heap,size,i);

    cout << endl;
    cout << "Отсортированный массив (MIN --> MAX)\n";
    for (int i = 0; i < size; i++) cout << fixed << heap[i] << " ";
    cout << endl;

    return 0;
}
