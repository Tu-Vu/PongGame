#ifndef _SCORE_H_
#define _SCORE_H_
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Score:public Text
{
private:
	int value;
public:
	Score(Font& font,unsigned int size);
	void ScoreUp();
	void Update();
};
#endif

