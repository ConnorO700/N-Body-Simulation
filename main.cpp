#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream> 
#include <string>
#include <vector> 
#include "U.hpp"
#include <math.h>
double mathThePos(double planetPos, double univSize, double winSize){
	return (planetPos/univSize)*(winSize/2)+(winSize/2);
}	
void planetTurn(Body& planet, double time){
	if(!(planet.get_name()=="sun.gif")){
		
	double xp = planet.get_xpos(); 
	double yp = planet.get_ypos();

	double r  = sqrt((xp*xp)+(yp*yp)); //calculate distance between planet and sun
	double F  = ((6.67e-11)*(1.9890e+30)*(planet.get_mass()))/(r*r); //find force
	//std::cout << "F:" << F << std::endl;
	double Fx = F*-xp/r; //force in x direction
	double Fy = F*yp/r; //force in y direction
	//std::cout << "Fx:" << Fx <<std::endl; 
	double ax = Fx/planet.get_mass(); //acceleration in the x direction
	double ay = Fy/planet.get_mass(); //acceleration in the y direction
	//std::cout << "ax:" << ax << std::endl;
	double xv = planet.get_xvel()+ax*time;
	double yv = planet.get_yvel()+ay*time;
	planet.set_xvel(xv);
	planet.set_yvel(yv); 
	planet.set_xpos(planet.get_xpos()+planet.get_xvel()*time);
	planet.set_ypos(planet.get_ypos()-planet.get_yvel()*time);
	}
}
using namespace std;
int main(int argc,char *argv[]){
	double bigTe = atof(argv[1]);
	double deltaTe = atof(argv[2]);
	double te = 0;
	string fname = argv[4]; 
	int j =0;
	double univ =0;  
	cin >> j;
	cin >> univ;
	vector<Body> Universe(j);
	for(int h=0;h<=j-1;h++){ 
		cin >> Universe[h];
	} 
	
	
	
	int x = 1000;
	int y = 800;
	sf::RenderWindow window(sf::VideoMode(x,y), "Sol System");
	while(window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
			}
		}

		window.clear();
		for(unsigned int i=0;i<=Universe.size()-1;i++){ 
			if(te<bigTe){
				planetTurn(Universe[i],deltaTe);
			}
			Universe[i].setSpr(mathThePos(Universe[i].get_xpos(),univ,x),mathThePos(Universe[i].get_ypos(),univ,y)); 
			window.draw(Universe[i]);
		}
		te = te + deltaTe;
		window.display(); 
	}
}


