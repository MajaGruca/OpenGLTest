//
// Created by olga on 18.04.20.
//

#include <GL/gl.h>
#include <iostream>
#include <fstream>
#include "Terrain.h"
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <random>
#include <tuple>
#include <iomanip>

using namespace std;

int x1 = 0;

Terrain::Terrain(int rows, int columns, int length) {
    this->rows = rows;
    this->columns = columns;
    this->length = length;
}

void Terrain::GenerateTerrain() {
    for (int h=0; h<this->columns; h++) {
        glPushMatrix();
        glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
        glColor3f(0.0f, 1.0f, 0.0f);
        glBegin(GL_TRIANGLE_STRIP);
        int n =0;
        for (int w=0; w<this->rows*2; w=w+2) {
            double y = this->getHeightOfPoint(n, h);
            glTexCoord2f(x1, 0);
            glVertex3f((float) n, (float) y, (float) h);
//            std::cout << "Vert: " << (float) n << " " << (float) y << " " << (float) h << "\n";
            y = (float) this->getHeightOfPoint(n, h+1);
//            std::cout << "Vert: " << (float) n << " " << (float) y << " " << (float) h + 1 << "\n";
            glTexCoord2f(x1, 1);
            if(x1==0)
                x1=1;
            else
                x1=0;
            glVertex3f((float) n, (float) y, (float) h + 1);
            n++;
        }
        glEnd();
        glPopMatrix();
    }
};

double Terrain::getHeightOfPoint(int x, int y) {
    return this->ary[x][y];
}

tuple<double,double,double> Terrain::getPlaceForSkilift() {
    double x = this->rows-3;
    double z = this->columns/2;
    double y = this->getHeightOfPoint(int(x),int(z));
    return std::make_tuple(x,y,z);
}

tuple<double,double,double> Terrain::getPlaceForUpperSkiLift() {
    double x = 3.0;
    double z = this->columns/2;
    double y = this->getHeightOfPoint(int(x),int(z));
    return std::make_tuple(x,y,z);
}

void Terrain::getDistanceBetweenSkiLifts() {
    tuple<double,double,double> upper = this->getPlaceForUpperSkiLift();
    tuple<double,double,double> down = this->getPlaceForSkilift();
    double x1 = get<0>(upper);
    double y1 = get<1>(upper);
    double z1 = get<2>(upper);
    double x2 = get<0>(down);
    double y2 = get<1>(down);
    double z2 = get<2>(down);
    double d = sqrt(pow(x2 - x1, 2) +
                   pow(y2 - y1, 2) +
                   pow(z2 - z1, 2) * 1.0);
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    cout << " Distance is " << d;
}
void Terrain::getHeightArrayFromFile(std::string nameOfFile) {
    std::ifstream csv(nameOfFile);
    std::string line;
    std::vector <std::vector<double>> items;

    if (csv.is_open()) {
        cout << "Opened file";
        for (std::string row_line; std::getline(csv, row_line);)
        {
            items.emplace_back();
            std::istringstream row_stream(row_line);
            for(std::string column; std::getline(row_stream, column, ',');)
                items.back().push_back(std::stod(column));
        }
        this->ary = items;
        randomizeHeights();
    }
    else {
        cout << "Unable to open file";
    }
}

void Terrain::randomizeHeights() {
    double max, min, h1, h2 = 0.0;
    std::random_device rd;
    std::mt19937 generator(rd());
    std::vector <std::vector<double>> randomizedHeights;
    std::vector<double> zeros(this->columns*6+1, 0.0);
    randomizedHeights.push_back(zeros);
    for (int i=0; i<this->rows-1; i++) {
        int counter = 0;
        while (counter<5) {
            std::vector<double> randomizedHeightsRow;
            randomizedHeightsRow.push_back(0.0);
            for (int j = 0; j < this->columns - 1; j++) {
                if (counter == 0) {
                    h1 = getHeightOfPoint(i, j);
                    h2 = getHeightOfPoint(i, j + 1);
                } else {
                    h1 = getHeightOfPoint(i, j);
                    h2 = getHeightOfPoint(i + 1, j);
                }
                randomizedHeightsRow.push_back(h1);
                if (h1 < h2) {
                    max = h2;
                    min = h1;
                } else {
                    max = h1;
                    min = h2;
                };
                std::uniform_real_distribution<double> distribution(min-0.1, max+0.1);
                for (int z = 0; z < 5; z++) {
                    randomizedHeightsRow.push_back(distribution(generator));
                }
                randomizedHeightsRow.push_back(h2);
            }
            counter++;
            randomizedHeightsRow.push_back(0.0);
            randomizedHeights.push_back(randomizedHeightsRow);
        }
    }
    randomizedHeights.push_back(zeros);
    this->ary = randomizedHeights;
    this->columns = (this->columns*6)+1;
    this->rows = (this->rows-1)*5+2;
}

