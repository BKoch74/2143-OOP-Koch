## A05 - Designing Your Game
### Bryce Koch
### Description:

UML class design for a D&D program to help visualize the implementation of code in the program.

### Files

|   #   | File     | Description                      |
| :---: | -------- | -------------------------------- |
|   1   | [Banner.cpp](https://github.com/BKoch74/2143-OOP-Koch/blob/main/Assignments/A05/Banner.cpp) | Banner page for my assignment.|
|   2   | [OOP_A05_DND.pdf](https://github.com/BKoch74/2143-OOP-Koch/blob/main/Assignments/A05/OOP_A05_DND.pdf) | UML class design of my D&D program. |

### D&D Classes
![DND DM](https://user-images.githubusercontent.com/113659870/236082026-852be036-1c7a-40b2-907b-cce679546451.png)

The above image shows the D&D campaign and dungeon master along with their relationships. Since the dungeon master is in full control of the campaign, they inherit everything from campaign so they have full access to make, edit, and alter campaigns. 

![DND characters](https://user-images.githubusercontent.com/113659870/236082793-b964029a-4368-4c60-bf75-63e4e7759e68.png)

The players and enemies of the D&D campaign are both children classes of the character class. This is due to them sharing similar aspects and definitions. The player class and enemies class have an is-a relationship with the character class because they are both types of characters. 

Players and enemies in D&D have many statistics, a weapon or weapons, and an inventory.

![Character additions](https://user-images.githubusercontent.com/113659870/236083298-e154d315-4a8d-4625-9830-a1eeca6bb890.png)

The four classes above define the characteristics of each player and enemy created in the campaign. Spell and hanheld both inherit from weapon as they are both types of weapons and can have simalar stats to one another. For instance, a barbarian might use a sword which is a type of handheld weapon and the same goes for spell.

The classes inventory, stats, spell, and handheld all make-up the two character types. So the two character classes share a has-a relationship with the four aforementioned classes.

![DND DM-Battle](https://user-images.githubusercontent.com/113659870/236084457-47d624f5-f25c-40fb-91bd-bc2a7e27c68d.png)

The battles class ties into the characters as a battle is composed of players and enemies. The battle is controlled by the dungeon master but uses the abilities, stats, weapons, and everything else available to the characters.
