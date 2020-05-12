#include<iostream>
#include <vector>
#include<set>
#include<string>
using namespace std;

class Apriori
{
    int item[100][100],C2[100],L2[100][100];
    int i,j,k,row,col;
    vector<vector<vector<string>>> C;
    vector<vector<string>> FreqItemset;
public:
    void getdata();
    void getCandidateSet();
    void getFrequentItemSet();
    void prune();
    void countItems();
    void display();
};

void Apriori::getdata()
{
    cout<<"Enter the rows and cols";
    cin>> row >> col;
    for(i=1;i<=row;i++){
        for(j=1;j<=col;j++){
            cin >> item[i][j];
        }
    }
}

void Apriori::getCandidateSet()
{
     int count=0;

    for(i=1;i<=row;i++){
        for(j=1;j<=col;j++){
            count=0;
            if(item[i][j]==1)
            {
                count++;
                C2[j]+=count;
            }
        }
    }
    
    
    for(i=1;i<=col;i++)
    {
        cout << C2[i] << "\n";
    }
}
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
  if(c ==A.size()){
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


void Apriori::display()
{
    for(i=1;i<=row;i++){
	  for(j=1;j<=col;j++){
		cout<<"\t"<<item[i][j];
		}
	      cout<<"\n";
	  }
}

int main()
{
    Apriori a;
    a.getdata();
    a.display();
    a.getCandidateSet();
    a.getFrequentItemSet();
    return 0;
}