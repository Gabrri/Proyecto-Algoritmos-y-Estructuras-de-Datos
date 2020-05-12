#include<iostream>
using namespace std;

class Apriori
{
    int item[100][100],C2[100],L2[100][100];
    int i,j,k,row,col;
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

void Apriori::getFrequentItemSet()
{
  /** int min_sup=3;
    for(i=1;i<col;i++)
    {
        L1[i]=0;
        if(C2[i]>=min_sup)
        {
            L1[i]=C2[i];
        }
    }
    
     for(i=1;i<col;i++)
    {
      cout << L1[i] << "\n";
     }
    */
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
   // a.getFrequentItemSet();
    return 0;
}