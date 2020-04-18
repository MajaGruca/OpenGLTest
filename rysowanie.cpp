#ifdef _RYSOWANIE

    glTranslatef(0.0,0.0,-80); // przesuniecie obiektu przed kamere
	//glRotatef(15, 1, 0, 0);
	//glRotatef(45, 0, -1, 0);

	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	glMatrixMode(GL_MODELVIEW);


    glBegin(GL_QUADS);

	glTexCoord2f(3, 3);
	glVertex3f(10.0f, 10.0f, 10.0f);
	glTexCoord2f(0, 3);
	glVertex3f(-10.0f, 10.0f, 10.0f);
	glTexCoord2f(0, 0);
	glVertex3f(-10.0f, -10.0f, 10.0f);
	glTexCoord2f(3, 0);
	glVertex3f(10.0f, -10.0f, 10.0f);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, tex_blue);

/*
	// Tu (na koncu) rysowanie obiektow BLEND

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

#undef _RYSOWANIE
#endif
