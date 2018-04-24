#pragma once
#include <string> 
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Body : public sf::Drawable {
public:		
	sf::Sprite getSpr();
	void setSpr(int x, int y);
	Body();
	Body(double xin, double yin, double xv, double yv, double m, std::string s); 
	void printU();
	friend std::istream& operator>>(std::istream& in,Body& b);
	double get_xpos(); 
	double get_ypos();
	double get_xvel();
	double get_yvel(); 
	std::string get_name(); 
	void set_xpos(double x);
	void set_ypos(double y);
	void set_xvel(double x);
	void set_yvel(double y); 
	double get_mass();
	
	
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	double xpos; 
	double ypos;
	double xvel;
	double yvel;	
	double mass;
	sf::Sprite spr;
	sf::Texture tex; 
	std::string gif;
	
};
