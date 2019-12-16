#ifndef _SCORE_H_
#define _SCORE_H_
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Score:public Text{
public:
	int value; // trị số điểm
	Score(Font&, unsigned int size); // set điểm
	void ScoreUp(); // tăng điểm
	void ScoreDown(); // giảm điểm
	void Update(); // update điểm
};
#endif

