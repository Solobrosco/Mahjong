class Majong{
    constructor(data){
        this.garbage = data["garbage"];
        this.eHand = data["eastHand"];
        this.nHand = data["northHand"];
        this.wHand = data["westHand"];
        this.sHand = data["southHand"];
    }
    setBoard(data){
        this.garbage = data["garbage"];
        this.eHand = data["eastHand"];
        this.nHand = data["northHand"];
        this.wHand = data["westHand"];
        this.sHand = data["southHand"];
    }
    getHand(){
        var r = 0;
        for (var i = 0; i < 14; i++){
            if(i < 10){
                var EID = "#E0" + i.toString();
                var NID = "#N0" + i.toString();
                var WID = "#W0" + i.toString();
                var SID = "#S0" + i.toString();
            }else{
                var EID = "#E" + i.toString();
                var NID = "#N" + i.toString();
                var WID = "#W" + i.toString();
                var SID = "#S" + i.toString();
            }
            $(EID).html(this.displayTiles(this.eHand[r][i]));
            $(NID).html(this.displayTiles(this.nHand[r][i]));
            $(WID).html(this.displayTiles(this.wHand[r][i]));
            $(SID).html(this.displayTiles(this.sHand[r][i]));
        }
    }
    getGarbage(){
        return this.garbage;
    }
    displayTiles(tileNum){
        var result = "";
        if(tileNum >= 0 && tileNum < 4){
            result = '<img src="tiles/M_Bamboo1.png">';
        }else if(tileNum >= 4 && tileNum < 8){
            result = '<img src="tiles/M_Bamboo2.png">';
        }else if(tileNum >= 8 && tileNum < 12){
            result = '<img src="tiles/M_Bamboo3.png">';
        }else if(tileNum >= 12 && tileNum < 16){
            result = '<img src="tiles/M_Bamboo4.png">';
        }else if(tileNum >= 16 && tileNum < 20){
            result = '<img src="tiles/M_Bamboo5.png">';
        }else if(tileNum >= 20 && tileNum < 24){
            result = '<img src="tiles/M_Bamboo6.png">';
        }else if(tileNum >= 24 && tileNum < 28){
            result = '<img src="tiles/M_Bamboo7.png">';
        }else if(tileNum >= 28 && tileNum < 32){
            result = '<img src="tiles/M_Bamboo8.png">';
        }else if(tileNum >= 32 && tileNum < 36){
            result = '<img src="tiles/M_Bamboo9.png">';
        }else if(tileNum >= 36 && tileNum < 40){
            result = '<img src="tiles/M_Characters1.png">';
        }else if(tileNum >= 40 && tileNum < 44){
            result = '<img src="tiles/M_Characters2.png">';
        }else if(tileNum >= 44 && tileNum < 48){
            result = '<img src="tiles/M_Characters3.png">';
        }else if(tileNum >= 48 && tileNum < 52){
            result = '<img src="tiles/M_Characters4.png">';
        }else if(tileNum >= 52 && tileNum < 56){
            result = '<img src="tiles/M_Characters5.png">';
        }else if(tileNum >= 56 && tileNum < 60){
            result = '<img src="tiles/M_Characters6.png">';
        }else if(tileNum >= 60 && tileNum < 64){
            result = '<img src="tiles/M_Characters7.png">';
        }else if(tileNum >= 64 && tileNum < 68){
            result = '<img src="tiles/M_Characters8.png">';
        }else if(tileNum >= 68 && tileNum < 72){
            result = '<img src="tiles/M_Characters9.png">';
        }else if(tileNum >= 72 && tileNum < 76){
            result = '<img src="tiles/M_Dot1.png">';
        }else if(tileNum >= 76 && tileNum < 80){
            result = '<img src="tiles/M_Dot2.png">';
        }else if(tileNum >= 80 && tileNum < 84){
            result = '<img src="tiles/M_Dot3.png">';
        }else if(tileNum >= 84 && tileNum < 88){
            result = '<img src="tiles/M_Dot4.png">';
        }else if(tileNum >= 88 && tileNum < 92){
            result = '<img src="tiles/M_Dot5.png">';
        }else if(tileNum >= 92 && tileNum < 96){
            result = '<img src="tiles/M_Dot6.png">';
        }else if(tileNum >= 96 && tileNum < 100){
            result = '<img src="tiles/M_Dot7.png">';
        }else if(tileNum >= 100 && tileNum < 104){
            result = '<img src="tiles/M_Dot8.png">';
        }else if(tileNum >= 104 && tileNum < 108){
            result = '<img src="tiles/M_Dot9.png">';
        }else if(tileNum >= 108 && tileNum < 112){
            result = '<img src="tiles/M_Wind_East.png">';
        }else if(tileNum >= 112 && tileNum < 116){
            result = '<img src="tiles/M_Wind_South.png">';
        }else if(tileNum >= 116 && tileNum < 120){
            result = '<img src="tiles/M_Wind_West.png">';
        }else if(tileNum >= 120 && tileNum < 124){
            result = '<img src="tiles/M_Wind_North.png">';
        }else if(tileNum >= 124 && tileNum < 128){
            result = '<img src="tiles/M_Dragon_Red.png">';
        }else if(tileNum >= 128 && tileNum < 132){
            result = '<img src="tiles/M_Dragon_Green.png">';
        }else if(tileNum >= 132 && tileNum < 136){
            result = '<img src="tiles/M_Dragon_White.png">';
        }else if(tileNum == 136){
            result = '<img src="tiles/M_Flower_Plum_Blossom.png">';
        }else if(tileNum == 137){
            result = '<img src="tiles/M_Flower_Orchid.png">';
        }else if(tileNum == 138){
            result = '<img src="tiles/M_Flower_chrysanthemum.png">';
        }else if(tileNum == 139){
            result = '<img src="tiles/M_Flower_Bamboo.png">';
        }else if(tileNum == 140){
            result = '<img src="tiles/M_Season_Spring.png">';
        }else if(tileNum == 141){
            result = '<img src="tiles/M_Season_Summer.png">';
        }else if(tileNum == 142){
            result = '<img src="tiles/M_Season_Autumn.png">';
        }else if(tileNum == 143){
            result = '<img src="tiles/M_Season_Winter.png">';
        }
        return result
    }
}

