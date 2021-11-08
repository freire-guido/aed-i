#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"

//-- DEPRECADA: Usar indiceMenorigual -- Inserta un elemento en una lista de manera ordenada.
template<typename T>
void insertarOrdenado(T e, vector<T>& v){
    //busca el elemento "anterior" (el menor mas grande)
    int i = 0;
    int j = v.size() - 1;
    while (i <= j){
        int k = (i + j) / 2;
        if (v[k] < e){
            i = k + 1;
        } else {
            j = k - 1;
        }
    }
    v.insert(v.begin() + i, e);
    return;
}

//-- DEPRECADA: Usar indiceMenorigual -- Dada una lista v de pares T, V ordenados, devuelve verdadero si e pertenece al primer elemento de algun par.
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

//-- DEPRECADA: Usar indiceMenorigual -- Dada una lista v de T ordenados, devuelve verdadero si e pertenece a v.
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

//Devuelve el indice del ultimo elemento de v menor o igual a e, -1 si no hay.
template<typename T>
int indiceMenorigual(T e, vector<T>& v){
    int i = 0;
    int j = v.size() - 1;
    while (i <= j){
        int k = (i + j) / 2;
        if (v[k] <=  e){
            i = k + 1;
        } else {
            j = k - 1;
        }
    }
    return i - 1;
}

//Devuelve el indice del ultimo par de v con primer elemento menor o igual a e, -1 si no hay.
int indiceMenorigual(int e, vector<pair<int, int>>& v);

//Devuelve el indice del ultimo subvector cuyo primer elemento es menor o igual a e, -1 si no hay.
int indiceMenorigual(int e, vector<vector<int>>& v);

int cantidadHabitantes(dato &h,eph_i ti);

void ordenarSegun(int e, vector<vector<int>>& v);

float distanciaEuclideana(pair<int, int> centro, int latitud, int longitud);

#endif //SOLUCION_AUXILIARES_H