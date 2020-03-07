#include <iostream>
using namespace std;

void move(int matrix[][3]){
	int temp;
	for(int i=0;i<3;i++)
		for(int j=0;j<i;j++){
			temp=matrix[i][j];
			matrix[i][j]=matrix[j][i];
			matrix[j][i]=temp;
		}
}

int main(){
	int i,j,mat[3][3];

	cout<<"输入3×3矩阵"<<endl;
	for(i=0;i<3;i++){
		cout<<"第"<<i+1<<"行：";
		for(j=0;j<3;j++) cin>>mat[i][j];
	}

	cout<<"\n输入的3×3矩阵为："<<endl;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			cout<<mat[i][j]<<"  ";
		cout<<endl;
	}

	move(mat);
	cout<<"转置后的矩阵为："<<endl;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			cout<<*(*(mat+i)+j)<<"  ";//指针形式
		cout<<endl;
	}
    return 0;
}
