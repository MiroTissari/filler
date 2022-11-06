# Filler - Create an AI player.
  
Filler-project is from the Algorithm-branch at The Hive Helsinki.  
The objective is to create a (winning) player for a game that's given as a virtual machine.  
  
Key things I learned: Got more in depth with reading and saving data, how to capitalize the data, and that testing includes abusing the program with terrible arguments.  
  
  
## Executing the program
  
- Clone the repository to your workspace and go to the root of the repo.
- type `make` to create the executable (the player).
- You can choose the player you want to play against, all the players are located at */resources/players/*.
- You have three possibilities for map size - small(map00), regular(map01) or big(map02). The maps are located at */resources/maps/*.
- To launch the game from the root:  
&emsp;- **./resources/filler_vm -f resources/maps/_mapsize-of-your-choice_ -p1 mtissari.filler -p2 resources/players/_player-of-your-choice_**
- Example: `./resources/filler_vm -f resources/maps/map01 -p1 mtissari.filler -p2 resources/players/superjeannot`
  
## How the game works
  
The idea of the game is to fill a map with your own symbols.  
Both players receive different shapes to put into the map and the game ends when neither player can put any more pieces to the map.  
When a player cannot fit a piece to the map, the game ends for that player but the other player can continue until the same happens to it.  

The virtual machine gives the program all the needed information in standard output.  
Both players receive their symbol and starting position.
  
