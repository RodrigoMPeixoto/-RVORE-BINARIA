#pragma once

#include "cNo.h"
#include <cmath>
#include <vector>

class quadTree
{
    private:
      cNo* root;
      int numElem;
      void buscaImagemRec(cNo* pai, cQuad domain);

    public:
      quadTree();
      ~quadTree();

      bool vazia();
      bool insereElem(cNo* pai); //Insere o elemento passando seu intervalo/quadrante e coordenadas

      //bool removeElem();

      static bool temCirculo(cQuad domain); //Verifica se a expressão resulta em  valores maiores, menores ou igua a 0 e retorna se tem curva ou não

      static bool temAstroid(cQuad domain);

      static bool temReta(cQuad domain, float m, float c); // Função especifica de Reta para uso do raio
      
      void buscaImagemRec(cNo* pai, cQuad domain, int n);

      void buscaImagem(cQuad domain, int n); //Passamos o canvas como parametro

      void verificarDistancia(vector<int> &vetor, cNo* pai, cPoint a);

      float distancia(cPoint a, cPoint b); //distancia do ponto da reta ao centro do quadrante

      cPoint centro(cNo* a); //Pegar o centro de cada quadrante

      bool verificaRaio(cNo* pai, float m, float c, int n);
      
      bool buscaInsereRaio(cNo* pai, cPoint a, cPoint b, int n); //Está busca irá acessar a arvore já pronta, pintando todos os setores/quadrantes em seu caminho, até encontrar um nó da curva

      void setRoot(cNo* no);

      cNo* getRoot();
};