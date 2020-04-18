/*

 C++ przez OpenGL - szablon do cwiczen laboratoryjnych
 (C) Michal Turek.

*/

#ifdef _RYSOWANIE

ter->GenerateTerrain();
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
