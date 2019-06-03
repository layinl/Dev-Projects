import 'main.js';

var Player = {

     // Attributes
     name,
     health,
     damage,
     gold,
     current_experience,
     level,


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
     checkLevelUp: function(){

          var should_level_up = this.experience >= maximum_experience();

     }
}