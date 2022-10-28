function Bomb(num){
    this.time = num;
    for(let i=0; i < this.time-1; i++) {
      setTimeout(function(){
          console.log(num-i-1);
      }, i*1000);
   }
    setTimeout(function(){console.log("ВЗРЫВ");}, (num-1)*1000);
  }
  
  
  let bomb = new Bomb(7);