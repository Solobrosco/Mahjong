#include <igloo/igloo.h>
#include <stdio.h>
#include <Player.h>
#include <MahjongTiles.h>

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

Context(MahjongTilesTest){
	Spec(CanGetTiles){
		MahjongTiles tiles = MahjongTiles(144);
		std::vector<int> vect;
		for(int i = 0; i < 144; i++){
            vect.push_back(i+1);
        }
		Assert::That(tiles.getTiles(), Equals(vect));
	}
	Spec(CanGetTile){
		MahjongTiles tiles = MahjongTiles(144);
		int n = 99;
		Assert::That(tiles.getTile(n), Equals(n+1));
	}
	Spec(CanGetAmount){
		MahjongTiles tiles = MahjongTiles(144);
		Assert::That(tiles.getAmount(), Equals(144));
	}
};

int main() {
	// Run all the tests defined above
	return TestRunner::RunAllTests();
}
