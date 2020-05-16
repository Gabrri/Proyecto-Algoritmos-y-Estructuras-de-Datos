#include<iostream>
#include <vector>
#include<set>
#include<string>
using namespace std;

class Apriori
{
    vector<int> vectorAnhos;
    int anho;
    vector<vector<vector<string>>> C;
    vector<vector<string>> FreqItemset;
public:
    void anhos();
    void getFrequentItemSet();
   
};
/*Esto se pone en la clase peliculas, y va metiendo los años a un vector
void Apriori::anhos(){
    if(anho == getAnho){
        vectorAnhos.push_back(anho);
    }
}*/
int subset(vector<string> A, vector<string> B)
{
  int c=0;
  for(unsigned int i=0; i<A.size(); i++)
  {
    for(unsigned int j=0; j<B.size(); j++)
    {
      if(A[i]==B[j])
        c++;
    }
  }
  int b = A.size();
  if(c ==b){
    return 1;
  }else{
    return 0;
  }
}
void Apriori::getFrequentItemSet()
{
 for(unsigned int i = 0; i<C.size()-1; i++){
     for(unsigned int j = 0; j<C[i].size();j++){
         int c = 0;
         for(unsigned int k = 0; k<C[i+1].size();k++){
             if(subset(C[i][j], C[i+1][k])){
                 c++;
             }
         }
         if(c==0){
             FreqItemset.push_back(C[i][j]);
         }
     }
 }
}
int main()
{
    Apriori a;
    a.getFrequentItemSet();
    return 0;
}