$(document).ready(function(){
	$.get("/init", {}, function(response){
        var data = JSON.parse(response);
        let game = new Majong(data);
        $("#trash").html(game.displayTiles(game.getGarbage()));
        game.getHand();
        $("#trash").click({hand: i = 0, player: j = -1},function(e){
            var x = e.data.player;
            var y = e.data.hand;
            console.log("(Player: " + x + ", Tile: " + y + ") Clicked");
            $.get("/handle", {"x": x, "y": y, "btn": "left"}, function(response){
                var data = JSON.parse(response);
                game.setBoard(data);
                $("#trash").html(game.getGarbage());
                game.getHand();    
            });
        });
        for (var i = 0; i < 14; i++){
            if(i < 10){
                var EID = "#E0" + i.toString();
                var NID = "#N0" + i.toString();
                var WID = "#W0" + i.toString();
                var SID = "#S0" + i.toString();
            }else{
                var EID = "#E" + i.toString();
                var NID = "#N" + i.toString();
                var WID = "#W" + i.toString();
                var SID = "#S" + i.toString();
            }
            $(EID).click({hand: i, player: j = 0},function(e){
                var x = e.data.player;
                var y = e.data.hand;
                console.log("(Player: " + x + ", Tile: " + y + ") Clicked");
                $.get("/handle", {"x": x, "y": y, "btn": "left"}, function(response){
                    var data = JSON.parse(response);
                    game.setBoard(data);
                    $("#trash").html(game.displayTiles(game.getGarbage()));
                    game.getHand();   
                });
            });
            $(SID).click({hand: i, player: j = 1},function(e){
                var x = e.data.player;
                var y = e.data.hand;
                console.log("(Player: " + x + ", Tile: " + y + ") Clicked");
                $.get("/handle", {"x": x, "y": y, "btn": "left"}, function(response){
                    var data = JSON.parse(response);
                    game.setBoard(data);
                    $("#trash").html(game.displayTiles(game.getGarbage()));
                    game.getHand();    
                });
            });
            $(WID).click({hand: i, player: j = 2},function(e){
                var x = e.data.player;
                var y = e.data.hand;
                console.log("(Player: " + x + ", Tile: " + y + ") Clicked");
                $.get("/handle", {"x": x, "y": y, "btn": "left"}, function(response){
                    var data = JSON.parse(response);
                    game.setBoard(data);
                    $("#trash").html(game.displayTiles(game.getGarbage()));
                    game.getHand();     
                });
            });
            $(NID).click({hand: i, player: j = 3},function(e){
                var x = e.data.player;
                var y = e.data.hand;
                console.log("(Player: " + x + ", Tile: " + y + ") Clicked");
                $.get("/handle", {"x": x, "y": y, "btn": "left"}, function(response){
                    var data = JSON.parse(response);
                    game.setBoard(data);
                    $("#trash").html(game.displayTiles(game.getGarbage()));
                    game.getHand();    
                });
            });
        }
    });
});
