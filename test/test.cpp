#include <igloo/igloo.h>
#include <Player.h>
#include <stdio.h>

using namespace igloo;

Context(PlayerTest){
	Spec(CanGetNumHand){
		Player player = Player("East");
		Assert::That(player.getnumHand(), Equals(14));
	}
	Spec(CanGetTurnEast){
		Player player = Player("East");
		Assert::That(player.getTurn(), Equals(true));
	}
	Spec(CanGetTurnSouth){
		Player player = Player("South");
		Assert::That(player.getTurn(), Equals(false));
	}
};

int main() {
	// Run all the tests defined above
	return TestRunner::RunAllTests();
}
