#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"

int cantidadHabitantes(dato &h,eph_i ti){
    int habitantes = 0;
    for(individuo i : ti){
        if(i[INDCODUSU] == h){
            habitantes += 1;
        }
    }
    return(habitantes);
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