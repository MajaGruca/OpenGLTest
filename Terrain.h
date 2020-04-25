//
// Created by olga on 18.04.20.
//

#ifndef OPENGLTEST_TERRAIN_H
#define OPENGLTEST_TERRAIN_H

#include <string>
#include <vector>

class Terrain {
private:
    int rows, columns, length = 0;
    //ary [rows][columns] = {
//            {1,1,1,1,2,1,1,1},
//            {1,2,1,1,1,1,1,1},
//            {1,1,1,0,1,1,0,1},
//            {1,1,1,1,1,1,0,0}
//    };
public:
    Terrain(int rows, int columns, int length);
    double getHeightOfPoint(int x, int y);
    void GenerateTerrain();
    std::vector< std::vector<double> > ary;
    void getHeightArrayFromFile(std::string nameOfFile);
//    int ary[2][3] = {
//            {1,1,1},
//            {1,2,1}
//    };
};


#endif //OPENGLTEST_TERRAIN_H
