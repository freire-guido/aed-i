#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"

int indiceMenorigual(int e, vector<pair<int, int>>& v){
    int i = 0;
    int j = v.size() - 1;
    while (i <= j){
        int k = (i + j) / 2;
        if (v[k].first <=  e){
            i = k + 1;
        } else {
            j = k - 1;
        }
    }
    return i - 1; 
}

int indiceMenorigual(int e, vector<vector<int>>& v){
    int i = 0;
    int j = v.size() - 1;
    while (i <= j){
        int k = (i + j) / 2;
        if (v[k][0] <=  e){
            i = k + 1;
        } else {
            j = k - 1;
        }
    }
    return i - 1;
}

//Ordena (insertion) un vector de vectores de acuerdo al valor del indice e de cada elemento.
void ordenarSegun(int e, vector<vector<int>>& v){
    for (int i=0; i < v.size(); i++){
        for (int j=i; j > 0 && v[j][e] < v[j-1][e]; j--){
            v[j].swap(v[j-1]);
        }
    }
}

float distanciaEuclideana(pair<int, int> centro, int latitud, int longitud){
    return sqrt((centro.first - latitud)*(centro.first - latitud) + (centro.second - longitud)*(centro.second - longitud)); // Exponenciacion en C++ ???
}