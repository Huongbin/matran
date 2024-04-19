#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
void xuat(float a[][max],int dong,int cot){
	for (int i=1;i<=dong;i++){
		for (int j=1;j<=cot;j++){
			printf("%.2f \t",a[i][j]);
			
		}printf("\n");
	}	
}
int docfile(float a[][max],int &n,char ten[]){
	FILE *f=fopen(ten,"r");
	if (f!=NULL){
	    fscanf(f,"%d",&n);
	    for (int i=1;i<=n;i++)
		    for (int j=1;j<=n;j++)
		    	if (!feof(f)) fscanf(f,"%f",&a[i][j]);
		    	else {
			    	printf("\nDu lieu khong hop le");return(0);
			    
			    }
    }
    else{
    	printf("\nfile khong ton tai");
    	return(0);
	}
	
	fclose(f);
	printf("\nMa tran can tinh la\n"); xuat(a,n,n);
	return(1);	
	}

void luu(float c[][max],int n){
	FILE *fo=fopen("DATA.OUT.txt","w");
	if (fo==NULL){
	printf("\nKhong mo duoc file ");
	return;
	} 
	fprintf(fo,"ma tran la\n");
    fprintf(fo,"%d\n",n);
    for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			fprintf(fo,"%.2f \t",c[i][j]);
		}fprintf(fo,"\n");
	}
	fclose(fo);	
}

void hoanvi(float a[][max],int m,int h,int k){
	if ((k!=h)&&((1<=k)&&(k<=m))&&((1<=h)&&(h<=m))){
		for (int i=1;i<=m;i++){
			a[h][i]=a[k][i]+a[h][i];
			a[k][i]=a[h][i]-a[k][i];
			a[h][i]=a[h][i]-a[k][i];
		}
	}
}
void themdong(float a[][max], int n)
{
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
			a[i][n+1]+=a[i][j];
	}	
}
int matranbacthang(float a[][max],int n){
	int i,j,l;
	for (i=1;i<=n;i++){
		if (a[i][i]==0){
			for ( j=i+1;j<=n;j++){
				if (a[j][i]!=0) break;
			}
			if ( j>n) return 0;
			else {
				hoanvi(a,n,i,j);
			}
		}
		for ( j=i+1;j<=n+1;j++){
			float q=-a[j][i]/a[i][i];
			for ( l=i;l<=n+1;l++) a[j][l]=a[j][l]+a[i][l]*q;
		}		
	}
	if (a[n][n]==0)
	{
		if (a[n][n+1]==0) return 1;
		else return 0;
	}
	else return 2;	
}
void timnghiem(float a[][max], float x[max], int n)
{
	float s;
	for (int i=n;i>0;i--)
	{
		s=0;
		for (int j=i+1;j<=n;j++)
			s+=a[i][j]*x[j];
		x[i]=(a[i][n+1]-s)/a[i][i];
		}
	}

int main(){
	int n,cv,d,kt=0;
	char ten[50];
	float a[max][max],x[max],con[max][max];
	do{ system("COLOR F0");
		printf("\n--------------MENU--------------\n");
		printf("\n1.Nhap ten file luu ma tran");
		printf("\n2.Cong lai cac phan tu tren mot hang va them ket qua do vao cot cuoi cung");
		printf("\n3.Ma tran bac thang");
		printf("\n4.Tim nghiem");
		printf("\n0.Ket thuc");
		printf("\nnhap so thu tu cong viec can thuc hien ");
		scanf("%d",&cv);
		switch(cv){
		    case 1: printf("\nNhap ten file luu ma tran ");fflush(stdin);gets(ten);
	                strcat(ten,".txt");
	                kt=docfile(a,n,ten);
	                break;
		    case 2: if (kt==1)
		    		{
		    			themdong(a,n);
		    			xuat(a,n,n+1);
						getchar();
						break;
					}
		    case 3:	if (kt==1)
		    		{
		    			d=matranbacthang(a,n);
		            	xuat(a,n,n+1);
						getchar();					
					}
					else 
					{
						printf("khong co du lieu");
						getchar();
					};
					break;
		    case 4: if (kt==1)
		    		{
		    			if (d==0) printf ("he vo so nghiem"); 
						if (d==1) printf ("he vo nghiem");
						else {
		    			timnghiem(a,x,n);
		    			for (int i=1;i<=n;i++)
		    			printf("x%d=%f\n",i,x[i]);getchar();
					}}
					else 
					{
						printf("khong co du lieu");
					}getchar();
					break;
    	    case 0: break;
    	    default: printf("\nnhap sai so thu tu, moi ban nhap lai");
    	             scanf("%d",&cv);
    	             break;     
		}
		getchar();
	}while (cv!=0);

}
