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