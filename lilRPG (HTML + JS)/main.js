/*
// PLAYER
var Player = {

     // Attributes
     name,
     health,
     max_health,
     shield,
     damage,
     gold,
     current_experience,
     level,
     armor,
     race,
     job,
     overheal: false,

     // Methods
     maximum_experience: function(){
          return (this.level**2)*5 + 5;
     },
     gainExperience: function(exp){
          this.experience += exp;
          cl('Recieved '+exp);
          this.checkLevelUp();

          cl('Current Level: '+this.level);
     },
     levelUp: function(){
          var should_level_up = this.experience >= maximum_experience();
          if(should_level_up){

          }
     },
     getHit: function(damage){

     },
     loseHealth: function(damage) {
          this.health -= damage;
          if(this.health<=0){
               die();
          }
     },
     restoreHealth: function(heal) {
          this.health += heal;
          if(this.health>=max_health && !overheal){
               this.health = max_health;
          }
     },
     dealDamage: function(entity){
          entity.getHit(this.damage);
     },
}
*/
// enemy
var enemy = {
     health: max_health,
     max_health: 25,
     damage: 5,
     gold: 10,
     experience: 15,

     getHit: function(damage){
          this.loseHealth(damage);
     },
     loseHealth: function(damage){
          this.health -= damage;
          if(this.health<=0){
               this.die();
          }
     },
     die(){
          player.gold += this.gold;
          player.experience += this.experience;

     },
}

// player
var player = {
     health: max_health,
     max_health: 100,
     damage: 10,
     gold: 0,
     experience: 0,
     
     getHit: function(damage){
          this.loseHealth(damage);
     },
     loseHealth: function(damage){
          this.health -= damage;
          if(this.health<=0){
               this.die();
          }
     },
     die(){
          player.gold += this.gold;
          player.experience += this.experience;
          restartGame();
     },
}

// Main

prompt();

//
// Functions
//

function restartGame(){
     player = {
          health: max_health,
          max_health: 100,
          damage: 10,
          gold: 0,
          experience: 0,
          
          getHit: function(damage){
               this.loseHealth(damage);
          },
          loseHealth: function(damage){
               this.health -= damage;
               if(this.health<=0){
                    this.die();
               }
          },
          die(){
               player.gold += this.gold;
               player.experience += this.experience;
               restartGame();
          },
     }
}

function cl(message) {
     console.log(message);
}


//
// Variables
//





