// golotip_N.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <cmath>
#include <iostream>
#include <time.h>
using namespace std;

int random(int f,int e){
	f-=e;
	return rand()%f+e;
};
int dfini(int n,int a[][3] ,int h){
	int qwe=0;
	int M1=0;
	int M2=0;
	int tmp=0;
	M1=a[0][h];
	for(int i=0;i<n;i++){
			tmp=a[i][h];
		if(M1<tmp)
			M1=tmp;
	}
	M2=a[0][h];
	for(int i=0;i<n;i++){
			tmp=a[i][h];
		if(M2>tmp)
			M2=tmp;
	}
	qwe=M1-M2;
	return qwe;
};

double okr(double tt){
	tt*=1000;
	return (int(tt+0.5))/1000.0;
};
double mini( double qwe[],int t){
	double tq=qwe[t];
	for(int i=1;i<10;i++)
		if(qwe[i]!=0)
			if(tq>qwe[i])
				tq=qwe[i];
	return tq;
};

int main(){
	setlocale (LC_ALL,"rus");
	srand(time(0));
	int mo[10][3]={{63,100,1},{62,98,1},{64,92,1},{70,102,1},{66,91,1},{55,80,2},{59,85,2},{60,90,2},{58,88,2},{57,84,2}};
	int me[5][3]={{58,86,0},{56,88,0},{63,103,0},{57,90,0},{65,91,0}};
	double q1[10][10];
	double q2[10][10];
	double q3[10][10];
	double tq3[10][10];
	double tmp=0;
	//int tmp2=0;
	//cout<<df1<<"	"<<df2<<"	"<<df3<<"	"<<df4<<endl;
	
	int tmp1 = 130;
	int tmp2 = 40;
	int tmp3 = 70;
	int tmp4 = 30;
	int o=1;
	for(int i=0;i<10;i++ ){
		mo[i][0]=random(tmp1,tmp2);
		mo[i][1]=random(tmp3,tmp4);
		mo[i][2]=o;
		if(i==4){
		o=2;
		tmp1=150;
		tmp2=50;
		tmp3=50;
		tmp4=15;
		}
	}
	for(int i=0;i<5;i++ ){
		me[i][0]=random(150,40);
		me[i][1]=random(70,15);
		me[i][2]=0;
	}
	//*/
	int df1=dfini(10,mo,0);
	int df2=dfini(10,mo,1);
	int df3=dfini(5,me,0);
	int df4=dfini(5,me,1);
	
	for (int i=0;i<10;i++)
		for(int j=0;j<10;j++){
			q1[i][j]=1-(abs(mo[i][0]-mo[j][0])/(double)df1);
			q2[i][j]=1-(abs(mo[i][1]-mo[j][1])/(double)df2);
			q3[i][j]=okr((q1[i][j]+q2[i][j])/2);
			tmp+=q3[i][j];
			tq3[i][j]=q3[i][j];
		}

	double porog=(tmp-10)/(9*10);
	if(porog<0.85)porog=0.85;
		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				if(q3[i][j]<=porog) q3[i][j]=0;

cout<<"Просеянная общяя матрица мер сходства"<<endl;
	
	for (int i=0;i<10;i++){
		for(int j=0;j<10;j++)
			cout<<q3[i][j]<<"	";
		cout<<endl;
	}
	//*/

	int **grupp ;
		grupp = new int * [10];
		for(int i=0;i<10;i++)
			grupp[i]=new int[10];

		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				grupp[i][j]=0;



		int tmpmass[10];
		for (int i=0;i<10;i++)
			tmpmass[i]=i;
		int y=0;
		int ww=-1;
		
			
		for(int j=0;j<10;j++){
			y=0;
			if(tmpmass[j]==j){
				ww++;
				for(int k=0;k<10;k++){
						if(q3[j][k]!=0) {
							grupp[ww][y]=k+1;
							y++;
							for(int l=0;l<10;l++){
								if(tmpmass[l]==k){
									tmpmass[l]=0;
								}
							}
						}
				}
		
			}
		}
		
		int chet=0;
		for(int i=0;i<10;i++)
			if(grupp[i][0]!=0) chet++;

cout<<"Разбиение по группам"<<endl<<endl;
		for(int i=0;i<chet;i++){
			for(int j=0;j<10;j++){
				if(grupp[i][j]!=0)
					cout << grupp[i][j] << "	";
			}
			cout<<endl;
		}
		cout<<endl;
		for(int i=0;i<chet;i++)
			cout<<i+1<<"	"<<mini(q3[grupp[i][0]-1],grupp[i][0]-1)<<endl;

		int * ttt =new int[chet];
		for(int i=0;i<chet;i++)
			ttt[i]=0;

		for(int i=0;i<chet;i++){
			if(grupp[i][0]!=0)
				for(int j=0;j<10;j++)
					if(grupp[i][j]!=0){
						ttt[i]++;
					}
		}
		double ***uu;
		uu=new double **[chet];
		for(int i=0;i<chet;i++)
			uu[i]=new double * [ttt[i]];

		for(int i=0;i<chet;i++)
			for(int j=0;j<ttt[i];j++)
				uu[i][j]=new double [ttt[i]];

		struct mat{
		int num;
		double golo2;
		double golo1;
		double golo;
		void show(){cout<<this->num<<"   "<<this->golo;}
		};
		
		mat *t =new mat[chet];
		for(int j=0;j<chet;j++){
			for(int i=0;i<chet;i++){
				t[j].num=j+1;
				t[j].golo1=1-(abs(mo[grupp[j][0]-1][0]-me[i][0])/(double)df3);
				t[j].golo2=1-(abs(mo[grupp[j][0]-1][1]-me[i][1])/(double)df4);
				t[j].golo=okr((t[j].golo2+t[j].golo1)/2);
			}
		}
		for(int j=0;j<5;j++)
			if(t[j].golo<mini(q3[grupp[j][0]-1],grupp[j][0]-1))
				grupp[j][0]-1<5?me[j][2]=1:me[j][2]=2;
		//	else me[j][2]=2;
		
			cout<<"Материал экзамена с разделением на группы:"<<endl<<endl;
		for(int j=0;j<5;j++){
			cout<<me[j][0]<<"	"<<me[j][1]<<"	"<<me[j][2]<<endl;
		}

	delete [] t;

	for (int i=0;i<10;i++)
		delete [] grupp[i];
	delete [] grupp;

	
	
	system("pause");

	return 0;
}

