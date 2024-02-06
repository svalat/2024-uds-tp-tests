/*********************************************************/
#include "physics.hpp"
#include <gtest/gtest.h>

/*********************************************************/
using namespace experiment;

/*********************************************************/
TEST(TestPhysics, collide)
{
	//build
	Particle particle1(-1.0, 1.0);
	Particle particle2(1.0, -1.0);

	//call
	EXPECT_FALSE(physics::collide(particle1, particle2, 0.5)) << "A cause d'une erreur";
	EXPECT_FALSE(physics::collide(particle1, particle2, 0.9));
	EXPECT_TRUE(physics::collide(particle1, particle2, 1.0));
	EXPECT_TRUE(physics::collide(particle1, particle2, 2.0));
}

/*********************************************************/
TEST(TestPhysics, get_collision_time_1_symetric)
{
	//build
	Particle particle1(-1.0, 1.0);
	Particle particle2(1.0, -1.0);

	//call
	EXPECT_EQ(1.0, physics::get_collision_time(particle1, particle2));
}

/*********************************************************/
TEST(TestPhysics, get_collision_time_2_asymetric)
{
	//build
	Particle particle1(-0.5, 1.0);
	Particle particle2(1.0, -1.0);

	//call
	EXPECT_EQ(0.75, physics::get_collision_time(particle1, particle2));
}

/*********************************************************/
TEST(TestPhysics, test_elastic_collision_1_symetric)
{
	//build
	Particle particle1(-1.0, 1.0);
	Particle particle2(1.0, -1.0);

	//call
	bool ret = physics::elastic_collision(particle1, particle2, 2);
	ASSERT_TRUE(ret);

	//check states
	EXPECT_EQ(-1.0, particle1.get_x());
	EXPECT_EQ(-1.0, particle1.get_vx());
	EXPECT_EQ(1.0, particle2.get_x());
	EXPECT_EQ(1.0, particle2.get_vx());
}
