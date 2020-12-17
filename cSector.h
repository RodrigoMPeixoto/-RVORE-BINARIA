#pragma once

#include "cPoint.h"
#include "cQuad.h"

typedef enum 	{	INTERN,
					EXTERN,
					CROSS,
					NONE
				} eSectorClass;

class cSector {

	cQuad			sector;
	eSectorClass	sectorClass;

public:
	cSector();
	cSector(cQuad qd);
  cSector(cPoint p1, cPoint p2); //Novo

	void classifySector(float (*f)(cPoint p));
  
	cQuad	getSector();
  eSectorClass getSectorClass();
};