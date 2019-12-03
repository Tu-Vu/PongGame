#ifndef _SCORE_H_
#define _SCORE_H_
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Score:public Text{
private:
	
public:
	int value; // trị số điểm
	Score(Font&, unsigned int size); // set điểm
	void ScoreUp(); // tăng điểm
	void Update(); // update điểm
};
#endif

