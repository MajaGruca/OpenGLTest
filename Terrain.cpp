//
// Created by olga on 18.04.20.
//

#include <GL/gl.h>
#include <iostream>
#include "Terrain.h"

Terrain::Terrain(int rows, int columns, int length) {
    this->rows = rows;
    this->columns = columns;
    this->length = length;
}

void Terrain::GenerateTerrain() {
    for (int h=0; h<this->columns; h++) {
        glPushMatrix();
//        glTranslatef(0.0f, 0.0f, h);
        glBegin(GL_TRIANGLE_STRIP);
        int n =0;
        for (int w=0; w<this->rows*2; w++) {
            if (w%2 == 0) {
                float y = (float) this->getHeightOfPoint(n, h);
                glVertex3f((float) n, (float) y, (float) h);
                y = (float) this->getHeightOfPoint(n, h+1);
                glVertex3f((float) n, (float) y, (float) h + 1);
                n++;
            }
        }
        glEnd();
        glPopMatrix();
    }
};

int Terrain::getHeightOfPoint(int x, int y) {
    return this->ary[x][y];
};

