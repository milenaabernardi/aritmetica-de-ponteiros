#include <iostream>
using namespace std;

void encontrarMinMax(int* arr, int tam, int* minEnd, int* maxEnd);
int* juntar(const int* arr1, int tam1, const int* arr2, int tam2);
void separarParesImpares(const int* arr, int tam, int* pares, int& tamPares, int* impares, int& tamImpares);

int main(){
    int array1[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int minimo, maximo;
    encontrarMinMax(array1, sizeof(array1) / sizeof(array1[0]), &minimo, &maximo);
    cout << "Minimo: " << minimo << endl;
    cout << "Maximo: " << maximo << endl;

    int array2[] = {1, 2, 3};
    int tam1 = sizeof(array1) / sizeof(array1[0]);
    int tam2 = sizeof(array2) / sizeof(array2[0]);
    int* resultado = juntar(array1, tam1, array2, tam2);
    cout << "Vetor resultante da juncao: ";
    for (int i = 0; i < tam1 + tam2; ++i){
        cout << *(resultado + i) << " ";
    }
    cout << endl;
    delete[] resultado;

    int array3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int tam3 = sizeof(array3) / sizeof(array3[0]);
    int pares[tam3];
    int tamPares = 0;
    int impares[tam3];
    int tamImpares = 0;
    separarParesImpares(array3, tam3, pares, tamPares, impares, tamImpares);
    cout << "Pares: ";
    for (int i = 0; i < tamPares; ++i){
        cout << pares[i] << " ";
    }
    cout << endl;
    cout << "Impares: ";
    for (int i = 0; i < tamImpares; ++i){
        cout << impares[i] << " ";
    }
    cout << endl;

    return 0;
}
void encontrarMinMax(int* arr, int tam, int* minEnd, int* maxEnd){
    if (tam <= 0){
        cout << "O array está vazio." << endl;
        return;
    }
    *minEnd = *arr;
    *maxEnd = *arr;
    for (int i = 1; i < tam; ++i){
        if (*(arr + i) < *minEnd){
            *minEnd = *(arr + i);
        } else if (*(arr + i) > *maxEnd){
            *maxEnd = *(arr + i);
        }
    }
}
int* juntar(const int* arr1, int tam1, const int* arr2, int tam2){
    int* resultado = new int[tam1 + tam2];

    for (int i = 0; i < tam1; ++i){
        *(resultado + i) = *(arr1 + i);
    }

    for (int i = 0; i < tam2; ++i){
        *(resultado + tam1 + i) = *(arr2 + i);
    }

    return resultado;
}
void separarParesImpares(const int* arr, int tam, int* pares, int& tamPares, int* impares, int& tamImpares){
    tamPares = 0;
    tamImpares = 0;
    for (int i = 0; i < tam; ++i){
        if (*(arr + i) % 2 == 0){
            *(pares + tamPares) = *(arr + i);
            ++tamPares;
        } else {
            *(impares + tamImpares) = *(arr + i);
            ++tamImpares;
        }
    }
}