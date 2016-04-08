#include <iostream>
#include <fstream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

// 1. Insertion Sort
void Insertion_Sort(int* array, int length)
{
    int n, j;
    for (int i = 1; i < length; ++i)
    {
        n = array[i];
        for (j = i - 1; j >= 0 && array[j] > n; --j)
            array[j + 1] = array[j];
        array[j + 1] = n;
    }
}


// 2. Merge Sort

void Merge(int* array, int* workArray, int length, int leftStart, int leftCount, int rightStart, int rightCount)
{
    int i = leftStart, j = rightStart, leftBound = leftStart + leftCount, rightBound = rightStart + rightCount, index = leftStart;
    while (i < leftBound || j < rightBound)
    {
        if (i < leftBound && j < rightBound)
        {
            if (array[j] < array[i])
                workArray[index] = array[j++];
            else
                workArray[index] = array[i++];
        }
        else if (i < leftBound)
            workArray[index] = array[i++];
        else
            workArray[index] = array[j++];
        ++index;
    }
    for (i = leftStart; i < index; ++i)
        array[i] = workArray[i];
}

void Merge_Sort(int* array, int length)
{
    int* workArray = new int[length];

    for (int count = 1; count < length; count *= 2)
        for (int leftStart = 0; leftStart < length; leftStart += 2 * count)
        {
            if (count > length - leftStart)
                break;
            Merge(array, workArray, length, leftStart, count, leftStart + count, min(count, length - leftStart - count));
        }
}


//3. Quick Sort
void Quick_Sort(int* array, int length, int left, int right)
{
    if (right <= left)
        return;

    // random pivot
    //int pivotIndex = (int)((double)left + (double)rand() / (RAND_MAX + 1) * (right - left));
    //srand(rand());

    // middle pivot
    int pivotIndex = (left + right) / 2;
    int pivot = array[pivotIndex];
    swap(array[pivotIndex], array[right]);
    int swapIndex = left;
    for (int i = left; i < right; ++i)
    {
        if (array[i] <= pivot)
        {
            swap(array[i], array[swapIndex]);
            ++swapIndex;
        }
    }
    swap(array[swapIndex], array[right]);

    Quick_Sort(array, length, left, swapIndex - 1);
    Quick_Sort(array, length, swapIndex + 1, right);
}


//4. qsort()
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
    ifstream fin("input.txt");
    if(!fin)                        // �ˬdŪ�ɦ��\�P�_
    cout << "Ū�ɥ���" << endl;

    int data_amount = 0;
    fin >> data_amount;
    int *data = new int[data_amount];
    for(int i = 0 ; i < data_amount ; ++i)
        fin >> data[i];

    fin.close();


    // 1.Insertion Sort
    //�}�ɡA�غc��l��ƽƥ�
    ofstream fout_A("outputA.txt");
    int *copy_1 = new int[data_amount];
    for(int i = 0 ; i < data_amount ; ++i)
        copy_1[i] = data[i];

    //�ƧǨíp�����ɶ�
    clock_t start, stop;
    start = clock();
    Insertion_Sort(copy_1, data_amount);
    stop = clock();

    //��X���G���ɮ�
    fout_A << "Insertion Sort" << endl;
    for(int i = 0 ; i < data_amount ; ++i)
        fout_A << copy_1[i] << endl;
    fout_A.close();

    //��ܰ��浲�G
    cout << "1. Insertion sort" << endl;
    cout << "��Ƽƶq : " << data_amount << endl;
    cout << "�B�z�ɶ� : " <<((double) (stop - start)) << "ms" << endl;
    cout << endl << "/////////////////////////////////////////////////////////" << endl << endl;




    // 2.Merge Sort
    //�}�ɡA�غc��l��ƽƥ�
    ofstream fout_B("outputB.txt");
    int *copy_2 = new int[data_amount];
    for(int i = 0 ; i < data_amount ; ++i)
        copy_2[i] = data[i];

    //�ƧǨíp�����ɶ�
    start = clock();
    Merge_Sort(copy_2, data_amount);
    stop = clock();

    //��X���G���ɮ�
    fout_B << "Merge Sort" << endl;
    for(int i = 0 ; i < data_amount ; ++i)
        fout_B << copy_2[i] << endl;
    fout_B.close();

    //��ܰ��浲�G
    cout << "2. Merge Sort" << endl;
    cout << "��Ƽƶq : " << data_amount << endl;
    cout << "�B�z�ɶ� : " <<((double) (stop - start)) << "ms" << endl;
    cout << endl << "/////////////////////////////////////////////////////////" << endl << endl;




    // 3.Quick Sort
    //�}�ɡA�غc��l��ƽƥ�
    ofstream fout_C("outputC.txt");
    int *copy_3 = new int[data_amount];
    for(int i = 0 ; i < data_amount ; ++i)
        copy_3[i] = data[i];

    //�ƧǨíp�����ɶ�
    start = clock();
    Quick_Sort(copy_3, data_amount, 0, data_amount - 1);
    stop = clock();

    //��X���G���ɮ�
    fout_C << "Quick Sort" << endl;
    for(int i = 0 ; i < data_amount ; ++i)
        fout_C << copy_3[i] << endl;
    fout_C.close();

    //��ܰ��浲�G
    cout << "3. Quick Sort" << endl;
    cout << "��Ƽƶq : " << data_amount << endl;
    cout << "�B�z�ɶ� : " <<((double) (stop - start)) << "ms" << endl;
    cout << endl << "/////////////////////////////////////////////////////////" << endl << endl;




    // 4.qsort()
    //�}�ɡA�غc��l��ƽƥ�
    ofstream fout_D("outputD.txt");
    int *copy_4 = new int[data_amount];
    for(int i = 0 ; i < data_amount ; ++i)
        copy_4[i] = data[i];

    //�ƧǨíp�����ɶ�
    start = clock();
    qsort(copy_4, data_amount, sizeof(int), cmpfunc);
    stop = clock();

    //��X���G���ɮ�
    fout_D << "qsort()" << endl;
    for(int i = 0 ; i < data_amount ; ++i)
        fout_D << copy_4[i] << endl;
    fout_D.close();

    //��ܰ��浲�G
    cout << "4. qsort()" << endl;
    cout << "��Ƽƶq : " << data_amount << endl;
    cout << "�B�z�ɶ� : " <<((double) (stop - start)) << "ms" << endl;
    cout << endl << "/////////////////////////////////////////////////////////" << endl << endl;




    //5. sort()
    //�}�ɡA�غc��l��ƽƥ�
    ofstream fout_E("outputE.txt");
    int *copy_5 = new int[data_amount];
    for(int i = 0 ; i < data_amount ; ++i)
        copy_5[i] = data[i];

    //�ƧǨíp�����ɶ�
    start = clock();
    sort(copy_5, copy_5 + data_amount);
    stop = clock();

    //��X���G���ɮ�
    fout_E << "sort()" << endl;
    for(int i = 0 ; i < data_amount ; ++i)
        fout_E << copy_5[i] << endl;
    fout_E.close();

    //��ܰ��浲�G
    cout << "5. sort()" << endl;
    cout << "��Ƽƶq : " << data_amount << endl;
    cout << "�B�z�ɶ� : " <<((double) (stop - start)) << "ms" << endl;
    cout << endl << "/////////////////////////////////////////////////////////" << endl << endl;
}
