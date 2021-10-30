#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"

template<typename T>
bool perteneceBinario(vector<T> v, T e){
    
    bool res = false;
    int desde = 0;
    int hasta = v.size();
   
    while (desde <= hasta){
        
        int medio = (desde + hasta)/2;
        
        if(v[medio] == e){
            res = true;
        }
        
        if(v[medio] < e){
            desde = medio + 1;
        }else{
            hasta = medio - 1;
        }
    }
    return res;
}