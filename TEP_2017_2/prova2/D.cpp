#include <bits/stdc++.h>

using namespace std;

#define forn(i,n) for(int i=0; i<(int)n; ++i)

bool seguinte(int s_tv, int e_tv, int s_p, int e_p,int fim){
	//mesma temporada ep seguinte
	if(s_tv==s_p and e_p==e_tv-1)return true;

	//troca de temporada 
	if(s_p==s_tv-1 and e_tv==1 and e_p==fim)return true;

	return false;
}


int main(){
	int s_tv, e_tv, s_p, e_p;
	scanf("%d %d", &s_tv, &e_tv);
	scanf(" s%02de%02d", &s_p, &e_p);
	
	int dias, eps, horas,minutos;
	scanf("%d %d", &dias, &eps);
	scanf("%d:%d", &horas, &minutos);

	int s_m, e_m;
	int cont=0,maior=0;
	int salv_ep=e_p, salv_sp=s_p;
		// os time foi icaro que fez 
	int time=-1, dtime=-1, a,b, dtime2=-1,time2=-1;
	forn(i,dias){
		forn(k,eps){
			scanf(" s%03de%02d", &s_m, &e_m);
			if(seguinte(s_m, e_m, s_p, e_p, e_tv)){
				cont++;
				if(seguinte(s_m, e_m, salv_sp, salv_ep, e_tv)){
					dtime=i;
					time=k;
				}
				s_p=s_m;
				e_p=e_m;
			}else{
				if(cont>maior){
					dtime2=dtime;
					time2=time;
				}
				maior=max(maior,cont);
				cont=0;
				s_p=salv_sp;
				e_p=salv_ep;
			}
			if(cont>maior){
				dtime2=dtime;
				time2=time;
			}
			maior=max(maior,cont);
			//printf("[--%d--]\n", cont);
		}
	}
	printf("%d episodio(s)\n", maior);
	if(time!=-1){
		int horas_final=horas+time2;

		if(horas_final>=24 or horas_final>eps+horas){
			dtime2+=horas_final%24;
			horas_final%=24;
		}
		printf("Dia: %d\nHora: %02d:%02d\n",dtime2+1, horas_final, minutos);
	
	}

 return 0;
}

