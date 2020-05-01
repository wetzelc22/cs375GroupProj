#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <deque>
#include <stdio.h>
#include <utility>
#include <limits.h>
using namespace std;
void floyd_warshall(int **start,int **opt_prev, int num){
	for (int k = 0; k < num; k++){
		
		for (int i = 0; i < num; i++){
			
			for (int j = 0; j < num; j++){
				if (start[i][k] == INT_MAX || start[k][j] == INT_MAX){
					continue;
				}
				if (start[i][j] == INT_MAX){
					start[i][j] = start[i][k] + start[k][j];
					opt_prev[i][j] = k + 1;
					continue;
				}
				if (start[i][j] > start[i][k] + start[k][j]){
					start[i][j] = start[i][k] + start[k][j];
					cout << "Replaced something" << endl;
					opt_prev[i][j] = k + 1;
					
				}
			}
		}
	}
}
int main(int argc, char *argv[]){
	ifstream infile(argv[1]);
	string line = " ";
	getline(infile,line);
	stringstream linestream(line);
	string value;
	int check = 0;
	while (getline(linestream, value, ',')){
			if (value == "start"){
			}
			else{
				check = stoi(value);
			}
	}
	int **start_array = (int**)malloc(sizeof(int*)*(check));
		for (int i = 0; i < check; i++){
			start_array[i] = (int *)malloc(check * sizeof(int*));
		}
	int iter = 0;
	int **opt_prev = (int**)malloc(sizeof(int*)*(check));
		for (int i = 0; i < check; i++){
			opt_prev[i] = (int *)malloc(check * sizeof(int*));
		}
	while(getline(infile,line)){
		int iter_2 = 0;
		stringstream linestream(line);
		string value;
		bool new_start = false;
		while (getline(linestream, value, ',')){
			if (value == "start"){
				iter = 0;
				floyd_warshall(start_array,opt_prev,check);
				new_start = true;	
				continue;	
			}
			if (new_start == true){
				check = stoi(value);
				for (int i = 0; i < check; i++){
					for (int j = 0; j < check; j++){
						opt_prev[i] = 0;
						start_array[i] = 0;
					}
				}
			}
			if (value == "?"){
				start_array[iter][iter_2] = INT_MAX;
			}
			else{
				start_array[iter][iter_2] = stoi(value);
			}
			iter_2++;
		}
		iter++;
	}
#if 0
	for (int i = 0; i < check; i++){
		for (int j = 0; j < check; j++){
			cout << start_array[i][j] << ",";
		}
		cout << endl;
	}
#endif
	floyd_warshall(start_array, opt_prev, check);
	for (int i = 0; i < check; i++){
		for (int j = 0; j < check; j++){
			cout << start_array[i][j] << ",";
		}
		cout << endl;
	}
}

