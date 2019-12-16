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
            $(EID).html(this.eHand[r][i]);
            $(NID).html(this.nHand[r][i]);
            $(WID).html(this.wHand[r][i]);
            $(SID).html(this.sHand[r][i]);
        }
    }
    getGarbage(){
        return this.garbage;
    }
}

$(document).ready(function(){
	$.get("/init", {}, function(response){
        var data = JSON.parse(response);
        let game = new Majong(data);
        $("#trash").html(game.getGarbage());
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
                    $("#trash").html(game.getGarbage());
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
                    $("#trash").html(game.getGarbage());
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
                    $("#trash").html(game.getGarbage());
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
                    $("#trash").html(game.getGarbage());
                    game.getHand();    
                });
            });
        }
    });
});
