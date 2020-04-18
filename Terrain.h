//
// Created by olga on 18.04.20.
//

#ifndef OPENGLTEST_TERRAIN_H
#define OPENGLTEST_TERRAIN_H


#include <vector>

class Terrain {
private:
    int rows, columns, length = 0;

public:
    Terrain(int rows, int columns, int length);
    int getHeightOfPoint(int x, int y);
    void GenerateTerrain();
    int ary[4][4] = {
            {1,1,1,1},
            {1,2,1,1},
            {1,1,1,0},
            {1,1,1,1}
    };
};


#endif //OPENGLTEST_TERRAIN_H
