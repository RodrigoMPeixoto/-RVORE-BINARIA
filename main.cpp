#include <iostream>
#include <string>

#include "cPoint.h"
#include "cQuad.h"
#include "cNo.h"
#include "quadTree.h"

using namespace std;

void fazFrase(string frase)
{
  string a = frase;
  cout << "||*****************" << a << "*****************||" << endl;
}

int main() {
  //1º Cria a janela/canvas
  /*
  win.setDomain(cQuad(cPoint(-3.0f, -3.0f), cPoint(3.0f, 3.0f), BLUE));

	win.init(argc, argv);

	win.setKeyboardFunc(myKeyboard);
	win.setDisplayFunc(draw);

	win.mainLoop();
  */

  //2º Opções do Menu

  fazFrase("Menuzin");
  //Cria uma arvore vazia
  quadTree q = quadTree();
  int value;
  while(true) {
    cout << "Escolha um: " <<endl;
    cout << "1 (Circulo)" << "\n" << "2 (Astroide)" << endl;
    cin >> value;
    if((value == 1) || (value == 2))
      break;
    cout << "Valor inválido, por favor digite 1 ou 2." << endl << endl;
  }
  cout << value <<endl;

  //3º Busca pela imagem
  //q.buscaImagem(win.getDomain(), value);
  
  //4º Imprime a arvore
  //Imprimir Arvore// Precisa de função pra isso??

  //Passa pontos da reta
  while(true) {
    cout << "Escolha uma raio" << endl;
    cout << "1. " << "P(a) = (-3,-3)" << " a " << "P(b) = (3,3)" << endl;
    cout << "2. "<< "P(a) = (3,-3)" << " a " << "P(b) = (-3,3)" << endl;
    cin >> value;
    if((value == 1) || (value == 2))
      break;
    cout << "Valor inválido, por favor digite 1 ou 2." << endl << endl;
  }
  cout << value << endl;

  //5º Passa o Raio Pintando
  /*
  cPoint a = cPoint();
  cPoint b = cPoint();
  if(value == 1)
  {
    a.setCoords(cPoint(-3,-3));
    b.setCoords(cPoint(3,3));
    buscaRaio(q->getRoot(), a, b);
  }else if (value == 2)
  {
    a.setCoords(cPoint(3,-3));
    b.setCoords(cPoint(-3,3));
    buscaRaio(q->getRoot(), a, b);
  }
  */
  
  cout << "Me da 10 professor" << endl;
}