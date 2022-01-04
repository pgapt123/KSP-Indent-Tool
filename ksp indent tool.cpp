#include<bits/stdc++.h>
using namespace std;

char buf[100005], bg[100005];

int main(int argc, char **argv){
	if(argc<2){
		puts("Drag *.ksp file onto me!");
		system("pause");
		return 0;
	}
	
	freopen(argv[1], "r", stdin);
	argv[1][strlen(argv[1])-4] = '\0';
	freopen(strcat(argv[1], "_indented.ksp"), "w", stdout);
	
	int cnt=0;
	
	buf[0]=0;
	
	while(scanf("%[^\n]",buf)!=EOF){
		getchar(); 
		if(buf[0]==0) continue; 
		sscanf(buf,"%s",bg);
		if(strncmp(bg,"end",3)==0 || strncmp(bg,"else",4)==0){
			cnt--;
		}
		for(int i=0; i<cnt; i++) printf("    ");
		printf("%s\n",buf);
		if(strncmp(bg,"end",3)==0){
			printf("\n");
			if(cnt==0) printf("\n");
		}
		
		if(strncmp(bg,"if",2)==0 || strncmp(bg,"while",5)==0 || strncmp(bg,"else",4)==0
		|| strncmp(bg,"on",2)==0 || strncmp(bg,"select",6)==0 || strncmp(bg,"function",7)==0){
			cnt++;
		}
		
		buf[0]=0;
		
	}
}

