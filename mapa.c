#include <map>

using namespace std;

class MapaDeTipos{

	vector< map<string, int> > listMapas;
	int nivel;
	int currsize;
	MapaDeTipos(){
		nivel = 1;
		currsize = 16; // Tama;o inicial
		listMapas.resize(currsize);
	}

	~MapaDeTipos(){
		for (int i = 0; i < listMapas.size(); i++){
			listMapas[i].
		}
	}

	void nuevoNivel(){
		nivel++;
		if (nivel == currsize){
			currsize = 2*currsize;
			listMapas.resize(currsize);
		}
	}

	bool bajarNivel(){
		if (nivel == 1){
			return false;
		}
		else{
			nivel--;
			return true;
		}
	}

	bool estaDeclarado(string s){
		if (listMapas[nivel - 1].find(s) != listMapas[i].end()){
			return true; 
		}
		return false;
	}

	bool estaDeclaradoEnNivel(string s){
		if (listMapas[nivel - 1].find(s) != listMapas[nivel - 1].end()){
			return true;
		}
		else{
			return false
		}
	}

	int obtenerTipo(string s){
		for (int i = nivel - 1; i >= 0;i--){
			if (listMapas[i].find(s) != listMapas[i].end()){
				return listMapas[i][s];
			}
		}
		return -1;
	}


	void agregar(string s,int i){
		listMapas[nivel][s] = i;
	}

};








/*
soy el mapa.cpp

					  @@                                    
					 @@@@                                   
					@@`#@                                   
				   @#```#@        @                         
				  @#`````@@    @@@@@                        
				 @#``````#@@ @@@#``#@@                      
				@#````````#@@@#``````#@                     
			   @#``````````@#`````````#@                    
			  @@``````````#````````````@@                   
			 @@#````````##``````````##``@                   
			 @#````````#````````````@@@##@  @@@             
			@@````````#````````````##,,,#@@@@@@@            
			@#``````##`````````````##,,,,,@#```#@           
		   @@``````##``````````````##,,,,,,##```@           
		   @#`````##`````````````####,,,,,,,,#``#@          
		   @`````#`````````````##``##,,,##@@@@#``@          
		   @````#``````#@#```##````###@@##```````#@         
		  @@```##``````@,##`#```````#`````````````@         
		   @```#``````##,,@#``````````````````````@         
		   @#`#```````@,,,,@``````````````````````#@        
			@@```````##,,,,##``````````````````````@        
		   @@````````@,,,,,,@``````````````````````@        
		   @#```````##,,,,,,@``````````````````````#@       
		  @@```````#@,,,,,#@````````````````````````@       
		  @#``````#`#,,,,##`````````````````````````@@      
		   @#````#`##,,,##``````````````````````````#@      
			@```#``#,,,@#```````````````````````````#@      
			@@`#```@,,@``````````````````````````````@      
			 @#````@#@```````````````````````````````@@     
			@@`````@@````````````````````````````````#@     
		   @@``````@````````````````````#@@@#````````#@     
		   @#``````````````````````````#     #````````@     
		  @@```````````````````````````@      #```````@     
		  @@``````````````````````````#        ```````#     
		   @#``````````````````#@@@@``@        #``````#@    
			@#````````````````@     @#         @```````@    
		   @@#```````````````#       @   @@@    ```````@    
		  @#``#``````````````@        @ @@  @   #``````@    
		@@#````#`````````````          @@@@@@   #``````@    
		@#`````##```````````#  @@@     @@@@@@   #``````#@   
	   @#```````#```````````# @@@ @    @ @@@    #``````#@   
	  #``````````#``````````` @@@@@             #``````#@   
	 @````````````#`````````` @@@@@             ```````#@   
	@#````````````#``````````@ @@@@            #````````@   
   @#``````````````#`````````#                @`````````@   
   #```````````````#``````````@         @    @#`````````@   
  @`````````````````#`````````#@@      @##@@@```````````@   
 @``````````````````#```````#@#``##@   #````````````````@   
 #```````````````````#``````````````# @`````````````````@   
 #```````````````````#```````````````##`````````````````@   
@`````````````````````#```````````````#`````````````````@@  
@`````````````````````#`````````````````````````````````@@  
 @`````````````````````#````````````````````````````````@@  
  @#```````````````````#````````````````````````````````@@  
	@```````````````````#```````````````````````````````@@  
	 @#`````````````````@``````#````````````````````````@@  
	  @@````````````````#```````###`````````````##``````@@  
	   @@#```````````````#```````;#@##```````###````````@@  
		@@#``````````````#```````#;;;;###@###;#`````````@@  
		  @@`````````````#```````#;;;;;;;;;;;;#`````````@   
		   @@#````````````#``````#;;;;;;;;;;;;``````````@   
			@@#```````````+``````#;;;;;;;;;;;;``````````@   
			  @#``````````#```````#;;;;;;;;;;;``````````@   
			   @#`````````````````#;;;;;;;;;;#``````````@   
				@``````````#``````#;;;;;;;;;;;``````````@   
				 @`````````#```````#;;;;;;;;;;``````````@   
				 @#````````#```````#;;;;;;;;;;#`````````@   
				  @````````#````````#;;;;;;;;;#````````#@   
				  @#`````````````````#;;;;;;;;#````````#@   
				  @@``````````````````#;;;;;;;#````````#@   
				   @````````#`````````##;;;;;;#````````@@   
				   @#```````#``````````##;;;;;;````````@@   
				   @@```````#````````````@###;###``````@@   
					@```````#``````````````#####```````@    
					@#``````#``````````````````````````@    
					@#``````#``````````````````#``````#@    
					@@``````#````````````````##```````#@    
					 @``````````````````````#`````````@     
					 @````````````````````````````````@     
					 @````````````````````````````````@     
					 @```````#```````````````````````#@     
					 @#``````#```````````````````````#@     
					 @#``````````````````````````````@      
					 @#``````````````````````````````@      
					 @#`````````````````````````````#@      
					 @#`````#```````````````````````#@      
					 @#`````#```````````````````````@       
					 @#`````#```````````````````````@       
					 @#`````#``````````````````````#@       
					 @#`````@``````````````````````@@       
					 @``````#``````````````````````@        
					 @``````#`````````````````````#@        
					 @````````````````````````````@@        
					 @````````````````````````````@         
					 @`````#`````````````````````#@         
					 @`````#`````````````````````@          
					 @@#```#`````````````````````@          
					  @@@#`#````````````````````#@          
						@@@`````````````````````@           
						 @@````````````````````#@           
						 @@````````````````````@            
						  @#`````````````````#@@            
						   @@#``````````````#@@             
							 @@@##```````##@@               
							   @@@@@@@@@@@                  
															
															
															
*/