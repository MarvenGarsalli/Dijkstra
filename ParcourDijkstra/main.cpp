#include <iostream>
#include <string>
#include <vector>
#define ns 30
using namespace std;
typedef struct nomPereDist
{string nom,pere;
   int d;
}nomPereDist;
int existe(nomPereDist t[],string s,int n)
{for(int k=0;k<n;k++)
    if (t[k].nom == s)
        return k;
return -1;
}
int initial(nomPereDist t[],string s,int n)
{ int p=-1;
    for(int i=0;i<n;i++)
     { if(t[i].nom == s)
        {t[i].d= 0;
         p=i;
        }
      else
        t[i].d=999999;
      }
return p;
}
/*int position(pair<string,string> t[],string s,int n)
{for(int k=0;k<n;k++)
    if (t[k].nom == s)
        return k;
  return -1;
}*/
int main()
{int nadj,n,p;
string nom,ch;
    cout<<"donner le nombre des sommets: ";cin>>n;
    pair<string,int> m[n][n]; ///mat de (nom sommet,poid=-1) et (adj,poid)
    /*cout<<m[n-1][n-2].first<<endl;*/
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        m[i][j].first="nil";
   nomPereDist t[n];  ///tab du nom sommet et de pere
    for (int j=0;j<n;j++)
    {cout<<"donner le nom du sommet num "<<j+1<<":  ";cin>>nom;
    m[0][j].first=nom;m[0][j].second=-1;t[j].nom=nom;t[j].pere="nil";t[j].d=9999999;
    cout<<"donner le nombre d'adjacents pour "<<nom<<":  ";cin>>nadj;
        for(int i=1;i<=nadj;i++)
        {cout<<"donner le nom du sommet adjacent de "<<m[0][j].first<<" num "<<i<<" : ";cin>>nom;
         m[i][j].first=nom;
         cout<<"donner le poid entre "<<m[0][j].first<<" et "<<m[i][j].first<<" : ";
         cin>>m[i][j].second;
        }
    }
    /*for(int i=0;i<n;i++)
        cout<<t[i].nom<<"-->";*/
     p=-1;   /// Saisir du sommet source
    while(p == -1)
   {cout <<"Donner le nom du source: ";cin>>nom;ch=nom;
    p=initial(t,ch,n);
   }
       /*** Le parcour ***/
for (int cpt=0;cpt<n-1;cpt++)
 {for(int k=0;k<n;k++)
    {int i=1,p=existe(t,m[0][k].first,n);
  while(i<n&&m[i][k].first != "nil")
  {int p2=existe(t,m[i][k].first,n);
  if(t[p2].d > t[p].d+m[i][k].second)
   {t[p2].d= t[p].d+m[i][k].second;
    t[p2].pere=m[0][k].first;}
  i++; }
  }
 }

   do
   {cout <<"Donner la distination ";cin>>nom;
       p=existe(t,nom,n);
   }while(p == -1);
 /*** Affichage ***/
 int s(0),cpt(0);
  s=t[p].d;
 nomPereDist  tab[n];
while(nom != "nil")
{tab[cpt].nom=nom;
   cpt++;
   nom=t[p].pere;
    p=existe(t,nom,n);
}
cpt--;
cout<<" La plus cours chemin est:"<<endl;
while(cpt != 0)
{cout<<tab[cpt].nom<<"-->";
cpt--;}
cout<<tab[0].nom<<endl;
cout<<"le temps ou la distance necessaire est "<<s<<endl;

    return 0;
}
