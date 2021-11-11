#include "../definiciones.h"
#include "../Funciones_TPI.h"
#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

#define UMBRAL 0.0001

// Caso de división por cero que sea igual a 0
TEST(laCasaEstaQuedandoChicaTEST, hacinamientoCriticoTodosIgualAUno) {

//                                                    Región\ +500 /Tipo
//                                                       v  v  v
    eph_h th = {{22114, 2020,   3,  319611, 629088, 3,  1,  0,  1,  3,  1,  2},
                {22866, 2020,   3,  317157, 627217, 2,  40, 0,  1,  2,  1,  2},
                {20957, 2020,   3,  313965, 623297, 1,  41, 0,  1,  3,  1,  2},
                {22110, 2020,   3,  319611, 629088, 3,  42, 0,  1,  3,  1,  2},
                {22111, 2020,   3,  319611, 629088, 3,  43, 0,  1,  3,  1,  2},
                {22112, 2020,   3,  319611, 629088, 3,  44, 0,  1,  3,  1,  2}};

    eph_i ti = {{20957, 2020,   1,  1,  3,  1,  88, 0,  0,  90000,  10},
                {20957, 2020,   2,  1,  3,  2,  82, 0,  0,  25000,  10},
                {20957, 2020,   3,  1,  3,  2,  82, 0,  0,  25000,  10},
                {20957, 2020,   4,  1,  3,  2,  82, 0,  0,  25000,  10},
                {22866, 2020,   1,  0,  3,  1,  31, 1,  3,  59000,  10},
                {22866, 2020,   2,  1,  3,  2,  28, 1,  3,  0,      6},
                {22866, 2020,   3,  1,  3,  2,  28, 1,  3,  0,      6},
                {22866, 2020,   4,  1,  3,  2,  28, 1,  3,  0,      6},
                {22110, 2020,   1,  0,  3,  1,  18, 0,  0,  20000,  10},
                {22110, 2020,   2,  0,  3,  1,  18, 0,  0,  20000,  10},
                {22110, 2020,   3,  0,  3,  1,  18, 0,  0,  20000,  10},
                {22110, 2020,   4,  0,  3,  1,  18, 0,  0,  20000,  10},
                {22114, 2020,   1,  0,  3,  1,  18, 0,  0,  20000,  10},
                {22114, 2020,   2,  0,  3,  1,  18, 0,  0,  20000,  10},
                {22114, 2020,   3,  0,  3,  1,  18, 0,  0,  20000,  10},
                {22114, 2020,   4,  0,  3,  1,  18, 0,  0,  20000,  10},
                {22111, 2020,   1,  0,  3,  1,  18, 0,  0,  20000,  10},
                {22111, 2020,   2,  0,  3,  1,  18, 0,  0,  20000,  10},
                {22111, 2020,   3,  0,  3,  1,  18, 0,  0,  20000,  10},
                {22111, 2020,   4,  0,  3,  1,  18, 0,  0,  20000,  10},
                {22112, 2020,   1,  0,  3,  1,  18, 0,  0,  20000,  10},
                {22112, 2020,   2,  0,  3,  1,  18, 0,  0,  20000,  10},
                {22112, 2020,   3,  0,  3,  1,  18, 0,  0,  20000,  10},
                {22112, 2020,   4,  0,  3,  1,  18, 0,  0,  20000,  10}
    };

    EXPECT_TRUE(esEncuestaValida(th, ti));

    vector<pair<int,float>> esperado = {make_pair(1,1.0),
                                        make_pair(40, 1.0),
                                        make_pair(41, 1.0),
                                        make_pair(42,1.0),
                                        make_pair(43,1.0),
                                        make_pair(44,1.0)};
    vector<pair<int,float>> resultado = laCasaEstaQuedandoChica(th, ti);

    int i=0;
    while( i < 6 ) {
        EXPECT_EQ( esperado[i].first, resultado[i].first );
        EXPECT_TRUE(flotante_valido(esperado[i].second, resultado[i].second, UMBRAL) );
        i++;
    }
}



// Test nuestros

TEST(laCasaEstaQuedandoChicaTEST, validaMinima) {
    eph_h th = {{22114, 2020,   3,  319611, 629088, 3,  41, 0,  1,  3,  1,  2}};
    eph_i ti = {{22114, 2020,   1,  0,  3,  1,  18, 0,  0,  20000,  10}};

    vector<pair<int,float>> esperado = {make_pair(1,0),
                                        make_pair(40, 0),
                                        make_pair(41, 0),
                                        make_pair(42,0),
                                        make_pair(43,0),
                                        make_pair(44,0)};
    vector<pair<int,float>> resultado = laCasaEstaQuedandoChica(th, ti);
    int i=0;
    while( i < 6 ) {
        EXPECT_EQ( esperado[i].first, resultado[i].first );
        EXPECT_EQ( true, flotante_valido(esperado[i].second, resultado[i].second, UMBRAL) );
        i++;
    }

}