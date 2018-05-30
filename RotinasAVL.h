#include <iostream>

class ArvoreAvl
{
   private:
    
    struct noAvl
    {
        int info;
        noAvl *esq;
        noAvl *dir;
        char fb; 
    };

    noAvl *L;    
    int *quantidadeElementos;
    int *altura;
    void Rotacionar(noAvl **);
    void RotacaoEsquerda(noAvl **);
    void RotacaoDireita(noAvl **);
    void RotacaoDuplaEsquerda(noAvl **);
    void RotacaoDuplaDireita(noAvl **);
    void ins(noAvl **,int);
    
    public:
     void Inserir(int);
     bool Remover(int);
     void VisualizarRegras();
     void EmOrdem(int);
     void PosOrdem(int);
     void PreOrdem(int);
     
    ArvoreAvl();
};

ArvoreAvl :: ArvoreAvl()
{
    L = NULL;
    quantidadeElementos = new int;
    altura = new int;
}

void ArvoreAvl :: Inserir(int x)
{
    ins(&L,x);   
}

bool ArvoreAvl :: Remover(int x)
{
    return false;
}

void ArvoreAvl :: VisualizarRegras()
{

}

void ArvoreAvl::ins(noAvl **T, int x)
{

    if((*T) == NULL)
    {
        (*T) = new noAvl;
        (*T)->dir = NULL;
        (*T)->esq = NULL;
        (*T)->fb = 0;
        (*T)->info = x;
        *altura = 1; 
    }
    else if(x < (*T)->info)
    {
      ins(&((*T)->esq),x);
      if(*altura)
      {
          switch((*T)->fb)
          {
            case  1: (*T)->fb =  0; *altura = 0; break;
            case  0: (*T)->fb = -1;  break;
            case -1: Rotacionar(&(*T));*altura = 0; break;
          }
      }


    }
    else
    {
      ins(&((*T)->dir),x);
             
      if(*altura)
      {
          switch((*T)->fb)
          {
            case -1: (*T)->fb = 0; *altura = 0; break;
            case  0: (*T)->fb = 1;break;
            case  1: Rotacionar(&(*T)); *altura=0; break;
          }
      }


    }

}

void ArvoreAvl :: Rotacionar(noAvl **T)
{
    if((*T)->fb == 1 )
    {
        if((*T)->dir->fb < 0)
        {
            RotacaoDuplaEsquerda(&(*T));
        }
        else
        {
            RotacaoEsquerda(&(*T));
        }
    }
    else
    {
        if((*T)->esq->fb > 0)
        {
            RotacaoDuplaDireita(&(*T));
        }
        else
        {
            RotacaoDireita(&(*T));
        }
    }
}    

void ArvoreAvl::RotacaoEsquerda(noAvl **T)
{
    noAvl *Q = (*T)->dir;
    (*T)->dir = Q->esq;
    Q->esq = *T;
    T = &(Q);

    // noAvl *aux = (*T);
    // T = &((*T)->dir);
    // aux->dir = (*T)->esq;
    // (*T)->esq = aux;     
}

void ArvoreAvl::RotacaoDireita(noAvl **T)
{
    noAvl *Q = (*T)->esq;
    (*T)->esq = Q->dir;
    Q->dir = *T;
    T = &(Q); 
}

void ArvoreAvl::RotacaoDuplaEsquerda(noAvl **T)
{
    RotacaoDireita(&((*T)->dir));
    RotacaoEsquerda(&((*T)));
}

void ArvoreAvl::RotacaoDuplaDireita(noAvl **T)
{
    RotacaoEsquerda(&((*T)->esq));
    RotacaoDireita(&((*T)));
}