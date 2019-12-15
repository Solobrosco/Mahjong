#include <server.h>
#include <Mahjong.h>


using namespace ucm;

int main(int argc, char** argv){

    CrowServer server(argc, argv);

    BoardGame* game = new Mahjong();

    server.renderHTML("/", "index.html");

        server.route("/init", [&](const request& req, response& res){

        game->reset();
        
        json board = game->getBoard(); 

        res.sendJSON(board);
    });

    server.route("/handle", [&](const request& req, response& res){

        // if (req.has_params({"x", "y", "btn"})){

        //     std::string xS = req.url_params.get("x");
        //     std::string yS = req.url_params.get("y");
        //     std::string btn = req.url_params.get("btn");

        //     int x = stoi(xS);
        //     int y = stoi(yS);
        //     MouseButton button;
        //     if (btn == "left"){
        //         button = left;
        //     }
        //     else if (btn == "right"){
        //         button = right;
        //     }
        //     else{
        //         button = unknown;
        //     }

        //     game->handle(x, y, button);

        //     json board = game->getBoard();

        //     res.sendJSON(board);
        // }

        // else{
        //     res.sendError400();
        // }
    });

    server.run();
    delete game;
}
