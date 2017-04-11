#ifndef __COIN_BULLION_H__
#define __COIN_BULLION_H__

#include "B2Skeleton.h"
//#include "Agent.h"



class CoinBullion : public B2Skeleton{

public:
	CoinBullion(string jsonFile, string atlasFile, float scale);
	static CoinBullion* create(string jsonFile, string atlasFile, float scale);
	SkeletonAnimation *effect;

	void updateMe(BaseHero* hero);
	void picked();
	//void listener();
	void onExit();
};

#endif // __B2_SPRITE_H__