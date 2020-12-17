#pragma once


#include "cPoint.h"
#include "cQuad.h"

using namespace std;

class cNo
{
    private:
        //Ponteiros para os quatro filhos
        cNo* topRight;
        cNo* topLeft;
        cNo* botRight;
        cNo* botLeft;

        cQuad q; //Um nó armazena o intervalo que está contido dentro dele. Evitando assim acesso desnecessário.


    public:
        cNo();
        cNo(cNo* topRight,
            cNo* topLeft,
            cNo* botRight, 
            cNo* botLeft);
        cNo(cPoint p1, cPoint p2); 
        ~cNo();

        void setTopRight(cNo* no);
        void setTopLeft(cNo* no);
        void setBotRight(cNo* no);
        void setBotLeft(cNo* no);
    
        cNo* getTopRight();
        cNo* getTopLeft();
        cNo* getBotRight();
        cNo* getBotLeft();

        void setQuad(cPoint p1, cPoint p2);
        void setQuad(cQuad q0);
        cQuad getQuad();
};