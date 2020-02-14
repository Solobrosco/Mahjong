#include <igloo/igloo.h>
#include <stdio.h>
#include <Mahjong.h>
#include <Player.h>
#include <MahjongTiles.h>

using namespace igloo;

Context(PlayerTest){
	// Spec(CanGetNumHand){
	// 	Player player = Player("East");
	// 	Assert::That(player.getNumHand(), Equals(14));
	// }
	Spec(CanGetTurnEast){
		Player player = Player("East");
		Assert::That(player.getTurn(), Equals(true));
	}
	// Spec(CanGetTurnSouth){
	// 	Player player = Player("South");
	// 	Assert::That(player.getTurn(), Equals(false));
	// }
	Spec(CanSetAndGetTurnEast){
		Player player = Player("East");
		player.setTurn();
		Assert::That(player.getTurn(), Equals(false));
	}
	// Spec(CanSetandGetTurnSouth){
	// 	Player player = Player("South");
	// 	player.setTurn();
	// 	Assert::That(player.getTurn(), Equals(true));
	// }
	Spec(CanSetGetAndSortHandEast){
		Player player = Player("East");
		std::vector<int> hand = {1,5,8,3,2};
		std::vector<int> sorted = {1,2,3,5,8};
		for(int i = 0; i < hand.size(); i++){
			player.setHand(hand[i]);
		}
		Assert::That(player.getHand(), Equals(sorted));	
	}
	Spec(CanSetAndGetRevealEast){
		Player player = Player("East");
		std::vector<int> reveal = {137,138,140,141,139};
		for(int i = 0; i < reveal.size(); i++){
			player.setReveal(reveal[i]);
		}
		Assert::That(player.getReveal(), Equals(reveal));	
	}
	Spec(CanThrowTile){
		Player player = Player("North");
		std::vector<int> hand = {1,2,3,5,8};
		std::vector<int> ans = {1,2,5,8};
		for(int i = 0; i < hand.size(); i++){
			player.setHand(hand[i]);
		}
		player.throwTile(2);
		Assert::That(player.getHand(), Equals(ans));	
	}
};

Context(MahjongTilesTest){
	// Spec(CanGetTile){
	// 	MahjongTiles tiles = MahjongTiles(144);
	// 	int n = 99;
	// 	Assert::That(tiles.getTile(), Equals(n+1));
	// }
	// Spec(CanGetAmount){
	// 	MahjongTiles tiles = MahjongTiles(144);
	// 	Assert::That(tiles.getAmount(), Equals(144));
	// }
	// Spec(CanGetAndSetGarbage){
	// 	MahjongTiles tiles = MahjongTiles(144);
	// 	tiles.setGarbage(20);
	// 	Assert::That(tiles.getGarbage(), Equals(20));
	// }
	// Spec(CanRemoveTile){
	// 	MahjongTiles tiles = MahjongTiles(144);
	// 	std::vector<int> vect;
	// 	for(int i = 0; i < 144; i++){
    //         if(i != 3 && i != 123){
	// 			vect.push_back(i+1);
	// 		}
    //     }
	// 	tiles.rmTile(3);
	// 	tiles.rmTile(123 - 1);
	// 	Assert::That(tiles.getTiles(), Equals(vect));
	// }
};

int main() {
	// Run all the tests defined above
	return TestRunner::RunAllTests();
}
