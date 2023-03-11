#include <bits/stdc++.h>
#include <ctime>
using namespace std;
char check(char arr[][12],int x,int y){
	if (arr[x][y]=='*') return '*';
	int count=0;
	if (arr[x+1][y]=='*') count++;
	if (arr[x+1][y+1]=='*')count++;
	if (arr[x-1][y]=='*')count++;
	if (arr[x-1][y+1]=='*')count++;
	if (arr[x+1][y-1]=='*')count++;
	if (arr[x-1][y-1]=='*')count++;
	if (arr[x][y+1]=='*')count++;
	if (arr[x][y-1]=='*')count++;
	return (char)(count+'0');
}
void update(char arr[][12],int x,int y){
	int tmp1,tmp2,tmp3,tmp4,tmp5,tmp6,tmp7,tmp8,tmp9;
	tmp1 = check(arr,x,y);
	tmp2= check(arr,x+1,y);
	tmp3=check(arr,x+1,y+1);
	tmp4=check(arr,x-1,y);
	tmp5=check(arr,x-1,y+1);
	tmp6=check(arr,x+1,y-1);
	tmp7=check(arr,x-1,y-1);
	tmp8=check(arr,x,y+1);
	tmp9=check(arr,x,y-1);
	arr[x][y] =tmp1;arr[x+1][y] =tmp2;arr[x+1][y+1]=tmp3;arr[x-1][y]=tmp4;arr[x-1][y+1]=tmp5;
	arr[x+1][y-1]=tmp6;arr[x-1][y-1]=tmp7;arr[x][y+1]=tmp8;arr[x][y-1]=tmp9;
}
int main(){
	srand(time(0));
	int m,n,k;
	//cin >> m>>n >>k;
	m=10;n=10;k=10;
	char arr[m+2][12];
	for (int i=1; i<=m;i++){
		for (int j=1;j<=n;j++){
			arr[i][j]='.';
		}
	}
	for (int i=0; i<k;i++){
		arr[rand()%10+1][rand()%10+1]='*';
	}
//	for (int i=1; i<=m;i++){
//		for (int j=1;j<=n;j++){
//			cout << arr[i][j] <<" ";
//		}
//		cout << endl;
//	}
//	cout << endl;
	for (int i=1; i<=m;i++){
		for (int j=1;j<=n;j++){
			cout << "." <<" ";
		}
		cout << endl;
	}

	bool is_playing=true;
	int x,y;
	while (is_playing){
		cin >> x >> y;
		if (arr[x][y]!='.'&&arr[x][y]!='*') continue;
		if (arr[x][y]=='*') {
			cout << endl << "YOU'RE DEAD."<<endl;
			break;
		}
		else {
			update(arr,x,y);
			for (int i=1; i<=m;i++){
				for (int j=1;j<=n;j++){
					if (arr[i][j]!='*')
					cout << arr[i][j] <<" ";
					else cout << '.' <<" ";
				}
				cout << endl;
			}
		}
	}
	for (int i=1; i<=m;i++){
		for (int j=1;j<=n;j++){
			cout << arr[i][j] <<" ";
		}
		cout << endl;
	}
	return 0;
}
