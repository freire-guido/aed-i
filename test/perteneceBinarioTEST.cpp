#include "../auxiliares.h"
#include "gtest/gtest.h"

TEST(perteneceBinarioTEST, principioInt){
    vector<int> in = {1, 2, 4, 8, 10, 13, 10000};
    ASSERT_TRUE(perteneceBinario(1, in));
}

TEST(perteneceBinarioTEST, medioInt){
    vector<int> in = {2, 3, 4, 8, 10, 13, 99};
    ASSERT_TRUE(perteneceBinario(8, in));
}

TEST(perteneceBinarioTEST, finalInt){
    vector<int> in = {1, 2, 4, 8, 10, 13, 10000};
    ASSERT_TRUE(perteneceBinario(10000, in));
}

TEST(perteneceBinarioTEST, falsoInt){
    vector<int> in = {1, 2, 4, 8, 10, 13, 10000};
    ASSERT_FALSE(perteneceBinario(9, in));
}

TEST(perteneceBinarioTEST, principioPair){
    vector<pair<int, int>> in = {make_pair(1, 2), make_pair(1, 3), make_pair(2, 1), make_pair(3, 20), make_pair(100, 1)};
    ASSERT_TRUE(perteneceBinario(make_pair(1, 2), in));
}

TEST(perteneceBinarioTEST, medioPair){
    vector<pair<int, int>> in = {make_pair(1, 2), make_pair(1, 3), make_pair(2, 1), make_pair(3, 20), make_pair(100, 1)};
    ASSERT_TRUE(perteneceBinario(make_pair(2, 1), in));
}

TEST(perteneceBinarioTEST, finalPair){
    vector<pair<int, int>> in = {make_pair(1, 2), make_pair(1, 3), make_pair(2, 1), make_pair(3, 20), make_pair(100, 1)};
    ASSERT_TRUE(perteneceBinario(make_pair(100, 1), in));
}

TEST(perteneceBinarioTEST, falsoPair){
    vector<pair<int, int>> in = {make_pair(1, 2), make_pair(1, 3), make_pair(2, 1), make_pair(3, 20), make_pair(100, 1)};
    ASSERT_FALSE(perteneceBinario(make_pair(6, 1), in));
}

TEST(perteneceBinarioTEST, principioMix){
    vector<pair<int, int>> in = {make_pair(1, 2), make_pair(1, 3), make_pair(2, 1), make_pair(3, 20), make_pair(100, 1)};
    ASSERT_TRUE(perteneceBinario(1, in));
}

TEST(perteneceBinarioTEST, medioMix){
    vector<pair<int, int>> in = {make_pair(1, 2), make_pair(1, 3), make_pair(2, 1), make_pair(3, 20), make_pair(100, 1)};
    ASSERT_TRUE(perteneceBinario(2, in));
}

TEST(perteneceBinarioTEST, finalMix){
    vector<pair<int, int>> in = {make_pair(1, 2), make_pair(1, 3), make_pair(2, 1), make_pair(3, 20), make_pair(100, 1)};
    ASSERT_TRUE(perteneceBinario(100, in));
}

TEST(perteneceBinarioTEST, falsoMix){
    vector<pair<int, int>> in = {make_pair(1, 2), make_pair(1, 3), make_pair(2, 1), make_pair(3, 20), make_pair(100, 1)};
    ASSERT_FALSE(perteneceBinario(5, in));
}