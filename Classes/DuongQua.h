#ifndef __DUONG_QUA_H__
#define __DUONG_QUA_H__

#include "B2Skeleton.h"
#include "BaseHero.h"

class DuongQua : public BaseHero
{
public:

	DuongQua(string jsonFile, string atlasFile, float scale);
	static DuongQua* create(string jsonFile, string atlasFile, float scale);

protected:

	void initCirclePhysic(b2World *world, Point pos);

	void run();
	void normalJump();
	void doubleJump();
	void landing();
	void die();
	void attackNormal();
	void attackLanding();
	void attackBySkill1();
	void attackBySkill2();
	void attackBySkill3();
	void injured();
	void die(Point posOfCammera);
	void listener();
	void updateMe(float dt);

};
#endif // __DuongQua_H__