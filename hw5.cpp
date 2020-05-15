#include <fstream>
#include <iostream>
#include <map>
using namespace std;
int main(void){
	
	ifstream fin;
	fin.open("sample data.txt");
	ofstream fout;
	fout.open("TP_Sort_Result.txt");
	int v_num;
	while(fin>>v_num){
		
		map<int, int> a1;
		map<int, int> a2;
		int adj[v_num][v_num]={0};
		int ref[v_num]={0};

				
		for(int i=0;i<v_num;i++){
			int value;
			fin>>value;
			a1.insert(pair<int, int> (value,i));
			a2.insert(pair<int, int> (i,value));
		}
	
		int edge_num;
		fin>>edge_num;
		
		while(edge_num--){
			
			char c;
			int v1,v2;
			fin>>v1>>c>>v2;
			
			map<int,int>::iterator it;
			int v1_pos, v2_pos;
			it = a1.find(v1);
			v1_pos = (*it).second;
			it = a1.find(v2);
			v2_pos = (*it).second;

			if(c=='>')
				adj[v2_pos][v1_pos]+=1;
			else
				adj[v1_pos][v2_pos]+=1;
		}
	    
		for(int i=0; i< v_num; i++)
	        for (int j=0; j<v_num; j++)
	            if (adj[i][j])
	                ref[j] += adj[i][j];
	 
	    for(int i=0; i< v_num ; i++)
	    {
	        int no_edge = 0;
	        while (no_edge < v_num && ref[no_edge]!=0) 
				no_edge++;
	 
	        if (no_edge == v_num) 
				break;
	        
			ref[no_edge]=-1000;
			
	 		map<int,int>::iterator it;
	 		it = a2.find(no_edge);
	 		int answer;
	 		answer = (*it).second;
	        fout<<answer<<" ";
    
	        for(int i=0; i<v_num; i++)
	            if (adj[no_edge][i])
	                ref[i]--;
	    }
		
		fout << endl;
	}

}	
		

