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
 			int check;

 			for (int k= 0; k< str.size(); k++)  {

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
 					if(matrix2[i][j]=='E'){
 							
 								if(i-2>=0){
									 
 									if(matrix2[i-2][j] == 'G' || matrix2[i-2][j] == 'M' || matrix2[i-2][j] == 'E' || matrix2[i-2][j] == 'L' || matrix2[i-2][j] == 'C' || matrix2[i-2][j] == 'Z' || matrix2[i-2][j] == 'P'){
 											int j;
 										}
										 else{
											 string thanks = matrix[i][j]+matrix[i-2][j];
 											moves.push_back(thanks);
 											thanks=" ";
										 
									 }
 										}
 								if(i-1>=0){
									 
 									 if(matrix2[i-1][j] == 'G' || matrix2[i-1][j] =='M' || matrix2[i-1][j] =='E' || matrix2[i-1][j] =='L' || matrix2[i-1][j] =='C' || matrix2[i-1][j] =='Z' || matrix2[i-1][j] =='P'){
										  	int j;
 										}
										 else{
											  string thanks = matrix[i][j]+matrix[i-1][j];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
									 
 										}
 									
 								 if(i+2<=6){
 									if(matrix2[i+2][j] == 'G' ||  matrix2[i+2][j] =='M' || matrix2[i+2][j] =='E' || matrix2[i+2][j] =='L' || matrix2[i+2][j] =='C' || matrix2[i+2][j] =='Z' || matrix2[i+2][j] =='P'){
 										int j;
 										}
										 else{
											 	string thanks = matrix[i][j]+matrix[i+2][j];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 										}
 								if(i+1<=6){
 									 if(matrix2[i+1][j] == 'G' || matrix2[i+1][j] =='M' || matrix2[i+1][j] =='E' || matrix2[i+1][j] =='L' || matrix2[i+1][j] =='C' || matrix2[i+1][j] =='Z' || matrix2[i+1][j] =='P'){
										  int j;
 										}
										 else{
											 string thanks = matrix[i][j]+matrix[i+1][j];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 									}
 								 if(j-2>=0){
 									if(matrix2[i][j-2] == 'G' || matrix2[i][j-2] =='M' || matrix2[i][j-2] =='E' || matrix2[i][j-2] =='L' || matrix2[i][j-2] =='C' || matrix2[i][j-2] =='Z' || matrix2[i][j-2] =='P'){
 											int j;
 										}
										 else{
											 string thanks = matrix[i][j]+matrix[i][j-2];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 										}
 								if(j-1>=0){
 									 if(matrix2[i][j-1] ==  'G' || matrix2[i][j-1] == 'M' || matrix2[i][j-1] == 'E' || matrix2[i][j-1] == 'L' || matrix2[i][j-1] == 'C' || matrix2[i][j-1] == 'Z' || matrix2[i][j-1] == 'P'){
 										int j;
 										}else{
											 string thanks = matrix[i][j]+matrix[i][j-1];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 									}
 								 if(j+1<=6){
 									if(matrix2[i][j+1] == 'G' || matrix2[i][j+1] =='M' || matrix2[i][j+1] =='E' || matrix2[i][j+1] =='L' || matrix2[i][j+1] =='C' || matrix2[i][j+1] =='Z' || matrix2[i][j+1] =='P'){
 										int j;
 										}
										 else{
											 string thanks = matrix[i][j]+matrix[i][j+1];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 										}
 								if(j+2<=6){
 									 if(matrix2[i][j+2] == 'G' || matrix2[i][j+2] =='M' || matrix2[i][j+2] =='E' || matrix2[i][j+2] =='L' || matrix2[i][j+2] =='C' || matrix2[i][j+2] =='Z' || matrix2[i][j+2] =='P'){
 										int j;
 										}
										 else{
											 string thanks = matrix[i][j]+matrix[i][j+2];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 									}
 								
 						}
 				}
 		}
 		
 }
 else{
 
 	for(int i=0;i<7;i++){
 			for(int j=0;j<7;j++){
 					if(matrix2[i][j]=='e'){
 							
 								if(i-2>=0){
									 
 									if(matrix2[i-2][j] == 'g' || matrix2[i-2][j] == 'm' || matrix2[i-2][j] == 'e' || matrix2[i-2][j] == 'l' || matrix2[i-2][j] == 'c' || matrix2[i-2][j] == 'z' || matrix2[i-2][j] == 'p'){
 											int j;
 										}
										 else{
											 string thanks = matrix[i][j]+matrix[i-2][j];
 											moves.push_back(thanks);
 											thanks=" ";
										 
									 }
 										}
 								if(i-1>=0){
									 
 									 if(matrix2[i-1][j] == 'g' || matrix2[i-1][j] =='m' || matrix2[i-1][j] =='e' || matrix2[i-1][j] =='l' || matrix2[i-1][j] =='c' || matrix2[i-1][j] =='z' || matrix2[i-1][j] =='p'){
										  	int j;
 										}
										 else{
											  string thanks = matrix[i][j]+matrix[i-1][j];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
									 
 										}
 									
 								 if(i+2<=6){
 									if(matrix2[i+2][j] == 'g' ||  matrix2[i+2][j] =='m' || matrix2[i+2][j] =='e' || matrix2[i+2][j] =='l' || matrix2[i+2][j] =='c' || matrix2[i+2][j] =='z' || matrix2[i+2][j] =='p'){
 										int j;
 										}
										 else{
											 	string thanks = matrix[i][j]+matrix[i+2][j];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 										}
 								if(i+1<=6){
 									 if(matrix2[i+1][j] == 'g' || matrix2[i+1][j] =='m' || matrix2[i+1][j] =='e' || matrix2[i+1][j] =='l' || matrix2[i+1][j] =='c' || matrix2[i+1][j] =='z' || matrix2[i+1][j] =='p'){
										  int j;
 										}
										 else{
											 string thanks = matrix[i][j]+matrix[i+1][j];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 									}
 								 if(j-2>=0){
 									if(matrix2[i][j-2] == 'g' || matrix2[i][j-2] =='m' || matrix2[i][j-2] =='e' || matrix2[i][j-2] =='l' || matrix2[i][j-2] =='c' || matrix2[i][j-2] =='z' || matrix2[i][j-2] =='p'){
 											int j;
 										}
										 else{
											 string thanks = matrix[i][j]+matrix[i][j-2];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 										}
 								if(j-1>=0){
 									 if(matrix2[i][j-1] ==  'g' || matrix2[i][j-1] == 'm' || matrix2[i][j-1] == 'e' || matrix2[i][j-1] == 'l' || matrix2[i][j-1] == 'c' || matrix2[i][j-1] == 'z' || matrix2[i][j-1] == 'p'){
 										int j;
 										}else{
											 string thanks = matrix[i][j]+matrix[i][j-1];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 									}
 								 if(j+1<=6){
 									if(matrix2[i][j+1] == 'g' || matrix2[i][j+1] =='m' || matrix2[i][j+1] =='e' || matrix2[i][j+1] =='l' || matrix2[i][j+1] =='c' || matrix2[i][j+1] =='z' || matrix2[i][j+1] =='p'){
 										int j;
 										}
										 else{
											 string thanks = matrix[i][j]+matrix[i][j+1];
 											moves.push_back(thanks);
 											thanks=" ";
										 }
 										}
 								if(j+2<=6){
 									 if(matrix2[i][j+2] == 'g' || matrix2[i][j+2] =='m' || matrix2[i][j+2] =='e' || matrix2[i][j+2] =='l' || matrix2[i][j+2] =='z' || matrix2[i][j+2] =='z' || matrix2[i][j+2] =='p'){
 										int j;
 										}
										 else{
											 string thanks = matrix[i][j]+matrix[i][j+2];
 											moves.push_back(thanks);
 											thanks=" ";
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
  /*vector<string> white_pawn;
  vector<string> black_pawn;
  vector<string> white_superpawn;
  vector<string> black_superpawn;
  vector<string> white_giraffe;
  vector<string> black_giraffe;
  vector<string> white_monkey;
  vector<string> black_monkey;
  vector<string> white_elephant;
  vector<string> black_elephant;
  vector<string> white_lion;
  vector<string> black_lion;
  vector<string> white_crocodile;
  vector<string> black_crocodile;
  vector<string> white_zebra;
  vector<string> black_zebra;
  
  for(int i=0;i<7;i++){
 	for(int j=0;j<7;j++){
 		if(matrix2[i][j] =='P'){
 			white_pawn.push_back(matrix[i][j]);
 		}	
 		if(matrix2[i][j] =='p'){
 			black_pawn.push_back(matrix[i][j]);
 		}
 		if(matrix2[i][j] =='S'){
 			white_superpawn.push_back(matrix[i][j]);
 		}
 		if(matrix2[i][j] =='s'){
 			black_superpawn.push_back(matrix[i][j]);
 		}
 		if(matrix2[i][j] =='G'){
 			white_giraffe.push_back(matrix[i][j]);
 		}
 		if(matrix2[i][j] =='g'){
 			black_giraffe.push_back(matrix[i][j]);
 		}
 		if(matrix2[i][j] =='M'){
 			white_monkey.push_back(matrix[i][j]);
 		}
 		if(matrix2[i][j] =='m'){
 			black_monkey.push_back(matrix[i][j]);
 		}
 		if(matrix2[i][j] =='E'){
 			white_elephant.push_back(matrix[i][j]);
 		}
 		if(matrix2[i][j] =='e'){
 			black_elephant.push_back(matrix[i][j]);
 		}
 		if(matrix2[i][j] =='L'){
 			white_lion.push_back(matrix[i][j]);
 		}
 		if(matrix2[i][j] =='l'){
 			black_lion.push_back(matrix[i][j]);
 		}
 		if(matrix2[i][j] =='C'){
 			white_crocodile.push_back(matrix[i][j]);
 		}
 		if(matrix2[i][j] =='c'){
 			black_crocodile.push_back(matrix[i][j]);
 		}
 		if(matrix2[i][j] =='Z'){
 			white_zebra.push_back(matrix[i][j]);
 		}
 		if(matrix2[i][j] =='z'){
 			black_zebra.push_back(matrix[i][j]);
 		}
 		
 	}
 }
 
  sort(white_pawn.begin(),white_pawn.end());
  sort(black_pawn.begin(),black_pawn.end());
  sort(white_superpawn.begin(),white_superpawn.end());
  sort(black_superpawn.begin(),black_superpawn.end());
  sort(white_giraffe.begin(),white_giraffe.end());
  sort(black_giraffe.begin(),black_giraffe.end());
  sort(white_monkey.begin(),white_monkey.end());
  sort(black_monkey.begin(),black_monkey.end());
  sort(white_elephant.begin(),white_elephant.end());
  sort(black_elephant.begin(),black_elephant.end());
  sort(white_lion.begin(),white_lion.end());
  sort(black_lion.begin(),black_lion.end());
  sort(white_crocodile.begin(),white_crocodile.end());
  sort(black_crocodile.begin(),black_crocodile.end());
  sort(white_zebra.begin(),white_zebra.end());
  sort(black_zebra.begin(),black_zebra.end());
  
		if(white_pawn.size() > 0){
			cout<<"white pawn: ";
 			for(string x:white_pawn){
 				cout<<x<<" ";
 			}
 			cout<<endl;
 		}
 		else{
 			cout<<"white pawn: "<<endl;
 			}
 			
 		if(black_pawn.size() > 0){
			cout<<"black pawn: ";
 			for(string x:black_pawn){
 				cout<<x<<" ";
 			}
 			cout<<endl;
 		}
 		else{
 			cout<<"black pawn: "<<endl;
 			}
 			
 		if(white_superpawn.size() > 0){
			cout<<"white superpawn: ";
 			for(string x:white_superpawn){
 				cout<<x<<" ";
 			}
 			cout<<endl;
 		}
 		else{
 			cout<<"white superpawn: "<<endl;
 			}
 			
 		if(black_superpawn.size() > 0){
			cout<<"black superpawn: ";
 			for(string x:black_superpawn){
 				cout<<x<<" ";
 			}
 			cout<<endl;
 		}
 		else{
 			cout<<"black superpawn: "<<endl;
 			}
 		
 		if(white_giraffe.size() > 0){
			cout<<"white giraffe: ";
 			for(string x:white_giraffe){
 				cout<<x<<" ";
 			}
 			cout<<endl;
 		}
 		else{
 			cout<<"white giraffe: "<<endl;
 			}
 			
 		if(black_giraffe.size() > 0){
			cout<<"black giraffe: ";
 			for(string x:black_giraffe){
 				cout<<x<<" ";
 			}
 			cout<<endl;
 		}
 		else{
 			cout<<"black giraffe: "<<endl;
 			}
 			
 		if(white_monkey.size() > 0){
			cout<<"white monkey: ";
 			for(string x:white_monkey){
 				cout<<x<<" ";
 			}
 			cout<<endl;
 		}
 		else{
 			cout<<"white monkey: "<<endl;
 			}
 			
 		if(black_monkey.size() > 0){
			cout<<"black monkey: ";
 			for(string x:black_monkey){
 				cout<<x<<" ";
 			}
 			cout<<endl;
 		}
 		else{
 			cout<<"black monkey: "<<endl;
 			}
 			
 		if(white_elephant.size() > 0){
			cout<<"white elephant: ";
 			for(string x:white_elephant){
 				cout<<x<<" ";
 			}
 			cout<<endl;
 		}
 		else{
 			cout<<"white elephant: "<<endl;
 			}
 			
 		if(black_elephant.size() > 0){
			cout<<"black elephant: ";
 			for(string x:black_elephant){
 				cout<<x<<" ";
 			}
 			cout<<endl;
 		}
 		else{
 			cout<<"black elephant: "<<endl;
 			}
 			
 		if(white_lion.size() > 0){
			cout<<"white lion: ";
 			for(string x:white_lion){
 				cout<<x<<" ";
 			}
 			cout<<endl;
 		}
 		else{
 			cout<<"white lion: "<<endl;
 			}
 			
 		if(black_lion.size() > 0){
			cout<<"black lion: ";
 			for(string x:black_lion){
 				cout<<x<<" ";
 			}
 			cout<<endl;
 		}
 		else{
 			cout<<"black lion: "<<endl;
 			}
 			
 		if(white_crocodile.size() > 0){
			cout<<"white crocodile: ";
 			for(string x:white_crocodile){
 				cout<<x<<" ";
 			}
 			cout<<endl;
 		}
 		else{
 			cout<<"white crocodile: "<<endl;
 			}
 			
 		if(black_crocodile.size() > 0){
			cout<<"black crocodile: ";
 			for(string x:black_crocodile){
 				cout<<x<<" ";
 			}
 			cout<<endl;
 		}
 		else{
 			cout<<"black crocodile: "<<endl;
 			}
 			
 		if(white_zebra.size() > 0){
			cout<<"white zebra: ";
 			for(string x:white_zebra){
 				cout<<x<<" ";
 			}
 			cout<<endl;
 		}
 		else{
 			cout<<"white zebra: "<<endl;
 			}
 			
 		if(black_zebra.size() > 0){
			cout<<"black zebra: ";
 			for(string x:black_zebra){
 				cout<<x<<" ";
 			}
 			cout<<endl;
 		}
 		else{
 			cout<<"black zebra: "<<endl;
 			}
 			
 		cout<<"side to play: ";
 		if(v[1]=="b"){
 			cout<<"black"<<endl;
 			}
 			else{
 				cout<<"white"<<endl;
 				}
 				cout<<endl;*/
 				
 		

	
	
	
	
	return 0;
}
