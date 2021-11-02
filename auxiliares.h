#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"

template<typename T>
void insertarOrdenado(T e, vector<T>& v){
    //busca el elemento "anterior" (el menor mas grande)
    int i = 0;
    int j = v.size() - 1;
    while (i <= j){
        int k = (i + j) / 2;
        if (v[k] <  e){
            i = k + 1;
        } else {
            j = k - 1;
        }
    }
    v.insert(v.begin() + i, e);
    return;
}

//Dada una lista v de pares T, V ordenados, devuelve verdadero si e pertenece al primer elemento de algun par
template<typename T, typename V>
bool perteneceBinario(T e, const vector<pair<T, V>>& v){
    int i = 0;
    int j = v.size() - 1;
    while (i <= j){  
        int k = (i + j) / 2;
        if (v[k].first == e){
            return true;
        }
        else if (v[k].first < e){
            i = k + 1;
        } else {
            j = k - 1;
        }
    }
    return false;
}

//Dada una lista v de T ordenados, devuelve verdadero si e pertenece a v
template<typename T>
bool perteneceBinario(T e, const vector<T>& v){
    int i = 0;
    int j = v.size() - 1;
    while (i <= j){  
        int k = (i + j) / 2;
        if (v[k] == e){
            return true;
        }
        else if (v[k] < e){
            i = k + 1;
        } else {
            j = k - 1;
        }
    }
    return false;
}

int cantidadHabitantes(dato &h,eph_i ti);

#endif //SOLUCION_AUXILIARES_H