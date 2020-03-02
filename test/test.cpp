#include <igloo/igloo.h>
#include <stdio.h>
#include <Mahjong.h>
#include <Player.h>
#include <MahjongTiles.h>

using namespace igloo;

Context(PlayerTest){
	Spec(CanGetPlayer){
		std::string East = "East";
		std::string South = "South";
		std::string West = "West";
		std::string North = "North";
		std::string Random = "Gibby";
		Player playerE = Player(East);
		Player playerS = Player(South);
		Player playerW = Player(West);
		Player playerN = Player(North);
		Player playerR = Player(Random);
		Assert::That(playerE.getPlayer(), Equals(East));
		Assert::That(playerS.getPlayer(), Equals(South));
		Assert::That(playerW.getPlayer(), Equals(West));
		Assert::That(playerN.getPlayer(), Equals(North));
		Assert::That(playerR.getPlayer(), Equals(Random));
	}
	Spec(CanResetPlayer){
		Player playerE = Player("East");
		Player playerS = Player("South");
		playerE.resetPlayer();
		playerS.resetPlayer();
		Assert::That(playerE.getNumHand(), Equals(0));
		Assert::That(playerS.getNumHand(), Equals(0));
		Assert::That(playerE.getTurn(), Equals(true));
		Assert::That(playerS.getTurn(), Equals(false));
	}
	Spec(CanGetPlayerTurn){
		Player playerE = Player("East");
		Player playerS = Player("South");
		Assert::That(playerE.getTurn(), Equals(true));
		Assert::That(playerS.getTurn(), Equals(false));
	}
	Spec(CanSetAndGetPlayerTurn){
		Player playerE = Player("East");
		Player playerS = Player("South");
		playerE.setTurn();
		playerS.setTurn();
		Assert::That(playerE.getTurn(), Equals(false));
		Assert::That(playerS.getTurn(), Equals(true));
	}
	Spec(CanSetAndGetPlayerHandSortted){
		Player playerE = Player("East");
		std::vector<int> hand = {1,5,8,3,2};
		std::vector<int> sorted = {1,2,3,5,8};
		for(int i = 0; i < hand.size(); i++){
			playerE.setHand(hand[i]);
		}
		Assert::That(playerE.getHand(), Equals(sorted));
	}
	Spec(CanSetAndGetRevealEast){
		Player playerE = Player("East");
		std::vector<int> reveal = {137,138,140,141,139};
		for(int i = 0; i < reveal.size(); i++){
			playerE.setReveal(reveal[i]);
		}
		Assert::That(playerE.getReveal(), Equals(reveal));	
	}
	Spec(CanThrowTile){
		Player player = Player("East");
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

Context(MahjongBoardGame){
};

int main() {
	// Run all the tests defined above
	return TestRunner::RunAllTests();
}
