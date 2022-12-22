# Filler - Create an AI player.
  <img width="326" alt="Screen Shot 2022-12-22 at 7 25 26 PM" src="https://user-images.githubusercontent.com/90178358/209191779-b2c34c4c-c9a7-4b0d-9598-becd9a91f853.png"> <img width="328" alt="Screen Shot 2022-12-22 at 7 12 26 PM" src="https://user-images.githubusercontent.com/90178358/209190166-5a8cdb60-9954-40cb-86d3-9cff9374532a.png"> <img width="330" alt="Screen Shot 2022-12-22 at 7 22 06 PM" src="https://user-images.githubusercontent.com/90178358/209191419-d3e470e3-7d15-47a7-b263-9234767c025b.png">

Filler-project is from the Algorithm-branch at The Hive Helsinki.  
The objective is to create a (winning) player for a game that's given as a virtual machine.  
  
Key things I learned: Got more in depth with reading and saving data, how to capitalize the data, and that testing includes abusing the program with terrible arguments.  
  
  

## Executing the program
  
- Clone the repository to your workspace and go to the root of the repo.
- type `make` to create the executable (the player).
- You can choose the player you want to play against, all the players are located at */resources/players/*.
- You have three possibilities for map size - small(map00), regular(map01) or big(map02). The maps are located at */resources/maps/*.
- To launch the game from the root you have to use the players in the resources/players -folder:  
&emsp; **./resources/filler_vm -f resources/maps/_mapsize-of-your-choice_ -p1 resources/players/mtissari.filler -p2 resources/players/_player-of-your-choice_**
- Example: `./resources/filler_vm -f resources/maps/map01 -p1 resources/players/mtissari.filler -p2 resources/players/superjeannot.filler`
- To launch the player you just made with `make`:
  - Go to resources directory (`cd resources`) and from there type:  
&emsp; **./filler_vm -f maps/map01 -p1 ../mtissari.filler -p2 players/grati.filler** (or the player(or map) of your choice)
  
## How the game works
  
The idea of the game is to fill a map with your own symbols.  
Both players receive different shapes to put into the map and the game ends when neither player can put any more pieces to the map.  
When a player cannot fit a piece to the map, the game ends for that player but the other player can continue until the same happens to it.  
The virtual machine gives the program all the needed information in standard output.  
  
### How the game flows
First the players receive information whether they're player 1 or player 2, which tells them if their symbol is 'O' or 'X'.  
Second information is the map - how big it is, and where is the starting position of the players.  
Third, and last piece of information is the piece the player needs to fit to the map.  
The virtual machine sends an updated map each turn, with a new piece. 
  
#### Fitting the piece
- The _whole piece_ needs to fit in the map - _not just the shape_ of it.
- _One, and only one, cell of the shape_ **must** overlap _one_ of your _own symbols_ on the map.
- The empty cells ('.') can overlap any symbol on the map.
  
The terminal fills with turns as both players fill the map on their turn. Depending on the map size, it takes 0 - 10 seconds to play a map.  
The winner can be seen on the terminal or from the trace in the resources directory.
  
  
## The code
  
I tried to make the code as readable as possible, and I think I did quite well, apart from the algorithm part(heat_map).  
I even changed most of the architecture when I already had a functioning program, however the readability wasn't the only reason for it.  
I had great challenges to find a mistake in the code, which made the program segfault every now and then, and the architecture change was one of the attempts.
Eventually the problem was found in the algorithm.  
  
When I started the project, I already knew I was going to use the heat map -approach. The algorithm came to me quite quickly after completely understanding the rules and how the game flows.  
  

before making the heatmap:

<img width="252" alt="Screenshot 2022-10-12 at 14 26 52" src="https://user-images.githubusercontent.com/86073849/195331079-7dbd316b-feb7-4ccb-9e7a-970dabae2766.png">

heatmap:

<img width="372" alt="Screenshot 2022-10-12 at 13 51 12" src="https://user-images.githubusercontent.com/86073849/195326031-63d5bb13-04de-4b8f-a0ca-e79cef2fc012.png">
  
  
  
