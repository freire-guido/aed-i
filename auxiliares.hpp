#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"

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
}