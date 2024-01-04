import './App.css';
import React from 'react';
import { useState } from 'react';
//3D array prob: prob[i][j][k] === probability of beating k armies when attacker has i+1 and defendent has j+1 armies
let prob = [
  [
    [0.583333,0.416667,0],
    [0.745370,0.254630,0]
  ],
  [
    [0.421296,0.578704,0],
    [0.448302,0.324074, 0.227623],
  ],
  [
    [0.340278,0.659722,0],
    [0.292567, 0.335777,0.371656]
  ]
]
function p (my_armies, opp_armies, want_to_win) {
  return prob[my_armies-1][opp_armies-1][want_to_win];
}
function play (my_armies, opp_armies) {
  console.log(my_armies, opp_armies);
  if (my_armies <= 0) return 0;
  if (opp_armies <= 0) return 1;

  if (opp_armies == 1) {
    if (my_armies == 1) return p(1,1,1);
    else if (my_armies == 2) {
      return p(2,1,1) + p(2,1,0) * play(1,1);
    }
    else {
      return p(3,1,1) + p(3,1,0) * play(my_armies-1,1);
    }
  } else {
    if (my_armies == 1) {
      return p(1,2,1) * play(1,opp_armies-1);
    } else if (my_armies == 2) {
      return p(2,2,2) * play(2,opp_armies-2) + p(2,2,1) * play(1,opp_armies-1);
    } else {
      return p(3,2,2) * play(my_armies, opp_armies-2) + 
             p(3,2,1) * play(my_armies-1,opp_armies-1) +
             p(3,2,0) * play(my_armies-2,opp_armies);
    }
  }
}


function App() {
  const [probability,setProbability] = useState(0);
  function handleCalculateClick (my_armies,opp_armies) {
    let probability_of_winning = play(my_armies-1, opp_armies-0);
    setProbability(probability_of_winning);
  }
  return (
    <div className="App">
      <div>You (the attacker) have : 
      <form>
        <input id="my_armies" type="number" min="2" defaultValue="2" max="20" required></input>
        </form>
        armies (including the one you should leave behind). </div>
        <div>The opponent has: 
      <form>
        <input id = "opp_armies" type="number" min="1" defaultValue="1" max="20" required></input>
        </form>
        armies in the territory you want to attack. </div>
       <div className="result">
    <button onClick={() => handleCalculateClick(document.getElementById("my_armies").value, document.getElementById("opp_armies").value)}>Calculate your chances!</button>
    
        {probability ? (
           <div >The probability of getting the territory is: <strong>{probability*100}%.</strong></div>
        ) : (
          <div></div>
        )}
        
      
    </div>
    </div>
  );
}

export default App;
