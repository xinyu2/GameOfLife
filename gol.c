#include <stdio.h>
#include <stdlib.h>

#define N 8

int curr[N][N];
int prev[N][N];


void initGrid(void);
void prntGrid(char f);
void putMonster(void);
void c2p(void);
void go(void);
int  liveOrDie(int xpos,int ypos);
int  getLiveNbrs(int xpos,int ypos);
int  isLive(int xpos,int ypos);

int main(int argc, char * argv[]){
  printf("game of life\n");
  initGrid();
  prntGrid('p');
  putMonster();
  prntGrid('c');
  c2p();
  prntGrid('p');
  go();
  prntGrid('c');
  return (0);
}

void initGrid(void){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      curr[i][j]=0;
      prev[i][j]=0;
    }
  }
}

void prntGrid(char f){
  if(f == 'p'){
    printf("previous grid is:\n");
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
	printf("%d\t",prev[i][j]);
      }
      printf("\n");
    }
  }
  if(f == 'c'){
    printf("current grid is:\n");
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
	printf("%d\t",curr[i][j]);
      }
      printf("\n");
    }
  }
}

void putMonster(void){
  int xpos,ypos;
  printf("input x,y (input -1 x will end input):\n");
  while(xpos>-1){
    scanf ("%d%d",&xpos,&ypos);
    if(xpos>-1){
      printf("x(%d) y(%d)\n",xpos,ypos);
      curr[xpos][ypos]=1;
    }
  }
}

void c2p(void){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      prev[i][j]=curr[i][j];
    }
  }
}

void go(void){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
	curr[i][j]=liveOrDie(i,j);
    }
  }
}

int liveOrDie(int xpos, int ypos){
  if(isLive(xpos,ypos)){
    if ((getLiveNbrs(xpos,ypos)<2)||(getLiveNbrs(xpos,ypos)>3)){
	curr[xpos][ypos]=0;
    }
    else{
      //stay live
    }
  }
  else{
    if(getLiveNbrs(xpos,ypos)==3){
	curr[xpos][ypos]=1;
    }
    else{
      //stay dead
    }
  }
  printf("(%d,%d) %d\n",xpos,ypos,curr[xpos][ypos]);
  return (curr[xpos][ypos]);
}

int getLiveNbrs(int xpos, int ypos){
  int lx,hx,ly,hy;//lowerx,higherx,lowery,highery
  int cnt=0;
  if(xpos==0){
    lx=xpos;
    hx=xpos+1;
  }else if(xpos==N-1){
    lx=xpos-1;
    hx=xpos;
  }else{
    lx=xpos-1;
    hx=xpos+1;
  }
  if(ypos==0){
    ly=ypos;
    hy=ypos+1;
  }else if(ypos==N-1){
    ly=ypos-1;
    hy=ypos;
  }else{
    ly=ypos-1;
    hy=ypos+1;
  }

  for(int i=lx;i<hx+1;i++){
    for(int j=ly;j<hy+1;j++){
      if((i==xpos)&&(j==ypos)){
	  //not count self
      }else{
	if(prev[i][j]==1){
	  cnt++;
	}
      }
    }
  }
  printf("(%d,%d):%d\t",xpos,ypos,cnt);
  return (cnt);
}
int isLive(int xpos,int ypos){
  return (curr[xpos][ypos]);
}
