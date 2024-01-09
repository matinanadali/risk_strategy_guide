# <a href = "https://voluble-blini-e8e590.netlify.app/">Risk strategy guide</a>
#### A web app that calculates the probability of grabbing a territory with a certain number of armies and helps players adjust their strategy and improve their chances of winning in this all-time-classic strategic board game.
### Objective of the game and general rules

  - **Objective:** The main goal of the game is to achieve world domination by eliminating opponents and conquering territories.
- **Setup:** Players receive a certain number of armies based on the number of territories they control. Players take turns placing their armies on the map.
- **The game:** One their turn,  players can attack enemy territories by rolling dice to determine the outcome of battles. The more armies they have in the territory they are attacking from, the more dice they roll (with a maximum of three dice). Same holds for the defender with a maximum of two dice. More specifically, to determine the outcome of a battle, we compare the highest die each of the players (attacker and defender) rolled. If the attacker's is higher, the defender loses an army from the territory under attack. Else the attacker loses an army from the territory he attacked from. If each of the players has more than one army in their territory, they roll more than one dice, so the process is repeated for the pair of dices with the second greatest values.
- **Winning:** The game continues until a player conquers all territories, eliminating opponents along the way.<br><br>
  You can find out more about the official rules of the game<a href="https://www.officialgamerules.org/risk#google_vignette"> here</a><br>
### Using the app
The attacker enters the number of armies he has in the territory he wants to attack from, as well as the number of armies his opponent has in the territory he (the attacker) wants to grab. By clicking on the "Calculate your chances" button, he can see how likely it is to win the battle and then decide, whether he will go for it or not.
<br>

### App's Breakdown
The app is split into 2 parts: the C programm for finding the probability of winning a battle when the attacker rolls x (1 <= x <= 3) and the defender y (1 <= y <= 2) dice and the React App for creating the user interface and calculating the probability of winning when the attacker has a (2 <= a <= 20) armies and the defender b (1 <= b <= 20) armies.
- **C programm calculate_dice_probabilities**:calculates and prints the probabilities of winning, losing, and tying in various scenarios of a dice game. Nested loops simulate all possible outcomes for each scenario by iterating through the possible values of the dice.
- **React.js App risk_strategy_guide**: this application provides a simple user interface for users to input the number of armies for the attacker and defender, and it dynamically calculates and displays the probability of the attacker winning the territory based on the defined probabilities, transfered from the helper C programm.

### Technologies used
- React.js
- HTML, CSS, Javascript
- C



