#include <iostream>

#include "quadTree.h"

using namespace std;


/// ***********************************************************************
/// ** 
/// ***********************************************************************
quadTree::quadTree()
{
    root = NULL;
    numElem ++;
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************
quadTree::~quadTree()
{

}

/// ***********************************************************************
/// ** 
/// ***********************************************************************
bool quadTree::vazia()
{
  if(root == NULL)
      return true;
  return false;
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************
bool quadTree::insereElem(cNo* pai)//Insere o elemento passando seu intervalo/quadrante e coordenadas
{

  //Verificar se a arvore está vazia??

  //Divir quadrantes (codar)
  cNo* novoNo1 = new cNo();
  cNo* novoNo2 = new cNo();
  cNo* novoNo3 = new cNo();
  cNo* novoNo4 = new cNo(); //Instancia um nó com intervalo e coordenadas, mas sem filhos
  
  //Inserindo 1º Quadrante          
  cPoint p1 = cPoint( (pai->getQuad().getMaxPoint().getX()+pai->getQuad().getMinPoint().getX()/2),
                      (pai->getQuad().getMaxPoint().getY()+pai->getQuad().getMinPoint().getY())/2);

  novoNo1->setQuad(pai->getQuad().getMinPoint(), p1); // O quadrante dele é formado pelo ponto central da raiz (minimo) e ponto maximo do Quad da raiz (PMax)

  //Inserindo 2º Quadrante
  cPoint p2 = cPoint( (pai->getQuad().getMaxPoint().getX()+pai->getQuad().getMinPoint().getX())/2,
                      (pai->getQuad().getMinPoint().getY()));

  cPoint p3 = cPoint (pai->getQuad().getMaxPoint().getX(),
                       (pai->getQuad().getMaxPoint().getY()+pai->getQuad().getMinPoint().getY())/2);
                      
  novoNo2->setQuad(p2, p3);

  //Inserindo 3º Quadrante (codar)
  cPoint p4 = cPoint( pai->getQuad().getMinPoint().getX(),
                       (pai->getQuad().getMinPoint().getY()+pai->getQuad().getMaxPoint().getY())/2);

  cPoint p5 = cPoint( (pai->getQuad().getMaxPoint().getX()+pai->getQuad().getMaxPoint().getX())/2,
                      pai->getQuad().getMaxPoint().getY());
                      

  novoNo3->setQuad(p4, p5);

  //Inserindo 4º Quadrante (codar)

                      
  novoNo4->setQuad(p1, pai->getQuad().getMaxPoint());


  //Insere primeiro filho (1º quadrante)
  pai->setTopRight(novoNo1);

  //Insere primeiro filho (2º quadrante)
  pai->setTopLeft(novoNo2);

  //Insere primeiro filho (3º quadrante)
  pai->setBotLeft(novoNo3);

  //Insere primeiro filho (4º quadrante)
  pai->setBotRight(novoNo4);

  numElem += 4;
  return true;
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************
bool quadTree::temCirculo(cQuad domain) //Verifica se a expressão resulta em  valores maiores, menores ou iguais a 0 e retorna se tem curva ou não
{
  float f[4];
  cPoint P[4];

	P[0] = domain.getMinPoint();  //Vertice 1
	P[1] = domain.getMaxPoint(); //Vertice 2 
	P[2] = cPoint(domain.getMinPoint().getX(), domain.getMaxPoint().getY() );  //Vertice 3
	P[3] = cPoint(domain.getMaxPoint().getX(), domain.getMinPoint().getY() );  //Vertice 4

	for (int i = 0 ; i < 4 ; i++) 		
  {
  	float x,y;
    x = P[i].getX();
    y = P[i].getY();
    f[i] = ((x*x)+(y*y)-2.5); //Raio definido como 2,5
  }
	
  //Se estiver Externa ou Através significa que "não tem curva", portanto n iremos aprofundar no quadrante
	if ( (f[0] > 0) && (f[1] > 0) && (f[2] > 0) && (f[3] > 0) )
		return true;
	else
		if ( (f[0] < 0) && (f[1] < 0) && (f[2] < 0) && (f[3] < 0) )
			return true;
		else
      domain.setQuadColor(BLACK);
			return false;
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************
bool quadTree::temAstroid(cQuad domain) //Verifica se a expressão resulta em  valores maiores, menores ou iguais a 0 e retorna se tem curva ou não
{
  float f[4];
  cPoint P[4];

	P[0] = domain.getMinPoint(); 
	P[1] = domain.getMaxPoint(); 
	P[2] = cPoint( domain.getMinPoint().getX(), domain.getMaxPoint().getY() ); 
	P[3] = cPoint(domain.getMaxPoint().getX(), domain.getMinPoint().getY() ); 

	for (int i = 0 ; i < 4 ; i++) 		
  {
  	float x,y;
    x = P[i].getX();
    y = P[i].getY();
    f[i] =  (pow(x,(2/3))+pow(y,(2/3))-1.4); //Raio definido como 2,5
  }
	
  //Se estiver Externa ou Através significa que "não tem curva", portanto n iremos aprofundar no quadrante
	if ( (f[0] > 0) && (f[1] > 0) && (f[2] > 0) && (f[3] > 0) )
		return true;
	else
		if ( (f[0] < 0) && (f[1] < 0) && (f[2] < 0) && (f[3] < 0) )
			return true;
		else
      domain.setQuadColor(BLACK);
			return false;
  
  
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************
bool quadTree::temReta(cQuad domain, float m, float c) //Passa o sector a ser analisado e pontos m e c da equação da reta
{
  float f[4]; //Cria vetor de float (resultado das operações
  cPoint P[4]; // Cria vetor de pontos para 
  float m1,c1;

	P[0] = domain.getMinPoint(); 
	P[1] = domain.getMaxPoint(); 
	P[2] = cPoint( domain.getMinPoint().getX(), domain.getMaxPoint().getY() ); 
	P[3] = cPoint( domain.getMaxPoint().getX(), domain.getMinPoint().getY() ); 

	for (int i = 0 ; i < 4 ; i++) 		
  {
    float x,y,m,c;
    x = P[i].getX();
    y = P[i].getY();
    m1 = m;
    c1 = c;
    f[i] =  m1*x +c1 - y; //Raio definido como 1
  }  
	
	if ( (f[0] > 0) && (f[1] > 0) && (f[2] > 0) && (f[3] > 0) )
	  return true; //sectorClass = EXTERN;
	else
		if ( (f[0] < 0) && (f[1] < 0) && (f[2] < 0) && (f[3] < 0) )
			return true; //sectorClass = INTERN;
		else
      domain.setQuadColor(BLACK);
			return false; //sectorClass = CROSS;
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************
void quadTree::buscaImagemRec(cNo* pai, cQuad domain, int n)
{
  //drawQuad(pai->getQuad());
  if(vazia())
  {
    pai->setQuad(domain);
    insereElem(pai); // Cria os quatro quadrantes. É necessário passar um pai  
  }

  if(n == 1)
  {
    if(!temCirculo(domain)) // n é qual dar equações vai ser utilizada
    {
      return;
    }
  }
  else {
    if(!temAstroid(domain))
      return;
  }

  pai->setQuad(domain);

  insereElem(pai); // Cria os quatro quadrantes. É necessário passar um pai

  buscaImagemRec( pai->getTopRight() ,
                  pai->getTopRight()->getQuad(), n); //Busca primeiro no TopRight

  buscaImagemRec( pai->getTopLeft(),
                  pai->getTopLeft()->getQuad(), n); //Busca segundo no TopLeft

  buscaImagemRec( pai->getBotLeft(),
                  pai->getBotLeft()->getQuad(), n); //Busca segundo no TopLeft

  buscaImagemRec( pai->getBotRight(),
                  pai->getBotRight()->getQuad(), n); //Busca segundo no TopLeft
  return;
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************
void quadTree::buscaImagem(cQuad domain, int n) //Passamos o canvas como parametro
{
  
  return buscaImagemRec(root, domain, n);
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************
float quadTree::distancia(cPoint a, cPoint b) {
  return sqrt(pow((a.getX()-b.getX()), 2) + pow((a.getX()-b.getX()), 2) );
}

cPoint quadTree::centro(cNo* a) { //Retorna o centro do quadrante
  float retornoX = (a->getQuad().getMinPoint().getX() + a->getQuad().getMaxPoint().getX()) / 2;
  float retornoY = (a->getQuad().getMinPoint().getY()+ a->getQuad().getMaxPoint().getX()) / 2;
  cPoint retorno = cPoint(retornoX, retornoY);
  return retorno;
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************
void quadTree::verificarDistancia(vector<int> &vetor, cNo* pai, cPoint a)
{
  cPoint centroTopR = centro(pai->getTopRight());
  cPoint centroTopL = centro(pai->getTopLeft());
  cPoint centroBotL = centro(pai->getTopLeft());
  cPoint centroBotR = centro(pai->getBotRight());
 
  float distanciaTopR = distancia(a,centroTopR);
  float distanciaTopL = distancia(a,centroTopL);
  float distanciaBotL = distancia(a,centroBotR);
  float distanciaBotR = distancia(a,centroBotR);

  int numTopR = 1;
  int numTopL = 2;
  int numBotL = 3;
  int numBotR = 4;

  float temp[4] = {distanciaTopR, distanciaTopL, distanciaBotL, distanciaBotR};

  for (int i = 0; i < 4; i++) {
    for (int j = i+1; j < 4; j++) {
      if (temp[i] > temp[j]) {
        float aux = temp[i];
        temp[i] = temp[j];
        temp[j] = aux;
      }
    }
  }

  for (int i=0; i<4; i++) {
    if (temp[i] == distanciaTopR) 
      vetor[i] = 1;
    else if(temp[i] == distanciaTopL)
      vetor[i] = 2;
    else if(temp[i] == distanciaBotL)
      vetor[i] = 3;
    else
      vetor[i] = 4;

  }
}

bool quadTree::verificaRaio(cNo* pai, float m, float c, int n)
{
  //Expressão y = mx +c
  //Verificar se a curva(reta), está dentro quadrante (inside)
  
  if(!temReta(pai->getQuad(), m, c)) //2 equivale a reta
  {
    return false;
  }

  // Verifica se a reta passa pelo setor e pela curva ao mesmo tempo
  if (n == 1)
  {
    if( temReta(pai->getQuad(), m, c) && temCirculo(pai->getQuad())) //Ex: Reta e Circulo
    {
    //drawLine(a, ); ???
    return true; //Ativa a flag da barreira (Final da buscaRaio)
    }
  }else if(n == 2)
  {
    if(temReta(pai->getQuad(), m, c) && temAstroid(pai->getQuad())) //Ex: Reta e Circulo
    {
    //drawLine(a, ); ???
    return true; //Ativa a flag da barreira (Final da buscaRaio)
    }
  }
  
  //Existe reta no quadrante, mas não tem circulo, então pinta de azul
  pai->getQuad().setQuadColor(CIAN); // Colocar cor em todo o quadrante
  return false;
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************
bool quadTree::buscaInsereRaio(cNo* pai, cPoint a, cPoint b, int n) //Está busca irá acessar a arvore já pronta, pintando todos os setores/quadrantes em seu caminho, até encontrar um nó da curva
{
  bool flag = false;
  float x1,x2,y1,y2,m,c; // Valores para calculo da equação da reta "y = mx +c"
  x1 = a.getX();
  y1 = a.getY();
  x2 = b.getX();
  y2 = b.getY();
  m = (y2-y1)/(x2-x1);
  c = y1-m*x1;

//1º Passo: Chegar até o setor que possui centro mais proximo do ponto a
  if(pai->getTopRight() != NULL) //Tem filho?
  {
    vector<int> v(4);
    verificarDistancia(v, pai, a); //Retorna quatro setores por ordem de proximade do ponto a;

    int i;
    for(i=0; i<=3; i++)
    {
      if(flag == true)
        break;
      
      switch(v[i])
      {
        case 1:
          if(buscaInsereRaio(pai->getTopRight(),a, b, n))
            flag = true;
          break;

        case 2:
          if(buscaInsereRaio(pai->getTopLeft(),a, b, n))
            flag = true;
          break;

        case 3:
          if(buscaInsereRaio(pai->getBotLeft(),a, b, n))
            flag = true;
          break;

        case 4:
          if(buscaInsereRaio(pai->getBotRight(),a, b, n))
            flag = true;
          break;
      }
    }
  }

  //2º Passo: Retornar verificando se a reta passa pelo setor e pinta-lo;  
  if(flag == false)
  {
    if(verificaRaio(pai, m, c, n)) //Os valores C e M são necessário para equação da reta. retorna true se encontrar uma barreira
    //printar
    return true;
  }

  return false;
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************
void quadTree::setRoot(cNo* no)
{
  root = no;
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************
cNo* quadTree::getRoot()
{
  return root;
}