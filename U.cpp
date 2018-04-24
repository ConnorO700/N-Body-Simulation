#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector> 
#include <fstream> 
#include <iostream> 
#include <string>
#include "U.hpp"

Body::Body(){
	xpos =0; 
	ypos = 0;
	xvel =0;
	yvel=0;
	mass=0; 
	gif="";
}
Body::Body(double xin, double yin, double xv, double yv, double m, std::string s){
	xpos =xin; 
	ypos = yin;
	xvel =xv;
	yvel=yv;
	mass=m; 
	gif=s;

	sf::Image maker;
	if(!maker.loadFromFile(s)){
	}
	tex.loadFromImage(maker);
	sf::Sprite temp(tex); 
	spr = temp; 


}
double Body::get_xpos(){
	return xpos; 
}
double Body::get_ypos(){
	return ypos;
}
double Body::get_xvel(){
	return xvel; 
}
double Body::get_yvel(){
	return yvel; 
}
std::string Body::get_name(){
	return gif; 
}
std::istream& operator>>(std::istream& in, Body& b){
	in >> b.xpos;	
	in >> b.ypos;
	in >> b.xvel;
	in >> b.yvel;
	in >> b.mass;
	in >> b.gif; 
	sf::Image maker;
	if(!maker.loadFromFile(b.gif)){
	}
	b.tex.loadFromImage(maker);
	sf::Sprite temp(b.tex); 
	b.spr = temp;
	return in; 
}
sf::Sprite Body::getSpr(){
	return spr; 
}
void Body::setSpr(int x, int y){
	spr.setPosition(x,y);
}
void Body::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	//target.draw(spr,states);
	target.draw(spr); 
}
void Body::set_xpos(double x){
	xpos=x;
}
void Body::set_ypos(double y){
	ypos=y; 	
}
void Body::set_xvel(double x){
	xvel=x; 
}
void Body::set_yvel(double y){
	yvel=y; 
}
double Body::get_mass(){
	return mass;
}
void Body::printU(){
	
		std::cout << xpos << " " << ypos << " "<< xvel << " "<< yvel << " "<< mass << " " << gif << " " <<std::endl;
		
	
}

