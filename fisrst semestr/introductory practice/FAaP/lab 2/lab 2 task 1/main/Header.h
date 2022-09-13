#pragma once


class cube {

protected:
	int a;

public:
	cube();
	cube(int a);
	int valume();
};

class parallelepiped : public cube {
private:
	int h;
	int b;
public:
	parallelepiped(int a,int b, int h);
	int valume();
	

};