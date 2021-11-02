#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "ejercicios.h"

//Dada una lista v de T ordenados, devuelve verdadero si e pertenece a v
template<typename T>
bool perteneceBinario(T e, const vector<T>& v);
template<typename T>
void insertarOrdenado(T e, vector<T>& v);

#include "auxiliares.hpp"

#endif //SOLUCION_AUXILIARES_H
