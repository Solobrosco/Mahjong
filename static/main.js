function getHand(eHand, nHand, wHand, sHand){
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
        $(EID).html(eHand[r][i]);
        $(NID).html(nHand[r][i]);
        $(WID).html(wHand[r][i]);
        $(SID).html(sHand[r][i]);
    }
}

$(document).ready(function(){
	$.get("/init", {}, function(response){
        var data = JSON.parse(response);
        var garbage = data["garbage"];
        var eHand = data["eastHand"];
        var nHand = data["northHand"];
        var wHand = data["westHand"];
        var sHand = data["southHand"];
        $("#trash").html(garbage);
        getHand(eHand, nHand, wHand, sHand);
        $("#trash").click({hand: i = 0, player: j = -1},function(e){
            var x = e.data.player;
            var y = e.data.hand;
            console.log("(Player: " + x + ", Tile: " + y + ") Clicked");
            $.get("/handle", {"x": x, "y": y, "btn": "left"}, function(response){
                var data = JSON.parse(response);
                var garbage = data["garbage"];
                var eHand = data["eastHand"];
                var nHand = data["northHand"];
                var wHand = data["westHand"];
                var sHand = data["southHand"];
                $("#trash").html(garbage);
                getHand(eHand, nHand, wHand, sHand);    
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
                    var garbage = data["garbage"];
                    var eHand = data["eastHand"];
                    var nHand = data["northHand"];
                    var wHand = data["westHand"];
                    var sHand = data["southHand"];
                    $("#trash").html(garbage);
                    getHand(eHand, nHand, wHand, sHand);    
                });
            });
            $(SID).click({hand: i, player: j = 1},function(e){
                var x = e.data.player;
                var y = e.data.hand;
                console.log("(Player: " + x + ", Tile: " + y + ") Clicked");
                $.get("/handle", {"x": x, "y": y, "btn": "left"}, function(response){
                    var data = JSON.parse(response);
                    var garbage = data["garbage"];
                    var eHand = data["eastHand"];
                    var nHand = data["northHand"];
                    var wHand = data["westHand"];
                    var sHand = data["southHand"];
                    $("#trash").html(garbage);
                    getHand(eHand, nHand, wHand, sHand);    
                });
            });
            $(WID).click({hand: i, player: j = 2},function(e){
                var x = e.data.player;
                var y = e.data.hand;
                console.log("(Player: " + x + ", Tile: " + y + ") Clicked");
                $.get("/handle", {"x": x, "y": y, "btn": "left"}, function(response){
                    var data = JSON.parse(response);
                    var garbage = data["garbage"];
                    var eHand = data["eastHand"];
                    var nHand = data["northHand"];
                    var wHand = data["westHand"];
                    var sHand = data["southHand"];
                    $("#trash").html(garbage);
                    getHand(eHand, nHand, wHand, sHand);    
                });
            });
            $(NID).click({hand: i, player: j = 3},function(e){
                var x = e.data.player;
                var y = e.data.hand;
                console.log("(Player: " + x + ", Tile: " + y + ") Clicked");
                $.get("/handle", {"x": x, "y": y, "btn": "left"}, function(response){
                    var data = JSON.parse(response);
                    var garbage = data["garbage"];
                    var eHand = data["eastHand"];
                    var nHand = data["northHand"];
                    var wHand = data["westHand"];
                    var sHand = data["southHand"];
                    $("#trash").html(garbage);
                    getHand(eHand, nHand, wHand, sHand);    
                });
            });
        }
    });
});
