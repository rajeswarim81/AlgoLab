#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<limits.h>

typedef struct
{
  int r,g,b;
}color;

typedef struct
{
  int x,y;
  color *data;
}pixel;

int global[2][2048];
int temp[2][2048];
int g=0;
void readppm(char *filename)
{
  FILE *fp=fopen(filename,"rb");
  char p;
  int n,x,y,rgb;
  p=getc(fp);
  fscanf(fp,"%d %d %d %d",&n,&x,&y,&rgb);
  if(p=='P'||n==6)
  printf("\nCorrect input format--> P6");
  printf("\nSize of the image is %d * %d",x,y);
  printf("\nRGB max value is %d\n",rgb);
  color img[x][y];
  int i,j;
  for(i=0;i<x;i++)
  {
    for(j=0;j<y;j++)
    {
      fscanf(fp,"%d %d %d",&img[i][j].r,&img[i][j].g,&img[i][j].b);
    }
   }
  //calculating disruptions for each pixel
  int d[x][y];
  
  for(i=0;i<x;i++)
  {
    for(j=0;j<y;j++)
    {
      d[i][j]=disrupt(img,x,y,i,j);
    }
  }
  
  int d_index=0;
  int d_min=INT_MAX;
  int d_sum; int l,m;

  for(i=0;i<y;i++)
  { g=0;
   d_sum=path(d,x,y,0,i);
   if(d_sum<d_min)
   {
    d_min=d_sum;
    d_index=i;
    
   for(l=0;l<2;l++)
   {
   for(m=0;m<y;m++)
   {
    global[l][m]=temp[l][m];
   }
   }
   }
  }
  
  color new[x][y-1];
  int k;
  for(l=0;l<x;l++)
   {k=0;
   for(m=0;m<y;m++)
   {
    if(m==d_index)
     continue;
    else if(m==global[1][m-1])
     continue;
    new[l][k++].r=img[l][m].r;
    new[l][k++].g=img[l][m].g;
    new[l][k++].b=img[l][m].b;
   }
   }

  FILE *fpo=fopen("newimage.ppm","wb");
  putc('P',fpo);
  fprintf(fpo, "%d %d %d %d",6,x,y-1,255);
  
  fclose(fpo);
  fclose(fp);

 
  
}

int path(int **d,int x,int y,int i,int j)
{ //int temp[2][y];
 if(i==x-1)
 { 
  return d[i][j];
 }
 
 //int d_min=INT_MAX;
 int i1,j1; int sum=d[i][j];
 //return sum+=d[i][j];
 if(d[i+1][j-1]>d[i+1][j])
 {   j1=j;}
 else if(d[i+1][j]>d[i+1][j+1])
 {  j1=j+1;}
 else {j1=j-1;}
temp[0][g]=i+1;
temp[1][g]=j1;
g++;
return sum+=path(d,x,y,i+1,j1);




 }

int disrupt(color **img,int x,int y,int r,int c)
{
  int i,j;
  int d;
  if(r==0||c==0||r==x-1||c==y-1)
  {
   if(r==0&&c==0)
   {
    for(i=r;i<=r+1;i++)
     {
       for(j=c;j<=c+1;j++)
       { 
          d=abs(img[r][c].r-img[i][j].r)+ abs(img[r][c].g-img[i][j].g)+ abs(img[r][c].b-img[i][j].b);
       }
     }
   }
  else if(r==0&&c==y-1)
  {
    for(i=r+1;i>=r;i--)
     {
       for(j=c-1;j<=c;j++)
       { 
          d=abs(img[r][c].r-img[i][j].r)+ abs(img[r][c].g-img[i][j].g)+ abs(img[r][c].b-img[i][j].b);
       }
     }
  }



else if(r==x-1&&c==0)
{
    for(i=r-1;i>=r;i++)
     {
       for(j=c+1;j>=c;j--)
       { 
          d=abs(img[r][c].r-img[i][j].r)+ abs(img[r][c].g-img[i][j].g)+ abs(img[r][c].b-img[i][j].b);
       }
     }
  }
else if(r==x-1&&c==y-1)
{
    for(i=r-1;i<=r;i++)
     {
       for(j=c-1;j<=c;j++)
       { 
          d=abs(img[r][c].r-img[i][j].r)+ abs(img[r][c].g-img[i][j].g)+ abs(img[r][c].b-img[i][j].b);
       }
     }
  }
else
{
 if(r==0)
 {
   for(i=r;i<=r+1;i++)
     {
       for(j=c-1;j<=c+1;j++)
       { 
          d=abs(img[r][c].r-img[i][j].r)+ abs(img[r][c].g-img[i][j].g)+ abs(img[r][c].b-img[i][j].b);
       }
     }
 }


if(r==x-1)
{ 
  for(i=r-1;i<=r;i++)
     {
       for(j=c-1;j<=c+1;j++)
       { 
          d=abs(img[r][c].r-img[i][j].r)+ abs(img[r][c].g-img[i][j].g)+ abs(img[r][c].b-img[i][j].b);
       }
     }
}

if(c==0)
{
   for(i=r-1;i<=r+1;i++)
     {
       for(j=c+1;j>=r;j--)
       { 
          d=abs(img[r][c].r-img[i][j].r)+ abs(img[r][c].g-img[i][j].g)+ abs(img[r][c].b-img[i][j].b);
       }
     }
}

if(c==y-1)
{
 for(i=r-1;i<=r+1;i++)
     {
       for(j=c-1;j<=c;j++)
       { 
          d=abs(img[r][c].r-img[i][j].r)+ abs(img[r][c].g-img[i][j].g)+ abs(img[r][c].b-img[i][j].b);
       }
     }
}


}


return d;
}
//all boundary cases have been handled

 for(i=r-1;i<=r+1;i++)
     {
       for(j=c-1;j<=c+1;j++)
       { 
          d=abs(img[r][c].r-img[i][j].r)+ abs(img[r][c].g-img[i][j].g)+ abs(img[r][c].b-img[i][j].b);
       }
     }

return d;
}

int main(int argc, char *argv[])
{
readppm(argv[1]);
}

