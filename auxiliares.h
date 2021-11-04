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
        if (v[k] < e){
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

//Devuelve el indice del ultimo par de v con primer elemento menor o igual a e, -1 si no hay
template<typename T, typename V>
int indiceMenorigual(T e, vector<pair<T, V>>& v){
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

//Devuelve el indice del ultimo elemento de v menor o igual a e, -1 si no hay
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

//Devuelve una lista ordenada por ordenador de elementos que cumplen pred
template<typename T, typename O, typename P>
vector<pair<int, int>> contarPorAtributo(const vector<T>& v, O ordenador, P pred){
    vector<pair<int, int>> res;
    for (T e: v){
        if (pred(e)){
            auto orden = ordenador(e);
            int indice = indiceMenorigual(orden, res);
            if (indice > -1 && res[indice].first == orden){
                res[indice].second++;
            } else {
                res.insert(res.begin() + indice + 1, make_pair(orden, 1));
            }
        }
    }
    return res;
}

template<typename T, typename O>
vector<pair<int, int>> contarPorAtributo(const vector<T>& v, O ordenador){
    vector<pair<int, int>> res;
    for (T e: v){
        auto orden = ordenador(e);
        int indice = indiceMenorigual(orden, res);
        if (indice > -1 && res[indice].first == orden){
            res[indice].second++;
        } else {
            res.insert(res.begin() + indice + 1, make_pair(orden, 1));
        }
    }
    return res;
}

int cantidadHabitantes(dato &h,eph_i ti);

#endif //SOLUCION_AUXILIARES_H