class Majong{
    constructor(data){
        this.state = data["State"];
        this.thrown = data["Thrown"];
        this.eHand = data["EastHand"];
        this.sHand = data["SouthHand"];
        this.wHand = data["WestHand"];
        this.nHand = data["NorthHand"];
        this.eReveal = data["EastReveal"];
        this.sReveal = data["SouthReveal"];
        this.wReveal = data["WestReveal"];
        this.nReveal = data["NorthReveal"];
    }
    setBoard(data){
        this.state = data["State"];
        this.thrown = data["Thrown"];
        this.eHand = data["EastHand"];
        this.sHand = data["SouthHand"];
        this.wHand = data["WestHand"];
        this.nHand = data["NorthHand"];
        this.eReveal = data["EastReveal"];
        this.sReveal = data["SouthReveal"];
        this.wReveal = data["WestReveal"];
        this.nReveal = data["NorthReveal"];
    }
    getSet(){
        this.getEastSet();
        this.getSouthSet();
        this.getWestSet();
        this.getNorthSet();
    }
    getEastSet(){
        var r = 0;
        for(var i = 0; i < this.eHand[r].length; i++){
            var E = "E" + i.toString();
            var EID = "#E" + i.toString();
            $("#eastHand").append('<div class="tile" id='+ E +'></div>');
            $(EID).html(this.displayTiles(this.eHand[r][i]));
        }
        for(var i = 0; i < this.eReveal[r].length; i++){
            var ER = "ER" + i.toString();
            var ERID = "#ER" + i.toString();
            $("#eastReveal").append('<div class="tile" id='+ ER +'></div>');
            $(ERID).html(this.displayTiles(this.eReveal[r][i]));
        }
    }
    getSouthSet(){
        
    }
    getWestSet(){
        
    }
    getNorthSet(){
        
    }
    getThrown(){
        return this.thrown;
    }
    getState(){
        return this.state;
    }
    displayTiles(tileNum){
        var result = "";
        if(tileNum >= 1 && tileNum < 5){
            result = '<img src="tiles/M_Bamboo1.png">';
        }else if(tileNum >= 5 && tileNum < 9){
            result = '<img src="tiles/M_Bamboo2.png">';
        }else if(tileNum >= 9 && tileNum < 13){
            result = '<img src="tiles/M_Bamboo3.png">';
        }else if(tileNum >= 13 && tileNum < 17){
            result = '<img src="tiles/M_Bamboo4.png">';
        }else if(tileNum >= 17 && tileNum < 21){
            result = '<img src="tiles/M_Bamboo5.png">';
        }else if(tileNum >= 21 && tileNum < 25){
            result = '<img src="tiles/M_Bamboo6.png">';
        }else if(tileNum >= 25 && tileNum < 29){
            result = '<img src="tiles/M_Bamboo7.png">';
        }else if(tileNum >= 29 && tileNum < 33){
            result = '<img src="tiles/M_Bamboo8.png">';
        }else if(tileNum >= 33 && tileNum < 37){
            result = '<img src="tiles/M_Bamboo9.png">';
        }else if(tileNum >= 37 && tileNum < 41){
            result = '<img src="tiles/M_Characters1.png">';
        }else if(tileNum >= 41 && tileNum < 45){
            result = '<img src="tiles/M_Characters2.png">';
        }else if(tileNum >= 45 && tileNum < 49){
            result = '<img src="tiles/M_Characters3.png">';
        }else if(tileNum >= 49 && tileNum < 53){
            result = '<img src="tiles/M_Characters4.png">';
        }else if(tileNum >= 53 && tileNum < 57){
            result = '<img src="tiles/M_Characters5.png">';
        }else if(tileNum >= 57 && tileNum < 61){
            result = '<img src="tiles/M_Characters6.png">';
        }else if(tileNum >= 61 && tileNum < 65){
            result = '<img src="tiles/M_Characters7.png">';
        }else if(tileNum >= 65 && tileNum < 69){
            result = '<img src="tiles/M_Characters8.png">';
        }else if(tileNum >= 69 && tileNum < 73){
            result = '<img src="tiles/M_Characters9.png">';
        }else if(tileNum >= 73 && tileNum < 77){
            result = '<img src="tiles/M_Dot1.png">';
        }else if(tileNum >= 77 && tileNum < 81){
            result = '<img src="tiles/M_Dot2.png">';
        }else if(tileNum >= 81 && tileNum < 85){
            result = '<img src="tiles/M_Dot3.png">';
        }else if(tileNum >= 85 && tileNum < 89){
            result = '<img src="tiles/M_Dot4.png">';
        }else if(tileNum >= 89 && tileNum < 93){
            result = '<img src="tiles/M_Dot5.png">';
        }else if(tileNum >= 93 && tileNum < 97){
            result = '<img src="tiles/M_Dot6.png">';
        }else if(tileNum >= 97 && tileNum < 101){
            result = '<img src="tiles/M_Dot7.png">';
        }else if(tileNum >= 101 && tileNum < 105){
            result = '<img src="tiles/M_Dot8.png">';
        }else if(tileNum >= 105 && tileNum < 109){
            result = '<img src="tiles/M_Dot9.png">';
        }else if(tileNum >= 109 && tileNum < 113){
            result = '<img src="tiles/M_Wind_East.png">';
        }else if(tileNum >= 113 && tileNum < 117){
            result = '<img src="tiles/M_Wind_South.png">';
        }else if(tileNum >= 117 && tileNum < 121){
            result = '<img src="tiles/M_Wind_West.png">';
        }else if(tileNum >= 121 && tileNum < 125){
            result = '<img src="tiles/M_Wind_North.png">';
        }else if(tileNum >= 125 && tileNum < 129){
            result = '<img src="tiles/M_Dragon_Red.png">';
        }else if(tileNum >= 129 && tileNum < 133){
            result = '<img src="tiles/M_Dragon_Green.png">';
        }else if(tileNum >= 133 && tileNum < 137){
            result = '<img src="tiles/M_Dragon_White.png">';
        }else if(tileNum == 137){
            result = '<img src="tiles/M_Flower_Plum_Blossom.png">';
        }else if(tileNum == 138){
            result = '<img src="tiles/M_Flower_Orchid.png">';
        }else if(tileNum == 139){
            result = '<img src="tiles/M_Flower_chrysanthemum.png">';
        }else if(tileNum == 140){
            result = '<img src="tiles/M_Flower_Bamboo.png">';
        }else if(tileNum == 141){
            result = '<img src="tiles/M_Season_Spring.png">';
        }else if(tileNum == 142){
            result = '<img src="tiles/M_Season_Summer.png">';
        }else if(tileNum == 143){
            result = '<img src="tiles/M_Season_Autumn.png">';
        }else if(tileNum == 144){
            result = '<img src="tiles/M_Season_Winter.png">';
        }
        return result
    }
}

$(document).ready(function(){
	$.get("/init", {}, function(response){
        var data = JSON.parse(response);
        let game = new Majong(data);
        $("#state").html(game.getState());
        if(game.getThrown() != -1){
            $(".thrown").html('<div class="tile" id="thrown"></div>')
            $("#thrown").html(game.displayTiles(game.getThrown()));
        }

        game.getSet();
// 
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
                var EID = "#E" + i.toString();
                var NID = "#N" + i.toString();
                var WID = "#W" + i.toString();
                var SID = "#S" + i.toString();
            $(EID).click({hand: i, player: j = 0},function(e){
                var x = e.data.player;
                var y = e.data.hand;
                console.log("(Player: " + x + ", Tile: " + y + ") Clicked");
                $.get("/handle", {"x": x, "y": y, "btn": "left"}, function(response){
                    var data = JSON.parse(response);
                    game.setBoard(data);
                    $("#state").html(game.getState());
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
                    $("#state").html(game.getState());
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
                    $("#state").html(game.getState());
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
                    $("#state").html(game.getState());
                    $("#trash").html(game.displayTiles(game.getGarbage()));
                    game.getHand();    
                });
            });
        }
    });
});
