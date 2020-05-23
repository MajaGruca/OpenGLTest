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

using namespace std;

Terrain::Terrain(int rows, int columns, int length) {
    this->rows = rows;
    this->columns = columns;
    this->length = length;
}

void Terrain::GenerateTerrain() {
    for (int h=0; h<this->columns; h++) {
        glPushMatrix();
        glBegin(GL_TRIANGLE_STRIP);
        glColor3f(0.0, 1.0, 0.0);
        int n =0;
        for (int w=0; w<this->rows*2; w=w+2) {
            double y = this->getHeightOfPoint(n, h);
            glVertex3f((float) n, (float) y, (float) h);
            std::cout << "Vert: " << (float) n << " " << (float) y << " " << (float) h << "\n";
            y = (float) this->getHeightOfPoint(n, h+1);
            std::cout << "Vert: " << (float) n << " " << (float) y << " " << (float) h + 1 << "\n";
            glVertex3f((float) n, (float) y, (float) h + 1);
            n++;
        }
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnd();
        glPopMatrix();
    }
};

double Terrain::getHeightOfPoint(int x, int y) {
    return this->ary[x][y];
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
                items.back().push_back(std::stoi(column));
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
    for (int i=0; i<this->rows-1; i++) {
        int counter = 0;
        while (counter<5) {
            std::vector<double> randomizedHeightsRow;
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
                std::uniform_real_distribution<double> distribution(min, max);
                for (int z = 0; z < 5; z++) {
                    randomizedHeightsRow.push_back(distribution(generator));
                }
                randomizedHeightsRow.push_back(h2);
            }
            counter++;
            randomizedHeights.push_back(randomizedHeightsRow);
        }
    }
    this->ary = randomizedHeights;
    this->columns = (this->columns+1)*5;
    this->rows = (this->rows-1)*5;
}
