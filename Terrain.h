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
    void randomizeHeights();

    std::tuple<double, double, double> getPlaceForSkilift();
    std::tuple<double, double, double> getPlaceForUpperSkiLift();
    std::vector<std::tuple<double,double,double>> drawPoles(double x1, double y1, double z1, double x2, double y2, double z2);

    std::tuple<double, double, double> getChairPlace(double x1, double y1, double z1, double x2, double y2, double z2);

    std::tuple<double, double, double>
    getChairPlace(double x1, double y1, double z1, double x2, double y2, double z2, double nx);
};


#endif //OPENGLTEST_TERRAIN_H
