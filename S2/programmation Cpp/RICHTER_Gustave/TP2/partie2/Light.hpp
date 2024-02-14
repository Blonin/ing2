#ifndef __LIGHT_HPP__
#define __LIGHT_HPP__
class Ligth { 
	private :
		bool on; //marking if the light is on or not
	protected :
	public :
		Ligth();      // Constructeur par défaut qui crée une lumière éteinte
		~Ligth();      // Destructeur
	 	void toggle();
	 	bool isOn();
		friend std::ostream &operator<<(std::ostream&out, const Ligth& l);
};

#endif