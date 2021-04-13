# Pokemon-Battle-Simulator-Game

Language: C++ 11

The game aims to provide kids as well as Pokemon fans with a turn-based fighting game that features classic Pokemon such as Pikachu and Squirtle. The program incorporates many features to make this game an enjoyable experience for players. To begin with, the user will be prompted to pick 1 from 3 different Pokemon and will fight with one Bot. In addition, the player can enter, “0,” to get relevant info of any Pokemon before picking. Information regarding the Pokemon is stored in an aggregated class called PokemonID. Each Pokemon will be in its own class. Pokemon classes are derived from the Health Class which keeps track of the Pokemon’s Health. The Pokemon will initially begin with a full Health Bar, which is dependent on the Pokemon’s stats. Each Pokemon will have four moves(skills) with different damage values, some of the moves can heal themselves. Also, each move will have a limit, which means, how many times it can be used. While fighting the user and opponent take turns using moves, the user will select its moves, while the bot will have its moves chosen randomly. If a move has a status condition associated with it it will call the Health class to subtract however many health points (HP) from the Pokemon. Moves made by the player or bot can be dodged. The dodge calculation is done by the HitProbabilityCalculator class. Besides the Health class mentioned above, each Pokemon class also derives from HitPobilityCalculator class. If the move is dodged, the Health class will not be evoked. When the HP of either side is less than or equal to 0, a message box will be popped up to highlight which side won the game. Winner information will be stored including the final HP and a .txt file after the end of the game.


Main components relationship diagram:
![image](https://user-images.githubusercontent.com/50966363/114493165-085d9200-9be8-11eb-9eb9-8708ce201f41.png)

Project Run\

![image](https://user-images.githubusercontent.com/50966363/114493437-92a5f600-9be8-11eb-8530-9c45ad2dfc6e.png)

![image](https://user-images.githubusercontent.com/50966363/114493503-a9e4e380-9be8-11eb-9de4-7ad1c5cbbcae.png)

![image](https://user-images.githubusercontent.com/50966363/114493519-b2d5b500-9be8-11eb-979b-ed1a6e755a5f.png)

![image](https://user-images.githubusercontent.com/50966363/114493557-c3862b00-9be8-11eb-9bf4-f22352230f50.png)

![image](https://user-images.githubusercontent.com/50966363/114493574-ca14a280-9be8-11eb-99f9-76de160fd3f4.png)

