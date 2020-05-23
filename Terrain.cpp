//
// Created by olga on 18.04.20.
//

#include <GL/gl.h>
#include <iostream>
#include <fstream>
#include "Terrain.h"
//#include <boost/algorithm/string.hpp>
//#include <algorithm>
//#include <cstdlib>
#include <vector>
#include <sstream>

using namespace std;

int x1 = 0, y1=0;

Terrain::Terrain(int rows, int columns, int length) {
    this->rows = rows;
    this->columns = columns;
    this->length = length;
}

void Terrain::GenerateTerrain() {
    for (int h=0; h<this->columns; h++) {
        glPushMatrix();
//        glTranslatef(0.0f, 0.0f, h);
        glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
        glColor3f(0.0f, 1.0f, 0.0f);
        glBegin(GL_TRIANGLE_STRIP);
        int n =0;
        for (int w=0; w<this->rows*2; w=w+2) {
            double y = this->getHeightOfPoint(n, h);
            glTexCoord2f(x1, 0);
            glVertex3f((float) n, (float) y, (float) h);
            std::cout << "Vert: " << (float) n << " " << (float) y << " " << (float) h << "\n";
            y = (float) this->getHeightOfPoint(n, h+1);
            std::cout << "Vert: " << (float) n << " " << (float) y << " " << (float) h + 1 << "\n";
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
    }
    else {
        cout << "Unable to open file";
    }
}



