#include "../auxiliares.h"
#include "gtest/gtest.h"

TEST(insertarOrdenadoTEST, repetidosPrincipio){
    vector<int> in = {1, 1, 1, 2, 4, 5, 10};
    vector<int> esperado = {1, 1, 1, 2, 3, 4, 5, 10};
    insertarOrdenado(3, in);
    ASSERT_EQ(esperado, in);
}

TEST(insertarOrdenadoTEST, repetidosFinal){
    vector<int> in = {1, 2, 4, 5, 10, 10, 10};
    vector<int> esperado = {1, 2, 3, 4, 5, 10, 10, 10};
    insertarOrdenado(3, in);
    ASSERT_EQ(esperado, in);
}

TEST(insertarOrdenadoTEST, insertarRepetido){
    vector<int> in = {1, 2, 4, 5, 5, 6, 10};
    vector<int> esperado = {1, 2, 4, 5, 5, 5, 6, 10};
    insertarOrdenado(5, in);
    ASSERT_EQ(esperado, in);
}

TEST(insertarOrdenadoTEST, todosRepetidos){
    vector<int> in = {1, 1, 1, 1, 1};
    vector<int> esperado = {1, 1, 1, 1, 1, 3};
    insertarOrdenado(3, in);
    ASSERT_EQ(esperado, in);
}

TEST(insertarOrdenadoTEST, insertarAlPrincipio){
    vector<int> in = {2, 3, 4};
    vector<int> esperado = {1, 2, 3, 4};
    insertarOrdenado(1, in);
    ASSERT_EQ(esperado, in);
}

TEST(insertarOrdenadoTEST, insertarAlFinal){
    vector<int> in = {2, 3, 4};
    vector<int> esperado = {2, 3, 4, 5};
    insertarOrdenado(5, in);
    ASSERT_EQ(esperado, in);
}