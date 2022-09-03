#include <iostream>
using namespace std;

/**
 * Процедура обрабатывает сверху вниз ветку бинарной кучи массива
 * до последнего элемента ветки кучи со стороны максимальных чисел
 * @param heapArray - массив бинарной кучи
 * @param size - размер массива
 * @param indexRoot - корневой индекс разбираемой кучи
 */
void heapBranch (float heapArray[], int size, int indexRoot)
{
    int indexMax = indexRoot;
    int indexLeft = 2 * indexRoot + 1;
    int indexRight = 2 * indexRoot + 2;

    // определяем индекс максимального числа в треугольнике ветки
    if (indexLeft < size && heapArray[indexLeft] > heapArray[indexMax])
        indexMax = indexLeft;
    if (indexRight < size && heapArray[indexRight] > heapArray[indexMax])
        indexMax = indexRight;
    // если максимальное число не в вершине, двигает его в вершину и рекурсивно
    // вызывает саму себя - чтобы добраться до последнего элемента ветки вниз
    if (indexMax != indexRoot) {
        swap(heapArray[indexRoot], heapArray[indexMax]);
        heapBranch(heapArray, size, indexMax);
    }
}


int main() {

    float heap[15]{2.13,4.01,1.12,3.31,4.87,6.50,3.65,7.75,
                   4.84,5.91,3.13,5.16,6.12,7.31,5.40};

    cout.precision(2);
    cout << "У нас есть массив с такими параметрами\n";
    for (float i : heap) cout << fixed << i << " ";
    cout << endl << endl;

    int size = 15;
    // поднимаем максимальные числа всех веток снизу вверх
    for (int i = size / 2 - 1; i >= 0; i--)
        heapBranch(heap, size, i);
    // сортируем элементы массива
    for (int i = size - 1; i >= 0; i--) {
        swap(heap[0], heap[i]);
        heapBranch(heap,i,0);
    }

    cout << "Отсортированный массив\n";
    for (int i = 14; i >= 0; i--) cout << fixed << heap[i] << " ";
    cout << endl;


    return 0;
}
