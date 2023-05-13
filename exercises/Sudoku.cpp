#include<bits/stdc++.h>

using namespace std;

int c,r,v;
int sudoku[9][9];
int markRow[10][10];
int markCol[10][10];
int markSquare[10][10][10];

bool check(int r, int c, int v){
	if(markRow[r][v] == false && markCol[c][v] == false && markSquare[r/3][c/3][v] == false) {
		return true;
	}
		
	return false;
}

void print_sudoku(){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout << sudoku[i][j] << " ";
		}
		cout << endl;
	}
	cout << "----------------------------------" << endl;
}

void Try(int r, int c){
	for(int v=1; v<=9; v++){
		if(check(r,c,v)){
			sudoku[r][c] = v;
			markRow[r][v] = true;
			markCol[c][v] = true;
			markSquare[r/3][c/3][v] = true;
			
			if(r==8 && c==8){
				print_sudoku();
			}else{
				if(c<8){
					Try(r,c+1);
				}else{
					Try(r+1,0);
				}
			}
			
			
			markRow[r][v] = false;
			markCol[c][v] = false;
			markSquare[r/3][c/3][v] = false;
		}
	}
}

int main(){
	for(int v=1;v<=9;v++){
		for(int r=0;r<=8;r++){
			markRow[r][v] = false;
		}
		for(int c=0;c<=8;c++){
			markCol[c][v] = false;
		}
		for(int i=0;i<=2;i++){
			for(int j=0;j<=2;j++){
				markSquare[i][j][v] == false;
			}
		}
	}
	
	Try(0,0);
	
	return 0;
}
