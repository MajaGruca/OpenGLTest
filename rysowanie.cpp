#ifdef _RYSOWANIE
glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
glMatrixMode(GL_MODELVIEW);
glBindTexture(GL_TEXTURE_2D, snow_texture);
ter->GenerateTerrain();
glPushMatrix();
        glEnable(GL_BLEND);
        glDepthMask(GL_FALSE);
        glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_COLOR);
        glBindTexture(GL_TEXTURE_2D, skilift_texture);
        glMateriali(GL_FRONT, GL_EMISSION,(0,0,0,1));
        glTranslatef(105,-6.7,-103);
        rysujModel ("skilift");
        glDepthMask(GL_TRUE);
        glDisable(GL_BLEND);
    glPopMatrix();

/*


    glBegin(GL_QUADS);
    int texTiles = 3;   // zmiana wartości 3 na inną sprawia że tekstura jest bardziej lub mniej rozciągnięta
	glTexCoord2f(texTiles, texTiles);
	glVertex3f(10.0f, 10.0f, 10.0f);
	glTexCoord2f(0, texTiles);
	glVertex3f(-10.0f, 10.0f, 10.0f);
	glTexCoord2f(0, 0);
	glVertex3f(-10.0f, -10.0f, 10.0f);
	glTexCoord2f(texTiles, 0);
	glVertex3f(10.0f, -10.0f, 10.0f);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, tex_blue);
*/
/******************* SZABLON **************************/
//glPushMatrix();
//    glBegin(GL_TRIANGLE_STRIP);
//    glColor3f(0.0f, 1.0f, 0.0f);     // Red
//    glVertex3f( 0.0f, 0.0f, 0.0f);
//    glVertex3f(0.0f, 0.0f, 1.0f);
//    glVertex3f(1.0f, 0.0f, 0.0f);
//    glVertex3f(1.0f, 0.5f, 1.0f);
//    glVertex3f(2.0f, 0.0f, 0.0f);
//    glVertex3f(2.0f, -0.5f, 1.0f);
//    glVertex3f(3.0f, 0.0f, 0.0f);
//    glVertex3f(3.0f, 0.0f, 1.0f);
//    glEnd();
//glPopMatrix();
//
//glPushMatrix();
//    glTranslatef(0.0f, 0.0f, 1.0f);
//    glBegin(GL_TRIANGLE_STRIP);
//    glColor3f(0.0f, 1.0f, 0.0f);
//    glVertex3f( 0.0f, 0.0f, 0.0f);
//    glVertex3f(0.0f, 0.0f, 1.0f);
//    glVertex3f(1.0f, 0.0f, 0.0f);
//    glVertex3f(1.0f, 0.5f, 1.0f);
//    glVertex3f(2.0f, 0.0f, 0.0f);
//    glVertex3f(2.0f, -0.5f, 1.0f);
//    glVertex3f(3.0f, 0.0f, 0.0f);
//    glVertex3f(3.0f, 0.0f, 1.0f);
//    glEnd();
//    glVertex3f( 3.0f, 0.0f, 2.0f);
//    glVertex3f(2.0f, -0.5f, 1.0f);
//    glVertex3f(2.0f, 0.0f, 2.0f);
//    glVertex3f(1.0f, 0.5f, 1.0f);
glPopMatrix();


    //glBindTexture(GL_TEXTURE_2D, tex_green);

/*
    // Tu (na koncu) rysowanie obiekt�w BLEND

    glPushMatrix();
        glEnable(GL_BLEND);
        glDepthMask(GL_FALSE);
        glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_COLOR);
        GLfloat  mat1[4] = {0.5,0.4,0.7,1};
        glMaterialfv(GL_FRONT, GL_SPECULAR,mat1);
        glMaterialfv(GL_FRONT, GL_AMBIENT,mat1);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,mat1);
        glTranslatef(105,-6.7,-103);
        rysujModel ("woda");
        glDepthMask(GL_TRUE);
        glDisable(GL_BLEND);
    glPopMatrix();
*/
	/******************************************************/


#undef _RYSOWANIE
#endif
