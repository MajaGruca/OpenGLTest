#ifdef _RYSOWANIE
glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
glMatrixMode(GL_MODELVIEW);
glBindTexture(GL_TEXTURE_2D, snow_texture);
ter->GenerateTerrain();

glDisable(GL_TEXTURE_2D);

glPushMatrix();
        auto vars = ter->getPlaceForSkilift();
        glTranslatef(std::get<0>(vars), std::get<1>(vars), std::get<2>(vars));
        glScalef(0.1,0.1,0.1);
        glRotatef(270,0,1,0);
        rysujModel ("skilift");
    glPopMatrix();


    glPushMatrix();
        auto vars_up = ter->getPlaceForUpperSkiLift();
        glTranslatef(std::get<0>(vars_up), std::get<1>(vars_up), std::get<2>(vars_up));
        glScalef(0.1,0.1,0.1);
        glRotatef(90,0,1,0);
        rysujModel ("skilift");
    glPopMatrix();


    glPushMatrix();
        double xDiff = double(int(std::get<0>(vars)/10));
        double poleX = std::get<0>(vars_up)+xDiff;
        double poleZ = std::get<2>(vars_up);
        double poleY = ter->getHeightOfPoint(int(poleX), int(poleZ));
        std::cout<<"Pole x "<<poleX<<" Pole y "<<poleY<<" Pole z "<<poleZ<<"\n";
        glTranslatef(poleX, poleY, poleZ);
        glScalef(0.3,0.3,0.3);
        glRotatef(90,0,1,0);
        rysujModel ("skipole");
    glPopMatrix();

        glPushMatrix();
        double pole2X = std::get<0>(vars)-xDiff;
        double pole2Z = std::get<2>(vars);
        double pole2Y = ter->getHeightOfPoint(int(pole2X), int(pole2Z));
        std::cout<<"Pole x "<<pole2X<<" Pole y "<<pole2Y<<" Pole z "<<pole2Z<<"\n";
        glTranslatef(pole2X, pole2Y, pole2Z);
        glScalef(0.3,0.3,0.3);
        glRotatef(90,0,1,0);
        rysujModel ("skipole");
    glPopMatrix();



    std::vector< std::tuple<double,double,double> > tuple_list = ter->drawPoles(poleX, poleY, poleZ, pole2X, pole2Y, pole2Z);

        for(auto const& value: tuple_list) {
            glPushMatrix();
            glTranslatef(std::get<0>(value), std::get<1>(value), std::get<2>(value));
            glScalef(0.3,0.3,0.3);
            glRotatef(90,0,1,0);
            rysujModel ("skipole");
            glPopMatrix();
            }
    std::vector< std::tuple<double,double,double> >  resultv;
    resultv = tuple_list;
    glPushMatrix();
        glBegin (GL_LINES);
        glVertex3f (std::get<0>(vars_up), std::get<1>(vars_up)+0.4, std::get<2>(vars_up));
        glVertex3f (poleX, poleY+1.6, poleZ-0.2);
        glVertex3f (poleX, poleY+1.6, poleZ-0.2);
        for(auto const& value: tuple_list) {
            glVertex3f (std::get<0>(value), std::get<1>(value)+1.6, std::get<2>(value)-0.2);
            glVertex3f (std::get<0>(value), std::get<1>(value)+1.6, std::get<2>(value)-0.2);
        }
        glVertex3f (pole2X-0.2, pole2Y+1.6, pole2Z-0.2);
        glVertex3f (pole2X-0.2, pole2Y+1.6, pole2Z-0.2);
        glVertex3f (std::get<0>(vars)-1.5, std::get<1>(vars)+0.4, std::get<2>(vars)-0.4);
        glEnd();
        glBegin (GL_LINES);
        glVertex3f (std::get<0>(vars_up)+0.2, std::get<1>(vars_up)+0.4, std::get<2>(vars_up)+0.2);
        glVertex3f (poleX+0.2, poleY+1.6, poleZ+0.2);
        resultv.insert(resultv.begin(),std::tuple<double,double,double>(poleX, poleY, poleZ));
        resultv.insert(resultv.begin(),std::tuple<double,double,double>(std::get<0>(vars_up), std::get<1>(vars_up)-1.15, std::get<2>(vars_up)+0.2));
        glVertex3f (poleX+0.2, poleY+1.6, poleZ+0.2);
        for(auto const& value: tuple_list) {
            glVertex3f (std::get<0>(value), std::get<1>(value)+1.6, std::get<2>(value)+0.2);
            glVertex3f (std::get<0>(value), std::get<1>(value)+1.6, std::get<2>(value)+0.2);
        }
        glVertex3f (pole2X, pole2Y+1.6, pole2Z+0.2);
        glVertex3f (pole2X, pole2Y+1.6, pole2Z+0.2);
        glVertex3f (std::get<0>(vars)-1.5, std::get<1>(vars)+0.4, std::get<2>(vars)+0.4);
        glEnd();
    glPopMatrix();
    if (posx >2000) {
        posx = 0;
    }
    std::tuple<double,double,double> result;
    std::reverse(resultv.begin(), resultv.end()) ;
    double prevX = std::get<0>(vars)-1.5;
    double prevY = std::get<1>(vars)+0.5;
    double prevZ = std::get<2>(vars)-0.4;
    for(auto const& value: resultv) {
        double X = std::get<0>(value);
        double Y = std::get<1>(value)+1.6;
        double Z = std::get<2>(value)-0.2;
        double XDdiff = abs(prevX-X)/5;
        for (int z=0; z<5; z++) {
            result = ter->getChairPlace(prevX, prevY, prevZ, X, Y, Z, prevX-XDdiff*z-XDdiff/2000*posx);
            posx +=1;
            glPushMatrix();
            glTranslatef(std::get<0>(result), std::get<1>(result)-0.67, std::get<2>(result)+0.43);
            glScalef(0.3,0.3,0.3);
            glRotatef(90,0,1,0);
            rysujModel ("chair");
            glPopMatrix();
        }
        prevX = X;
        prevY = Y;
        prevZ = Z;
    }

    std::reverse(resultv.begin(), resultv.end());
    int el = 0;
    for(auto const& value: resultv) {
        if (el == 0) {
            prevX = std::get<0>(value);
            prevY = std::get<1>(value)+1.6;
            prevZ = std::get<2>(value);
        }
        else {
        double X = std::get<0>(value);
        double Y = std::get<1>(value)+1.6;
        double Z = std::get<2>(value)-0.2;
        double XDdiff = abs(prevX-X)/5;
        for (int z=0; z<5; z++) {
            result = ter->getChairPlace(prevX, prevY, prevZ, X, Y, Z, prevX+XDdiff*z+XDdiff/2000*posx);
            posx +=1;
            glPushMatrix();
            glTranslatef(std::get<0>(result), std::get<1>(result)-0.67, std::get<2>(result)+0.43);
            glScalef(0.3,0.3,0.3);
            glRotatef(-90,0,1,0);
            rysujModel ("chair");
            glPopMatrix();
        }
        prevX = X;
        prevY = Y;
        prevZ = Z;
        }
        el += 1;
        }


glEnable(GL_TEXTURE_2D);
//*/
//    glBegin(GL_QUADS);
//    int texTiles = 3;   // zmiana wartości 3 na inną sprawia że tekstura jest bardziej lub mniej rozciągnięta
//	glTexCoord2f(texTiles, texTiles);
//	glVertex3f(10.0f, 10.0f, 10.0f);
//	glTexCoord2f(0, texTiles);
//	glVertex3f(-10.0f, 10.0f, 10.0f);
//	glTexCoord2f(0, 0);
//	glVertex3f(-10.0f, -10.0f, 10.0f);
//	glTexCoord2f(texTiles, 0);
//	glVertex3f(10.0f, -10.0f, 10.0f);
//
//	glEnd();
//
//	glBindTexture(GL_TEXTURE_2D, tex_blue);
//*/
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
