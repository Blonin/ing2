#ifndef __LIGHT_HPP__
#define __LIGHT_HPP__
class Light { 
	private :
		bool on = false; //marking if the light is on or not
	protected :
	public :
	 	void toggle(){on= !on;}
	 	bool isOn(){return on;}
        friend std::ostream&operator << (std::ostream&out, const Light &f);
};
#endif 