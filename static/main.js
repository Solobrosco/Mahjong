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
    });
});
