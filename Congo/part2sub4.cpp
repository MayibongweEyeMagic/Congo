#include<iostream>
#include<vector>
#include<cctype>
#include<cstring>
#include<sstream>
#include<algorithm>
#include<set>
#include<iterator>
using namespace std;

void SplitString(string s, vector<string>& v) {

	string temp = "";
	for (int i = 0; i < s.length(); ++i) {

		if (s[i] == ' ') {
			v.push_back(temp);
			temp = "";
		}
		else {
			temp.push_back(s[i]);
		}

	}
	v.push_back(temp);

}

void SplitString2(string s, vector<string>& v) {

	string temp = "";
	for (int i = 0; i < s.length(); ++i) {

		if (s[i] == '/') {
			v.push_back(temp);
			temp = "";
		}
		else {
			temp.push_back(s[i]);
		}

	}
	v.push_back(temp);

}

void PrintVector(vector<string> v) {
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << endl;
	cout << "\n";
}

int main() {
	vector<string> inputs;

	int N;
	cin >> N;
	cin.ignore(); //NB!
	for (int i = 0; i < N; ++i) {
		string fen;
		getline(cin, fen);
		inputs.push_back(fen);
		}

	
	
	for(string x:inputs){
	vector<string> v;
	string s =x;
	//string s = "1m1El2/P1P2P1/1S4C/4S2/1E3S1/1P3c1/2GL3 b 79";
	//cout << "Input String: " << endl << s << endl;
	SplitString(s, v);

	vector<string> v2;
	string first = v[0];
	SplitString2(first, v2);
	//cout << "String After Split" << endl;
	//PrintVector(v);
	
	vector<vector<string>> matrix ={{"a7","b7","c7","d7","e7","f7","g7"},
									{"a6","b6","c6","d6","e6","f6","g6"},
									{"a5","b5","c5","d5","e5","f5","g5"},
									{"a4","b4","c4","d4","e4","f4","g4"},
									{"a3","b3","c3","d3","e3","f3","g3"},
									{"a2","b2","c2","d2","e2","f2","g2"},
									{"a1","b1","c1","d1","e1","f1","g1"}
									};
	
	
	vector<vector<char>> matrix2;
	for(int i=0;i<7;i++){
		string str = v2[i];
		vector<char> keep;
			//if(hold[j]
			//string str=v2[i];
 			int check;

 			for (int k= 0; k< str.size(); k++)  {

    // check if str[i] is a digit
    		check = isdigit(str[k]);

	
    		if (check){
    	
    			int x=str[k]-48;
    			for(int j=0;j<x;j++){
    				keep.push_back('#');
      					}
      				}
     			else{
					keep.push_back(str[k]);
						}
  					}
  					matrix2.push_back(keep);
  					
  					
		
				
	
			}
	
 /*for(int i=0;i<7;i++){
 	for(int j=0;j<7;j++){
 		cout<<matrix2[i][j]<<" ";
 	}
 	cout<<endl;
 }
 cout<<endl;*/
 
 vector<string> moves;
 vector<char> black={'g','m','e','l','c','z','p'};
 vector<char> white={'G','M','E','L','C','Z','P'};
 if(v[1]=="w"){
 	for(int i=0;i<7;i++){
 			for(int j=0;j<7;j++){
 				if(matrix2[i][j]=='P'){
 					if(i<3){
 							if(i==0){
 										string thanks = matrix[i][j]+matrix[i+1][j];
 										moves.push_back(thanks);
 										thanks=" ";
 							
 									}
									 else{
										 if(matrix2[i+1][j] =='#' ){
											 	 string thanks = matrix[i][j]+matrix[i+1][j];
 										moves.push_back(thanks);
 										thanks=" ";
										 }
										 
										 if(matrix2[i+1][j] =='#' && matrix2[i+2][j] =='#'  ){
											 	 	 string thanks = matrix[i][j]+matrix[i+2][j];
 										moves.push_back(thanks);
 										thanks=" ";
										 }
										 
									 }
							 if(i-1>=0){
								 	if(matrix2[i-1][j] == 'G' || matrix2[i-1][j] =='M' || matrix2[i-1][j] =='E' || matrix2[i-1][j] =='L' || matrix2[i-1][j] =='C' || matrix2[i-1][j] =='Z' || matrix2[i-1][j] =='P'){
									 int k;
								 	}
								 	else{
									 	string thanks = matrix[i][j]+matrix[i-1][j];
 										moves.push_back(thanks);
 										thanks=" ";
									 }
							 	}
							 if(i-1>=0 && j-1>=0){
								 	if(matrix2[i-1][j-1] == 'G' || matrix2[i-1][j-1] =='M' || matrix2[i-1][j-1] =='E' || matrix2[i-1][j-1] =='L' || matrix2[i-1][j-1] =='C' || matrix2[i-1][j-1] =='Z' || matrix2[i-1][j-1] =='P'){
									 	int k;
								 	}
								 	else{
									 string thanks = matrix[i][j]+matrix[i-1][j-1];
 										moves.push_back(thanks);
 										thanks=" ";
								 	}
								 
							 	}

							if(i-1>=0 && j+1<=6){
								if(matrix2[i-1][j+1] == 'G' || matrix2[i-1][j+1] =='M' || matrix2[i-1][j+1] =='E' || matrix2[i-1][j+1] =='L' || matrix2[i-1][j+1] =='C' || matrix2[i-1][j+1] =='Z' || matrix2[i-1][j+1] =='P'){
									int k;
								}
								else{
									string thanks = matrix[i][j]+matrix[i-1][j+1];
 										moves.push_back(thanks);
 										thanks=" ";
								}
							}
							
 					}


				 
				 else{
					 if(i-1>=0){
								 	if(matrix2[i-1][j] == 'G' || matrix2[i-1][j] =='M' || matrix2[i-1][j] =='E' || matrix2[i-1][j] =='L' || matrix2[i-1][j] =='C' || matrix2[i-1][j] =='Z' || matrix2[i-1][j] =='P'){
									 int k;
								 	}
								 	else{
									 	string thanks = matrix[i][j]+matrix[i-1][j];
 										moves.push_back(thanks);
 										thanks=" ";
									 }
							 	}
							 if(i-1>=0 && j-1>=0){
								 	if(matrix2[i-1][j-1] == 'G' || matrix2[i-1][j-1] =='M' || matrix2[i-1][j-1] =='E' || matrix2[i-1][j-1] =='L' || matrix2[i-1][j-1] =='C' || matrix2[i-1][j-1] =='Z' || matrix2[i-1][j-1] =='P'){
									 	int k;
								 	}
								 	else{
									 string thanks = matrix[i][j]+matrix[i-1][j-1];
 										moves.push_back(thanks);
 										thanks=" ";
								 	}
								 
							 	}

							if(i-1>=0 && j+1<=6){
								if(matrix2[i-1][j+1] == 'G' || matrix2[i-1][j+1] =='M' || matrix2[i-1][j+1] =='E' || matrix2[i-1][j+1] =='L' || matrix2[i-1][j+1] =='C' || matrix2[i-1][j+1] =='Z' || matrix2[i-1][j+1] =='P'){
									int k;
								}
								else{
									string thanks = matrix[i][j]+matrix[i-1][j+1];
 										moves.push_back(thanks);
 										thanks=" ";
								}
							}

				 }
				 }

			 }
	 }
 		
 }
 else{
 
 	for(int i=0;i<7;i++){
 			for(int j=0;j<7;j++){
 				
 						if(matrix2[i][j]=='p'){
 					if(i>3){
 							if(i==6){
 										string thanks = matrix[i][j]+matrix[i-1][j];
 										moves.push_back(thanks);
 										thanks=" ";
 							
 									}
									 else{
										 if(matrix2[i-1][j] =='#' ){
											 	 string thanks = matrix[i][j]+matrix[i-1][j];
 										moves.push_back(thanks);
 										thanks=" ";
										 }
										 
										 if(matrix2[i-1][j] =='#' && matrix2[i-2][j] =='#'  ){
											 	 	 string thanks = matrix[i][j]+matrix[i-2][j];
 										moves.push_back(thanks);
 										thanks=" ";
										 }
										 
									 }
							 if(i+1<=6){
								 	if(matrix2[i+1][j] == 'g' || matrix2[i+1][j] =='m' || matrix2[i+1][j] =='e' || matrix2[i+1][j] =='l' || matrix2[i+1][j] =='c' || matrix2[i+1][j] =='z' || matrix2[i+1][j] =='p'){
									 int k;
								 	}
								 	else{
									 	string thanks = matrix[i][j]+matrix[i+1][j];
 										moves.push_back(thanks);
 										thanks=" ";
									 }
							 	}
							 if(i+1<=6 && j-1>=0){
								 	if(matrix2[i+1][j-1] == 'g' || matrix2[i+1][j-1] =='m' || matrix2[i+1][j-1] =='e' || matrix2[i+1][j-1] =='l' || matrix2[i+1][j-1] =='c' || matrix2[i+1][j-1] =='z' || matrix2[i+1][j-1] =='p'){
									 	int k;
								 	}
								 	else{
									 string thanks = matrix[i][j]+matrix[i+1][j-1];
 										moves.push_back(thanks);
 										thanks=" ";
								 	}
								 
							 	}

							if(i+1<=6 && j+1<=6){
								if(matrix2[i+1][j+1] == 'g' || matrix2[i+1][j+1] =='m' || matrix2[i+1][j+1] =='e' || matrix2[i+1][j+1] =='l' || matrix2[i+1][j+1] =='c' || matrix2[i+1][j+1] =='z' || matrix2[i+1][j+1] =='p'){
									int k;
								}
								else{
									string thanks = matrix[i][j]+matrix[i+1][j+1];
 										moves.push_back(thanks);
 										thanks=" ";
								}
							}
							
 					}


				 
				 else{
						  if(i+1<=6){
								 	if(matrix2[i+1][j] == 'g' || matrix2[i+1][j] =='m' || matrix2[i+1][j] =='e' || matrix2[i+1][j] =='l' || matrix2[i+1][j] =='c' || matrix2[i+1][j] =='z' || matrix2[i+1][j] =='p'){
									 int k;
								 	}
								 	else{
									 	string thanks = matrix[i][j]+matrix[i+1][j];
 										moves.push_back(thanks);
 										thanks=" ";
									 }
							 	}
							 if(i+1<=6 && j-1>=0){
								 	if(matrix2[i+1][j-1] == 'g' || matrix2[i+1][j-1] =='m' || matrix2[i+1][j-1] =='e' || matrix2[i+1][j-1] =='l' || matrix2[i+1][j-1] =='c' || matrix2[i+1][j-1] =='z' || matrix2[i+1][j-1] =='p'){
									 	int k;
								 	}
								 	else{
									 string thanks = matrix[i][j]+matrix[i+1][j-1];
 										moves.push_back(thanks);
 										thanks=" ";
								 	}
								 
							 	}

							if(i+1<=6 && j+1<=6){
								if(matrix2[i+1][j+1] == 'g' || matrix2[i+1][j+1] =='m' || matrix2[i+1][j+1] =='e' || matrix2[i+1][j+1] =='l' || matrix2[i+1][j+1] =='c' || matrix2[i+1][j+1] =='z' || matrix2[i+1][j+1] =='p'){
									int k;
								}
								else{
									string thanks = matrix[i][j]+matrix[i+1][j+1];
 										moves.push_back(thanks);
 										thanks=" ";
								}
							}

				 }
				 }	
 			}
 							
	}
 		
 }
 sort(moves.begin(),moves.end());
 for(string test:moves){
 		cout<<test<<" ";
 	}
 	cout<<endl;
 }
  cout<<endl;
  
  
return 0;
}
